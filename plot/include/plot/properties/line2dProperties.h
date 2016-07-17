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
#ifndef __LINE2D_H__
#define __LINE2D_H__

#include "plot/abstractPlot.h"

template<class tBase, bool IsDict, bool IsBase >
class Line2DProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class Line2DProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, Line2DProperties< tBase, IsDict >, tBase & >::type tReturn;

    enum class CapStyle
    {
        Butt,
        Round,
        Projecting
    };

    enum class JoinStyle
    {
        Miter,
        Round,
        Bevel
    };

    enum class DrawStyle
    {
        Default,
        Steps,
        StepsPre,
        StepsMid,
        StepsPost
    };

    enum class FillStyle
    {
        Full,
        Left,
        Right,
        Bottom,
        Top
    };

    enum class LineStyle
    {
        Solid,
        Dashed,
        DashDot,
        Dotted,
        None
    };

    Line2DProperties()
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

        return static_cast<tReturn &>( *this );
    }

    tReturn &Animated( bool animated )
    {
        AddArgument( "animated", GetBool( animated ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &AntiAliased( bool aa )
    {
        AddArgument( "aa", GetBool( aa ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &ClipOn( bool clip )
    {
        AddArgument( "clipon", GetBool( clip ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetColour( const std::string &colour )
    {
        AddArgument( "color", GetString( colour ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetDashCapStyle( CapStyle style )
    {
        AddArgument( "dash_capstyle", GetString( GetCapStyle( style ) ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetDashJoinStyle( JoinStyle style )
    {
        AddArgument( "dash_joinstyle", GetString( GetJoinStyle( style ) ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetSolidCapStyle( CapStyle style )
    {
        AddArgument( "solid_capstyle", GetString( GetCapStyle( style ) ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetSolidJoinStyle( JoinStyle style )
    {
        AddArgument( "solid_joinstyle", GetString( GetJoinStyle( style ) ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetDashes( const std::vector< uint32_t > &dashes )
    {
        AddArgument( "dashes", ToArray( dashes ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetDrawStyle( DrawStyle style )
    {
        AddArgument( "drawstyle", GetDrawStyle( style ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetFillStyle( FillStyle style )
    {
        AddArgument( "fillstyle", GetFillStyle( style ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetLabel( const std::string &label )
    {
        AddArgument( "label", GetString( label ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetLineStyle( LineStyle style )
    {
        AddArgument( "linestyle", GetLineStyle( style ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetLineStyle( uint32_t offset, const std::vector< uint32_t > &dashes )
    {
        AddArgument( "linestyle", ToTuple( offset, ToArray( dashes ) ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetLineWidth( double lineWidth )
    {
        AddArgument( "linewidth", lineWidth );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetMarker( const std::string &marker )
    {
        AddArgument( "marker", GetString( marker ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetMarkerEdgeColour( const std::string &colour )
    {
        AddArgument( "markeredgecolor", GetString( colour ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetMarkerFaceColour( const std::string &colour )
    {
        AddArgument( "markerfacecolor", GetString( colour ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetMarkerFaceColourAlt( const std::string &colour )
    {
        AddArgument( "markerfacecoloralt", GetString( colour ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetMarkerEdgeWidth( double width )
    {
        AddArgument( "markeredgewidth", width );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetMarkerSize( double size )
    {
        AddArgument( "markersize", size );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetEvery( uint32_t every )
    {
        AddArgument( "every", every );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetEvery( uint32_t start, uint32_t every )
    {
        AddArgument( "every", ToTuple( start, every ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetEvery( const std::vector< uint32_t > &every )
    {
        AddArgument( "every", ToArray( every ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetEvery( double every )
    {
        AddArgument( "every", every );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetEvery( double mult, double every )
    {
        AddArgument( "every", ToTuple( mult, every ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetPickRadius( double radius )
    {
        AddArgument( "pickradius", radius );

        return static_cast<tReturn &>( *this );
    }

    tReturn &Rasterised( bool rasterised )
    {
        AddArgument( "rasterized", GetBool( rasterised ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetUrl( const std::string &url )
    {
        AddArgument( "url", GetString( url ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &Visible( bool visible )
    {
        AddArgument( "visible", GetBool( visible ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetXData( const Vec &xdata )
    {
        AddArgument( "xdata", ToArray( xdata ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetYData( const Vec &ydata )
    {
        AddArgument( "ydata", ToArray( ydata ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetZOrder( uint32_t zorder )
    {
        AddArgument( "zorder", zorder );

        return static_cast<tReturn &>( *this );
    }

private:

    std::string GetCapStyle( CapStyle style )
    {
        switch ( style )
        {
        CapStyle::Butt:
            return "'butt";
        CapStyle::Round:
            return "'round'";
        CapStyle::Projecting:
            return "'projecting'"
        }

        return "''";
    }

    std::string GetJoinStyle( JoinStyle style )
    {
        switch ( style )
        {
        JoinStyle::Miter:
            return "'miter";
        JoinStyle::Round:
            return "'round'";
        JoinStyle::Bevel:
            return "'bevel'";
        }

        return "''";
    }

    std::string GetDrawStyle( DrawStyle style )
    {
        switch ( style )
        {
        DrawStyle::Default:
            return "'default'";
        DrawStyle::Steps:
            return "'steps'";
        DrawStyle::StepsPre:
            return "'steps-pre'";
        DrawStyle::StepsMid:
            return "'steps-mid'";
        DrawStyle::StepsPost:
            return "'steps-post'";
        }

        return "''";
    }

    std::string GetFillStyle( FillStyle style )
    {
        switch ( style )
        {
        FillStyle::Full:
            return "'full'";
        FillStyle::Left :
            return "'left'";
        FillStyle::Right :
            return "'right'";
        FillStyle::Bottom :
            return "'bottom'";
        FillStyle::Top :
            return "'top'";
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

typedef Line2DProperties<> Line2D;

#endif