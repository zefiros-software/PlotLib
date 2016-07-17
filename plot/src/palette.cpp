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

#include "plot/palette.h"
#include "plot/define.h"

#include <assert.h>

PLOTLIB_INLINE Palette::Palette( Type type )
    : mType( type )
{

}

PLOTLIB_INLINE Palette::Palette( const std::string &type, Type typeEnum /*= Type::Custom */ )
    : mCustomType( type ),
      mType( typeEnum )
{

}

PLOTLIB_INLINE std::string Palette::ToString() const
{
    return GetPalette( mType );
}

PLOTLIB_INLINE std::string Palette::GetArguments() const
{
    return mArguments.str();
}

PLOTLIB_INLINE Palette &Palette::SetColours( size_t nColours )
{
    mArguments << ", n_colors = " << nColours;
    return *this;
}

PLOTLIB_INLINE Palette &Palette::SetDesaturation( double desat )
{
    mArguments << ", desat = " << desat;
    return *this;
}

PLOTLIB_INLINE Palette &Palette::UseColourCodes( bool colourCodes )
{
    mArguments << ", color_codes = " << ( colourCodes ? "True" : "False" );
    return *this;
}

PLOTLIB_INLINE Palette &Palette::SetColourMap( bool map )
{
    mArguments << ", as_cmap = " << ( map ? "True" : "False" );
    return *this;
}

PLOTLIB_INLINE std::string Palette::GetPalette( Type palette ) const
{
    switch ( palette )
    {
    case Type::Reset:
        return "'None'";

    case Type::Custom:
        return "'" + mCustomType + "'";

    case Type::ColorPallette:
        return mCustomType;

    case Type::Other:
        {
            std::string arguments = mArguments.str();

            if ( arguments.size() > 0 && *arguments.begin() == ',' )
            {
                arguments = std::string( arguments.begin() + 1, arguments.end() );
            }

            return mStream.str() + arguments + " )";
        }
    }

    return "";
}

PLOTLIB_INLINE HUSLPalette::HUSLPalette()
    : Palette( Type::Other )
{
    mStream << "sns.husl_palette( ";
}

PLOTLIB_INLINE HUSLPalette &HUSLPalette::SetColours( size_t nColours )
{
    mArguments << ", n_colors = " << nColours;
    return *this;
}

PLOTLIB_INLINE HUSLPalette &HUSLPalette::SetHue( double h )
{
    mArguments << ", h = " << h;
    return *this;
}

PLOTLIB_INLINE HUSLPalette &HUSLPalette::SetSaturation( double s )
{
    mArguments << ", s = " << s;
    return *this;
}

PLOTLIB_INLINE HUSLPalette &HUSLPalette::SetLightness( double l )
{
    mArguments << ", l = " << l;
    return *this;
}

PLOTLIB_INLINE HLSPalette::HLSPalette()
    : Palette( Type::Other )
{
    mArguments << "sns.hls_palette( ";
}

PLOTLIB_INLINE HLSPalette &HLSPalette::SetColours( size_t nColours )
{
    mArguments << ", n_colors = " << nColours;
    return *this;
}

PLOTLIB_INLINE HLSPalette &HLSPalette::SetHue( double h )
{
    mArguments << ", h = " << h;
    return *this;
}

PLOTLIB_INLINE HLSPalette &HLSPalette::SetSaturation( double s )
{
    mArguments << ", s = " << s;
    return *this;
}

PLOTLIB_INLINE HLSPalette &HLSPalette::SetLightness( double l )
{
    mArguments << ", l = " << l;
    return *this;
}

PLOTLIB_INLINE CubeHelixPalette::CubeHelixPalette()
    : Palette( Type::Other )
{
    mStream << "sns.cubehelix_palette( ";
}

PLOTLIB_INLINE CubeHelixPalette &CubeHelixPalette::SetColours( size_t nColours )
{
    mArguments << ", n_colors = " << nColours;
    return *this;
}

PLOTLIB_INLINE CubeHelixPalette &CubeHelixPalette::SetStart( double start )
{
    mArguments << ", start = " << start;
    return *this;
}

PLOTLIB_INLINE CubeHelixPalette &CubeHelixPalette::SetRot( double rot )
{
    mArguments << ", rot = " << rot;
    return *this;
}

PLOTLIB_INLINE CubeHelixPalette &CubeHelixPalette::SetGamma( double gamma )
{
    mArguments << ", gamma = " << gamma;
    return *this;
}

PLOTLIB_INLINE CubeHelixPalette &CubeHelixPalette::SetHue( double hue )
{
    mArguments << ", hue = " << hue;
    return *this;
}

PLOTLIB_INLINE CubeHelixPalette &CubeHelixPalette::SetDark( double dark )
{
    mArguments << ", dark = " << dark;
    return *this;
}

PLOTLIB_INLINE CubeHelixPalette &CubeHelixPalette::SetLight( double light )
{
    mArguments << ", light = " << light;
    return *this;
}

PLOTLIB_INLINE CubeHelixPalette &CubeHelixPalette::SetReverse( bool reverse )
{
    mArguments << ", reverse = " << ( reverse ? "True" : "False" );
    return *this;
}

PLOTLIB_INLINE DarkPalette::DarkPalette( std::tuple< uint8_t, uint8_t, uint8_t > colour, Input input )
    : Palette( Type::Other )
{
    assert( input != Input::XKCD );
    mArguments << "sns.dark_palette( ( " << std::get<0>( colour ) << ", "
               << std::get<1>( colour ) << ", "
               << std::get<2>( colour ) << " ), input = " << GetInput( input );
}

PLOTLIB_INLINE DarkPalette::DarkPalette( const std::string &colour, Input input )
    : Palette( Type::Other )
{
    assert( input == Input::XKCD );
    mArguments << "sns.dark_palette( " << colour << ", input = " << GetInput( input );
}

PLOTLIB_INLINE DarkPalette::DarkPalette( Type type )
    : Palette( type )
{

}

PLOTLIB_INLINE std::string DarkPalette::GetInput( Input input )
{
    switch ( input )
    {
    case Input::RGB:
        return "'rgb'";

    case Input::HLS:
        return "'hls'";

    case Input::HUSL:
        return "'huls'";

    case Input::XKCD:
        return "'xkcd'";
    }

    return "";
}

PLOTLIB_INLINE DarkPalette &DarkPalette::SetColours( size_t nColours )
{
    mArguments << ", n_colors = " << nColours;
    return *this;
}

PLOTLIB_INLINE DarkPalette &DarkPalette::SetReverse( bool reverse )
{
    mArguments << ", reverse = " << ( reverse ? "True" : "False" );
    return *this;
}

PLOTLIB_INLINE LightPalette::LightPalette( std::tuple< uint8_t, uint8_t, uint8_t > colour, Input input )
    : DarkPalette( Type::Other )
{
    assert( input != Input::XKCD );
    mArguments << "sns.light_palette( ( " << std::get<0>( colour ) << ", "
               << std::get<1>( colour ) << ", "
               << std::get<2>( colour ) << " ), input = " << GetInput( input );
}

PLOTLIB_INLINE LightPalette::LightPalette( const std::string &colour, Input input )
    : DarkPalette( Type::Other )
{
    assert( input == Input::XKCD );
    mArguments << "sns.light_palette( " << colour << ", input = " << GetInput( input );
}

PLOTLIB_INLINE DivergingPalette::DivergingPalette( double hNeg, double hPos )
    : Palette( Type::Other )
{
    assert( hNeg >= 0 && hNeg <= 359 );
    assert( hPos >= 0 && hPos <= 359 );
    mArguments << "sns.diverging_palette( " << hNeg << ", " << hPos;
}

PLOTLIB_INLINE DivergingPalette &DivergingPalette::SetSaturation( double sat )
{
    mArguments << ", s = " << sat;
    return *this;
}

PLOTLIB_INLINE DivergingPalette &DivergingPalette::SetLightness( double light )
{
    mArguments << ", l = " << light;
    return *this;
}

PLOTLIB_INLINE DivergingPalette &DivergingPalette::SetColours( size_t nColours )
{
    mArguments << ", n_colors = " << nColours;
    return *this;
}

PLOTLIB_INLINE DivergingPalette &DivergingPalette::SetCentre( Centre centre )
{
    mArguments << ", center = " << ( centre == Centre::Dark ? "'dark'" : "light'" );
    return *this;
}

PLOTLIB_INLINE std::string ColourMap::ToString() const
{
    return "'" + mStream.str() + "'";
}
