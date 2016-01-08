#pragma once
#ifndef __BARPLOT_H__
#define __BARPLOT_H__

#include "plot/abstractPlot.h"

#include <string>
#include <tuple>

class BarPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    BarPlot( const Vec &x, const Vec &y )
    {
        mStream << "sns.barplot(" << ToArray( x ) << "," << ToArray( y );
    }

    BarPlot( const std::vector< std::pair< Vec, Vec > > &data )
    {
        mStream << "x = []\ny = []\n";
        mStream << "x = x ";

        for ( auto &tup : data )
        {
            mStream << "+ " << ToArray( tup.first );
        }

        mStream << "\ny = y ";

        for ( auto &tup : data )
        {
            mStream << "+ " << ToArray( tup.second );
        }

        mStream << "\nsns.barplot( x, y";
    }

    BarPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue )
    {
        mStream << "x = []\ny = []\nh = []\n";
        mStream << "x = x ";

        for ( auto &tup : data )
        {
            assert( tup.first.GetSize() == tup.second.GetSize() );
            mStream << "+ " << ToArray( tup.first );
        }

        mStream << "\ny = y ";

        for ( auto &tup : data )
        {
            mStream << "+ " << ToArray( tup.second );
        }

        size_t i = 0;

        mStream << "\nh = h ";

        for ( auto &tup : data )
        {
            mStream << "+ " << ToArray( std::vector< std::string >( tup.first.GetSize(), hue[i++] ) );
        }

        mStream << "\nsns.barplot( x, y, h";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    BarPlot &SetOrder( const Vec &order )
    {
        mStream << ", order = " << ToArray( order );
        return *this;
    }

    BarPlot &SetHueOrder( const std::vector< std::string > &order )
    {
        mStream << ", hue_order = " << ToArray( order );
        return *this;
    }

    BarPlot &SetConfidenceInterval( double ci )
    {
        mStream << ", ci = " << ci;
        return *this;
    }

    BarPlot &SetNBoot( size_t bootstrap )
    {
        mStream << ", n_boot = " << bootstrap;
        return *this;
    }

    BarPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
        return *this;
    }

    BarPlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
        return *this;
    }

    BarPlot &SetColourMap( Palette pallet )
    {
        mStream << ", palette = " << pallet.ToString();
        return *this;
    }

    BarPlot &SetSaturation( double sat )
    {
        mStream << ", saturation = " << sat;
        return *this;
    }

    BarPlot &SetErrorColour( const std::string &colour )
    {
        mStream << ", errcolor = '" << colour << "'";
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif