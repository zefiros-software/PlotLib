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

#include "plot/pairPlot.h"

PLOTLIB_INLINE PairPlot::PairPlot( const std::vector< Mat > &mats, const std::vector< std::string > &names,
                                   const std::vector< std::string > &hue )
{
    assert( hue.size() == mats.size() );
    mStream << "data = pd.DataFrame()\nhue = []\n";

    for ( size_t k = 0, kEnd = names.size(); k < kEnd; ++k )
    {
        mStream << "x" << k << " = []\n";
    }

    size_t j = 0;

    for ( const auto &mat : mats )
    {
        assert( names.size() == mat.GetData().size() );

        size_t i = 0;

        for ( const auto &column : mat.GetData() )
        {
            mStream << "x" << i << " = x" << i << " + " << ToArray( column ) << "\n";
            ++i;
        }

        mStream << "hue = hue + "
                << ToArray( std::vector< std::string >( mat.GetData()[0].size(), hue[j++] ) ) << "\n";
    }

    size_t l = 0;

    for ( const auto &name : names )
    {
        mStream << "data['" << name << "']" << " = x" << l << "\n";
        ++l;
    }

    mStream << "data['hue'] = hue\n";
    mStream << "sns.pairplot( data, hue = 'hue'";
}

PLOTLIB_INLINE PairPlot::PairPlot( const Mat &mat, const std::vector< std::string > &names )
{
    assert( names.size() == mat.GetData().size() );
    mStream << "data = pd.DataFrame()\n";
    size_t i = 0;

    for ( const auto &column : mat.GetData() )
    {
        mStream << "data['" << names[i++] << "'] = " << ToArray( column ) << "\n";
    }

    mStream << "sns.pairplot( data";
}

PLOTLIB_INLINE std::string PairPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE PairPlot &PairPlot::SetXVars( const std::vector< std::string > &xvars )
{
    this->AddArgument( "x_vars", ToArray( xvars ) );
    return *this;
}

PLOTLIB_INLINE PairPlot &PairPlot::SetYVars( const std::vector< std::string > &yvars )
{
    this->AddArgument( "y_vars", ToArray( yvars ) );
    return *this;
}

PLOTLIB_INLINE PairPlot &PairPlot::SetType( Type type )
{
    this->AddArgument( "kind", this->GetString( type == Type::Scatter ? "scatter" : "reg" ) );
    return *this;
}

PLOTLIB_INLINE PairPlot &PairPlot::SetDiagonalType( DiagonalType type )
{
    this->AddArgument( "diag_kind", this->GetString( type == DiagonalType::Histogram ? "hist" : "kde" ) );
    return *this;
}

PLOTLIB_INLINE PairPlot &PairPlot::SetMarker( const std::string &marker )
{
    this->AddArgument( "markers", this->GetString( marker ) );
    return *this;
}

PLOTLIB_INLINE PairPlot &PairPlot::SetMarkers( const std::vector<std::string> &marker )
{
    this->AddArgument( "markers", ToArray( marker ) );
    return *this;
}

PLOTLIB_INLINE PairPlot &PairPlot::SetSize( double size )
{
    this->AddArgument( "size", size );
    return *this;
}

PLOTLIB_INLINE PairPlot &PairPlot::SetAspect( double aspect )
{
    this->AddArgument( "aspect", aspect );
    return *this;
}
