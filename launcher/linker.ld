ENTRY(_start)

SECTIONS {
	start_addr = 0x8CFE0000;

	. = start_addr;

	.init : {
		*(.init)
	}

	.text : {
		*(.text*)
		*(.rodata*)
	}

	.data : {
		*(.data*)
	}

	.bss : {
		*(.bss*)
		*(COMMON)
	}
}
