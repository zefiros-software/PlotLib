#pragma once
#ifndef __PALPLOT_H__
#define __PALPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <string>

class PalPlot
    : public AbstractPlot
{
public:

    PalPlot( Palette palette )
    {
        mStream << "plt.palplot(" << palette.ToString();
    }
    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    PalPlot &SetSize( double size )
    {
        mStream << ", size=" << size;
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif