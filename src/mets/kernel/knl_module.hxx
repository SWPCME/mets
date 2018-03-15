/******************************************************************************
 * $Id: knl_module.hxx 2018-02 $
 *
 * Project:  METS(Layer: mets::cKnl).
 * Purpose:  Knl module (Kernel module).
 * Author:   Weiwei Huang, 898687324@qq.com
 *
 ******************************************************************************
 * Copyright (c) 2018-02 ~ 2018 Weiwei Huang
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

#ifndef METS_KNL_MODULE_HXX_INCLUDED
#define METS_KNL_MODULE_HXX_INCLUDED

#include "knl_base.hxx"
#include "knl_vga.hxx"
#include "knl_term.hxx"

namespace mets
{
    // class cKnlVga;
    // class cKnlTerm;

    class METS_KNL_LIB cKnlModule
    {
      public:
        cKnlModule();
        ~cKnlModule();

        tUErrCode init();

        cKnlTerm *term();
        cKnlVga *vga();

      protected:
      private:
        cKnlTerm mTerm;
        cKnlVga mVga;
    };
};

#endif  // METS_KNL_MODULE_HXX_INCLUDED
