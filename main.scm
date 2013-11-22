(define (foo)
  (display (map has-entity '(0 1 2 3 4 5 6 7 8 9 10)))
  (newline))

(define bar
  (lambda () (display "script called") (newline)))

(display "Hey world!\n")
