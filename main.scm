(define (foo)
  (map has-entity '(0 1 2 3 4 5 6 7 8 9 10)))

(define (main)
  (display "Called the `main` function.\n")
  (display "Factorial: ") (display (factorial 10)) (newline)
  (display "Entity existence map: ") (display (foo)) (newline))

(display "Loaded main.scm!\n")
