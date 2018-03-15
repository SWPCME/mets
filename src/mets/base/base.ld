/******************************************************************************
 * $Id: base.ld 2018-03 $
 *
 * Project:  METS(Layer: base).
 * Purpose:  Base linker.
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
 * \brief Boot loader entry.
 */
ENTRY(mets_start)

/**
 * \brief Section description.
 */
SECTIONS
{
    /* the location counter */
	. = 4M;

    /* program code */
	.text ALIGN(4K) :
	{
		*(.text)
		*(.mets_mboot)
	}

	/* read-only data */
	.rodata ALIGN(4K) :
	{
		*(.rodata)
	}

	/* read-write initialized data */
	.data ALIGN(4K) :
	{
		*(.data)
	}

	/* read-write zero initialized data */
	.bss ALIGN(4K) :
	{
		*(.bss)
		*(COMMON)
	}
}
