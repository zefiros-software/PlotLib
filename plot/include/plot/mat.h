#pragma once
#ifndef __MAT_H__
#define __MAT_H__

#ifdef PLOTLIB_ARMA
#pragma warning(push)
#pragma warning(disable : 4702)
#include <armadillo>
#pragma warning(pop)
#endif

#include <initializer_list>
#include <algorithm>
#include <assert.h>
#include <vector>

class Mat
{
public:

    Mat( const std::vector< std::vector< double > > &data )
        : mData( data )
    {
        CheckDimensions( data );
    }

    Mat( const std::initializer_list< std::initializer_list< double > > &data )
        : mData( data.begin(), data.end() )
    {
        CheckDimensions( mData );
    }

#ifdef PLOTLIB_ARMA

    Mat( const arma::mat &data )
        : mData( data.n_rows )
    {
        size_t i = 0;

        data.each_row( [&]( const arma::vec & v )
        {
            mData[i++] = arma::conv_to< std::vector<double> >::from( v );
        } );
    }

#endif

    const std::vector< std::vector< double > > &GetData() const
    {
        return mData;
    }

    size_t GetSize() const
    {
        return mData.size();
    }

private:

    std::vector< std::vector< double > > mData;

    static void CheckDimensions( const std::vector< std::vector< double > > &data )
    {
        if ( !data.size() )
        {
            return;
        }

        const size_t size = ( *data.begin() ).size();

        for ( auto vec : data )
        {
            assert( vec.size() == size );
        }
    }

};

#endif