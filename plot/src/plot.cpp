/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Koen Visscher, Paul Visscher and individual contributors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @endcond
 */

#include "plot/customLegend.h"
#include "plot/palette.h"
#include "plot/plot.h"

#include <assert.h>

PLOTLIB_INLINE Plot::Plot( const AbstractPlot &plot )
    : Plot()
{
    AddPlot( plot );
}

PLOTLIB_INLINE Plot::Plot( Context context )
    : mHasColourCycler( false )
{
    mInitStream << "import seaborn as sns\n"
                "import numpy as np\n"
                "import pandas as pd\n"
                "import matplotlib.pyplot as plt\n"
                "import itertools\n"
                "import matplotlib.patches as mpatches\n";

    Set( context, 1.2 );
}

PLOTLIB_INLINE Plot::Plot()
    : Plot( Context::Notebook )
{

}

PLOTLIB_INLINE Plot &Plot::SetYLabel( const std::string &ylabel )
{
    mStream << "plt.ylabel('" << ylabel << "')\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetYLabel( const std::string &ylabel, size_t fontSize )
{
    mStream << "plt.ylabel('" << ylabel << "',fontsize=" << fontSize << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetXLimit( double xmin, double xmax )
{
    mStream << "plt.xlim(" << xmin << "," << xmax << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetYLimit( double ymin, double ymax )
{
    mStream << "plt.ylim(" << ymin << "," << ymax << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetTitle( const std::string &title )
{
    mStream << "plt.title('" << title << "')\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetTitle( const std::string &title, size_t fontSize )
{
    mStream << "plt.title('" << title << "',fontsize=" << fontSize << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetSupTitle( const std::string &title )
{
    mStream << "plt.suptitle('" << title << "')\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetSupTitle( const std::string &title, size_t fontSize )
{
    mStream << "plt.suptitle('" << title << "',fontsize=" << fontSize << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetLegend( Location location )
{
    mStream << "plt.legend( loc='" << GetLocation( location ) << "')\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetLegend( const std::vector<std::string> &titles, Location location )
{
    mStream << "plt.legend(" << AbstractPlot::ToArray( titles ) << ", loc='" << GetLocation( location ) << "')\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetLegend( const std::vector<std::string> &titles )
{
    SetLegend( titles, Location::Best );

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetLegend( const std::vector<std::string> &titles, size_t fontSize )
{
    mStream << "plt.legend(" << AbstractPlot::ToArray( titles ) << ", fontsize=" << fontSize << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::AxisStyle( Style style,
                                      const std::vector< std::pair< std::string, std::string >> &params /*= {} */ )
{
    mStream << "sns.set_style('" << GetStyle( style ) << "'," << GetDictionary( params ) << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::Set( Context context, double fontScale,
                                const std::vector< std::pair< std::string, std::string >> &params /*= {} */ )
{
    mStream << "sns.set('" << GetContext( context )
            << "', font_scale=" << fontScale
            << ", rc=" << GetDictionary( params ) << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::Set( Context context,
                                const std::vector< std::pair< std::string, std::string >> &params /*= {} */ )
{
    mStream << "sns.set('" << GetContext( context ) << "', rc=" << GetDictionary( params ) << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetXLabel( const std::string &xlabel )
{
    mStream << "plt.xlabel('" << xlabel << "')\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetXLabel( const std::string &xlabel, size_t fontSize )
{
    mStream << "plt.xlabel('" << xlabel << "',fontsize=" << fontSize << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetXKCD()
{
    mInitStream << "plt.xkcd()\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::ResetDefaults()
{
    mStream << "sns.reset_defaults()\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::ResetOrig()
{
    mStream << "sns.reset_orig()\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::AxisLabels( const std::string &xlabel, const std::string &ylabel )
{
    mStream << "sns.axlabel(" << xlabel << "," << ylabel << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetPalette( const Palette &palette )
{
    mStream << "sns.set_palette(" << palette.ToString() << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetYScale( Scale scale )
{
    mStream << "plt.yscale('" << GetScale( scale ) << "')\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetYScaleSymLog( double linthreshy, double linscaley )
{
    mStream << "plt.yscale('" << GetScale( Scale::Symlog ) << "', linthreshy=" << linthreshy << ", linscaley=" << linscaley
            << ")\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::AddPlot( const AbstractPlot &plot )
{
    mStream << "\n" << plot.ToString() << "\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::AddColourCycler( const Palette &palette )
{
    mHasColourCycler = true;
    mStream << "colour_cycler = itertools.cycle( " << palette.ToString() << " )\n";
    return *this;
}

PLOTLIB_INLINE std::string Plot::GetColourCycler() const
{
    assert( mHasColourCycler );
    return "colour_cycler";
}

PLOTLIB_INLINE Plot &Plot::AddCustomLegend( const CustomLegend &legend )
{
    mStream << "\n" << legend.ToString() << "\n";
    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetSize( size_t width, size_t height )
{
    mStream << "\nfig = plt.gcf()\ndpi = fig.get_dpi()\nfig.set_size_inches("
            << width << "/float(dpi)," << height << "/float(dpi), forward=True)\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::Despine()
{
    mStream << "\nsns.despine()\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::Show()
{
    std::ofstream ss( "plot.in" );

    ss << mInitStream.str() << mStream.str() << "\nplt.show()";

    ss.close();

#ifdef _WIN32
    system( "python plot.in" );
#else
    system( "python3.5 plot.in" );
#endif
    return *this;
}

PLOTLIB_INLINE Plot &Plot::SetTightLayout()
{
    mStream << "\ntry:\n\tplt.tight_layout(pad=1)\nexcept: \n\tpass";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::Save( const std::string &fname )
{
    std::ofstream ss( "plot.in" );

    ss << mInitStream.str() << mStream.str() << "\nplt.savefig( '" << fname << "', dpi=90 )";

    ss.close();

#ifdef _WIN32
    system( "python plot.in" );
#else
    system( "python3.5 plot.in" );
#endif

    return *this;
}

PLOTLIB_INLINE Plot &Plot::Figure()
{
    mStream << "\nplt.figure()\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::Figure( size_t n )
{
    mStream << "\nplt.figure( " << n << " )\n";

    return *this;
}

PLOTLIB_INLINE Plot &Plot::SubPlot( size_t y, size_t x, size_t n )
{
    mStream << "\nplt.subplot( " << y << ", " << x << ", " << n << " )\n";

    return *this;
}

PLOTLIB_INLINE std::string Plot::GetContext( Context context )
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

PLOTLIB_INLINE std::string Plot::GetScale( Scale scale )
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

PLOTLIB_INLINE std::string Plot::GetLocation( Location location )
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

PLOTLIB_INLINE std::string Plot::GetStyle( Style style )
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

PLOTLIB_INLINE std::string Plot::GetDictionary( const std::vector< std::pair< std::string, std::string >> &params )
{
    std::stringstream ss;
    bool first = true;
    ss << " {";

    for ( auto it = params.begin(), end = params.end(); it != end; ++it )
    {
        if ( !first )
        {
            ss << ", ";
        }

        ss << "'" << ( *it ).first << "': " << ( *it ).second;
        first = false;
    }

    ss << "}";

    return ss.str();
}
