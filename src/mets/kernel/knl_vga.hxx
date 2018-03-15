/******************************************************************************
 * $Id: knl_vga.hxx 2018-03 $
 *
 * Project:  METS(Layer: mets::cKnl).
 * Purpose:  Knl vga.
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

#ifndef METS_KNL_VGA_HXX_INCLUDED
#define METS_KNL_VGA_HXX_INCLUDED

// knl
#include "knl_base.hxx"
#include "knl_vgabase.hxx"

namespace mets
{
    class cKnlModule;

    class METS_KNL_LIB cKnlVga
    {
      public:
        cKnlVga();
        ~cKnlVga();

        tUErrCode init(cKnlModule *aModule);
        tUInt entry(tUChar aChar, tKnlVgaColorCode aColor);
        tKnlVgaColorCode entryColor(tKnlVgaColorCode aFg,
                                    tKnlVgaColorCode aBg);
        tUErrCode setWidth(const tUInt aWidth);
        tUInt width() const;
        tUErrCode setHeight(const tUInt aHeight);
        tUInt height() const;

      protected:
      private:
        cKnlModule *mModule;

        tUInt mWidth;
        tUInt mHeight;
    };
}

#endif  // METS_KNL_VGA_HXX_INCLUDED
