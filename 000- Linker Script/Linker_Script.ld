/*
*  Linker_Script FOR BLACK PILL (STM32F401CC)
*  Author : Abdelrahman Ibrahim 
*/


_Min_Heap_Size = 0x200 ;  
_Min_Stack_Size = 0x400 ; 

/*Memory definitions*/

MEMORY{
    SRAM (xrw) = : ORIGIN : 0x20000000 , LENGHT = 64K
    FLASH (rx) = : ORIGIN : 0x08000000 , LENGHT = 256K
}


/*Sections definitions*/

SECTIONS{

    /* ISR VT section (to save interrupt vector table) in FLASH*/

 .isr_vector :
    {
        . = ALIGN(4);
        *(.isr_vector);
        . = ALIGN(4);
    } >FLASH

    /* .text section (to save programm code) in FLASH*/

 .text :
    {
        . = ALIGN(4);
        *(.text);
        *(.text*);
        . = ALIGN(4);
    } >FLASH

    /* .rodata section (to save const) in FLASH*/

 .rodata :
    {
        . = ALIGN(4);
        *(.rodata);
        *(.rodata*);
        . = ALIGN(4);
    } >FLASH

    /* .data section (to save static and global variables) in FLASH and SRAM*/

 .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data);
        *(.data*);
        . = ALIGN(4);
         _edata = .;
    } >SRAM AT >FLASH 

    /* .bss section (to save uninitialized global variables) in SRAM*/

 .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss);
        *(.bss*);
        . = ALIGN(4);
        _ebss = .;
    } >SRAM

    /* .User Heap Stack section (to save Heap sub section) in SRAM*/

  ._user_heap_stack :
  {
    . = ALIGN(8);
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >RAM
}