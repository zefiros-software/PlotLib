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
#ifndef __BARPROPERTIES_H__
#define __BARPROPERTIES_H__

#include "plot/abstractPlot.h"

template<class tBase, bool IsDict, bool IsBase >
class BarPlotProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class BarPlotProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, BarPlotProperties< tBase, IsDict >, tBase & >::type tReturn;

    enum class Align
    {
        Edge,
        Centre
    };

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    tReturn &SetWidth( double width )
    {
        this->AddArgument( "width", width );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetWidth( const Vec &widths )
    {
        this->AddArgument( "width", ToArray( widths ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetBottom( double bottom )
    {
        this->AddArgument( "bottom", bottom );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetBottom( const Vec &bottoms )
    {
        this->AddArgument( "bottom", ToArray( bottoms ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetColour( const std::string &colour )
    {
        this->AddArgument( "color", GetString( colour ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetColour( const Vec &colours )
    {
        this->AddArgument( "color", ToArray( colours ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetEdgeColour( const std::string &colour )
    {
        this->AddArgument( "edgecolor", GetString( colour ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetEdgeColour( const Vec &colours )
    {
        this->AddArgument( "edgecolor", ToArray( colours ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetLineWidth( double width )
    {
        this->AddArgument( "linewidth", width );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetLineWidth( const Vec &widths )
    {
        this->AddArgument( "linewidth", ToArray( widths ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetTickLabel( const std::string &label )
    {
        this->AddArgument( "tick_label", label );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetTickLabel( const Vec &labels )
    {
        this->AddArgument( "tick_label", ToArray( labels ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetXError( double xerr )
    {
        this->AddArgument( "xerr", xerr );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetXError( const Vec &xerr )
    {
        this->AddArgument( "xerr", ToArray( xerr ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetYError( double yerr )
    {
        this->AddArgument( "yerr", yerr );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetYError( const Vec &yerr )
    {
        this->AddArgument( "yerr", ToArray( yerr ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetErrorColour( const std::string &ecolour )
    {
        this->AddArgument( "ecolor", ecolour );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetErrorColour( const Vec &ecolour )
    {
        this->AddArgument( "ecolor", ToArray( ecolour ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetCapSize( double size )
    {
        this->AddArgument( "capsize", size );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetAlign( Align align )
    {
        this->AddArgument( "align", GetString( align == Align::Centre ? "center" : "edge" ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetOrientation( Orientation orientation )
    {
        this->AddArgument( "align", GetString( orientation == Orientation::Horizontal ? "horizontal" : "vertical" ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &Log( bool log )
    {
        this->AddArgument( "log", GetBool( log ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetHatch( const std::string &hatch )
    {
        this->AddArgument( "hatch", GetString( hatch ) );

        return static_cast<tBase &>( *this );
    }
};

#endif