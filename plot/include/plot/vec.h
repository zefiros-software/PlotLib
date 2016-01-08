#pragma once
#ifndef __VEC_H__
#define __VEC_H__

#ifdef PLOTLIB_ARMA
#pragma warning(push)
#pragma warning(disable : 4702)
#include <armadillo>
#pragma warning(pop)
#endif

#include <initializer_list>
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <map>
#include <functional>

class Vec
{
    friend class Matrix;
public:

    Vec( const std::vector< double > &data )
        : mData( data )
    {
    }

    Vec( const std::initializer_list< double > &data )
        : mData( data )
    {
    }

    Vec( const std::vector< std::string > &data )
        : mStrData( data )
    {
    }

    Vec( const std::vector< int64_t > &data, const std::map< int64_t, std::string > &map )
    {
        for ( auto &val : data )
        {
            mStrData.push_back( map.at( val ) );
        }
    }

    Vec( std::function< Vec( Vec ) > function, double min, double max, size_t n )
        : Vec( function, LinSpace( min, max, n ) )
    {
    }

    Vec( std::function< Vec( Vec ) > function, const Vec &x )
        : mData( function( x ).GetData() )
    {
    }

#ifdef PLOTLIB_ARMA

    Vec( const arma::vec &data )
        : mData( data.begin(), data.end() )
    {
    }

#endif

    const std::vector< double > &GetData() const
    {
        return mData;
    }

    const std::vector< std::string > &GetStrings() const
    {
        return mStrData;
    }

    size_t GetSize() const
    {
        return mData.size();
    }

    double Min() const
    {
        return *std::min( mData.begin(), mData.end() );
    }

    double Max() const
    {
        return *std::max( mData.begin(), mData.end() );
    }

private:

    std::vector< double > mData;
    std::vector< std::string > mStrData;

    std::vector<double> LinSpace( double start, double end, size_t num )
    {
        double delta = ( end - start ) / ( num - 1 );

        std::vector<double> linspaced( num - 1 );

        for ( int i = 0; i < num; ++i )
        {
            linspaced[i] = start + delta * i;
        }

        linspaced.push_back( end );
        return linspaced;
    }
};

#endif