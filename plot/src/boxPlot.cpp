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

#include "plot/boxPlot.h"
#include "plot/palette.h"

#include <assert.h>

PLOTLIB_INLINE BoxPlot::BoxPlot( const std::vector< std::pair< Vec, Vec > > &data,
                                 const std::vector< std::string > &hue )
{
    mStream << "x = []\ny = []\nh = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        assert( tup.first.GetSize() == tup.second.GetSize() );
        mStream << " + " << this->ToArray( tup.first );
    }

    mStream << "\ny = y ";

    for ( auto &tup : data )
    {
        mStream << " + " << this->ToArray( tup.second );
    }

    size_t i = 0;

    mStream << "\nh = h ";

    for ( auto &tup : data )
    {
        mStream << " + " << this->ToArray( std::vector< std::string >( tup.first.GetSize(), hue[i++] ) );
    }

    mStream << "\nsns.boxplot( x, y, h";
}

PLOTLIB_INLINE BoxPlot::BoxPlot( const std::vector< std::pair< Vec, Vec > > &data )
{
    mStream << "x = []\ny = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        mStream << " + " << this->ToArray( tup.first );
    }

    mStream << "\ny = y ";

    for ( auto &tup : data )
    {
        mStream << " + " << this->ToArray( tup.second );
    }

    mStream << "\nsns.boxplot( x, y";
}

PLOTLIB_INLINE BoxPlot::BoxPlot( const Vec &x, const Vec &y )
{
    mStream << "sns.boxplot( " << this->ToArray( x ) << ", " << this->ToArray( y );
}

PLOTLIB_INLINE std::string BoxPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetOrder( const Vec &order )
{
    mStream << ", order = " << this->ToArray( order );
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetHueOrder( const std::vector< std::string > &order )
{
    mStream << ", hue_order = " << this->ToArray( order );
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetOrientation( Orientation orientation )
{
    mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetColour( const std::string &colour )
{
    mStream << ", color = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetColourMap( const Palette &pallet )
{
    mStream << ", palette = " << pallet.ToString();
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetSaturation( double sat )
{
    mStream << ", saturation = " << sat;
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetWidth( double width )
{
    mStream << ", width = " << width;
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetFlierSize( double fliersize )
{
    mStream << ", fliersize = " << fliersize;
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetLineWidth( double width )
{
    mStream << ", linewidth = " << width;
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::SetWhis( double whis )
{
    mStream << ", whis = " << whis;
    return *this;
}

PLOTLIB_INLINE BoxPlot &BoxPlot::Notch( bool notch )
{
    mStream << ", notch = " << GetBool( notch );
    return *this;
}
