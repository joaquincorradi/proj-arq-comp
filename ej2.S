.data
  n: .word 10000

.text
  .global main
  main:
    @ Cargar n en R1
    LDR R0, =n
    LDR R1, [R0]


  loop:

  done:

.end