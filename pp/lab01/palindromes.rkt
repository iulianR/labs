;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-abbr-reader.ss" "lang")((modname palindromes) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ())))
;; Avem de rezolvat urmatoarea problema:
;; Sa se gaseasca toate numerele naturale, mai mici sau egale cu un numar n,
;; care sunt palindroame atat in baza 10 cat si in baza 2

;; Pentru a rezolva problema, vom defini, pe rand, functii pentru:
;; - reprezentarea (ca lista de "cifre") a unui numar natural intr-o baza b
;; - testul ca o lista este palindrom (adica este totuna cu lista inversata)
;; - testul ca un numar este palindrom in toate bazele dintr-o lista data
;; - parcurgerea tuturor numerelor pana la un numar dat n, si selectarea celor
;;   palindroame in toate bazele dintr-o lista data de baze

;; 1. (2p)
;; Fie urmatoarele axiome pentru obtinerea reprezentarii unui numar natural
;; in baza b.
;; num->base(0,b) = [ ]                                   ; pt n=0
;; num->base(n,b) = num->base(n div b, b) ++ [ n mod b ]  ; pt n>0
;; Implementati functia corespunzatoare in Scheme:

(define (num->base n b)
  (if (= n 0)
      null
      (append (num->base (quotient n b) b) (list (modulo n b)))))

(check-expect (num->base 489 10) '(4 8 9))
(check-expect (num->base 489 2) '(1 1 1 1 0 1 0 0 1))

;; 2. (2p)
;; Fie urmatoarele axiome pentru inversarea unei liste.
;; rev([ ]) = [ ]
;; rev(x:l) = rev(l) ++ [x]
;; Implementati functia corespunzatoare in Scheme:

(define (rev L)
  (if (null? L)
      null
      (append (rev (cdr L)) (list (car L)))))

(check-expect (rev '(5 1 4 8 7)) '(7 8 4 1 5))

;; 3. (1p)
;; Implementati testul ca o lista L este palindrom.

(define (palindrome? L)
  (if (equal? L (rev L))
      #t
      #f))


(check-expect (palindrome? '(1 4 4 1)) #t)
(check-expect (palindrome? '(1 4 2 4 1)) #t)
(check-expect (palindrome? '(1 4 4 1 4 1)) #f)

;; 4. (2,5p)
;; Testati ca n este palindrom in toate bazele din lista Bases

(define (all-palindromes? n Bases)
  (if (null? Bases)
      #t
      (and (palindrome? (num->base n (car Bases))) (all-palindromes? n (cdr Bases)))))


(check-expect (all-palindromes? 585 '(2 10)) #t)
(check-expect (all-palindromes? 594 '(2 10)) #f)

;; 5. (2,5p)
;; Gasiti toate numerele naturale, mai mici sau egale cu n, care sunt
;; palindroame in toate bazele din lista Bases

(define (palindromes-to-n n Bases)
  (if (< n 0)
      null
      (if (all-palindromes? n Bases)
           (append (palindromes-to-n (- n 1) Bases) (list n))
           (palindromes-to-n (- n 1) Bases))))
        
(check-expect (palindromes-to-n 100 '(2 10)) '(0 1 3 5 7 9 33 99))

;; 6. BONUS (2p)
;; Sa se gaseasca primul numar de cel putin 2 cifre care este palindrom in
;; minim 4 baze dintre bazele 2, 3, 4, 5, 6, 7, 8, 9, 10.

(define (bases-count n Bases)
  (if (null? Bases)
      0
      (+ (if (palindrome? (num->base n (car Bases)))
             1
             0)
         (bases-count n (cdr Bases)))))

(define (palindrome-in-4-bases two-digits Bases)
  (if (>= (bases-count two-digits Bases) 4)
      two-digits
      (palindrome-in-4-bases (+ 1 two-digits) Bases)))

(define Bases '(2 3 4 5 6 7 8 9 10))

(define first-4-palindrome
  (palindrome-in-4-bases 10 Bases))

(check-expect first-4-palindrome 121)

;; 7. BONUS (3p)
;; Un numar Lychrel este un numar natural care nu devine palindrom in urma
;; procesului iterativ de a aduna numarul cu inversul sau.
;; Exemple de numere care nu sunt Lychrel:
;; 56 devine palindrom dupa o iteratie: 56 + 65 = 121
;; 59 devine palindrom dupa 3 iteratii:
;; 59 + 95 = 154, 154 + 451 = 605, 605 + 506 = 1111
;; Sa se gaseasca numerele naturale pana la Max care nu sunt si nu devin
;; palindroame dupa n iteratii

(define (reverse-number  x)
  (string->number
   (list->string
    (rev
     (string->list
      (number->string x))))))

;; true if palindrome
;; n numărul
(define (check-number n iterations)
  (if (< iterations 0)
      #f
      (or (palindrome? (num->base n 10)) (check-number (+ n (reverse-number n)) (- iterations 1)))))

;; Max nr, n iterațiile
(define (maybe-lychrel Max n)
  (if (< Max 0)
      null
      (if (equal? (check-number Max n) #f)
          (append (maybe-lychrel (- Max 1) n) (list Max))
          (maybe-lychrel (- Max 1) n))))
                 

(check-expect (maybe-lychrel 200 25) '(196))