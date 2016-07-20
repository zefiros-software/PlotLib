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

#include "plot/violinPlot.h"
#include "plot/palette.h"

#include <assert.h>

PLOTLIB_INLINE ViolinPlot::ViolinPlot( const std::vector< std::pair< Vec, Vec > > &data,
                                       const std::vector< std::string > &hue )
{
    mStream << "x = []\ny = []\nh = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        assert( tup.first.GetSize() == tup.second.GetSize() );
        mStream << "+ " << this->ToArray( tup.first );
    }

    mStream << "\ny = y ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( tup.second );
    }

    size_t i = 0;

    mStream << "\nh = h ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( std::vector< std::string >( tup.first.GetSize(), hue[i++] ) );
    }

    mStream << "\nsns.violinplot( x, y, h";
}

PLOTLIB_INLINE ViolinPlot::ViolinPlot( const std::vector< std::pair< Vec, Vec > > &data )
{
    mStream << "x = []\ny = []\n";
    mStream << "x = x ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( tup.first );
    }

    mStream << "\ny = y ";

    for ( auto &tup : data )
    {
        mStream << "+ " << this->ToArray( tup.second );
    }

    mStream << "\nsns.violinplot( x, y";
}

PLOTLIB_INLINE ViolinPlot::ViolinPlot( const Vec &x, const Vec &y )
{
    mStream << "sns.violinplot(" << this->ToArray( x ) << "," << this->ToArray( y );
}

PLOTLIB_INLINE std::string ViolinPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetOrder( const Vec &order )
{
    mStream << ", order=" << this->ToArray( order );
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetHueOrder( const std::vector< std::string > &order )
{
    mStream << ", hue_order=" << this->ToArray( order );
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetBandwidth( double bw )
{
    mStream << ", bw=" << bw;
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetBandwidth( KernelBandwidth bw )
{
    mStream << ", bw= " << ( bw == KernelBandwidth::Scott ? "'scott'" : "'silverman'" );
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetCut( double cut )
{
    mStream << ", cut=" << cut;
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetScale( Scale scale )
{
    mStream << ", scale=" << GetScale( scale );
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetScaleHue( bool scale )
{
    mStream << ", scale_hue=" << GetBool( scale );
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetGridSize( size_t size )
{
    mStream << ", gridsize= " << size;
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetWidth( double width )
{
    mStream << ", width= " << width;
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetInterior( Interior inner )
{
    mStream << ", inner= " << GetInterior( inner );
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetSplit( bool split )
{
    mStream << ", split=" << GetBool( split );
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetOrientation( Orientation orientation )
{
    mStream << ", orient = " << ( orientation == Orientation::Horizontal ? "'h'" : "'v'" );
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetLineWidth( double width )
{
    mStream << ", linewidth=" << width;
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetColour( const std::string &colour )
{
    mStream << ", color = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetColourMap( const Palette &pallet )
{
    mStream << ", palette = " << pallet.ToString();
    return *this;
}

PLOTLIB_INLINE ViolinPlot &ViolinPlot::SetSaturation( double sat )
{
    mStream << ", saturation = " << sat;
    return *this;
}

PLOTLIB_INLINE std::string ViolinPlot::GetScale( Scale scale ) const
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

PLOTLIB_INLINE std::string ViolinPlot::GetInterior( Interior inner ) const
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
