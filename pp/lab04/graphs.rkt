#lang racket

;(require test-engine/racket-tests) ;; vreau rezultatele de la teste în consolă
(require test-engine/racket-gui) ;; vreau rezultatele de la teste în fereastră separată

(define (to-curry f)    (λ (x) (λ (y) (f x y))))
(define (to-uncurry f)  (λ args (foldl (λ (arg fp) (fp arg)) f args)))
(define (to-curryN N f) (if (zero? N) (let ((lista (reverse f))) (apply (car lista) (cdr lista))) (λ (x) (to-curryN (- N 1) (cons x (if (list? f) f (list f)))))))
(define (compose f g)   (λ (x) (f (g x))))

;; Ne propunem sa realizam o aplicatie care sa certifice stapanirea urmatoarelor concepte/competente:
;; - abstractizarea la nivel de date (tipuri de date abstracte care ofera o interfata (constructori + operatori)
;;   utilizatorului, astfel incat acesta sa nu fie nevoit sa cunoasca implementarea interna)
;; - abstractizarea la nivel de proces (abilitatea de a folosi functionale)
;; - caracteristica functiilor de a fi valori de ordinul intai
;; - abilitatea de a implementa un program mai mare ca o serie de functii care se apeleaza unele pe altele
;; - folosirea expresiilor de legare statica a variabilelor (let, let*, letrec, named let)

;; Pentru aceasta, definim structura de date graf orientat

;; retinem un graf ca pe o lista de noduri si o lista de arce
(define (make-directed-graph V E) (cons V E))
(define G1 (make-directed-graph 
            '(a b c d e f g) 
            '((a b) (c b) (c d) (d a) (d e) (d f) (e g) (f e) (g b) (g c) (g f))))
(define G2 (make-directed-graph 
            '(a b c d e f g) 
            '((a b) (c b) (c d) (d a) (d e) (d f) (f e) (g b) (g c) (g e) (g f))))

;; 1. (3p)
;; Completati tipul de date graf orientat cu urmatorii operatori:

;; intoarce lista de noduri din graf (0,25p)
(define (get-nodes G)
  (first G))

(check-expect (get-nodes G1) '(a b c d e f g))

;; intoarce lista de arce din graf (0,25p)
(define (get-edges G)
  (cdr G))

(check-expect (get-edges G2) '((a b) (c b) (c d) (d a) (d e) (d f) (f e) (g b) (g c) (g e) (g f)))

;; lista nodurilor catre care nodul v are arc (1,25p)
;; se va implementa obligatoriu folosind functionale si/sau functii anonime, fara recursivitate
(define (outgoing G v)
  (let ([pairs (filter (lambda (x) (equal? v (car x))) (get-edges G))])
    (map cadr pairs)))

(check-expect (outgoing G1 'g) '(b c f))

;; lista nodurilor care au arc catre nodul v (1,25p)
;; se va implementa obligatoriu folosind functionale si/sau functii anonime, fara recursivitate
(define (incoming G v)
  (let ([pairs (filter (lambda (x) (equal? v (cadr x))) (get-edges G))])
    (map car pairs)))

(check-expect (incoming G2 'e) '(d f g))

;; 2. (4p)
;; Realizati parcurgerea DFS a grafului G pornind dintr-un nod dat v. 
;; Rezultatul final va trebui sa fie o lista ordonata de perechi cu punct de forma (nod-vizitat . parinte).
;; Folositi diverse forme de let.
;; Folositi functii auxiliare, daca aveti nevoie.
(define (dfs G v)
  (let DFS ([node v]
            [path (list (cons v 'none))])
    (let ([neighbors (outgoing G node)])
      (foldl
       (lambda (current path)
         (if (assoc current path)
             path
             (DFS current (append path (list (cons current node))))))
       path
       neighbors))))

(check-expect (dfs G1 'd) '((d . none) (a . d) (b . a) (e . d) (g . e) (c . g) (f . g)))

;; 3. (4p)
;; Determinati o cale intre nodurile v1 si v2 din graful G, folosind functia de mai sus.
;; Rezultatul final va fi o lista de noduri sau o lista vida, daca o asemenea cale nu exista.
;; Folositi diverse forme de let.
;; Folositi functii auxiliare, daca aveti nevoie.

(define (get-path G v1 v2)
  (let ([dfs-list (dfs G v1)])
    (foldr
     (λ (edge path)
       (if (equal? (car path) (car edge))
           (if (equal? (car edge) v1)
               path
               (cons (cdr edge) path))
           path))
     (list v2)   
     dfs-list)))

(check-expect (get-path G1 'c 'f) '(c d e g f))

;; 4. BONUS (4p)
;; Determinati daca un graf orientat are cicluri sau nu.
(define (cycle? G node)
  (if (null? (incoming G node))
      #f
      (foldl
       (lambda (current parent)
         (or parent (> (length (get-path G node current)) 1)))
       #f
       (incoming G node))))

(define (has-cycle? G)
  (let ([dfs-list (get-nodes G)])
    (foldl
     (lambda (node parent) (or parent (cycle? G node)))
     #f
     dfs-list)))


(check-expect (has-cycle? G1) #t)
(check-expect (has-cycle? G2) #f)

(test)