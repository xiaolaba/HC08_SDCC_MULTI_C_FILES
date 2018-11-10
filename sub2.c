// xiaolaba, 2018-NOV-11
// testing sdcc3.8.0
// multiple C source files compile and link
// sub2.c

void sub2(){
  __asm
    lda #2
    nop
  __endasm;
}