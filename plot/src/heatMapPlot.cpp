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

#include "plot/heatMapPlot.h"

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetYTickLabel( bool enable )
{
    mStream << ", yticklabels = " << GetBool( enable );
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetYTickLabel( const std::vector< std::string > &names )
{
    mStream << ", yticklabels = '" << ToArray( names ) << "'";
    return *this;
}

PLOTLIB_INLINE HeatMapPlot::HeatMapPlot( const Vec &x, const Vec &y, std::pair< size_t, size_t > bins )
{
    mStream << "heatmap, xedges, yedges = np.histogram2d( "
            << ToArray( x ) << ", " << ToArray( y ) << ", bins=(" << bins.first << "," << bins.second << "))\n";
    mStream << "sns.heatmap(heatmap";
}

PLOTLIB_INLINE HeatMapPlot::HeatMapPlot( const Vec &x, const Vec &y, size_t bins /*= 50 */ )
{
    mStream << "heatmap, xedges, yedges = np.histogram2d( "
            << ToArray( x ) << ", " << ToArray( y ) << ", bins=" << bins << ")\n";
    mStream << "sns.heatmap(heatmap";
}

PLOTLIB_INLINE HeatMapPlot::HeatMapPlot( const Mat &map )
{
    mStream << "sns.heatmap(" << ToArray( map );
}

PLOTLIB_INLINE std::string HeatMapPlot::ToString() const
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetMinValue( double value )
{
    mStream << ", vmin = " << value;
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetMaxValue( double value )
{
    mStream << ", vmax = " << value;
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetCenter( double value )
{
    mStream << ", center = " << value;
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetRobust( bool robust )
{
    mStream << ", robust = " << GetBool( robust );
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetAnnotate( bool annotate )
{
    mStream << ", annot = " << GetBool( annotate );
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetFormat( const std::string &fmt )
{
    mStream << ", fmt = " << fmt;
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetLineWidths( double value )
{
    mStream << ", linewidths = " << value;
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetColour( const std::string &colour )
{
    mStream << ", color = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetColourMap( Palette pallet )
{
    pallet.SetColourMap( true );
    mStream << ", cmap = " << pallet.ToString();
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetSquare( bool square )
{
    mStream << ", square = " << GetBool( square );
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetXTickLabel( bool enable )
{
    mStream << ", xticklabels = " << GetBool( enable );
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetXTickLabel( const std::vector< std::string > &names )
{
    mStream << ", xticklabels = '" << ToArray( names ) << "'";
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetMask( const std::vector< bool > &mask )
{
    mStream << ", mask = " << ToArray( mask );
    return *this;
}

PLOTLIB_INLINE HeatMapPlot &HeatMapPlot::SetColourBar( bool enable )
{
    mStream << ", cbar = " << GetBool( enable );
    return *this;
}
