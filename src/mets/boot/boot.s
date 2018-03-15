// -*- mode:asm -*-
/******************************************************************************
 * $Id: boot.s 2018-03 $
 *
 * Project:  METS(Layer: boot).
 * Purpose:  Boot.
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-03 ~ 2018 Weiwei Huang
 *
 * This program is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
 * more details.
 *
 * You should have received a copy of the GNU General Public License along 
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

/** 
 * \brief Constants.
 * The constants for the multiboot header.
 */
    // To set the const variable with value.
    // Align the loaded modules on page boundaries.
	.set MBOOT_ALIGN, 1<<0
    // Provide the memory map.
	.set MBOOT_MEMINFO, 1<<1
    // The flag field for multiboot.
	.set MBOOT_FLAGS, MBOOT_ALIGN | MBOOT_MEMINFO
	// The address for the entry of boot, let the bootloader to find the header.
	.set MBOOT_ENTRY, 0x1BADB002
	// Checksum of above, to prove for the multiboot.
	.set MBOOT_CHECK, -(MBOOT_ENTRY + MBOOT_FLAGS)

/**
 * \brief Multiboot header.
 */ 
    // The ".section" defines the section of memory in which the assembly
    // language program is defining elements. 
    .section .mets_mboot
    // The .align directive instructs the gas assembler to align the data on
    // a specific memory boundary. It takes a single operand, the size of the
    // memory boundary on which to align the data.
    .align 4
    // The data types were declared using assembler directives used in the GNU
    // assembler. The .long , .ascii , and .float directives are used to alert
    // the assembler that a specific type of data is being declared.
    // 32-bit integer number (same as .int).
    .long MBOOT_ENTRY
    .long MBOOT_FLAGS
    .long MBOOT_CHECK

/**
 * \brief Stack.
 */
    .section .bss
    .align 16
mets_stack_bottom:
    // 16 KiB
	.skip 16384
mets_stack_top:
    // linker script
    .section .text
    // makes the "mets_start" visible to 'ld'
    .global mets_start
    // The .type directive informs the GNU assembler that the mets_start label
    // defines the start of a function that will be used within the assembly
    // language program. The mets_start label defines the start of the
    // function. The first instruction after the mets_start label is the
    // beginning of the function.
    .type mets_start, %function
mets_start:
    // set up a stack
	mov $mets_stack_top, %esp

/**
 * \brief Kernel.
 * Enter the high-level kernel.
 */
	call mets_main
    cli
1:	hlt
	jmp 1b
    .size mets_start, . - mets_start
