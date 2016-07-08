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

PLOTLIB_INLINE std::string RegressionPlot::ToString() const
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXBins( const Vec &bins )
{
    mStream << ", x_bins=" << ToArray( bins );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXBins( size_t bins )
{
    mStream << ", x_bins=" << bins;
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXConfidenceInterval( size_t ci )
{
    assert( ci <= 100 );
    mStream << ", x_ci=" << ci;
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetConfidenceInterval( size_t ci )
{
    assert( ci <= 100 );
    mStream << ", ci=" << ci;
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetScatter( bool scatter )
{
    mStream << ", scatter=" << GetBool( scatter );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetFitRegression( bool fit )
{
    mStream << ", fit_reg=" << GetBool( fit );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetNBoots( size_t nboots )
{
    mStream << ", n_boots=" << nboots;
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetOrder( size_t order )
{
    mStream << ", order=" << order;
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetLogistic( bool logistic )
{
    mStream << ", logistic=" << GetBool( logistic );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetLowess( bool lowess )
{
    mStream << ", lowess=" << GetBool( lowess );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetRobust( bool robust )
{
    mStream << ", robust=" << GetBool( robust );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetLogX( bool logx )
{
    mStream << ", logx=" << GetBool( logx );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXPartial( const Mat &mat )
{
    mStream << ", x_partial=" << ToArray( mat );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetYPartial( const Mat &mat )
{
    mStream << ", y_partial=" << ToArray( mat );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetTruncate( bool trunc )
{
    mStream << ", truncate=" << GetBool( trunc );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXJitter( double jitter )
{
    mStream << ", x_jitter=" << jitter;
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetYJitter( double jitter )
{
    mStream << ", y_jitter=" << jitter;
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetLabel( const std::string &label )
{
    mStream << ", label=" << label;
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetColour( const std::string &colour )
{
    mStream << ", color='" << colour << "'";
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetMarker( const std::string &marker )
{
    mStream << ", markers = '" << marker << "'";
    return *this;
}