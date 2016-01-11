#pragma once
#ifndef __PLOTVLINE_H__
#define __PLOTVLINE_H__

#include "plot/abstractPlot.h"

#include <string>

class PlotVLine
    : public AbstractPlot
{
public:

    PlotVLine( double x = 0 )
    {
        mStream << "plt.axvline(" << x;
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    PlotVLine &SetYMin( double ymin )
    {
        mStream << ", ymin=" << ymin;
        return *this;
    }

    PlotVLine &SetYMax( double ymax )
    {
        mStream << ", ymax=" << ymax;
        return *this;
    }

private:

    std::stringstream mStream;

};

#endif