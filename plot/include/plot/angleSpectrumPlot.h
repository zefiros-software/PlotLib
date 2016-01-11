#pragma once
#ifndef __ANGLESPECTRUMPLOT_H__
#define __ANGLESPECTRUMPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class AngleSpectrumPlot
    : public AbstractPlot
{
public:

    enum class Sides
    {
        Default,
        OneSided,
        TwoSided
    };

    AngleSpectrumPlot( const Vec &vec )
    {
        mStream << "plt.angle_spectrum(" << ToArray( vec );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    AngleSpectrumPlot &SetSamplingFrequency( double fs )
    {
        mStream << ", Fs=" << fs;
        return *this;
    }

    AngleSpectrumPlot &SetSides( Sides sides )
    {
        mStream << ", sides=" << GetSides( sides );
        return *this;
    }

    AngleSpectrumPlot &SetCenterFrequence( int32_t fc )
    {
        mStream << ", Fc=" << fc;
        return *this;
    }

    AngleSpectrumPlot &SetPadTo( int32_t pad )
    {
        mStream << ", pad_to=" << pad;
        return *this;
    }

private:

    std::stringstream mStream;

    std::string GetSides( Sides sides )
    {
        switch ( sides )
        {
        case Sides::Default:
            return "'default'";

        case Sides::OneSided:
            return "'onesided'";

        case Sides::TwoSided:
            return "'twosided'";
        }
    }

};

#endif