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

#include "plot/spyPlot.h"

static const char *const __PlotLibSpyPlotAspect[] =
{
    "'auto'",
    "'equal'",
    "None"
};


PLOTLIB_INLINE SpyPlot::SpyPlot( const Mat &mat )
{
    mStream << "plt.spy(" << ToArray( mat );
}

PLOTLIB_INLINE std::string SpyPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE SpyPlot &SpyPlot::SetPrecision( double precision )
{
    this->AddArgument( "precision", precision );
    return *this;
}

PLOTLIB_INLINE SpyPlot &SpyPlot::SetOrigin( Origin origin )
{
    this->AddArgument( "origin", GetString( origin == Origin::Lower ? "lower" : "upper" ) );
    return *this;
}

PLOTLIB_INLINE SpyPlot &SpyPlot::SetAspect( double aspect )
{
    this->AddArgument( "aspect", aspect );
    return *this;
}

PLOTLIB_INLINE SpyPlot &SpyPlot::SetAspect( Aspect aspect )
{
    this->AddArgument( "aspect", __PlotLibSpyPlotAspect[static_cast<size_t>( aspect )] );
    return *this;
}
