/*
*  Linker_Script FOR BLACK PILL (STM32F401CC)
*  Author : Abdelrahman Ibrahim 
*/


/*Memory definitions*/

MEMORY{
    SRAM (xrw) = : ORIGIN : 0x20000000 , LENGHT = 64K
    FLASH (rx) = : ORIGIN : 0x08000000 , LENGHT = 256K
}


/*Sections definitions*/

SECTIONS{

    /* ISR VT section (to save interrupt vector table) in FLASH*/


    /* .text section (to save programm code) in FLASH*/


    /* .rodata section (to save const) in FLASH*/


    /* .data section (to save static and global variables) in FLASH and SRAM*/


    /* .bss section (to save uninitialized global variables) in SRAM*/


    /* .User Heap Stack section (to save Heap sub section) in SRAM*/

    

}