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
#ifndef __COLOURBARPROPERTIES_H__
#define __COLOURBARPROPERTIES_H__

#include "plot/abstractPlot.h"

static const char *const __PlotLibColourBarPropertiesExtend[] =
{
    "neither",
    "both",
    "min",
    "max"
};

template<class tBase, bool IsDict, bool IsBase >
class ColourBarProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class ColourBarProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, ColourBarProperties< tBase, IsDict >, tBase & >::type tReturn;

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    enum class Extend
    {
        Neither,
        Both,
        Min,
        Max
    };

    enum class Spacing
    {
        Uniform,
        Proportional
    };

    tReturn &SetOrientation( Orientation orientation )
    {
        AddArgument( "orientation", GetString( orientation == Orientation::Horizontal ? "horizontal" : "vertical" ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetFraction( double fraction )
    {
        AddArgument( "fraction", fraction );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetPad( double pad )
    {
        AddArgument( "pad", pad );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetShrink( double shrink )
    {
        AddArgument( "shrink", shrink );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetAspect( double aspect )
    {
        AddArgument( "aspect", aspect );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetAnchor( std::pair<double, double> anchor )
    {
        AddArgument( "anchor", ToTuple( anchor.first, anchor.second ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetParentAnchor( std::pair<double, double> panchor )
    {
        AddArgument( "panchor", ToTuple( panchor.first, panchor.second ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetExtend( Extend extend )
    {
        AddArgument( "extend", GetString( __PlotLibColourBarPropertiesExtend[static_cast<size_t>( extend )] ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &ExtendRect( bool extend )
    {
        AddArgument( "extendrect", GetBool( extend ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetSpacing( Spacing spacing )
    {
        AddArgument( "spacing", GetString( spacing == Spacing::Proportional ? "proportional" : "uniform" ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetTicks( const Vec &ticks )
    {
        AddArgument( "ticks", ToArray( ticks ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetFormat( const std::string &fmt )
    {
        AddArgument( "fmt", GetString( fmt ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &DrawEdges( bool draw )
    {
        AddArgument( "drawedges", GetBool( draw ) );

        return static_cast<tBase &>( *this );
    }
};

typedef ColourBarProperties<> ColourBarProps;

#endif