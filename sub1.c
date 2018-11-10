// xiaolaba, 2018-NOV-11
// testing sdcc3.8.0
// multiple C source files compile and link
// sub1.c

void sub1(){
  __asm
    lda #1
    nop
  __endasm;
}