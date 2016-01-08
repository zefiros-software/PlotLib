#pragma once
#ifndef __COUNTPLOT_H__
#define __COUNTPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>

class CountPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    CountPlot( const Vec &x )
    {
        mStream << "sns.countplot(x=" << ToArray( x );
    }

    CountPlot( const std::vector< Vec > &data )
    {
        mStream << "x = []\n";
        mStream << "x = x ";

        for ( auto &tup : data )
        {
            mStream << "+ " << ToArray( tup );
        }

        mStream << "\nsns.countplot( x=x";
    }

    CountPlot( const std::vector< Vec > &data, const std::vector< std::string > &hue )
    {
        mStream << "x = []\nh = []\n";
        mStream << "x = x ";

        for ( auto &tup : data )
        {
            mStream << "+ " << ToArray( tup );
        }

        size_t i = 0;

        mStream << "\nh = h ";

        for ( auto &tup : data )
        {
            mStream << "+ " << ToArray( std::vector< std::string >( tup.GetSize(), hue[i++] ) );
        }

        mStream << "\nsns.countplot( x=x, hue=h";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    CountPlot &SetOrder( const Vec &order )
    {
        mStream << ", order=" << ToArray( order );
        return *this;
    }

    CountPlot &SetHueOrder( const std::vector< std::string > &order )
    {
        mStream << ", hue_order=" << ToArray( order );
        return *this;
    }

    CountPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orient=" << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
        return *this;
    }

    CountPlot &SetColour( const std::string &colour )
    {
        mStream << ", color='" << colour << "'";
        return *this;
    }

    CountPlot &SetColourMap( Palette pallet )
    {
        mStream << ", palette =" << pallet.ToString();
        return *this;
    }

    CountPlot &SetSaturation( double sat )
    {
        mStream << ", saturation=" << sat;
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif