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
#ifndef __TEXTPROPERTIES_H__
#define __TEXTPROPERTIES_H__

#include "plot/properties/fontProperties.h"

static const char *const __PlotLibTextPropertiesAlignment[] =
{
    "center",
    "right",
    "left"
};

static const char *const __PlotLibTextPropertiesRotation[] =
{
    "Vertical",
    "Horizontal"
};

template<class tBase, bool IsDict, bool IsBase >
class TextProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class TextProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, TextProperties< tBase, IsDict >, tBase & >::type tReturn;

    enum class Alignment
    {
        Centre,
        Right,
        Left
    };

    enum class Rotation
    {
        Vertical,
        Horizontal
    };

    tReturn &SetAlpha( double alpha )
    {
        this->AddArgument( "alpha", alpha );
        return static_cast<tBase &>( *this );
    }

    tReturn &Animated( bool animated )
    {
        this->AddArgument( "antialiased", GetBool( animated ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetBackgroundColour( const std::string &colour )
    {
        this->AddArgument( "backgroundcolor", GetString( colour ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &ClipOn( bool clip )
    {
        this->AddArgument( "clipon", GetBool( clip ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetColour( const std::string &colour )
    {
        this->AddArgument( "color", GetString( colour ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetFamily( const std::string &family )
    {
        this->AddArgument( "family", GetString( family ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetFont( Font &font )
    {
        this->AddArgument( "fontproperties", font.ToString() );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetHorizontalAlignment( Alignment alignment )
    {
        this->AddArgument( "horizontalalignment",
                     GetString( __PlotLibTextPropertiesAlignment[static_cast<size_t>( alignment )] ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetLabel( const std::string &label )
    {
        this->AddArgument( "label", GetString( label ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetText( const std::string &text )
    {
        this->AddArgument( "text", GetString( text ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetUrl( const std::string &url )
    {
        this->AddArgument( "url", GetString( url ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &Visible( bool visible )
    {
        this->AddArgument( "visible", GetBool( visible ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetLineSpacing( double spacing )
    {
        this->AddArgument( "linespacing", spacing );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetMultiAlignment( Alignment alignment )
    {
        this->AddArgument( "multialignment",
                     GetString( __PlotLibTextPropertiesAlignment[static_cast<size_t>( alignment )] ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetPosition( double x, double y )
    {
        this->AddArgument( "position", this->ToTuple( x, y ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &Rasterised( bool rasterised )
    {
        this->AddArgument( "rasterized", GetBool( rasterised ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetRotation( double rotation )
    {
        this->AddArgument( "rotation", rotation );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetRotation( Rotation rotation )
    {
        this->AddArgument( "rotation",
                     GetString( __PlotLibTextPropertiesRotation[static_cast<size_t>( rotation )] ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetZOrder( uint32_t zorder )
    {
        this->AddArgument( "zorder", zorder );

        return static_cast<tBase &>( *this );
    }
};

typedef TextProperties<> Text;

#endif