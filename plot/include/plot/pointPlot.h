#pragma once
#ifndef __POINTPLOT_H__
#define __POINTPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>
#include <tuple>

class PointPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    PointPlot( const Vec &x, const Vec &y )
    {
        mStream << "sns.pointplot(" << ToArray( x ) << "," << ToArray( y );
    }

    PointPlot( const std::vector< std::pair< Vec, Vec > > &data )
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

        mStream << "\nsns.pointplot( x, y";
    }

    PointPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue )
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

        mStream << "\nsns.pointplot( x, y, h";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    PointPlot &SetOrder( const Vec &order )
    {
        mStream << ", order=" << ToArray( order );
        return *this;
    }

    PointPlot &SetHueOrder( const std::vector< std::string > &order )
    {
        mStream << ", hue_order=" << ToArray( order );
        return *this;
    }

    PointPlot &SetConfidenceInterval( double ci )
    {
        mStream << ", ci=" << ci;
        return *this;
    }

    PointPlot &SetNBoot( size_t bootstrap )
    {
        mStream << ", n_boot=" << bootstrap;
        return *this;
    }

    PointPlot &SetMarkers( const std::vector< std::string > &markers )
    {
        mStream << ", markers=" << ToArray( markers );
        return *this;
    }

    PointPlot &SetLineStyles( const std::vector< std::string > &styles )
    {
        mStream << ", linestyles=" << ToArray( styles );
        return *this;
    }

    PointPlot &SetDodge( double dodge )
    {
        mStream << ", dodge=" << dodge;
        return *this;
    }

    PointPlot &SetDodge( bool dodge )
    {
        mStream << ", dodge=" << GetBool( dodge );
        return *this;
    }

    PointPlot &SetJoin( bool join )
    {
        mStream << ", dodge=" << GetBool( join );
        return *this;
    }

    PointPlot &SetScale( double scale )
    {
        mStream << ", scale=" << scale;
        return *this;
    }

    PointPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orient=" << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
        return *this;
    }

    PointPlot &SetColour( const std::string &colour )
    {
        mStream << ", color='" << colour << "'";
        return *this;
    }

    PointPlot &SetColourMap( Palette pallet )
    {
        mStream << ", palette =" << pallet.ToString();
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif