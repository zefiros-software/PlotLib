#pragma once
#ifndef __STRIPPLOT_H__
#define __STRIPPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>
#include <tuple>

class StripPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    StripPlot( const Vec &x, const Vec &y )
    {
        mStream << "sns.stripplot(" << ToArray( x ) << "," << ToArray( y );
    }

    StripPlot( const std::vector< std::pair< Vec, Vec > > &data )
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

        mStream << "\nsns.stripplot( x, y";
    }

    StripPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue )
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

        mStream << "\nsns.stripplot( x, y, h";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    StripPlot &SetOrder( const Vec &order )
    {
        mStream << ", order=" << ToArray( order );
        return *this;
    }

    StripPlot &SetHueOrder( const std::vector< std::string > &order )
    {
        mStream << ", hue_order=" << ToArray( order );
        return *this;
    }

    StripPlot &SetJitter( double jitter )
    {
        mStream << ", jitter= " << jitter;
        return *this;
    }

    StripPlot &SetJitter( bool jitter )
    {
        mStream << ", jitter= " << GetBool( jitter );
        return *this;
    }

    StripPlot &SetSplit( bool split )
    {
        mStream << ", jitter= " << GetBool( split );
        return *this;
    }

    StripPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
        return *this;
    }

    StripPlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
        return *this;
    }

    StripPlot &SetColourMap( Palette pallet )
    {
        mStream << ", palette = " << pallet.ToString();
        return *this;
    }

    StripPlot &SetScale( double scale )
    {
        mStream << ", scale=" << scale;
        return *this;
    }

    StripPlot &SetEdgdeColour( const std::string &colour )
    {
        mStream << ", edgecolor = '" << colour << "'";
        return *this;
    }

    StripPlot &SetLineWidth( double width )
    {
        mStream << ", linewidth=" << width;
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif