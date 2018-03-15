/******************************************************************************
 * $Id: knl.cxx 2018-03 $
 *
 * Project:  METS(Layer: mets::cKnl).
 * Purpose:  Knl(Kernel).
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

#include "knl_module.hxx"

using namespace mets;

/**
 * \brief Constructor.
 */
cKnl::cKnl()
{
    // METS_BMD_POINTER_INIT(mModule);
}

/**
 * \brief Destructor.
 */
cKnl::~cKnl()
{
    // METS_BMD_CLASS_DEL(mModule);
}

/**
 * \brief Initialize.
 */
tUErrCode cKnl::init()
{
    return tUErrNone;
}

/**
 * \brief Module.
 */
cKnlModule *cKnl::module()
{
    // METS_BMD_CLASS_NEW(mModule, cKnlModule);

    return &mModule;
}
