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
#ifndef __VIOLINPLOT_H__
#define __VIOLINPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/pvec.h"

class Palette;

class ViolinPlot
    : public AbstractPlot
{
public:

    enum Orientation
    {
        Vertical,
        Horizontal
    };

    enum KernelBandwidth
    {
        Scott,
        Silverman
    };

    enum Scale
    {
        Area,
        Count,
        Width
    };

    enum Interior
    {
        Box,
        Quartile,
        Point,
        Stick,
        None
    };

    ViolinPlot(const PVec &x, const PVec &y);

    ViolinPlot(const std::vector< std::pair< PVec, PVec >> &data);

    ViolinPlot(const std::vector< std::pair< PVec, PVec >> &data, const std::vector< std::string > &hue);

    virtual std::string ToString() override;

    ViolinPlot &SetOrder(const PVec &order);

    ViolinPlot &SetHueOrder(const std::vector< std::string > &order);

    ViolinPlot &SetBandwidth(KernelBandwidth bw);

    ViolinPlot &SetBandwidth(double bw);

    ViolinPlot &SetCut(double cut);

    ViolinPlot &SetScale(Scale scale);

    ViolinPlot &SetScaleHue(bool scale);

    ViolinPlot &SetGridSize(size_t size);

    ViolinPlot &SetWidth(double width);

    ViolinPlot &SetInterior(Interior inner);

    ViolinPlot &SetSplit(bool split);

    ViolinPlot &SetOrientation(Orientation orientation);

    ViolinPlot &SetLineWidth(double width);

    ViolinPlot &SetDodge(bool dodge);

    ViolinPlot &SetColour(const std::string &colour);

    ViolinPlot &SetColourMap(const Palette &pallet);

    ViolinPlot &SetSaturation(double sat);

private:

    std::string GetScale(Scale scale) const;

    std::string GetInterior(Interior inner) const;
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/violinPlot.cpp"
#endif

#endif