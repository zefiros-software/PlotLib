/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2017 Zefiros Software.
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
#ifndef __SCATTERPROPERTIES_H__
#define __SCATTERPROPERTIES_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

static const char *const __PlotLibScatterPlotPropertiesNormalise[] =
{
    "autoscale",
    "autoscale_None",
    "inverse",
    "process_value",
    "scaled"
};

template<class tBase, bool IsDict, bool IsBase >
class ScatterPlotProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class ScatterPlotProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, ScatterPlotProperties< tBase, IsDict >, tBase & >::type tReturn;

    enum class Normalise
    {
        AutoScale,
        AutoScaleNone,
        Inverse,
        ProcessValue,
        Scaled
    };

    ScatterPlotProperties()
    {
        mIsDictionary = IsDict;
    }

    std::string ToString() override
    {
        return AbstractPlot::ToString( mStream.str() );
    }

    inline tReturn &SetSize( double size )
    {
        this->AddArgument( "s", size );

        return static_cast<tReturn &>( *this );
    }

    inline tReturn &SetColour( const std::string &colour )
    {
        this->AddArgument( "c", colour );

        return static_cast<tReturn &>( *this );
    }

    inline tReturn &SetMarker( const std::string &style )
    {
        this->AddArgument( "marker", style );

        return static_cast<tReturn &>( *this );
    }

    inline tReturn &SetColourMap( ColourMap &map )
    {
        this->AddArgument( "cmap", map.ToString() );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetNormalise( Normalise norm )
    {
        this->AddArgument( "norm", __PlotLibScatterPlotPropertiesNormalise[static_cast<size_t>( norm )] );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetVMin( double vmin )
    {
        this->AddArgument( "vmin", vmin );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetVMax( double vmax )
    {
        this->AddArgument( "vmax", vmax );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetAlpha( double alpha )
    {
        this->AddArgument( "alpha", alpha );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetLineWidths( double width )
    {
        this->AddArgument( "linewidths", width );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetLineWidths( const PVec &widths )
    {
        this->AddArgument( "linewidths", this->ToArray( widths ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetEdgeColour( const std::string &colour )
    {
        this->AddArgument( "edgecolor", this->GetString( colour ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetEdgeColour( const PVec &colours )
    {
        this->AddArgument( "edgecolor", this->ToArray( colours ) );

        return static_cast<tReturn &>( *this );
    }

};

typedef ScatterPlotProperties<> Scatter;

#endif