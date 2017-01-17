/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2017 Zefiros Software.
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



PLOTLIB_INLINE DistancedBarPlot::DistancedBarPlot( const std::vector< std::pair< PVec, PVec > > &data,
                                                   const PVec &widths )
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

    mStream << "\nplt.bar( x, y" << ",width=" << this->ToArray( widths );
}

PLOTLIB_INLINE DistancedBarPlot::DistancedBarPlot( const PVec &x, const PVec &y, const PVec &widths )
{
    mStream << "plt.bar(" << this->ToArray( x ) << "," << this->ToArray( y ) << ",width=" << this->ToArray( widths );
}

PLOTLIB_INLINE std::string DistancedBarPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE DistancedBarPlot &DistancedBarPlot::SetZOrder( double order )
{
    this->AddArgument( "zorder", order );
    return *this;
}

PLOTLIB_INLINE DistancedBarPlot &DistancedBarPlot::UseColourCycler( const std::string &colourCycler )
{
    this->AddArgument( "color", "next( " + colourCycler + " )" );
    return *this;
}

PLOTLIB_INLINE DistancedBarPlot &DistancedBarPlot::CycleColour()
{
    this->AddArgument( "color", "next( colour_cycler )" );
    return *this;
}
