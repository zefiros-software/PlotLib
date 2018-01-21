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
#ifndef __PLOTPROPERTIES_H__
#define __PLOTPROPERTIES_H__

#include "plot/properties/line2dProperties.h"

template<class tBase, bool IsDict, bool IsBase >
class PlotProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class PlotProperties
    : public Line2DProperties< PlotProperties< tBase, IsDict >, IsDict, true >
{
public:

    inline typename Line2DProperties<PlotProperties<tBase, IsDict>, IsDict, true>::tReturn &UseColourCycler(
        const std::string &colourCycler)
    {
        this->AddArgument("color", "next(" + colourCycler + ")");

        return static_cast<tBase &>(*this);
    }

    inline typename Line2DProperties<PlotProperties<tBase, IsDict>, IsDict, true>::tReturn &SetWidth(double width)
    {
        this->AddArgument("linewidth", width);

        return static_cast<tBase &>(*this);
    }

    inline typename Line2DProperties<PlotProperties<tBase, IsDict>, IsDict, true>::tReturn &SetLineStyle(const std::string &style)
    {
        this->AddArgument("linestyle", this->GetString(style));

        return static_cast<tBase &>(*this);
    }

};

typedef PlotProperties<> Line;

#endif