
// xiaolaba, 2018-NOV-11
// testing sdcc3.8.0
// multiple C source files compile and link
// main.c

//function prototype
void sub1(void);
void sub2(void);


void main(void){
//  while(1) {
    __asm
      lda #0xff
      nop
    __endasm;
    
    sub1();
    sub2();  

//  } 
}