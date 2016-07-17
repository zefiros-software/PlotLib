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

#include "plot/distancedBarPlot.h"



PLOTLIB_INLINE DistancedBarPlot::DistancedBarPlot( const std::vector< std::pair< Vec, Vec > > &data, const Vec &widths )
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

    mStream << "\nplt.bar( x, y" << ",width=" << ToArray( widths );
}

PLOTLIB_INLINE DistancedBarPlot::DistancedBarPlot( const Vec &x, const Vec &y, const Vec &widths )
{
    mStream << "plt.bar(" << ToArray( x ) << "," << ToArray( y ) << ",width=" << ToArray( widths );
}

PLOTLIB_INLINE std::string DistancedBarPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE DistancedBarPlot &DistancedBarPlot::SetZOrder( double order )
{
    AddArgument( "zorder", order );
    return *this;
}

PLOTLIB_INLINE DistancedBarPlot &DistancedBarPlot::UseColourCycler( const std::string &colourCycler )
{
    AddArgument( "color", "next( " + colourCycler + " )" );
    return *this;
}

PLOTLIB_INLINE DistancedBarPlot &DistancedBarPlot::CycleColour()
{
    AddArgument( "color", "next( colour_cycler )" );
    return *this;
}
