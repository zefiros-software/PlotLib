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
#ifndef __CONTOURPROPERTIES_H__
#define __CONTOURPROPERTIES_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

static const char *const __PlotLibContourPropertiesCornerMask[] =
{
    "True",
    "False",
    "'legacy'"
};

static const char *const __PlotLibContourPropertiesNormalise[] =
{
    "autoscale",
    "autoscale_None",
    "inverse",
    "process_value",
    "scaled"
};

static const char *const __PlotLibContourPropertiesOrigin[] =
{
    "None",
    "'upper'",
    "'lower'",
    "'image'"
};

static const char *const __PlotLibContourPropertiesExtent[] =
{
    "neither",
    "both",
    "min",
    "max"
};

template<class tBase, bool IsDict, bool IsBase >
class ContourProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false>
class ContourProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, ContourProperties< tBase, IsDict >, tBase & >::type tReturn;

    enum class CornerMask
    {
        Enable,
        Disable,
        Legacy
    };

    enum class Normalise
    {
        AutoScale,
        AutoScaleNone,
        Inverse,
        ProcessValue,
        Scaled
    };

    enum class Origin
    {
        None,
        Upper,
        Lower,
        Image
    };

    enum class Extent
    {
        Neither,
        Both,
        Min,
        Max
    };

    enum class LineStyle
    {
        Solid,
        Dashed,
        DashDot,
        Dotted,
        None
    };

    ContourProperties()
    {
        mIsDictionary = IsDict;
    }

    std::string ToString() override
    {
        return AbstractPlot::ToString( mStream.str() );
    }

    tReturn &SetCornerMask( CornerMask mask )
    {
        this->AddArgument( "corner_mask", __PlotLibContourPropertiesCornerMask[static_cast<size_t>( mask )] );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetColour( const std::string &colour )
    {
        this->AddArgument( "color", this->GetString( colour ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetAlpha( double alpha )
    {
        this->AddArgument( "alpha", alpha );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetColourMap( ColourMap pallet )
    {
        this->AddArgument( "cmap", pallet.ToString() );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetNormalise( Normalise norm )
    {
        this->AddArgument( "norm", __PlotLibContourPropertiesNormalise[static_cast<size_t>( norm )] );

        return static_cast<tBase &>( *this );
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

    tReturn &SetLevels( const PVec &levels )
    {
        this->AddArgument( "levels", this->ToArray( levels ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetOrigin( Origin origin )
    {
        this->AddArgument( "origin", __PlotLibContourPropertiesOrigin[static_cast<size_t>( origin )] );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetExtent( double x0, double x1, double y0, double y1 )
    {
        this->AddArgument( "extent", this->ToTuple( x0, x1, y0, y1 ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetExtent( Extent extent )
    {
        this->AddArgument( "extent", __PlotLibContourPropertiesExtent[static_cast<size_t>( extent )] );

        return static_cast<tBase &>( *this );
    }

    tReturn &AntiAliased( bool aa )
    {
        this->AddArgument( "antialiased", GetBool( aa ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetNChunk( uint32_t nchunk )
    {
        this->AddArgument( "nchunk", nchunk );

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

    tReturn &SetLineStyle( LineStyle style )
    {
        this->AddArgument( "linestyles", GetLineStyle( style ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetHatches( const PVec &hatches )
    {
        this->AddArgument( "hatches", this->ToArray( hatches ) );

        return static_cast<tReturn &>( *this );
    }

private:

    std::string GetLineStyle( LineStyle style )
    {
        switch ( style )
        {
        case LineStyle::Solid:
            return "'solid'";

        case LineStyle::Dashed:
            return "'dashed'";

        case LineStyle::DashDot:
            return "'dashdot'";

        case LineStyle::Dotted:
            return "'dotted'";

        case LineStyle::None:
            return "'None'";
        }

        return "''";
    }
};

typedef ContourProperties<> Contour;

#endif