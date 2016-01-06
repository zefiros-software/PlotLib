#pragma once
#ifndef __PALETTEPLOT_H__
#define __PALETTEPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>

class PalettePlot
    : public AbstractPlot
{
public:

    enum class Axis
    {
        X,
        Y
    };

    PalettePlot( const Palette &palette )
    {
        mStream << "sns.palplot(" << palette.ToString();
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    PalettePlot &SetSize( double size )
    {
        mStream << ", size=" << size;
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif