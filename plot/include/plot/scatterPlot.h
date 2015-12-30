#pragma once
#ifndef __SCATTERPLOT_H__
#define __SCATTERPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class ScatterPlot
    : public AbstractPlot
{
public:

    ScatterPlot( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "plt.scatter(" << ToArray( exogenous ) << "," << ToArray( endogenous );
    }

    ScatterPlot( const Vec &exogenous, const Vec &endogenous, const std::string &marker )
    {
        mStream << "plt.scatter(" << ToArray( exogenous ) << "," << ToArray( endogenous ) << ",marker=" << marker;
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    ScatterPlot &SetAlpha( double alpha )
    {
        mStream << ", alpha=" << alpha;
        return *this;
    }

    ScatterPlot &SetScalar( double scalar )
    {
        mStream << ", s=" << scalar;
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif