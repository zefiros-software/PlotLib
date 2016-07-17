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
#ifndef __SWARMPLOT_H__
#define __SWARMPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/vec.h"

class Palette;

class SwarmPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    SwarmPlot( const Vec &x, const Vec &y );

    SwarmPlot( const std::vector< std::pair< Vec, Vec > > &data );

    SwarmPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue );

    virtual std::string ToString() override;

    SwarmPlot &SetOrder( const Vec &order );

    SwarmPlot &SetHueOrder( const std::vector< std::string > &order );

    SwarmPlot &SetSplit( bool split );

    SwarmPlot &SetOrientation( Orientation orientation );

    SwarmPlot &SetColour( const std::string &colour );

    SwarmPlot &SetColourMap( const Palette &pallet );

    SwarmPlot &SetSize( double size );

    SwarmPlot &SetEdgdeColour( const std::string &colour );

    SwarmPlot &SetEdgeColour( const std::string &colour );

    SwarmPlot &SetLineWidth( double width );

private:

    std::stringstream mStream;
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/swarmPlot.cpp"
#endif

#endif