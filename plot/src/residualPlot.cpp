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

#include "plot/residualPlot.h"

PLOTLIB_INLINE ResidualPlot::ResidualPlot( const PVec &exogenous, const PVec &endogenous )
{
    mStream << "sns.residplot( np.array(" << this->ToArray( exogenous ) << "), np.array(" << this->ToArray(
                endogenous ) << ")";
}

PLOTLIB_INLINE std::string ResidualPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::Lowess( bool lowess )
{
    this->AddArgument( "lowess", GetBool( lowess ) );
    return *this;
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::SetXPartial( const PMat &mat )
{
    this->AddArgument( "x_partial", this->ToArray( mat ) );
    return *this;
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::SetYPartial( const PMat &mat )
{
    this->AddArgument( "y_partial", this->ToArray( mat ) );
    return *this;
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::SetOrder( size_t order )
{
    this->AddArgument( "order", order );
    return *this;
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::Robust( bool robust )
{
    this->AddArgument( "robust", GetBool( robust ) );
    return *this;
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::SetLabel( const std::string &label )
{
    this->AddArgument( "label", this->GetString( label ) );
    return *this;
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::SetColour( const std::string &colour )
{
    this->AddArgument( "color", this->GetString( colour ) );
    return *this;
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::SetScatter( Scatter &scatter )
{
    this->AddArgument( "scatter_kws", scatter.ToString() );
    return *this;
}

PLOTLIB_INLINE ResidualPlot &ResidualPlot::SetLine( Line &scatter )
{
    this->AddArgument( "line_kws", scatter.ToString() );
    return *this;
}
