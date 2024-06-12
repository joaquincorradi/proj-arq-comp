.data
  .byte 0x80
  .byte 0x40
  .byte 0x20
  .byte 0x10
  .byte 0x08
  .byte 0x04
  .byte 0x02
  .byte 0x01
  .byte 0x02
  .byte 0x04
  .byte 0x08
  .byte 0x10
  .byte 0x20
  .byte 0x40
  .byte 0x80

.text
  .global auto_fantastico
  auto_fantastico:
    LDR R3, =array @ Cargar la dirección de memoria del array en R3
