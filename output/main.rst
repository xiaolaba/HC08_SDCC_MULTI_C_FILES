                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.8.0 #10562 (MINGW64)
                              4 ;--------------------------------------------------------
                              5 	.module main
                              6 	.optsdcc -mhc08
                              7 	
                              8 	.area HOME    (CODE)
                              9 	.area GSINIT0 (CODE)
                             10 	.area GSINIT  (CODE)
                             11 	.area GSFINAL (CODE)
                             12 	.area CSEG    (CODE)
                             13 	.area XINIT   (CODE)
                             14 	.area CONST   (CODE)
                             15 	.area DSEG    (PAG)
                             16 	.area OSEG    (PAG, OVR)
                             17 	.area XSEG
                             18 	.area XISEG
                             19 	.area	CODEIVT (ABS)
   FFFE                      20 	.org	0xfffe
   FFFE EE 00                21 	.dw	__sdcc_gs_init_startup
                             22 
                             23 	.area GSINIT0
   EE00                      24 __sdcc_gs_init_startup:
   EE00 45 01 00      [ 3]   25 	ldhx	#0x0100
   EE03 94            [ 2]   26 	txs
   EE04 CD EE 37      [ 5]   27 	jsr	__sdcc_external_startup
   EE07 27 03         [ 3]   28 	beq	__sdcc_init_data
   EE09 CC EE 21      [ 3]   29 	jmp	__sdcc_program_startup
   EE0C                      30 __sdcc_init_data:
                             31 ; _hc08_genXINIT() start
   EE0C 45 00 00      [ 3]   32         ldhx #0
   EE0F                      33 00001$:
   EE0F 65 00 00      [ 3]   34         cphx #l_XINIT
   EE12 27 0A         [ 3]   35         beq  00002$
   EE14 D6 EE 39      [ 4]   36         lda  s_XINIT,x
   EE17 D7 00 80      [ 4]   37         sta  s_XISEG,x
   EE1A AF 01         [ 2]   38         aix  #1
   EE1C 20 F1         [ 3]   39         bra  00001$
   EE1E                      40 00002$:
                             41 ; _hc08_genXINIT() end
                             42 	.area GSFINAL
   EE1E CC EE 21      [ 3]   43 	jmp	__sdcc_program_startup
                             44 
                             45 	.area CSEG
   EE21                      46 __sdcc_program_startup:
   EE21 CD EE 26      [ 5]   47 	jsr	_main
   EE24 20 FE         [ 3]   48 	bra	.
                             49 ;--------------------------------------------------------
                             50 ; Public variables in this module
                             51 ;--------------------------------------------------------
                             52 	.globl _main
                             53 	.globl _sub2
                             54 	.globl _sub1
                             55 ;--------------------------------------------------------
                             56 ; ram data
                             57 ;--------------------------------------------------------
                             58 	.area DSEG    (PAG)
                             59 ;--------------------------------------------------------
                             60 ; overlayable items in ram 
                             61 ;--------------------------------------------------------
                             62 ;--------------------------------------------------------
                             63 ; absolute ram data
                             64 ;--------------------------------------------------------
                             65 	.area IABS    (ABS)
                             66 	.area IABS    (ABS)
                             67 ;--------------------------------------------------------
                             68 ; absolute external ram data
                             69 ;--------------------------------------------------------
                             70 	.area XABS    (ABS)
                             71 ;--------------------------------------------------------
                             72 ; external initialized ram data
                             73 ;--------------------------------------------------------
                             74 	.area XISEG
                             75 ;--------------------------------------------------------
                             76 ; extended address mode data
                             77 ;--------------------------------------------------------
                             78 	.area XSEG
                             79 ;--------------------------------------------------------
                             80 ; global & static initialisations
                             81 ;--------------------------------------------------------
                             82 	.area HOME    (CODE)
                             83 	.area GSINIT  (CODE)
                             84 	.area GSFINAL (CODE)
                             85 	.area GSINIT  (CODE)
                             86 ;--------------------------------------------------------
                             87 ; Home
                             88 ;--------------------------------------------------------
                             89 	.area HOME    (CODE)
                             90 	.area HOME    (CODE)
                             91 ;--------------------------------------------------------
                             92 ; code
                             93 ;--------------------------------------------------------
                             94 	.area CSEG    (CODE)
                             95 ;------------------------------------------------------------
                             96 ;Allocation info for local variables in function 'main'
                             97 ;------------------------------------------------------------
                             98 ;main.c:12: void main(void){
                             99 ;	-----------------------------------------
                            100 ;	 function main
                            101 ;	-----------------------------------------
                            102 ;	Register assignment is optimal.
                            103 ;	Stack space usage: 0 bytes.
   EE26                     104 _main:
                            105 ;main.c:17: __endasm;
   EE26 A6 FF         [ 2]  106 	      lda	#0xff
   EE28 9D            [ 1]  107 	      nop
                            108 ;main.c:19: sub1();
   EE29 CD EE 2F      [ 5]  109 	jsr	_sub1
                            110 ;main.c:20: sub2();  
                            111 ;main.c:23: }
   EE2C CC EE 33      [ 3]  112 	jmp	_sub2
                            113 	.area CSEG    (CODE)
                            114 	.area CONST   (CODE)
                            115 	.area XINIT   (CODE)
                            116 	.area CABS    (ABS,CODE)
