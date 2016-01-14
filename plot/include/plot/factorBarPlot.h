#pragma once
#ifndef __FACTORBARPLOT_H__
#define __FACTORBARPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>
#include <tuple>

class FactorBarPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    FactorBarPlot( const Vec &x, const Vec &y )
    {
        mStream << "y = np.array(" << ToArray( y ) << ")\n";
        mStream << "sns.barplot(" << ToArray( x ) << ", y / y.min()";
    }

    FactorBarPlot( const std::vector< std::pair< Vec, Vec > > &data )
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

    FactorBarPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue )
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

    FactorBarPlot &SetOrder( const Vec &order )
    {
        mStream << ", order = " << ToArray( order );
        return *this;
    }

    FactorBarPlot &SetHueOrder( const std::vector< std::string > &order )
    {
        mStream << ", hue_order = " << ToArray( order );
        return *this;
    }

    FactorBarPlot &SetConfidenceInterval( double ci )
    {
        mStream << ", ci = " << ci;
        return *this;
    }

    FactorBarPlot &SetNBoot( size_t bootstrap )
    {
        mStream << ", n_boot = " << bootstrap;
        return *this;
    }

    FactorBarPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
        return *this;
    }

    FactorBarPlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
        return *this;
    }

    FactorBarPlot &SetColourMap( Palette pallet )
    {
        mStream << ", palette = " << pallet.ToString();
        return *this;
    }

    FactorBarPlot &SetSaturation( double sat )
    {
        mStream << ", saturation = " << sat;
        return *this;
    }

    FactorBarPlot &SetErrorColour( const std::string &colour )
    {
        mStream << ", errcolor = '" << colour << "'";
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif