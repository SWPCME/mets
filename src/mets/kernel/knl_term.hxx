/******************************************************************************
 * $Id: knl_term.hxx 2018-03 $
 *
 * Project:  METS(Layer: mets::cKnl).
 * Purpose:  Term(terminal).
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

#ifndef METS_KNL_TERM_HXX_INCLUDED
#define METS_KNL_TERM_HXX_INCLUDED

// knl
#include "knl_base.hxx"
#include "knl_vgabase.hxx"
#include "knl_vga.hxx"
#include "knl_term.hxx"

namespace mets
{
    // class cKnlModule;
    // class cKnlVga;

    class METS_KNL_LIB cKnlTerm
    {
      public:
        cKnlTerm();
        ~cKnlTerm();

        tUErrCode init(cKnlModule *aModule);
        tUErrCode clear();
        tUErrCode setRow(tUInt aRow);
        tUInt row();
        tUErrCode setColumn(tUInt aColumn);
        tUInt column();
        tUErrCode setColor(const tKnlVgaColorCode aColor);
        tUErrCode writeStr(const tUChar *aStr);

      protected:
      private:
        tKnlVgaColorCode color();
        tUErrCode putEntryAt(char aChar, const tKnlVgaColorCode aColor,
                             tUInt aX, tUInt aY);
        tUErrCode putChar(tUChar aChar);
        tUErrCode allocMemBuffer();
        tUErrCode setBuffer(tUInt aId, tUInt aVal);
        tUInt strLen(const tUChar *aStr);
        tUErrCode write(const tUChar *aData, tUInt aSize);

        cKnlModule *mModule;
        cKnlVga *mVga;

        unsigned short int *mBuffer;
        tUInt mRow;
        tUInt mColumn;
        tKnlVgaColorCode mColor;
    };
}

#endif  // METS_KNL_TERM_HXX_INCLUDED
