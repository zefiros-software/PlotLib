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

#include "plot/jointPlot.h"

PLOTLIB_INLINE JointPlot::JointPlot( const Vec &exogenous, const Vec &endogenous )
{
    mStream << "xl=" << ToArray( exogenous ) << "\n"
            << "yl=" << ToArray( endogenous ) << "\n";
    mStream << "sns.jointplot(x='x',y='y',data=pd.DataFrame.from_dict({'x': xl,'y': yl})";
}

PLOTLIB_INLINE std::string JointPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE JointPlot &JointPlot::SetKind( Kind kind )
{
    this->AddArgument( "kind", GetString( GetKind( kind ) ) );
    return *this;
}

PLOTLIB_INLINE JointPlot &JointPlot::SetSize( size_t size )
{
    this->AddArgument( "size", size );
    return *this;
}

PLOTLIB_INLINE JointPlot &JointPlot::SetRatio( size_t ratio )
{
    this->AddArgument( "ratio", ratio );
    return *this;
}

PLOTLIB_INLINE JointPlot &JointPlot::SetSpace( double space )
{
    this->AddArgument( "space", space );
    return *this;
}

PLOTLIB_INLINE JointPlot &JointPlot::SetXLimit( const std::pair<double, double> &x )
{
    this->AddArgument( "xlim", this->ToTuple( x.first, x.second ) );
    return *this;
}

PLOTLIB_INLINE JointPlot &JointPlot::SetYLimit( const std::pair<double, double> &y )
{
    this->AddArgument( "ylim", this->ToTuple( y.first, y.second ) );
    return *this;
}

PLOTLIB_INLINE JointPlot &JointPlot::SetColour( const std::string &colour )
{
    this->AddArgument( "color", GetString( colour ) );
    return *this;
}

PLOTLIB_INLINE std::string JointPlot::GetKind( Kind kind )
{
    switch ( kind )
    {
    case Kind::Scatter:
        return "scatter";

    case Kind::Regression:
        return "reg";

    case Kind::Residual:
        return "res";

    case Kind::KernelDensity:
        return "kde";

    case Kind::Hexbin:
        return "hex";
    }

    return "";
}
