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
#ifndef __REGRESSIONPLOT_H__
#define __REGRESSIONPLOT_H__

#include "plot/abstractPlot.h"

class RegressionPlot
    : public AbstractPlot
{
public:

    RegressionPlot( const PVec &exogenous, const PVec &endogenous );

    virtual std::string ToString() override;

    RegressionPlot &SetXBins( size_t bins );

    RegressionPlot &SetXBins( const PVec &bins );

    RegressionPlot &SetXConfidenceInterval( size_t ci );

    RegressionPlot &SetConfidenceInterval( size_t ci );

    RegressionPlot &Scatter( bool scatter );

    RegressionPlot &FitRegression( bool fit );

    RegressionPlot &SetNBoots( size_t nboots );

    RegressionPlot &SetOrder( size_t order );

    RegressionPlot &Logistic( bool logistic );

    RegressionPlot &Lowess( bool lowess );

    RegressionPlot &Robust( bool robust );

    RegressionPlot &LogX( bool logx );

    RegressionPlot &SetXPartial( const PMat &mat );

    RegressionPlot &SetYPartial( const PMat &mat );

    RegressionPlot &Truncate( bool trunc );

    RegressionPlot &SetXJitter( double jitter );

    RegressionPlot &SetYJitter( double jitter );

    RegressionPlot &SetLabel( const std::string &label );

    RegressionPlot &SetColour( const std::string &colour );

    RegressionPlot &SetMarker( const std::string &marker );
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/regressionPlot.cpp"
#endif

#endif