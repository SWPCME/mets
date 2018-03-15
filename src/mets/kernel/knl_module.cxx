/******************************************************************************
 * $Id: knl_module.cxx 2018-02 $
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

#include "knl_module.hxx"

// knl
#include "knl_vga.hxx"
#include "knl_term.hxx"

using namespace mets;

/**
 * \brief Constructor.
 */
cKnlModule::cKnlModule()
{
    mTerm.init(this);
    mVga.init(this);
    // METS_BMD_POINTER_INIT(mTerm);
    // METS_BMD_POINTER_INIT(mVga);
}

/**
 * \brief Destructor.
 */
cKnlModule::~cKnlModule()
{
    // METS_BMD_CLASS_DEL(mTerm);
    // METS_BMD_CLASS_DEL(mVga);
}

/**
 * \brief Initialize.
 */
tUErrCode cKnlModule::init()
{
    return tUErrNone;
}

/**
 * \brief Terminal.
 */
cKnlTerm *cKnlModule::term()
{
    // METS_BMD_CLASS_NEW_A_1(mTerm, cKnlTerm, this);

    return &mTerm;
}

/**
 * \brief Vga.
 */
cKnlVga *cKnlModule::vga()
{
    // METS_BMD_CLASS_NEW_A_1(mVga, cKnlVga, this);

    return &mVga;
}
