/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Mick van Duijn, Koen Visscher and Paul Visscher
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

#include "plot/stripPlot.h"
#include "plot/palette.h"

#include <assert.h>

PLOTLIB_INLINE StripPlot::StripPlot( const std::vector< std::pair< PVec, PVec > > &data,
                                     const std::vector< std::string > &hue )
{
    mStream << "x = []\ny = []\nh = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        assert( tup.first.GetSize() == tup.second.GetSize() );
        mStream << "+ " << this->ToArray( tup.first );
    }

    mStream << "\ny = y ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( tup.second );
    }

    size_t i = 0;

    mStream << "\nh = h ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( std::vector< std::string >( tup.first.GetSize(), hue[i++] ) );
    }

    mStream << "\nsns.stripplot( x, y, h";
}

PLOTLIB_INLINE StripPlot::StripPlot( const std::vector< std::pair< PVec, PVec > > &data )
{
    mStream << "x = []\ny = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( tup.first );
    }

    mStream << "\ny = y ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( tup.second );
    }

    mStream << "\nsns.stripplot( x, y";
}

PLOTLIB_INLINE StripPlot::StripPlot( const PVec &x, const PVec &y )
{
    mStream << "sns.stripplot(" << this->ToArray( x ) << "," << this->ToArray( y );
}

PLOTLIB_INLINE std::string StripPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE StripPlot &StripPlot::SetOrder( const PVec &order )
{
    mStream << ", order=" << this->ToArray( order );
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetHueOrder( const std::vector< std::string > &order )
{
    mStream << ", hue_order=" << this->ToArray( order );
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetJitter( bool jitter )
{
    mStream << ", jitter= " << GetBool( jitter );
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetJitter( double jitter )
{
    mStream << ", jitter= " << jitter;
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetSplit( bool split )
{
    mStream << ", jitter= " << GetBool( split );
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetOrientation( Orientation orientation )
{
    mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetColour( const std::string &colour )
{
    mStream << ", color = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetColourMap( const Palette &pallet )
{
    mStream << ", palette = " << pallet.ToString();
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetScale( double scale )
{
    mStream << ", scale=" << scale;
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetEdgdeColour( const std::string &colour )
{
    mStream << ", edgecolor = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE StripPlot &StripPlot::SetLineWidth( double width )
{
    mStream << ", linewidth=" << width;
    return *this;
}
