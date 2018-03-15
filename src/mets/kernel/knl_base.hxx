/******************************************************************************
 * $Id: knl_base.hxx 2018-03 $
 *
 * Project:  METS(Layer: mets::cKnl).
 * Purpose:  Knl base.
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

#ifndef METS_KNL_BASE_HXX_INCLUDED
#define METS_KNL_BASE_HXX_INCLUDED

#define METS_LIB

#define METS_KNL_LIB METS_LIB

#define METS_NOT_REACHABLE

// in "stddef.h"
#ifndef __cplusplus
#define NULL ((void*) 0)
#else  // cxx
#define NULL 0
#endif  // c

typedef int tUInt;
typedef char tUChar;

const tUChar charNull = ' ';

typedef enum
{
    tUErrNone  = 0,
    tUErrError = 1,
} tUErrCode;

#define METS_BMD_POINTER_INIT(aName)                 \
    aName = NULL

#define METS_BMD_CLASS_H(aName, aClass) \
    ((aClass *) aName)
    
#define METS_BMD_CLASS_NEWH(aName, aClass, aHandle)                 \
    if (aName == NULL)                                              \
    {                                                               \
        aName = (aHandle *) new aClass;                             \
        if (METS_BMD_CLASS_H(aName, aClass)->init() == tUErrError)  \
        {                                                           \
            delete aName;                                           \
            aName = NULL;                                           \
        }                                                           \
    }

#define METS_BMD_CLASS_NEWH_A_1(aName, aClass, aHandle, aParam1)        \
    if (aName == NULL)                                                  \
    {                                                                   \
        aName = (aHandle *) new aClass(aParam1);                        \
        if (METS_BMD_CLASS_H(aName, aClass)->init() == tUErrError)      \
        {                                                               \
            delete aName;                                               \
            aName = NULL;                                               \
        }                                                               \
    }

#define METS_BMD_CLASS_NEW(aName, aClass) \
    METS_BMD_CLASS_NEWH(aName, aClass, aClass)

#define METS_BMD_CLASS_NEW_A_1(aName, aClass, aParam1) \
    METS_BMD_CLASS_NEWH_A_1(aName, aClass, aClass, aParam1)

#define METS_BMD_POINTER_DELH(aName, aHandle) \
    if (aName != NULL)                        \
    {                                         \
        delete (aHandle *) aName;             \
        METS_BMD_POINTER_INIT(aName);         \
    }

#define METS_BMD_POINTER_DEL(aName)             \
    if (aName != NULL)                          \
    {                                           \
        delete aName;                           \
        METS_BMD_POINTER_INIT(aName);           \
    }

#define METS_BMD_CLASS_DELH(aName, aClass)      \
    METS_BMD_POINTER_DELH(aName, aClass)

#define METS_BMD_CLASS_DEL(aName)          \
    METS_BMD_POINTER_DEL(aName)

#endif  // METS_KNL_BASE_HXX_INCLUDED
