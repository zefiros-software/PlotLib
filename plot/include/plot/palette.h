#pragma once
#ifndef __PALETTE_H__
#define __PALETTE_H__

#include <sstream>

static const char *const PlotLibColours[] =
{
    "Purples_r",
    "CMRmap_r",
    "nipy_spectral",
    "Purples",
    "gist_stern_r",
    "bwr",
    "prism",
    "GnBu",
    "hsv",
    "spring",
    "YlGnBu_r",
    "BrBG_r",
    "Paired_r",
    "seismic_r",
    "autumn",
    "cool",
    "GnBu_r",
    "BuPu_r",
    "YlOrRd_r",
    "PiYG",
    "PuBuGn",
    "flag",
    "Paired",
    "YlOrBr",
    "PuBu_r",
    "YlGn_r",
    "Blues",
    "PuOr",
    "Pastel2_r",
    "gist_stern",
    "Reds_r",
    "brg",
    "gist_gray",
    "gist_ncar",
    "afmhot_r",
    "PuBu",
    "Spectral",
    "Pastel2",
    "winter",
    "Wistia",
    "Dark2",
    "PRGn",
    "Reds",
    "binary_r",
    "jet",
    "binary",
    "Greens",
    "Wistia_r",
    "Blues_r",
    "afmhot",
    "gist_yarg_r",
    "RdBu",
    "BuGn",
    "rainbow_r",
    "Greens_r",
    "RdYlBu",
    "Pastel1_r",
    "coolwarm",
    "Set2_r",
    "cubehelix",
    "terrain_r",
    "ocean",
    "seismic",
    "Accent",
    "RdBu_r",
    "RdPu",
    "OrRd",
    "YlOrBr_r",
    "winter_r",
    "YlOrRd",
    "Set3",
    "Greys",
    "flag_r",
    "OrRd_r",
    "hot",
    "ocean_r",
    "PuRd",
    "BuPu",
    "gray",
    "YlGnBu",
    "gnuplot2_r",
    "Set1_r",
    "Set1",
    "PRGn_r",
    "gnuplot",
    "spectral_r",
    "PuRd_r",
    "cool_r",
    "hot_r",
    "gist_heat_r",
    "pink_r",
    "autumn_r",
    "rainbow",
    "gnuplot_r",
    "Set2",
    "CMRmap",
    "spectral",
    "nipy_spectral_r",
    "gist_earth",
    "gist_heat",
    "gist_gray_r",
    "BuGn_r",
    "gist_rainbow",
    "Oranges_r",
    "PiYG_r",
    "summer_r",
    "brg_r",
    "BrBG",
    "cubehelix_r",
    "gist_ncar_r",
    "copper",
    "RdGy",
    "coolwarm_r",
    "spring_r",
    "bone_r",
    "terrain",
    "Set3_r",
    "Pastel1",
    "RdGy_r",
    "copper_r",
    "Accent_r",
    "bone",
    "prism_r",
    "Dark2_r",
    "Oranges",
    "Spectral_r",
    "gist_earth_r",
    "RdPu_r",
    "gnuplot2",
    "RdYlGn_r",
    "gray_r",
    "pink",
    "gist_yarg",
    "gist_rainbow_r",
    "jet_r",
    "YlGn",
    "PuBuGn_r",
    "Greys_r",
    "hsv_r",
    "RdYlBu_r",
    "PuOr_r",
    "summer",
    "RdYlGn",
    "bwr_r"
};

class Palette
{
public:

    enum class Type
    {
        Deep,
        Muted,
        Bright,
        Pastel,
        Dark,
        ColourBlind,
        Reset,
        Custom,
        Integer,
        Other
    };

    enum class Colour
    {
        Purples_r,
        CMRmap_r,
        nipy_spectral,
        Purples,
        gist_stern_r,
        bwr,
        prism,
        GnBu,
        hsv,
        spring,
        YlGnBu_r,
        BrBG_r,
        Paired_r,
        seismic_r,
        autumn,
        cool,
        GnBu_r,
        BuPu_r,
        YlOrRd_r,
        PiYG,
        PuBuGn,
        flag,
        Paired,
        YlOrBr,
        PuBu_r,
        YlGn_r,
        Blues,
        PuOr,
        Pastel2_r,
        gist_stern,
        Reds_r,
        brg,
        gist_gray,
        gist_ncar,
        afmhot_r,
        PuBu,
        Spectral,
        Pastel2,
        winter,
        Wistia,
        Dark2,
        PRGn,
        Reds,
        binary_r,
        jet,
        binary,
        Greens,
        Wistia_r,
        Blues_r,
        afmhot,
        gist_yarg_r,
        RdBu,
        BuGn,
        rainbow_r,
        Greens_r,
        RdYlBu,
        Pastel1_r,
        coolwarm,
        Set2_r,
        cubehelix,
        terrain_r,
        ocean,
        seismic,
        Accent,
        RdBu_r,
        RdPu,
        OrRd,
        YlOrBr_r,
        winter_r,
        YlOrRd,
        Set3,
        Greys,
        flag_r,
        OrRd_r,
        hot,
        ocean_r,
        PuRd,
        BuPu,
        gray,
        YlGnBu,
        gnuplot2_r,
        Set1_r,
        Set1,
        PRGn_r,
        gnuplot,
        spectral_r,
        PuRd_r,
        cool_r,
        hot_r,
        gist_heat_r,
        pink_r,
        autumn_r,
        rainbow,
        gnuplot_r,
        Set2,
        CMRmap,
        spectral,
        nipy_spectral_r,
        gist_earth,
        gist_heat,
        gist_gray_r,
        BuGn_r,
        gist_rainbow,
        Oranges_r,
        PiYG_r,
        summer_r,
        brg_r,
        BrBG,
        cubehelix_r,
        gist_ncar_r,
        copper,
        RdGy,
        coolwarm_r,
        spring_r,
        bone_r,
        terrain,
        Set3_r,
        Pastel1,
        RdGy_r,
        copper_r,
        Accent_r,
        bone,
        prism_r,
        Dark2_r,
        Oranges,
        Spectral_r,
        gist_earth_r,
        RdPu_r,
        gnuplot2,
        RdYlGn_r,
        gray_r,
        pink,
        gist_yarg,
        gist_rainbow_r,
        jet_r,
        YlGn,
        PuBuGn_r,
        Greys_r,
        hsv_r,
        RdYlBu_r,
        PuOr_r,
        summer,
        RdYlGn,
        bwr_r
    };

    Palette( Type type )
        : mType( type )
    {
    }

    Palette( const std::string &type )
        : mCustomType( type ),
          mType( Type::Custom )
    {
    }

    Palette( Colour colour )
        : Palette( PlotLibColours[static_cast< size_t >( colour )] )
    {
    }

    std::string ToString() const
    {
        return GetPalette( mType );
    }

    std::string GetArguments() const
    {
        return mArguments.str();
    }

    Palette &SetColours( size_t nColours )
    {
        mArguments << ", n_colors=" << nColours;
        return *this;
    }

    Palette &SetDesaturation( double desat )
    {
        mArguments << ", desat=" << desat;
        return *this;
    }

    Palette &UseColourCodes( bool colourCodes )
    {
        mArguments << ", color_codes=" << ( colourCodes ? "True" : "False" );
        return *this;
    }

    Palette &SetColourMap( bool map )
    {
        mArguments << ", as_cmap=" << ( map ? "True" : "False" );
        return *this;
    }

protected:

    std::stringstream mStream;
    std::stringstream mArguments;
    std::string mCustomType;
    Type mType;

    std::string GetPalette( Type palette ) const
    {
        switch ( palette )
        {
        case Type::Deep:
            return "'deep'";

        case Type::Muted:
            return "'muted'";

        case Type::Bright:
            return "'bright'";

        case Type::Pastel:
            return "'pastel'";

        case Type::Dark:
            return "'dark'";

        case Type::ColourBlind:
            return "'colorblind'";

        case Type::Reset:
            return "'None'";

        case Type::Custom:
            return "'" + mCustomType + "'";

        case Type::Other:
            {
                std::string arguments = mArguments.str();

                if ( arguments.size() > 0 && *arguments.begin() == ',' )
                {
                    arguments = std::string( arguments.begin() + 1, arguments.end() );
                }

                return mStream.str() + arguments + ")";
            }
        }

        return "";
    }
};

class HUSLPalette
    : public Palette
{
public:

    HUSLPalette()
        : Palette( Type::Other )
    {
        mStream << "sns.husl_palette(";
    }

    HUSLPalette &SetColours( size_t nColours )
    {
        mArguments << ", n_colours=" << nColours;
        return *this;
    }

    HUSLPalette &SetH( double h )
    {
        mArguments << ", h=" << h;
        return *this;
    }

    HUSLPalette &SetS( double s )
    {
        mArguments << ", s=" << s;
        return *this;
    }

    HUSLPalette &SetL( double l )
    {
        mArguments << ", l=" << l;
        return *this;
    }
};

class HLSPalette
    : public Palette
{
public:

    HLSPalette()
        : Palette( Type::Other )
    {
        mArguments << "sns.hls_palette(";
    }

    HLSPalette &SetColours( size_t nColours )
    {
        mArguments << ", n_colours=" << nColours;
        return *this;
    }

    HLSPalette &SetH( double h )
    {
        mArguments << ", h=" << h;
        return *this;
    }

    HLSPalette &SetS( double s )
    {
        mArguments << ", s=" << s;
        return *this;
    }

    HLSPalette &SetL( double l )
    {
        mArguments << ", l=" << l;
        return *this;
    }
};

class CubeHelixPalette
    : public Palette
{
public:

    CubeHelixPalette()
        : Palette( Type::Other )
    {
        mStream << "sns.cubehelix_palette(";
    }

    CubeHelixPalette &SetColours( size_t nColours )
    {
        mArguments << ", n_colours=" << nColours;
        return *this;
    }

    CubeHelixPalette &SetStart( double start )
    {
        mArguments << ", start=" << start;
        return *this;
    }

    CubeHelixPalette &SetRot( double rot )
    {
        mArguments << ", rot=" << rot;
        return *this;
    }

    CubeHelixPalette &SetGamma( double gamma )
    {
        mArguments << ", gamma=" << gamma;
        return *this;
    }

    CubeHelixPalette &SetHue( double hue )
    {
        mArguments << ", hue=" << hue;
        return *this;
    }

    CubeHelixPalette &SetDark( double dark )
    {
        mArguments << ", dark=" << dark;
        return *this;
    }

    CubeHelixPalette &SetLight( double light )
    {
        mArguments << ", light=" << light;
        return *this;
    }

    CubeHelixPalette &SetReverse( bool reverse )
    {
        mArguments << ", reverse=" << ( reverse ? "True" : "False" );
        return *this;
    }
};


#endif