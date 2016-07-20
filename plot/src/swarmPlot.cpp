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

#include "plot/swarmPlot.h"
#include "plot/palette.h"

#include <assert.h>

PLOTLIB_INLINE SwarmPlot::SwarmPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue )
{
    mStream << "x = []\ny = []\nh = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        assert( tup.first.GetSize() == tup.second.GetSize() );
        mStream << "+ " << ToArray( tup.first );
    }

    mStream << "\ny = y ";

    for ( auto &tup : data )
    {
        mStream << "+ " << ToArray( tup.second );
    }

    size_t i = 0;

    mStream << "\nh = h ";

    for ( auto &tup : data )
    {
        mStream << "+ " << ToArray( std::vector< std::string >( tup.first.GetSize(), hue[i++] ) );
    }

    mStream << "\nsns.swarmplot( x, y, h";
}

PLOTLIB_INLINE SwarmPlot::SwarmPlot( const std::vector< std::pair< Vec, Vec > > &data )
{
    mStream << "x = []\ny = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        mStream << "+ " << ToArray( tup.first );
    }

    mStream << "\ny = y ";

    for ( auto &tup : data )
    {
        mStream << "+ " << ToArray( tup.second );
    }

    mStream << "\nsns.swarmplot( x, y";
}

PLOTLIB_INLINE SwarmPlot::SwarmPlot( const Vec &x, const Vec &y )
{
    mStream << "sns.swarmplot(" << ToArray( x ) << "," << ToArray( y );
}

PLOTLIB_INLINE std::string SwarmPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetOrder( const Vec &order )
{
    mStream << ", order=" << ToArray( order );
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetHueOrder( const std::vector< std::string > &order )
{
    mStream << ", hue_order=" << ToArray( order );
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetSplit( bool split )
{
    mStream << ", jitter= " << GetBool( split );
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetOrientation( Orientation orientation )
{
    mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetColour( const std::string &colour )
{
    mStream << ", color = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetColourMap( const Palette &pallet )
{
    mStream << ", palette = " << pallet.ToString();
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetSize( double size )
{
    mStream << ", size =" << size;
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetEdgdeColour( const std::string &colour )
{
    mStream << ", edgecolor = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetEdgeColour( const std::string &colour )
{
    mStream << ", edgecolor  = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE SwarmPlot &SwarmPlot::SetLineWidth( double width )
{
    mStream << ", linewidth=" << width;
    return *this;
}