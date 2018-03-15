/******************************************************************************
 * $Id: mets.cxx 2018-03 $
 *
 * Project:  METS(Layer: main).
 * Purpose:  Mets.
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

#include "knl.hxx"

using namespace mets;

extern "C"
void mets_main(void)
{
    // Init.
    cKnl knl;
    knl.init();

    // Module.
    cKnlModule *knlM = knl.module();
    cKnlTerm *term = knlM->term();
    cKnlVga *vga = knlM->vga();

    // Vga.
    vga->setWidth(80);
    vga->setHeight(25);
    // Term.
    term->clear();
    term->setRow(0);
    term->setColumn(0);
    term->setColor(tKnlVgaColorCode::whiteLight);
    term->writeStr("Mets ready now!");
}
