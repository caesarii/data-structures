(define log 
    (lambda x 
        (display x)
        (newline)
    )
)


(define ListCreate 
    (lambda (l) 
        l
    )
)

(define ListLength
    (lambda (ls)
        (if (null? ls)
            0
            (+ (ListLength (cdr ls)) 1)
        )
    )
)

(define ListContains
    (lambda (ls target)
        (cond
            [(null? ls) #f]
            [(eqv? (car ls) target) #t]
            [else (ListContains (cdr ls) target)]
        )
    )
)

(define ListPrepend
    (lambda (ls element)
        (cons element ls)
    )
)

(define ListAppend
    (lambda (ls element)
        (letrec ([loop (lambda (l new)
            (if (null? l)
                new
                (loop (cdr l) (cons (car l) new))
            ))])
            (loop ls (cons element '()))    
        )

        ; (cons ls (cons element '()))
    )
)

(define ListShift
    (lambda (ls)
        (cdr ls)
    )
)

(define ListIndexOfElement
    (lambda (ls target)
        (letrec ([loop (lambda (l i)
            (if (null? l) 
                #f
                (if (eqv? (car l) target)
                    i
                    (loop (cdr l) (+ i 1))
                )
            )
        )])
        (loop ls 0)
        )
    
    )
)

(define ListElementAt
    (lambda (ls index)
        (if (= index 0)
            (car ls)
            (ListElementAt (cdr ls) (- index 1))
        )
    )
)

; (define ListInsert
;     (lambda (ls element index)
;         (letrec ([loop (lambda (left index right)
;             (if (= index 0)
;                 (begin 
;                     (cons element right)
;                     (cons ))))]))
            
            
;     )
; )



; test

; ListCreate
(define l1 (ListCreate '(1 2 3 4)))
(log l1)

; ListLength
(log (ListLength l1))

;ListContains
(log (ListContains l1 1))
(log (ListContains l1 5))

; ListAppend
(log "append" (ListAppend l1 0))

; ListPrepend
(log (ListPrepend l1 0))

; ListShift
(log (ListShift l1))

; ListIndexOfElement
(log (ListIndexOfElement l1 3))

; ListElementAt
(log (ListElementAt l1 2))
