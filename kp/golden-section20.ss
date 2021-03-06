;golden-section20

;(define(NOT? x?)(= 0(cond (x? 1) (else 0))))
(define a 1)(define b 4);3.47372
(define (fun x)
 (set! x (- x (* 29 (/ 30))))
 (-(-(- x (atan(* 2 x))) (log(* pi x))) 6)
)

(define (golden-section-search a b)
 (let(
      (xmin(cond((< a b)(golden-start a b))(else(golden-start b a ))))
     )
     (newline)
     xmin
 )
)
(define (golden-start a b)
 (let(
      (xa (+ a (* mphi(- b a))))
      (xb (- b (* mphi(- b a))))
     )
     (try a b xa (fun xa) xb (fun xb))
 )
)

(define (set1 a b xa xb ya yb)
  (set! b xb)
  (set! xb xa)
  (set! yb ya)
  (set! xa (+ a (* mphi(- b a))))
  (try a b xa (fun xa) xb yb)
 )
(define (set2 a b xa xb ya yb)
  (set! a xa)
  (set! xa xb)
  (set! ya yb)
  (set! xb (- b (* mphi(- b a))))
  (try a b xa ya xb (fun xb))
 )

(define mphi (* +0.5E+0(- 3(sqrt 5))))
(define (try a b xa ya xb yb)
 (cond((close-enough? a b)
      (* (+ a b)+0.5E+0))
      (else (let() (display "+")
             (cond((< ya yb) (let() (set1 a b xa xb ya yb))
                  )
                  (else (let() (set2 a b xa xb ya yb))
                   )
             );cond...
	)
      );let...
 );if...
)
(define (close-enough? x y)
  (<(abs (- x y))tolerance))
(define tolerance +0.00001E+0)
(define xmin 0)
(set! xmin(golden-section-search a b))
  (display"interval=\t[")
  (display a)
  (display" , ")
  (display b)
  (display"]\n")
  (display"xmin=\t\t")
xmin
  (display"f(xmin)=\t")
(fun xmin)
