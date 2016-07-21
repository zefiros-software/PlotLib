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

#pragma once
#ifndef __PALETTE_H__
#define __PALETTE_H__

#include <stdint.h>
#include <sstream>
#include <tuple>

static const char *const __PlotLibColours[] =
{
    "deep",
    "muted",
    "bright",
    "pastel",
    "dark",
    "colourBlind",

    "viridis", "inferno", "plasma", "magma",

    "Blues", "BuGn", "BuPu",
    "GnBu", "Greens", "Greys", "Oranges", "OrRd",
    "PuBu", "PuBuGn", "PuRd", "Purples", "RdPu",
    "Reds", "YlGn", "YlGnBu", "YlOrBr", "YlOrRd",

    "afmhot", "autumn", "bone", "cool",
    "copper", "gist_heat", "gray", "hot",
    "pink", "spring", "summer", "winter",

    "BrBG", "bwr", "coolwarm", "PiYG", "PRGn", "PuOr",
    "RdBu", "RdGy", "RdYlBu", "RdYlGn", "Spectral",
    "seismic",

    "Accent", "Dark2", "Paired", "Pastel1",
    "Pastel2", "Set1", "Set2", "Set3",

    "gist_earth", "terrain", "ocean", "gist_stern",
    "brg", "CMRmap", "cubehelix",
    "gnuplot", "gnuplot2", "gist_ncar",
    "nipy_spectral", "jet", "rainbow",
    "gist_rainbow", "hsv", "flag", "prism"
};


class ColourMap
{
public:

    enum class Type
    {
        Reset,
        Custom,
        Integer,
        Other,
        ColorPallette
    };

    enum class ColourType
    {
        None,
        Reverse,
        Dark
    };

    enum class Seaborn : size_t
    {
        Deep,
        Muted,
        Bright,
        Pastel,
        Dark,
        ColourBlind
    };

    enum class Colour : size_t
    {
        // seaborn
        Deep,
        Muted,
        Bright,
        Pastel,
        Dark,
        ColourBlind,

        // uniform
        Viridis,
        Inferno,
        Plasma,
        Magma,

        // sequential
        Blues,
        BuGn,
        BuPu,
        GnBu,
        Greens,
        Greys,
        Oranges,
        OrRd,
        PuBu,
        PuBuGn,
        PuRd,
        Purples,
        RdPu,
        Reds,
        YlGn,
        YlGnBu,
        YlOrBr,
        YlOrRd,

        // sequential 2
        Afmhot,
        Autumn,
        Bone,
        Cool,
        Copper,
        GistHeat,
        Gray,
        Hot,
        Pink,
        Spring,
        Summer,
        Winter,

        // diverging
        BrBG,
        Bwr,
        Coolwarm,
        PiYG,
        PRGn,
        PuOr,
        RdBu,
        RdGy,
        RdYlBu,
        RdYlGn,
        Spectral,
        Seismic,

        // qualitative
        Accent,
        Dark2,
        Paired,
        Pastel1,
        Pastel2,
        Set1,
        Set2,
        Set3,

        // misc
        GistEarth,
        Terrain,
        Ocean,
        GistStern,
        Brg,
        CMRmap,
        CubeHelix,
        GnuPlot,
        GnuPlot2,
        GistNcar,
        NipySpectral,
        Jet,
        Rainbow,
        GistRainbow,
        Hsv,
        Flag,
        Prism
    };

    enum class Uniform
    {
        Viridis = ( size_t )Colour::Viridis,
        Inferno = ( size_t )Colour::Inferno,
        Plasma = ( size_t )Colour::Plasma,
        Magma = ( size_t )Colour::Magma
    };

    enum class Sequential
    {
        Blues = ( size_t )Colour::Blues,
        BuGn = ( size_t )Colour::BuGn,
        BuPu = ( size_t )Colour::BuPu,
        GnBu = ( size_t )Colour::GnBu,
        Greens = ( size_t )Colour::Greens,
        Greys = ( size_t )Colour::Greys,
        Oranges = ( size_t )Colour::Oranges,
        OrRd = ( size_t )Colour::OrRd,
        PuBu = ( size_t )Colour::PuBu,
        PuBuGn = ( size_t )Colour::PuBuGn,
        PuRd = ( size_t )Colour::PuRd,
        Purples = ( size_t )Colour::Purples,
        RdPu = ( size_t )Colour::RdPu,
        Reds = ( size_t )Colour::Reds,
        YlGn = ( size_t )Colour::YlGn,
        YlGnBu = ( size_t )Colour::YlGnBu,
        YlOrBr = ( size_t )Colour::YlOrBr,
        YlOrRd = ( size_t )Colour::YlOrRd
    };

    enum class Sequential2
    {
        Afmhot = ( size_t )Colour::Afmhot,
        Autumn = ( size_t )Colour::Autumn,
        Bone = ( size_t )Colour::Bone,
        Cool = ( size_t )Colour::Cool,
        Copper = ( size_t )Colour::Copper,
        GistHeat = ( size_t )Colour::GistHeat,
        Gray = ( size_t )Colour::Gray,
        Hot = ( size_t )Colour::Hot,
        Pink = ( size_t )Colour::Pink,
        Spring = ( size_t )Colour::Spring,
        Summer = ( size_t )Colour::Summer,
        Winter = ( size_t )Colour::Winter
    };

    enum class Diverging
    {
        BrBG = ( size_t )Colour::BrBG,
        Bwr = ( size_t )Colour::Bwr,
        Coolwarm = ( size_t )Colour::Coolwarm,
        PiYG = ( size_t )Colour::PiYG,
        PRGn = ( size_t )Colour::PRGn,
        PuOr = ( size_t )Colour::PuOr,
        RdBu = ( size_t )Colour::RdBu,
        RdGy = ( size_t )Colour::RdGy,
        RdYlBu = ( size_t )Colour::RdYlBu,
        RdYlGn = ( size_t )Colour::RdYlGn,
        Spectral = ( size_t )Colour::Spectral,
        Seismic = ( size_t )Colour::Seismic
    };

    enum class Qualitative
    {
        Accent = ( size_t )Colour::Accent,
        Dark2 = ( size_t )Colour::Dark2,
        Paired = ( size_t )Colour::Paired,
        Pastel1 = ( size_t )Colour::Pastel1,
        Pastel2 = ( size_t )Colour::Pastel2,
        Set1 = ( size_t )Colour::Set1,
        Set2 = ( size_t )Colour::Set2,
        Set3 = ( size_t )Colour::Set3
    };

    enum class Miscellaneous
    {
        GistEarth = ( size_t )Colour::GistEarth,
        Terrain = ( size_t )Colour::Terrain,
        Ocean = ( size_t )Colour::Ocean,
        GistStern = ( size_t )Colour::GistStern,
        Brg = ( size_t )Colour::Brg,
        CMRmap = ( size_t )Colour::CMRmap,
        CubeHelix = ( size_t )Colour::CubeHelix,
        GnuPlot = ( size_t )Colour::GnuPlot,
        GnuPlot2 = ( size_t )Colour::GnuPlot2,
        GistNcar = ( size_t )Colour::GistNcar,
        NipySpectral = ( size_t )Colour::NipySpectral,
        Jet = ( size_t )Colour::Jet,
        Rainbow = ( size_t )Colour::Rainbow,
        GistRainbow = ( size_t )Colour::GistRainbow,
        Hsv = ( size_t )Colour::Hsv,
        Flag = ( size_t )Colour::Flag,
        Prism = ( size_t )Colour::Prism
    };

    ColourMap()
    {
        mStream << GetColour( Seaborn::Deep, ColourType::None );
    }


    template< typename tT >
    ColourMap( tT colour, ColourType type = ColourType::None )
    {
        mStream << GetColour( colour, type );
    }

    template<>
    ColourMap( Palette colour, ColourType type ) = delete;

    ColourMap( const ColourMap &colourMap )
    {
        mStream << colourMap.mStream.str();
    }

    virtual std::string ToString() const;

    template< typename tT >
    static std::string GetColour( tT colour, ColourType type )
    {
        std::string col = __PlotLibColours[static_cast<size_t>( colour )];

        if ( type != ColourType::None )
        {
            if ( type == ColourType::Dark )
            {
                col += "_d";
            }
            else
            {
                col += "_r";
            }
        }

        return col;
    }

    static std::string GetColour( Seaborn colour )
    {
        return __PlotLibColours[static_cast<size_t>( colour )];
    }

protected:

    std::stringstream mStream;

};

class Palette
    : public ColourMap
{
public:

    Palette( Type type );

    Palette( const std::string &type, Type typeEnum = Type::Custom );

    template< typename tT >
    Palette( tT colour, int32_t amount, ColourType type = ColourType::None )
        : mCustomType( "sns.color_palette( '" + GetColour( colour, type ) +
                       "', " + std::to_string( amount ) + " )" ),
          mType( Type::ColorPallette )
    {
    }

    template< typename tT >
    Palette( tT colour, ColourType type = ColourType::None )
        : Palette( "sns.color_palette( '" + GetColour( colour, type ) + "' )", Type::ColorPallette )
    {
    }

    Palette( const Palette &palette )
        : ColourMap( palette ),
          mArguments( palette.mArguments.str() ),
          mCustomType( palette.mCustomType ),
          mType( palette.mType )
    {
    }

    std::string ToString() const;

    std::string GetArguments() const;

    Palette &SetColours( size_t nColours );

    Palette &SetDesaturation( double desat );

    Palette &UseColourCodes( bool colourCodes );

    Palette &SetColourMap( bool map );

protected:

    std::stringstream mArguments;
    std::string mCustomType;
    Type mType;

    std::string GetPalette( Type palette ) const;
};

class HUSLPalette
    : public Palette
{
public:

    HUSLPalette();

    HUSLPalette &SetColours( size_t nColours );

    HUSLPalette &SetHue( double h );

    HUSLPalette &SetSaturation( double s );

    HUSLPalette &SetLightness( double l );
};

class HLSPalette
    : public Palette
{
public:

    HLSPalette();

    HLSPalette &SetColours( size_t nColours );

    HLSPalette &SetHue( double h );

    HLSPalette &SetSaturation( double s );

    HLSPalette &SetLightness( double l );
};

class CubeHelixPalette
    : public Palette
{
public:

    CubeHelixPalette();

    CubeHelixPalette &SetColours( size_t nColours );

    CubeHelixPalette &SetStart( double start );

    CubeHelixPalette &SetRot( double rot );

    CubeHelixPalette &SetGamma( double gamma );

    CubeHelixPalette &SetHue( double hue );

    CubeHelixPalette &SetDark( double dark );

    CubeHelixPalette &SetLight( double light );

    CubeHelixPalette &SetReverse( bool reverse );
};

class DarkPalette
    : public Palette
{
public:

    enum class Input
    {
        RGB,
        HLS,
        HUSL,
        XKCD
    };

    template< typename tT >
    DarkPalette( tT colour, ColourType type = ColourType::None )
        : Palette( Type::Other )
    {
        mArguments << "sns.dark_palette( '" << GetColour( colour, type ) << "'";
    }

    DarkPalette( std::tuple< uint8_t, uint8_t, uint8_t > colour, Input input );

    DarkPalette( const std::string &colour, Input input );

    DarkPalette &SetColours( size_t nColours );

    DarkPalette &SetReverse( bool reverse );

protected:

    DarkPalette( Type type );

    std::string GetInput( Input input );
};

class LightPalette
    : public DarkPalette
{
public:

    template< typename tT >
    LightPalette( tT colour, ColourType type = ColourType::None )
        : DarkPalette( Type::Other )
    {
        mArguments << "sns.light_palette( '" << GetColour( colour, type ) << "'";
    }

    LightPalette( std::tuple< uint8_t, uint8_t, uint8_t > colour, Input input );

    LightPalette( const std::string &colour, Input input );
};

class DivergingPalette
    : public Palette
{
public:

    enum class Centre
    {
        Light,
        Dark
    };

    DivergingPalette( double hNeg, double hPos );

    DivergingPalette &SetSaturation( double sat );

    DivergingPalette &SetLightness( double light );

    DivergingPalette &SetColours( size_t nColours );

    DivergingPalette &SetCentre( Centre centre );
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/palette.cpp"
#endif

#endif