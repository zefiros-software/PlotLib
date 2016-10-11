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

#include "plot/regressionPlot.h"

#include <assert.h>

PLOTLIB_INLINE RegressionPlot::RegressionPlot( const PVec &exogenous, const PVec &endogenous )
{
    mStream << "sns.regplot(np.array(" << this->ToArray( exogenous ) << "),np.array(" << this->ToArray( endogenous ) << ")";
}

PLOTLIB_INLINE std::string RegressionPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXBins( const PVec &bins )
{
    this->AddArgument( "x_bins", this->ToArray( bins ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXBins( size_t bins )
{
    this->AddArgument( "x_bins", bins );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXConfidenceInterval( size_t ci )
{
    assert( ci <= 100 );
    this->AddArgument( "x_ci", ci );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetConfidenceInterval( size_t ci )
{
    assert( ci <= 100 );
    this->AddArgument( "ci", ci );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Scatter( bool scatter )
{
    this->AddArgument( "scatter",  GetBool( scatter ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::FitRegression( bool fit )
{
    this->AddArgument( "fit_reg", GetBool( fit ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetNBoots( size_t nboots )
{
    this->AddArgument( "n_boots", nboots );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetOrder( size_t order )
{
    this->AddArgument( "order", order );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Logistic( bool logistic )
{
    this->AddArgument( "logistic", GetBool( logistic ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Lowess( bool lowess )
{
    this->AddArgument( "lowess", GetBool( lowess ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Robust( bool robust )
{
    this->AddArgument( "robust", GetBool( robust ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::LogX( bool logx )
{
    this->AddArgument( "logx", GetBool( logx ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXPartial( const PMat &mat )
{
    this->AddArgument( "x_partial", this->ToArray( mat ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetYPartial( const PMat &mat )
{
    this->AddArgument( "y_partial", this->ToArray( mat ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::Truncate( bool trunc )
{
    this->AddArgument( "truncate", GetBool( trunc ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetXJitter( double jitter )
{
    this->AddArgument( "x_jitter", jitter );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetYJitter( double jitter )
{
    this->AddArgument( "y_jitter", jitter );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetLabel( const std::string &label )
{
    this->AddArgument( "label", this->GetString( label ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetColour( const std::string &colour )
{
    this->AddArgument( "color", this->GetString( colour ) );
    return *this;
}

PLOTLIB_INLINE RegressionPlot &RegressionPlot::SetMarker( const std::string &marker )
{
    this->AddArgument( "marker", this->GetString( marker ) );
    return *this;
}