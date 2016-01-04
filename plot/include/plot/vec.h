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
#include <vector>

class Vec
{
public:

    Vec( const std::vector< double > &data )
        : mData( data )
    {
    }

    Vec( const std::initializer_list< double > &data )
        : mData( data )
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
};

#endif