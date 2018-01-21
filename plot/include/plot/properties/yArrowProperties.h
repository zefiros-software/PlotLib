/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016-2018 Zefiros Software.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @endcond
 */

#pragma once
#ifndef __ENGINE_YARROWPROPERTIES_H__
#define __ENGINE_YARROWPROPERTIES_H__

#include "plot/properties/patchProperties.h"

template<class tBase, bool IsDict >
class YArrowProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value >
class YArrowProperties
    : public PatchProperties< YArrowProperties< tBase, IsDict >, IsDict, true >
{
public:

    typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetXYTip(double x, double y)
    {
        this->AddArgument("xytip", this->ToTuple(x, y));

        return static_cast<typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>(*this);
    }

    typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetXYBase(double x, double y)
    {
        this->AddArgument("xybase", this->ToTuple(x, y));

        return static_cast<typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>(*this);
    }

    typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetWidth(double width)
    {
        this->AddArgument("width", width);

        return static_cast<typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>(*this);
    }

    typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetFraction(double frac)
    {
        this->AddArgument("frac", frac);

        return static_cast<typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>(*this);
    }

    typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetHeadWidth(double headWidth)
    {
        this->AddArgument("headwidth", headWidth);

        return static_cast<typename PatchProperties<YArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>(*this);
    }
};

typedef YArrowProperties<> YArrow;

#endif