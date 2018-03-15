/******************************************************************************
 * $Id: knl_term.cxx 2018-03 $
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

#include "knl_term.hxx"

// knl
#include "knl_module.hxx"
#include "knl_vga.hxx"

using namespace mets;

/**
 * \brief Constructor.
 */
cKnlTerm::cKnlTerm()
{
}

/**
 * \brief Destructor.
 */
cKnlTerm::~cKnlTerm()
{
}

/**
 * \brief Initialize.
 */
tUErrCode cKnlTerm::init(cKnlModule *aModule)
{
    mModule = aModule;
    mVga = mModule->vga();

    setRow(0);
    setColumn(0);
    allocMemBuffer();

    return tUErrNone;
}

/**
 * \brief Clear.
 */
tUErrCode cKnlTerm::clear()
{
	tKnlVgaColorCode color = mVga->entryColor(tKnlVgaColorCode::black,
                                              tKnlVgaColorCode::whiteLight);
    tUInt width = mVga->width();
    tUInt height = mVga->height();

	for (tUInt y = 0; y < height; ++y)
    {
		for (tUInt x = 0; x < width; ++x)
        {
			const tUInt id = y * width + x;
            tUInt val = mVga->entry(charNull, color);
            setBuffer(id, val);
		}
	}

    return tUErrNone;
}

/**
 * \brief Set row.
 */
tUErrCode cKnlTerm::setRow(tUInt aRow)
{
    mRow = aRow;

    return tUErrNone;
}

/**
 * \brief Get row.
 */
tUInt cKnlTerm::row()
{
    return mRow;
}

/**
 * \brief Set column.
 */
tUErrCode cKnlTerm::setColumn(tUInt aColumn)
{
    mColumn = aColumn;

    return tUErrNone;
}

/**
 * \brief Get column.
 */
tUInt cKnlTerm::column()
{
    return mColumn;
}

/**
 * \brief Set color.
 */
tUErrCode cKnlTerm::setColor(const tKnlVgaColorCode aColor)
{
    mColor = aColor;

    return tUErrNone;
}

/**
 * \brief Write string.
 */
tUErrCode cKnlTerm::writeStr(const tUChar *aData)
{
    tUInt len = strLen(aData);
	write(aData, len);

    return tUErrNone;
}
 
/***** Private A *****/

/**
 * \brief Get color.
 */
tKnlVgaColorCode cKnlTerm::color()
{
    return mColor;
}

/**
 * \brief Put entry at.
 */
tUErrCode cKnlTerm::putEntryAt(char aChar, const tKnlVgaColorCode aColor,
                               tUInt aX, tUInt aY)
{
    tUInt w = mVga->width();
	const tUInt id = aY * w + aX;
    tUInt val = mVga->entry(aChar, aColor);
	setBuffer(id, val);

    return tUErrNone;
}

/**
 * \brief Put char.
 */
tUErrCode cKnlTerm::putChar(tUChar aChar)
{
    tKnlVgaColorCode vColor = color();
    tUInt vColumn = column();
    tUInt vRow = row();

	putEntryAt(aChar, vColor, vColumn, vRow);

    tUInt vWidth = mVga->width();
    tUInt vHeight = mVga->height();

    setColumn(++vColumn);
	if (vColumn == vWidth)
    {
        setColumn(0);

        setRow(++vRow);
		if (vRow == vHeight)
        {
			setRow(0);
        }
	}

    return tUErrNone;
}

/**
 * \brief Allocate memory of buffer.
 */
tUErrCode cKnlTerm::allocMemBuffer()
{
    mBuffer = (unsigned short int *)0xB8000;

    return tUErrNone;
}


/**
 * \brief Set buffer by index.
 */
tUErrCode cKnlTerm::setBuffer(tUInt aId, tUInt aVal)
{
    mBuffer[aId] = aVal;

    return tUErrNone;
}

/**
 * \brief Calculate length of string.
 */
tUInt cKnlTerm::strLen(const tUChar *aStr)
{
	tUInt len = 0;
	while (aStr[len])
    {
		len++;
    }

	return len;
}

/**
 * \brief Wring string with size.
 */
tUErrCode cKnlTerm::write(const tUChar *aData, tUInt aSize)
{
	for (tUInt i = 0; i < aSize; ++i)
    {
		putChar(aData[i]);
    }

    return tUErrNone;
}
 
/***** Private B *****/
