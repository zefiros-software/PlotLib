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
#ifndef __STRIPPLOT_H__
#define __STRIPPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/pvec.h"

class Palette;

class StripPlot
    : public AbstractPlot
{
public:

    enum Orientation
    {
        Vertical,
        Horizontal
    };

    StripPlot( const PVec &x, const PVec &y );

    StripPlot( const std::vector< std::pair< PVec, PVec > > &data );

    StripPlot( const std::vector< std::pair< PVec, PVec > > &data, const std::vector< std::string > &hue );

    virtual std::string ToString() override;

    StripPlot &SetOrder( const PVec &order );

    StripPlot &SetHueOrder( const std::vector< std::string > &order );

    StripPlot &SetJitter( double jitter );

    StripPlot &SetJitter( bool jitter );

    StripPlot &SetSplit( bool split );

    StripPlot &SetOrientation( Orientation orientation );

    StripPlot &SetColour( const std::string &colour );

    StripPlot &SetColourMap( const Palette &pallet );

    StripPlot &SetScale( double scale );

    StripPlot &SetEdgdeColour( const std::string &colour );

    StripPlot &SetLineWidth( double width );
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/stripPlot.cpp"
#endif

#endif