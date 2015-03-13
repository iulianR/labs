#lang racket
(define (sum-list L)
  (if (null? L)
      0
      (+ (car L) (sum-list (cdr L)))))

(sum-list '(10 20 30))

(define sum-list2
  (λ (l acc)
    (if (null? l)
        acc
        (sum-list2 (cdr l) (+ acc (car l))))))

(sum-list2 '(2 4 8) 0)