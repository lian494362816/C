
SECTIONS {
    . = 0x30000000 ;

    . = ALIGN(4) ;
    __copy_code_start = . ;
    .text :
    {
    	start.o
    	*(.text)
    }

    . = ALIGN(4) ;
    .rodata : { *(.rodata) }

    . = ALIGN(4) ;
    .data : { *(.data) }

    . = ALIGN(4) ;
    __bbs_start = . ;
    .bbs : { *(.bbs) *(.COMMON) }
    __end = . ;

}
