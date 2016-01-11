#pragma once
#ifndef __AUTOCORRELATIONPLOT_H__
#define __AUTOCORRELATIONPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class AutoCorrelationPlot
    : public AbstractPlot
{
public:

    AutoCorrelationPlot( const Vec &vec )
    {
        mStream << "plt.acorr(" << ToArray( vec );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    AutoCorrelationPlot &SetHold( bool hold )
    {
        mStream << ", hold=" << GetBool( hold );
        return *this;
    }

    AutoCorrelationPlot &SetNormed( bool normed )
    {
        mStream << ", normed=" << GetBool( normed );
        return *this;
    }

    AutoCorrelationPlot &SetVLines( bool vlines )
    {
        mStream << ", usevlines=" << GetBool( vlines );
        return *this;
    }

    AutoCorrelationPlot &SetMaxLags( size_t maxlags )
    {
        mStream << ", maxlags=" << maxlags;
        return *this;
    }

private:

    std::stringstream mStream;

};

#endif