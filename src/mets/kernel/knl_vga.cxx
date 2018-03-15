/******************************************************************************
 * $Id: knl_vga.cxx 2018-03 $
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

#include "knl_vga.hxx"

using namespace mets;

/**
 * \brief Constructor.
 */
cKnlVga::cKnlVga()
{
}

/**
 * \brief Destructor.
 */
cKnlVga::~cKnlVga()
{
}

/**
 * \brief Initialize.
 */
tUErrCode cKnlVga::init(cKnlModule *aModule)
{
    mModule = aModule;

    return tUErrNone;
}

/**
 * \brief Entry.
 */
tUInt cKnlVga::entry(tUChar aChar, tKnlVgaColorCode aColor)
{
    unsigned short int vChar = (unsigned short int) aChar;
    unsigned short int vColor = (unsigned short int) aColor;

	return vChar | vColor << 8;
}

/**
 * \brief Entry Color.
 */
tKnlVgaColorCode cKnlVga::entryColor(tKnlVgaColorCode aFg,
                                     tKnlVgaColorCode aBg)
{
    unsigned char fg = (unsigned char) aFg;
    unsigned char bg = (unsigned char) aBg;

	return (tKnlVgaColorCode) (fg | bg << 4);
}

/**
 * \brief Set width.
 */
tUErrCode cKnlVga::setWidth(const tUInt aWidth)
{
    mWidth = aWidth;

    return tUErrNone;
}

/**
 * \brief Get width.
 */
tUInt cKnlVga::width() const
{
    return mWidth;
}

/**
 * \brief Set height.
 */
tUErrCode cKnlVga::setHeight(const tUInt aHeight)
{
    mHeight = aHeight;

    return tUErrNone;
}

/**
 * \brief Get height.
 */
tUInt cKnlVga::height() const
{
    return mHeight;
}
