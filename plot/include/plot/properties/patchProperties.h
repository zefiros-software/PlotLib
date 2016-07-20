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
#ifndef __PATCH_H__
#define __PATCH_H__

#include "plot/abstractPlot.h"

template<class tBase, bool IsDict, bool IsBase >
class PatchProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false>
class PatchProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, PatchProperties< tBase, IsDict >, tBase & >::type tReturn;


    enum class JoinStyle
    {
        Miter,
        Round,
        Bevel
    };

    enum class LineStyle
    {
        Solid,
        Dashed,
        DashDot,
        Dotted,
        None
    };

    PatchProperties()
    {
        mIsDictionary = IsDict;
    }

    std::string ToString() override
    {
        return AbstractPlot::ToString( mStream.str() );
    }

    tReturn &SetAlpha( double alpha )
    {
        AddArgument( "alpha", alpha );

        return static_cast<tBase &>( *this );
    }

    tReturn &Animated( bool animated )
    {
        AddArgument( "animated", GetBool( animated ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &AntiAliased( bool aa )
    {
        AddArgument( "antialiased", GetBool( aa ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &ClipOn( bool clip )
    {
        AddArgument( "clipon", GetBool( clip ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetColour( const std::string &colour )
    {
        AddArgument( "color", GetString( colour ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetJoinStyle( JoinStyle style )
    {
        AddArgument( "joinstyle", GetJoinStyle( style ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetDashes( const std::vector< uint32_t > &dashes )
    {
        AddArgument( "dashes", ToArray( dashes ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &Fill( bool fill )
    {
        AddArgument( "fill", GetBool( fill ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetHatch( const std::string &hatch )
    {
        AddArgument( "hatch", GetString( hatch ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetLabel( const std::string &label )
    {
        AddArgument( "label", GetString( label ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetLineStyle( LineStyle style )
    {
        AddArgument( "linestyle", GetLineStyle( style ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetLineStyle( uint32_t offset, const std::vector< uint32_t > &dashes )
    {
        AddArgument( "linestyle", ToTuple( GetLineStyle( offset ), ToArray( dashes ) ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetLineWidth( double lineWidth )
    {
        AddArgument( "linewidth", lineWidth );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetEdgeColour( const std::string &colour )
    {
        AddArgument( "edgecolor", GetString( colour ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetFaceColour( const std::string &colour )
    {
        AddArgument( "facecolor", GetString( colour ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &Rasterised( bool rasterised )
    {
        AddArgument( "rasterized", GetBool( rasterised ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetUrl( const std::string &url )
    {
        AddArgument( "url", GetString( url ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &Visible( bool visible )
    {
        AddArgument( "visible", GetBool( visible ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetZOrder( uint32_t zorder )
    {
        AddArgument( "zorder", zorder );

        return static_cast<tBase &>( *this );
    }

private:


    std::string GetJoinStyle( JoinStyle style )
    {
        switch ( style )
        {
        case JoinStyle::Miter:
            return "'miter";

        case JoinStyle::Round:
            return "'round'";

        case JoinStyle::Bevel:
            return "'bevel'";
        }

        return "''";
    }


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

#endif