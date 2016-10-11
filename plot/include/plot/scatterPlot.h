/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Mick van Duijn, Koen Visscher and Paul Visscher
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
#ifndef __SCATTERPLOT_H__
#define __SCATTERPLOT_H__

#include "plot/abstractPlot.h"

class ScatterPlot
    : public AbstractPlot
{
public:

    ScatterPlot( const PVec &exogenous, const PVec &endogenous );

    virtual std::string ToString() override;

    ScatterPlot &SetAlpha( double alpha );

    ScatterPlot &SetScalar( double scalar );

    ScatterPlot &SetScalar( const PVec &scalar );

    ScatterPlot &SetColour( const std::string &colour );

    ScatterPlot &SetEdgeColour( const std::string &colour );

    ScatterPlot &SetMarker( const std::string &marker );

    ScatterPlot &SetVMin( double vmin );

    ScatterPlot &SetVMax( double vmax );

    ScatterPlot &SetLineWidth( double lineWidth );

    ScatterPlot &SetLineWidth( const PVec &widths );
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/scatterPlot.cpp"
#endif

#endif