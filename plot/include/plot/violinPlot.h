#pragma once
#ifndef __VIOLINPLOT_H__
#define __VIOLINPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>
#include <tuple>

class ViolinPlot
    : public AbstractPlot
{
public:

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    enum class KernelBandwidth
    {
        Scott,
        Silverman
    };

    enum class Scale
    {
        Area,
        Count,
        Width
    };

    enum class Interior
    {
        Box,
        Quartile,
        Point,
        Stick,
        None
    };

    ViolinPlot( const Vec &x, const Vec &y )
    {
        mStream << "sns.violinplot(" << ToArray( x ) << "," << ToArray( y );
    }

    ViolinPlot( const std::vector< std::pair< Vec, Vec > > &data )
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

        mStream << "\nsns.violinplot( x, y";
    }

    ViolinPlot( const std::vector< std::pair< Vec, Vec > > &data, const std::vector< std::string > &hue )
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

        mStream << "\nsns.violinplot( x, y, h";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    ViolinPlot &SetOrder( const Vec &order )
    {
        mStream << ", order=" << ToArray( order );
        return *this;
    }

    ViolinPlot &SetHueOrder( const std::vector< std::string > &order )
    {
        mStream << ", hue_order=" << ToArray( order );
        return *this;
    }

    ViolinPlot &SetBandwidth( KernelBandwidth bw )
    {
        mStream << ", bw= " << ( bw == KernelBandwidth::Scott ? "'scott'" : "'silverman'" );
        return *this;
    }

    ViolinPlot &SetBandwidth( double bw )
    {
        mStream << ", bw=" << bw;
        return *this;
    }

    ViolinPlot &SetCut( double cut )
    {
        mStream << ", cut=" << cut;
        return *this;
    }

    ViolinPlot &SetScale( Scale scale )
    {
        mStream << ", scale=" << GetScale( scale );
        return *this;
    }

    ViolinPlot &SetScaleHue( bool scale )
    {
        mStream << ", scale_hue=" << GetBool( scale );
        return *this;
    }

    ViolinPlot &SetGridSize( size_t size )
    {
        mStream << ", gridsize= " << size;
        return *this;
    }

    ViolinPlot &SetWidth( double width )
    {
        mStream << ", width= " << width;
        return *this;
    }

    ViolinPlot &SetInterior( Interior inner )
    {
        mStream << ", inner= " << GetInterior( inner );
        return *this;
    }

    ViolinPlot &SetSplit( bool split )
    {
        mStream << ", split=" << GetBool( split );
        return *this;
    }

    ViolinPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
        return *this;
    }

    ViolinPlot &SetLineWidth( double width )
    {
        mStream << ", linewidth=" << width;
        return *this;
    }

    ViolinPlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
        return *this;
    }

    ViolinPlot &SetColourMap( Palette pallet )
    {
        mStream << ", palette = " << pallet.ToString();
        return *this;
    }

    ViolinPlot &SetSaturation( double sat )
    {
        mStream << ", saturation = " << sat;
        return *this;
    }

private:

    std::stringstream mStream;

    std::string GetScale( Scale scale ) const
    {
        switch ( scale )
        {
        case Scale::Area:
            return "'area'";

        case Scale::Count:
            return "'count'";

        case Scale::Width:
            return "'width'";
        }

        return "";
    }

    std::string GetInterior( Interior inner ) const
    {
        switch ( inner )
        {
        case Interior::Box:
            return "'box'";

        case Interior::Quartile:
            return "'quartile'";

        case Interior::Point:
            return "'point'";

        case Interior::Stick:
            return "'stick'";

        case Interior::None:
            return "None";
        }

        return "";
    }
};

#endif