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

#include "plot/define.h"
#include "plot/pvec.h"

#include <algorithm>

PLOTLIB_INLINE PVec::PVec( const std::initializer_list< std::string > &data )
    : mStrData( data )
{

}

PLOTLIB_INLINE PVec::PVec( const std::initializer_list< double > &data )
    : mData( data )
{

}

PLOTLIB_INLINE PVec::PVec( const PVec &x, std::function< double( double ) > function )
{
    for ( const auto &val : x.GetData() )
    {
        mData.push_back( function( val ) );
    }
}

PLOTLIB_INLINE PVec::PVec( double min, double max, size_t n, std::function< double( double ) > function )
    : PVec( LinSpace( min, max, n ), function )
{

}

PLOTLIB_INLINE PVec::PVec( double min, double max, size_t n )
    : PVec( LinSpace( min, max, n ) )
{

}

PLOTLIB_INLINE PVec::PVec( const std::vector< int64_t > &data, const std::map< int64_t, std::string > &map )
{
    for ( auto &val : data )
    {
        mStrData.push_back( map.at( val ) );
    }
}

PLOTLIB_INLINE PVec::PVec( const std::vector< std::string > &data )
    : mStrData( data )
{

}

PLOTLIB_INLINE const std::vector< double > &PVec::GetData() const
{
    return mData;
}

PLOTLIB_INLINE const std::vector< std::string > &PVec::GetStrings() const
{
    return mStrData;
}

PLOTLIB_INLINE size_t PVec::GetSize() const
{
    return mStrData.empty() ? mData.size() : mStrData.size();
}

PLOTLIB_INLINE double PVec::Min() const
{
    return *std::min_element( mData.begin(), mData.end() );
}

PLOTLIB_INLINE double PVec::Max() const
{
    return *std::max_element( mData.begin(), mData.end() );
}

PLOTLIB_INLINE std::vector<double> PVec::LinSpace( double start, double end, size_t num )
{
    double delta = ( end - start ) / ( num - 1 );

    std::vector<double> linspaced( num );
    linspaced[0] = start;

    for ( size_t i = 1; i < num; ++i )
    {
        linspaced[i] = start + delta * static_cast<int>( i );
    }

    return linspaced;
}
