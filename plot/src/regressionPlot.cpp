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

#include "plot/regressionPlot.h"

#include <assert.h>

PLOTLIB_INLINE RegressionPlot::RegressionPlot( const Vec &exogenous, const Vec &endogenous )
{
    mStream << "sns.regplot(np.array(" << ToArray( exogenous ) << "),np.array(" << ToArray( endogenous ) << ")";
}

PLOTLIB_INLINE std::string RegressionPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXBins( const Vec &bins )
{
    AddArgument( "x_bins", ToArray( bins ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXBins( size_t bins )
{
    AddArgument( "x_bins", bins );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXConfidenceInterval( size_t ci )
{
    assert( ci <= 100 );
    AddArgument( "x_ci", ci );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetConfidenceInterval( size_t ci )
{
    assert( ci <= 100 );
    AddArgument( "ci", ci );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Scatter( bool scatter )
{
    AddArgument( "scatter",  GetBool( scatter ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::FitRegression( bool fit )
{
    AddArgument( "fit_reg", GetBool( fit ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetNBoots( size_t nboots )
{
    AddArgument( "n_boots", nboots );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetOrder( size_t order )
{
    AddArgument( "order", order );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Logistic( bool logistic )
{
    AddArgument( "logistic", GetBool( logistic ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Lowess( bool lowess )
{
    AddArgument( "lowess", GetBool( lowess ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Robust( bool robust )
{
    AddArgument( "robust", GetBool( robust ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::LogX( bool logx )
{
    AddArgument( "logx", GetBool( logx ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXPartial( const Mat &mat )
{
    AddArgument( "x_partial", ToArray( mat ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetYPartial( const Mat &mat )
{
    AddArgument( "y_partial", ToArray( mat ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Truncate( bool trunc )
{
    AddArgument( "truncate", GetBool( trunc ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXJitter( double jitter )
{
    AddArgument( "x_jitter", jitter );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetYJitter( double jitter )
{
    AddArgument( "y_jitter", jitter );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetLabel( const std::string &label )
{
    AddArgument( "label", GetString( label ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetColour( const std::string &colour )
{
    AddArgument( "color", GetString( colour ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetMarker( const std::string &marker )
{
    AddArgument( "marker", GetString( marker ) );
    return *this;
}