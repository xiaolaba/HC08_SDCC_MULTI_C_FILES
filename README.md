# HC08_SDCC_MULTI_C_FILES
HC08 core, sdcc, how to compile and link multiple C source files
```
@echo. off


:: ref, source code, http://hc08web.de/#examples
:: SDCC manual, http://sdcc.sourceforge.net/doc/sdccman.pdf
:: see page 29, Command line option, select target MCU
:: how to compile

:: xiaolaba, 2018-NOV-11

del *.s19

:: compile multiple C files
sdcc -c -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF sub1.c
sdcc -c -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF sub2.c
sdcc    -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF main.c sub1.rel sub2.rel


:::: then link them 
sdcc -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF -o main.s19 main.rel sub1.rel sub2.rel 

mkdir output
move *.lst .\output\
move *.rel .\output\
move *.rst .\output\
move *.sym .\output\
move *.map .\output\
move *.cdb .\output\
move *.asm .\output\
move *.lk  .\output\
pause
```
