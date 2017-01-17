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

#pragma once
#ifndef __VEC_H__
#define __VEC_H__

#include <initializer_list>
#include <functional>
#include <valarray>
#include <string>
#include <vector>
#include <map>

class PVec
{
    friend class Matrix;
public:

    template< typename tT >
    PVec( const std::vector< tT > &data )
        : mData( data.begin(), data.end() )
    {
    }

    template< typename tT >
    PVec( const std::valarray< tT > &data )
        : mData( std::begin( data ), std::end( data ) )
    {
    }

    PVec( const std::vector< std::string > &data );

    PVec( const std::vector< int64_t > &data, const std::map< int64_t, std::string > &map );

    PVec( double min, double max, size_t n );

    PVec( double min, double max, size_t n, std::function< double( double ) > function );

    PVec( const PVec &x, std::function< double( double ) > function );

    PVec( const std::initializer_list< double > &data );

    PVec( const std::initializer_list< std::string > &data );

#ifdef PLOTLIB_ARMA

    template< typename tT >
    PVec( const tT &data )
        : mData( data.cbegin(), data.cend() )
    {
    }

#endif

    const std::vector< double > &GetData() const;

    const std::vector< std::string > &GetStrings() const;

    size_t GetSize() const;

    double Min() const;

    double Max() const;

private:

    std::vector< double > mData;
    std::vector< std::string > mStrData;

    std::vector<double> LinSpace( double start, double end, size_t num );
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/pvec.cpp"
#endif

#endif