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
#ifndef __BOXPLOT_H__
#define __BOXPLOT_H__

#include "plot/properties/boxPlotProperties.h"
#include "plot/pvec.h"

class Palette;

class BoxPlot
    : public BoxPlotProperties< BoxPlot >
{
public:

    enum Orientation
    {
        Vertical,
        Horizontal
    };

    BoxPlot( const PVec &x, const PVec &y );

    BoxPlot( const std::vector< std::pair< PVec, PVec > > &data );

    BoxPlot( const std::vector< std::pair< PVec, PVec > > &data, const std::vector< std::string > &hue );

    virtual std::string ToString() override;

    BoxPlot &SetOrder( const PVec &order );

    BoxPlot &SetHueOrder( const std::vector< std::string > &order );

    BoxPlot &SetOrientation( Orientation orientation );

    BoxPlot &SetColour( const std::string &colour );

    BoxPlot &SetColourMap( const Palette &pallet );

    BoxPlot &SetSaturation( double sat );

    BoxPlot &SetWidth( double width );

    BoxPlot &SetFlierSize( double fliersize );

    BoxPlot &SetLineWidth( double width );

    BoxPlot &SetWhis( double whis );

    BoxPlot &Notch( bool notch );
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/boxPlot.cpp"
#endif

#endif