(define (count-change amount)
  (cc amount 5))
;(define(NOT? x?)(= 0(cond (x? 1) (#t 0))))
          
;(define(NOT? x?)(= 0(cond (x? 1) (else 0))))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ;((or (< amount 0) (= kinds-of-coins 0)) 0)
	((< amount 0) 0)
	((= kinds-of-coins 0) 0)
        (else (+ (cc amount
                     (- kinds-of-coins 1))
                 (cc (- amount
                        (first-denomination kinds-of-coins))
                     kinds-of-coins)))))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 15)
        ((= kinds-of-coins 5) 20)
        (else 0)
        ))

(define group 8)
(define variant 29)

(count-change 100)
(count-change (remainder (+ (* 100 group) variant) 137))