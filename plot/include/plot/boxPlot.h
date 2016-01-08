#pragma once
#ifndef __BOXPLOT_H__
#define __BOXPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>

class BoxPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    BoxPlot( const Vec &x, const Vec &y )
    {
        mStream << "sns.boxplot(" << ToArray( x ) << "," << ToArray( y );
    }

    BoxPlot( const std::vector< std::pair< Vec, Vec > > &data )
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

        mStream << "\nsns.boxplot( x, y";
    }

    BoxPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue )
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

        mStream << "\nsns.boxplot( x, y, h";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    BoxPlot &SetOrder( const Vec &order )
    {
        mStream << ", order=" << ToArray( order );
        return *this;
    }

    BoxPlot &SetHueOrder( const std::vector< std::string > &order )
    {
        mStream << ", hue_order=" << ToArray( order );
        return *this;
    }

    BoxPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
        return *this;
    }

    BoxPlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
        return *this;
    }

    BoxPlot &SetColourMap( Palette pallet )
    {
        mStream << ", palette = " << pallet.ToString();
        return *this;
    }

    BoxPlot &SetSaturation( double sat )
    {
        mStream << ", saturation = " << sat;
        return *this;
    }

    BoxPlot &SetWidth( double width )
    {
        mStream << ", width= " << width;
        return *this;
    }

    BoxPlot &SetFlierSize( double fliersize )
    {
        mStream << ", fliersize= " << fliersize;
        return *this;
    }

    BoxPlot &SetLineWidth( double width )
    {
        mStream << ", linewidth=" << width;
        return *this;
    }

    BoxPlot &SetWhis( double whis )
    {
        mStream << ", whis= " << whis;
        return *this;
    }

    BoxPlot &SetNotch( bool notch )
    {
        mStream << ", notch= " << GetBool( notch );
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif