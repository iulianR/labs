

(define x 5)

(define nothing (lambda (x y z) #t))

(define oneof (lambda (first)
  (if first 1 gibberish)
))

(define (check-and-1) (and #t something other-something))
(define (check-and-2) (and #f something other-something))
(define (check-or-1) (or #t something other-something))
(define (check-or-2) (or #f something other-something))
