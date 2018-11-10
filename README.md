# HC08_SDCC_MULTI_C_FILES
HC08 core, sdcc, how to compile and link multiple C source files
```
:: compile multiple C files
sdcc -c -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF sub1.c
sdcc -c -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF sub2.c
sdcc    -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF main.c sub1.rel sub2.rel

:::: then link them 
sdcc -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF -o main.s19 main.rel sub1.rel sub2.rel 

```
.    
.      

```

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
```
.    
.      

```
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
```
.  
.  
    
```
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
```
.  
.  
    

partial output of main.rst, no code detail of sub1 or sub2 could be seen, unless load & disassemble main.s19  
actual code was there and good for excution.  
```
;------------------------------------------------------------
;main.c:9: void main(void){
;	-----------------------------------------
;	 function main
;	-----------------------------------------
;	Register assignment is optimal.
;	Stack space usage: 0 bytes.
_main:
;main.c:14: __endasm;
	      lda	#0xff
	      nop
;main.c:16: sub1();
	jsr	_sub1
;main.c:17: sub2();  
;main.c:20: }
	jmp	_sub2
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
```
