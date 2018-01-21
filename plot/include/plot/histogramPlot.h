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
#ifndef __HISTOGRAMPLOT_H__
#define __HISTOGRAMPLOT_H__

#include "plot/abstractPlot.h"

class HistogramPlot
    : public AbstractPlot
{
public:

    enum Type
    {
        Bar,
        BarStacked,
        Step,
        StepFilled
    };

    enum class Alignment
    {
        Left,
        Middle,
        Right
    };

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    HistogramPlot(const PVec &vec);

    virtual std::string ToString() override;

    HistogramPlot &SetBins(size_t value);

    HistogramPlot &SetBins(const PVec &bins);

    HistogramPlot &SetRange(double min, double max);

    HistogramPlot &SetNormed(bool normed);

    HistogramPlot &SetWeights(const PVec &weights);

    HistogramPlot &SetCumulative(bool cumulative);

    HistogramPlot &SetBottom(double bottom);

    HistogramPlot &SetBottom(const PVec &bottom);

    HistogramPlot &SetType(Type type);

    HistogramPlot &SetAllignment(Alignment align);

    HistogramPlot &SetOrientation(Orientation orientation);

    HistogramPlot &SetRelativeWidth(double rwidth);

    HistogramPlot &SetLogarithmic(bool log);

    HistogramPlot &SetColour(const std::string &colour);

    HistogramPlot &SetLabel(const std::string &label);

    HistogramPlot &SetStacked(bool stacked);

private:

    std::string GetType(Type type);

    std::string GetAlignment(Alignment align);

};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/histogramPlot.cpp"
#endif

#endif