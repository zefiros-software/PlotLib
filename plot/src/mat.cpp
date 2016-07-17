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

#include "plot/define.h"
#include "plot/mat.h"

PLOTLIB_INLINE Mat::Mat( const std::vector< std::vector< int64_t > > &data,
                         const std::map< int64_t, std::string > &map )
{
    mStrData.resize( data.size() );
    size_t i = 0;

    for ( auto &vec : data )
    {
        for ( auto &val : vec )
        {
            mStrData[i].push_back( map.at( val ) );
        }

        ++i;
    }

    mDimension = CheckDimensions( mStrData );
}

PLOTLIB_INLINE Mat::Mat( const std::initializer_list< std::initializer_list< std::string > > &data )
    : mStrData( data.begin(), data.end() )
{
    mDimension = CheckDimensions( mStrData );
}

PLOTLIB_INLINE Mat::Mat( const std::vector< std::vector< std::string > > &data )
    : mStrData( data )
{
    mDimension = CheckDimensions( mStrData );
}

#ifdef PLOTLIB_ARMA

PLOTLIB_INLINE Mat::Mat( const arma::mat &data )
    : mData( data.n_rows )
{
    size_t i = 0;

    data.each_row( [&]( const arma::rowvec & v )
    {
        mData[i++] = arma::conv_to< std::vector<double> >::from( v );
    } );

    mDimension = CheckDimensions( mData );
}

PLOTLIB_INLINE Mat::Mat( const arma::umat &data )
    : mData( data.n_rows )
{
    size_t i = 0;

    data.each_row( [&]( const arma::urowvec & v )
    {
        mData[i++] = arma::conv_to< std::vector<double> >::from( v );
    } );

    mDimension = CheckDimensions( mData );
}

#endif

PLOTLIB_INLINE Mat::Mat( const std::initializer_list< std::initializer_list< double > > &data )
    : mData( data.begin(), data.end() )
{
    mDimension = CheckDimensions( mData );
}

PLOTLIB_INLINE Mat::Mat( const std::vector< std::vector< double > > &data )
    : mData( data )
{
    mDimension = CheckDimensions( mData );
}

PLOTLIB_INLINE const std::vector< std::vector< double > > &Mat::GetData() const
{
    return mData;
}

PLOTLIB_INLINE const std::vector< std::vector< std::string > > &Mat::GetStrings() const
{
    return mStrData;
}

PLOTLIB_INLINE size_t Mat::GetSize() const
{
    return mStrData.empty() ? mData.size() : mStrData.size();
}

PLOTLIB_INLINE std::pair< size_t, size_t > Mat::GetDimension() const
{
    return mDimension;
}
