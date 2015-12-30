#pragma once
#ifndef __LOGLOGPLOT_H__
#define __LOGLOGPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class LogLogPlot
    : public AbstractPlot
{
public:

    LogLogPlot( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "plt.loglog(" << ToArray( exogenous ) << "," << ToArray( endogenous );
    }

    LogLogPlot( const Vec &exogenous, const Vec &endogenous, const std::string &marker )
    {
        mStream << "plt.loglog(" << ToArray( exogenous ) << "," << ToArray( endogenous ) << ",marker=" << marker;
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    LogLogPlot &SetAlpha( double alpha )
    {
        mStream << ", alpha=" << alpha;
        return *this;
    }

    LogLogPlot &SetScalar( double scalar )
    {
        mStream << ", s=" << scalar;
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif