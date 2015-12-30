#pragma once
#ifndef __PLOT_H__
#define __PLOT_H__

#include "plot/scatterPlot.h"
#include "plot/logLogPlot.h"
#include "plot/jointPlot.h"
#include "plot/distPlot.h"
#include "plot/semiLogX.h"
#include "plot/semiLogY.h"
#include "plot/linePlot.h"
#include "plot/easyPlot.h"
#include "plot/palette.h"
#include "plot/kdePlot.h"
#include "plot/rugPlot.h"

#include <sstream>
#include <vector>
#include <fstream>

class Plot
{
public:

    enum class Style
    {
        DarkGrid,
        WhiteGrid,
        Dark,
        White,
        Ticks
    };

    enum class Scale
    {
        Linear,
        Log,
        Logit,
        Symlog
    };

    enum class Context
    {
        Paper,
        Notebook,
        Talk,
        Poster
    };

    enum class Location
    {
        Best,
        UpperRight,
        UpperLeft,
        LowerLeft,
        LowerRight,
        Right,
        CenterLeft,
        CenterRight,
        LowerCenter,
        UpperCenter,
        Center
    };

    Plot()
    {
        mStream << "import seaborn as sns\n"
                "import numpy as np\n"
                "import pandas as pd\n"
                "import matplotlib.pyplot as plt\n";

        Set( Context::Poster, 1.2 );

        Despine();
    }

    Plot( const AbstractPlot &plot )
        : Plot()
    {
        AddPlot( plot );
    }

    Plot &AxisStyle( Style style, const std::vector< std::pair< std::string, std::string >> &params = {} )
    {
        mStream << "sns.set_style('" << GetStyle( style ) << "'," << GetDictionary( params ) << ")\n";

        return *this;
    }

    Plot &Set( Context context, const std::vector< std::pair< std::string, std::string >> &params = {} )
    {
        mStream << "sns.set('" << GetContext( context ) << "', rc=" << GetDictionary( params ) << ")\n";

        return *this;
    }

    Plot &Set( Context context, double fontScale, const std::vector< std::pair< std::string, std::string >> &params = {} )
    {
        mStream << "sns.set('" << GetContext( context )
                << "', font_scale=" << fontScale
                << ", rc=" << GetDictionary( params ) << ")\n";

        return *this;
    }

    Plot &SetXLabel( const std::string &xlabel, size_t fontSize )
    {
        mStream << "plt.xlabel('" << xlabel << "',fontsize=" << fontSize << ")\n";

        return *this;
    }

    Plot &SetYLabel( const std::string &ylabel, size_t fontSize )
    {
        mStream << "plt.ylabel('" << ylabel << "',fontsize=" << fontSize << ")\n";

        return *this;
    }

    Plot &SetXLimit( double xmin, double xmax )
    {
        mStream << "plt.xlim(" << xmin << "," << xmax << ")\n";

        return *this;
    }

    Plot &SetYLimit( double ymin, double ymax )
    {
        mStream << "plt.ylim(" << ymin << "," << ymax << ")\n";

        return *this;
    }

    Plot &SetTitle( const std::string &title, size_t fontSize )
    {
        mStream << "plt.title('" << title << "',fontsize=" << fontSize << ")\n";

        return *this;
    }

    Plot &SetLegend( const std::vector<std::string> &titles, size_t fontSize )
    {
        mStream << "plt.legend(" << AbstractPlot::ToArray( titles ) << ", fontsize=" << fontSize << ")\n";

        return *this;
    }

    Plot &SetXLabel( const std::string &xlabel )
    {
        mStream << "plt.xlabel('" << xlabel << "')\n";

        return *this;
    }

    Plot &SetYLabel( const std::string &ylabel )
    {
        mStream << "plt.ylabel('" << ylabel << "')\n";

        return *this;
    }

    Plot &SetTitle( const std::string &title )
    {
        mStream << "plt.title('" << title << "')\n";

        return *this;
    }

    Plot &SetLegend( const std::vector<std::string> &titles )
    {
        SetLegend( titles, Location::Best );

        return *this;
    }

    Plot &SetLegend( const std::vector<std::string> &titles, Location location )
    {
        mStream << "plt.legend(" << AbstractPlot::ToArray( titles ) << ", loc='" << GetLocation( location ) << "')\n";

        return *this;
    }

    Plot &SetXKCD()
    {
        mStream << "plt.xkcd()\n";

        return *this;
    }

    Plot &ResetDefaults()
    {
        mStream << "sns.reset_defaults()\n";

        return *this;
    }

    Plot &ResetOrig()
    {
        mStream << "sns.reset_orig()\n";

        return *this;
    }

    Plot &AxisLabels( const std::string &xlabel, const std::string &ylabel )
    {
        mStream << "sns.axlabel(" << xlabel << "," << ylabel << ")\n";

        return *this;
    }

    Plot &SetPalette( const Palette &palette )
    {
        mStream << "sns.set_palette(" << palette.ToString() << palette.GetArguments() << ")\n";

        return *this;
    }

    Plot &SetYScale( Scale scale )
    {
        mStream << "plt.yscale('" << GetScale( scale ) << "')\n";

        return *this;
    }

    Plot &AddPlot( const AbstractPlot &plot )
    {
        mStream << "\n" << plot.ToString() << "\n";

        return *this;
    }

    Plot &Despine()
    {
        mStream << "\nsns.despine()\n";

        return *this;
    }

    Plot &Show()
    {
        std::ofstream ss( "plot.in" );

        ss << mStream.str() <<  "\nplt.tight_layout()\nplt.show()";

        ss.close();

        system( "python plot.in" );

        return *this;
    }

    Plot &Save( const std::string &fname )
    {
        std::ofstream ss( "plot.in" );

        ss << mStream.str() << "\nplt.tight_layout()\nplt.savefig('" << fname << "')";

        ss.close();

        system( "python plot.in" );

        return *this;
    }

    Plot &Figure( size_t n )
    {
        mStream << "\nplt.figure(" << n << ")\n";

        return *this;
    }

    Plot &SubPlot( size_t y, size_t x, size_t n )
    {
        mStream << "\nplt.subplot(" << x << "," << y << "," << n << ")\n";

        return *this;
    }

protected:

    std::stringstream mStream;

    static std::string GetContext( Context context )
    {
        switch ( context )
        {
        case Context::Paper:
            return "paper";

        case Context::Notebook:
            return "notebook";

        case Context::Talk:
            return "talk";

        case Context::Poster:
            return "poster";
        }

        return "";
    }

    static std::string GetScale( Scale scale )
    {
        switch ( scale )
        {
        case Scale::Linear:
            return "linear";

        case Scale::Log:
            return "log";

        case Scale::Logit:
            return "logit";

        case Scale::Symlog:
            return "symlog";
        }

        return "";
    }

    static std::string GetLocation( Location location )
    {
        switch ( location )
        {
        case Location::Best:
            return "best";

        case Location::UpperRight:
            return "upper right";

        case Location::UpperLeft:
            return "upper left";

        case Location::LowerLeft:
            return "lower left";

        case Location::LowerRight:
            return "lower right";

        case Location::Right:
            return "right";

        case Location::CenterLeft:
            return "center left";

        case Location::CenterRight:
            return "center right";

        case Location::LowerCenter:
            return "lower center";

        case Location::UpperCenter:
            return "upper center";

        case Location::Center:
            return "center";
        }

        return "";
    }

    static std::string GetStyle( Style style )
    {
        switch ( style )
        {
        case Style::DarkGrid:
            return "darkgrid";

        case Style::WhiteGrid:
            return "whitegrid";

        case Style::Dark:
            return "dark";

        case Style::White:
            return "white";

        case Style::Ticks:
            return "ticks";
        }

        return "";
    }

    static std::string GetDictionary( const std::vector< std::pair< std::string, std::string >> &params )
    {
        std::stringstream ss;
        bool first = true;
        ss << "{";

        for ( auto it = params.begin(), end = params.end(); it != end; ++it )
        {
            if ( !first )
            {
                ss << ", ";
            }

            ss << "'" << ( *it ).first << "':" << ( *it ).second;
            first = false;
        }

        ss << "}";

        return ss.str();
    }

};

#endif