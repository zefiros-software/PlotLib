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
#ifndef __HEATMAPPLOT_H__
#define __HEATMAPPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

class SubPlots;

class HeatMapPlot
    : public AbstractPlot
{
public:

    friend class SubPlots;

    HeatMapPlot( const Mat &map );

    HeatMapPlot( const Vec &x, const Vec &y, size_t bins = 50 );

    HeatMapPlot( const Vec &x, const Vec &y, std::pair< size_t, size_t > bins );

    virtual std::string ToString() const override;

    HeatMapPlot &SetMinValue( double value );

    HeatMapPlot &SetMaxValue( double value );

    HeatMapPlot &SetCenter( double value );

    HeatMapPlot &SetRobust( bool robust );

    HeatMapPlot &SetAnnotate( bool annotate );

    HeatMapPlot &SetFormat( const std::string &fmt );

    HeatMapPlot &SetLineWidths( double value );

    HeatMapPlot &SetColour( const std::string &colour );

    HeatMapPlot &SetColourMap( Palette pallet );

    HeatMapPlot &SetSquare( bool square );

    HeatMapPlot &SetXTickLabel( const std::vector< std::string > &names );

    HeatMapPlot &SetYTickLabel( const std::vector< std::string > &names );

    HeatMapPlot &SetXTickLabel( bool enable );

    HeatMapPlot &SetYTickLabel( bool enable );

    HeatMapPlot &SetMask( const std::vector< bool > &mask );

    HeatMapPlot &SetColourBar( bool enable );

private:

    std::stringstream mStream;
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/heatMapPlot.cpp"
#endif

#endif