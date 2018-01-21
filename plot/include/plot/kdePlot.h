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
#ifndef __KDEPLOT_H__
#define __KDEPLOT_H__

#include "plot/abstractPlot.h"

class KDEPlot
    : public AbstractPlot
{
public:

    enum Kernel
    {
        Gauss,
        Cos,
        Biw,
        Epa,
        Tri,
        Triw
    };

    enum class BW
    {
        Scott,
        Silverman
    };

    KDEPlot(const PVec &data);

    KDEPlot(const PVec &data, const PVec &data2);

    virtual std::string ToString() override;

    KDEPlot &Vertical(bool vertical);

    KDEPlot &SetKernel(Kernel kernel);

    KDEPlot &SetBW(BW bw);

    KDEPlot &SetBW(double scalar);

    KDEPlot &SetBW(const std::pair<double, double> &scalars);

    KDEPlot &SetGridSize(size_t size);

    KDEPlot &SetCut(double cut);

    KDEPlot &SetClip(const std::pair<double, double> &clip);

    KDEPlot &SetClip(const std::pair<double, double> &clipx, const std::pair<double, double> &clipy);

    KDEPlot &Legend(bool legend);

    KDEPlot &Cumulative(bool cumulative);

    KDEPlot &ShadeLowest(bool shadwLowest);

    KDEPlot &ColourBar(bool bar);

private:

    static std::string GetBW(BW bw);

    static std::string GetKernel(Kernel kernel);
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/kdePlot.cpp"
#endif

#endif