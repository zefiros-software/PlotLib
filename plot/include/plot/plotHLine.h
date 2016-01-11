#pragma once
#ifndef __PLOTHLINE_H__
#define __PLOTHLINE_H__

#include "plot/abstractPlot.h"

#include <string>

class PlotHLine
    : public AbstractPlot
{
public:

    PlotHLine( double x = 0 )
    {
        mStream << "plt.axhline(" << x;
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    PlotHLine &SetXMin( double xmin )
    {
        mStream << ", xmin=" << xmin;
        return *this;
    }

    PlotHLine &SetXMax( double xmax )
    {
        mStream << ", xmax=" << xmax;
        return *this;
    }

private:

    std::stringstream mStream;

};

#endif