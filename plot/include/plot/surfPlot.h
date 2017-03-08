/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2017 Zefiros Software.
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
#ifndef __SURFPLOT_H__
#define __SURFPLOT_H__

#include "plot/properties/plotProperties.h"
#include "plot/palette.h"
#include "plot/pvec.h"
#include "plot/mat.h"

class SurfPlot : public PlotProperties< SurfPlot >
{
public:

    SurfPlot::SurfPlot( const PVec &x, const std::vector<PVec> &y, const std::vector<PVec> &z );

    SurfPlot::SurfPlot( const PVec &x, const PVec &y, const std::vector<PVec> &z );

    SurfPlot::SurfPlot( const PMat &x, const PMat &y, const PMat &z );

    SurfPlot &SetColourMap( const ColourMap &pallet );

    SurfPlot &ColourBar( bool bar );

    virtual std::string ToString() override;

private:

    bool mHasColourMap;
    bool mShowColourBar;

    SurfPlot();
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/surfPlot.cpp"
#endif

#endif
