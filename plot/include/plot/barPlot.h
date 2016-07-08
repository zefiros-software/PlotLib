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
#ifndef __BARPLOT_H__
#define __BARPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/vec.h"

#include <tuple>

class Palette;

class BarPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    BarPlot( const Vec &x, const Vec &y );

    BarPlot( const std::vector< std::pair< Vec, Vec > > &data );

    BarPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue );

    template< typename tT, typename tFunc >
    BarPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< tT > &hueData, const tFunc &hueFunc )
    {
        std::vector< std::string > hue;

        for ( const auto &hueValue : hueData )
        {
            hue.emplace_back( hueFunc( hueValue ) );
        }

        InitData( data );
        InitHue( data, hue );
        PlotDataHue();
    }

    virtual std::string ToString() const override;

    BarPlot &SetOrder( const Vec &order );

    BarPlot &SetHueOrder( const std::vector< std::string > &order );

    BarPlot &SetConfidenceInterval( double ci );

    BarPlot &SetNBoot( size_t bootstrap );

    BarPlot &SetOrientation( Orientation orientation );

    BarPlot &SetColour( const std::string &colour );

    BarPlot &UseColourCycler( const std::string &colourCycler );

    BarPlot &SetColourMap( const Palette &pallet );

    BarPlot &SetSaturation( double sat );

    BarPlot &SetErrorColour( const std::string &colour );

    BarPlot &SetHatch( const std::string &hatch );

private:

    std::stringstream mStream;

    void InitData( const std::vector< std::pair< Vec, Vec > > &data );

    void InitHue( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue );

    void PlotData();

    void PlotDataHue();
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/barPlot.cpp"
#endif

#endif