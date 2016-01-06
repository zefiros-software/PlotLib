#pragma once
#ifndef __HEATMAPPLOT_H__
#define __HEATMAPPLOT_H__


#include "plot/abstractPlot.h"

#include <string>

class HeatMapPlot
    : public AbstractPlot
{
public:

    HeatMapPlot( const Mat &map )
    {
        mStream << "sns.heatmap(" << ToArray( map );
    }

    HeatMapPlot( const Vec &x, const Vec &y, size_t bins = 50 )
    {
        mStream << "heatmap, xedges, yedges = np.histogram2d( "
                << ToArray( x ) << ", " << ToArray( y ) << ", bins=" << bins << ")\n";
        mStream << "sns.heatmap(heatmap";
    }

    HeatMapPlot( const Vec &x, const Vec &y, std::pair< size_t, size_t > bins )
    {
        mStream << "heatmap, xedges, yedges = np.histogram2d( "
                << ToArray( x ) << ", " << ToArray( y ) << ", bins=(" << bins.first << "," << bins.second << "))\n";
        mStream << "sns.heatmap(heatmap";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    HeatMapPlot &SetMinValue( double value )
    {
        mStream << ", vmin = " << value;
        return *this;
    }

    HeatMapPlot &SetMaxValue( double value )
    {
        mStream << ", vmax = " << value;
        return *this;
    }

    HeatMapPlot &SetCenter( double value )
    {
        mStream << ", center = " << value;
        return *this;
    }

    HeatMapPlot &SetRobust( bool robust )
    {
        mStream << ", robust = " << GetBool( robust );
        return *this;
    }

    HeatMapPlot &SetAnnotate( bool annotate )
    {
        mStream << ", annot = " << GetBool( annotate );
        return *this;
    }

    HeatMapPlot &SetFormat( const std::string &fmt )
    {
        mStream << ", fmt = " << fmt;
        return *this;
    }

    HeatMapPlot &SetLineWidths( double value )
    {
        mStream << ", linewidths = " << value;
        return *this;
    }

    HeatMapPlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
        return *this;
    }

    HeatMapPlot &SetColourMap( Palette pallet )
    {
        pallet.SetColourMap( true );
        mStream << ", cmap = " << pallet.ToString();
        return *this;
    }

    HeatMapPlot &SetSquare( bool square )
    {
        mStream << ", square = " << GetBool( square );
        return *this;
    }

    HeatMapPlot &SetXTickLabel( const std::vector< std::string > &names )
    {
        mStream << ", xticklabels = '" << ToArray( names ) << "'";
        return *this;
    }

    HeatMapPlot &SetYTickLabel( const std::vector< std::string > &names )
    {
        mStream << ", yticklabels = '" << ToArray( names ) << "'";
        return *this;
    }

    HeatMapPlot &SetMask( const std::vector< bool > &mask )
    {
        mStream << ", mask = " << ToArray( mask );
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif