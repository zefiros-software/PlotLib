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
#ifndef __COLOURBARPROPERTIES_H__
#define __COLOURBARPROPERTIES_H__

#include "plot/abstractPlot.h"

static const char *const __PlotLibColourBarPropertiesExtend[] =
{
    "neither",
    "both",
    "min",
    "max"
};

template<class tBase, bool IsDict, bool IsBase >
class ColourBarProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class ColourBarProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, ColourBarProperties< tBase, IsDict >, tBase & >::type tReturn;

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    enum class Extend
    {
        Neither,
        Both,
        Min,
        Max
    };

    enum class Spacing
    {
        Uniform,
        Proportional
    };

    tReturn &SetOrientation(Orientation orientation)
    {
        this->AddArgument("orientation", this->GetString(orientation == Orientation::Horizontal ? "horizontal" :
                                                         "vertical"));

        return static_cast<tBase &>(*this);
    }

    tReturn &SetFraction(double fraction)
    {
        this->AddArgument("fraction", fraction);

        return static_cast<tBase &>(*this);
    }

    tReturn &SetPad(double pad)
    {
        this->AddArgument("pad", pad);

        return static_cast<tBase &>(*this);
    }

    tReturn &SetShrink(double shrink)
    {
        this->AddArgument("shrink", shrink);

        return static_cast<tBase &>(*this);
    }

    tReturn &SetAspect(double aspect)
    {
        this->AddArgument("aspect", aspect);

        return static_cast<tBase &>(*this);
    }

    tReturn &SetAnchor(std::pair<double, double> anchor)
    {
        this->AddArgument("anchor", this->ToTuple(anchor.first, anchor.second));

        return static_cast<tBase &>(*this);
    }

    tReturn &SetParentAnchor(std::pair<double, double> panchor)
    {
        this->AddArgument("panchor", this->ToTuple(panchor.first, panchor.second));

        return static_cast<tBase &>(*this);
    }

    tReturn &SetExtend(Extend extend)
    {
        this->AddArgument("extend", this->GetString(__PlotLibColourBarPropertiesExtend[static_cast<size_t>(extend)]));

        return static_cast<tBase &>(*this);
    }

    tReturn &ExtendRect(bool extend)
    {
        this->AddArgument("extendrect", GetBool(extend));

        return static_cast<tBase &>(*this);
    }

    tReturn &SetSpacing(Spacing spacing)
    {
        this->AddArgument("spacing", this->GetString(spacing == Spacing::Proportional ? "proportional" : "uniform"));

        return static_cast<tBase &>(*this);
    }

    tReturn &SetTicks(const PVec &ticks)
    {
        this->AddArgument("ticks", this->ToArray(ticks));

        return static_cast<tBase &>(*this);
    }

    tReturn &SetFormat(const std::string &fmt)
    {
        this->AddArgument("fmt", this->GetString(fmt));

        return static_cast<tBase &>(*this);
    }

    tReturn &DrawEdges(bool draw)
    {
        this->AddArgument("drawedges", GetBool(draw));

        return static_cast<tBase &>(*this);
    }
};

typedef ColourBarProperties<> ColourBarProps;

#endif