/******************************************************************************
 * $Id: knl.hxx 2018-02 $
 *
 * Project:  METS(Layer: mets::cKnl).
 * Purpose:  Knl(Kernel).
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

#ifndef METS_KNL_HXX_INCLUDED
#define METS_KNL_HXX_INCLUDED

// knl
#include "knl_base.hxx"
#include "knl_module.hxx"

namespace mets
{
    // class cKnlModule;

    class METS_KNL_LIB cKnl
    {
      public:
        cKnl();
        ~cKnl();

        tUErrCode init();
        cKnlModule *module();

      protected:
      private:
        cKnlModule mModule;
    };
}

#endif  // METS_KNL_HXX_INCLUDED
