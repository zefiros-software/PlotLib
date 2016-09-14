/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Koen Visscher, Paul Visscher and individual contributors.
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
#ifndef __AUTOCORRELATIONPLOT_H__
#define __AUTOCORRELATIONPLOT_H__

#include "plot/properties/line2dProperties.h"

class AutoCorrelationPlot
    : public Line2DProperties< AutoCorrelationPlot >
{
public:

    enum Detrend
    {
        None,
        Mean,
        Linear
    };

    AutoCorrelationPlot( const PVec &vec );

    virtual std::string ToString() override;

    AutoCorrelationPlot &Hold( bool hold );

    AutoCorrelationPlot &Normed( bool normed );

    AutoCorrelationPlot &VLines( bool vlines );

    AutoCorrelationPlot &SetMaxLags( size_t maxlags );

    AutoCorrelationPlot &SetDetrend( Detrend detrend );

private:

    Detrend mDefaultDetrend;

};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/autoCorrelationPlot.cpp"
#endif

#endif