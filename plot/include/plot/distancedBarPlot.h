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
#ifndef __DISTANCEDBARPLOT_H__
#define __DISTANCEDBARPLOT_H__

#include "plot/properties/barProperties.h"
#include "plot/pvec.h"

class DistancedBarPlot
    : public BarPlotProperties< DistancedBarPlot >
{
public:

    DistancedBarPlot(const PVec &x, const PVec &y, const PVec &widths);

    DistancedBarPlot(const std::vector< std::pair< PVec, PVec >> &data, const PVec &widths);

    virtual std::string ToString() override;

    DistancedBarPlot &SetZOrder(double order);

    DistancedBarPlot &UseColourCycler(const std::string &colourCycler);

    DistancedBarPlot &CycleColour();
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/distancedBarPlot.cpp"
#endif

#endif