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
#ifndef __DISTPLOT_H__
#define __DISTPLOT_H__

#include "plot/abstractPlot.h"

class Vec;

class DistrPlot
    : public AbstractPlot
{
public:

    DistrPlot( const Vec &a );

    virtual std::string ToString() const override;

    DistrPlot &SetBins( bool log = false );

    DistrPlot &SetBins( const Vec &seq );

    DistrPlot &SetHist( bool hist );

    DistrPlot &SetKDE( bool kde );

    DistrPlot &SetRUG( bool rug );

    DistrPlot &SetVerical( bool vertical );

    DistrPlot &SetNormHist( bool normHist );

    DistrPlot &SetAxLabel( const std::string &axlabel );

    DistrPlot &SetAxLabel();

    DistrPlot &SetLabel( const std::string &label );

private:

    std::stringstream mStream;
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/distrPlot.cpp"
#endif

#endif