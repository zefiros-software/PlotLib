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
#ifndef __POINTPLOT_H__
#define __POINTPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/vec.h"

class Palette;

class PointPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    PointPlot( const Vec &x, const Vec &y );

    PointPlot( const std::vector< std::pair< Vec, Vec > > &data );

    PointPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue );

    virtual std::string ToString() const override;

    PointPlot &SetOrder( const Vec &order );

    PointPlot &SetHueOrder( const std::vector< std::string > &order );

    PointPlot &SetConfidenceInterval( double ci );

    PointPlot &SetNBoot( size_t bootstrap );

    PointPlot &SetMarkers( const std::vector< std::string > &markers );

    PointPlot &SetLineStyles( const std::vector< std::string > &styles );

    PointPlot &SetDodge( double dodge );

    PointPlot &SetDodge( bool dodge );

    PointPlot &SetJoin( bool join );

    PointPlot &SetScale( double scale );

    PointPlot &SetOrientation( Orientation orientation );

    PointPlot &SetColour( const std::string &colour );

    PointPlot &SetColourMap( const Palette &pallet );

private:

    std::stringstream mStream;
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/pointPlot.cpp"
#endif

#endif