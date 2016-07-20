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

#include "plot/countPlot.h"
#include "plot/palette.h"


PLOTLIB_INLINE CountPlot::CountPlot( const std::vector< Vec > &data, const std::vector< std::string > &hue )
{
    mStream << "x = []\nh = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( tup );
    }

    size_t i = 0;

    mStream << "\nh = h ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( std::vector< std::string >( tup.GetSize(), hue[i++] ) );
    }

    mStream << "\nsns.countplot( x=x, hue=h";
}

PLOTLIB_INLINE CountPlot::CountPlot( const std::vector< Vec > &data )
{
    mStream << "x = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( tup );
    }

    mStream << "\nsns.countplot( x=x";
}

PLOTLIB_INLINE CountPlot::CountPlot( const Vec &x )
{
    mStream << "sns.countplot(x=" << this->ToArray( x );
}

PLOTLIB_INLINE std::string CountPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE CountPlot &CountPlot::SetOrder( const Vec &order )
{
    mStream << ", order=" << this->ToArray( order );
    return *this;
}

PLOTLIB_INLINE CountPlot &CountPlot::SetHueOrder( const std::vector< std::string > &order )
{
    mStream << ", hue_order=" << this->ToArray( order );
    return *this;
}

PLOTLIB_INLINE CountPlot &CountPlot::SetOrientation( Orientation orientation )
{
    mStream << ", orient=" << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
    return *this;
}

PLOTLIB_INLINE CountPlot &CountPlot::SetColour( const std::string &colour )
{
    mStream << ", color='" << colour << "'";
    return *this;
}

PLOTLIB_INLINE CountPlot &CountPlot::SetColourMap( const Palette &pallet )
{
    mStream << ", palette =" << pallet.ToString();
    return *this;
}

PLOTLIB_INLINE CountPlot &CountPlot::SetSaturation( double sat )
{
    mStream << ", saturation=" << sat;
    return *this;
}