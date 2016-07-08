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

#pragma once
#ifndef __MAT_H__
#define __MAT_H__

#include <initializer_list>
#include <assert.h>
#include <vector>
#include <map>


#ifdef PLOTLIB_ARMA
#pragma warning(push)
#pragma warning(disable : 4702)
#include <armadillo>
#pragma warning(pop)
#endif

class Mat
{
public:

    Mat( const std::vector< std::vector< double > > &data );

    Mat( const std::initializer_list< std::initializer_list< double > > &data );

#ifdef PLOTLIB_ARMA

    Mat( const arma::mat &data );

#endif

    Mat( const std::vector< std::vector< std::string > > &data );


    Mat( const std::initializer_list< std::initializer_list< std::string > > &data );

    Mat( const std::vector< std::vector< int64_t > > &data, const std::map< int64_t, std::string > &map );

    const std::vector< std::vector< double > > &GetData() const;

    const std::vector< std::vector< std::string > > &GetStrings() const;

    size_t GetSize() const;

    std::pair< size_t, size_t > GetDimension() const;

private:

    std::vector< std::vector< double > > mData;
    std::vector< std::vector< std::string > > mStrData;
    std::pair< size_t, size_t > mDimension;

    template< typename tT >
    static std::pair< size_t, size_t > CheckDimensions( const std::vector< std::vector< tT > > &data )
    {
        if ( !data.size() )
        {
            return { 0, 0 };
        }

        const size_t size = ( *data.begin() ).size();

        for ( auto vec : data )
        {
            assert( vec.size() == size );
        }

        return { data.size(), size };
    }

};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/mat.cpp"
#endif

#endif