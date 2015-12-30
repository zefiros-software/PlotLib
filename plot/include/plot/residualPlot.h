#pragma once
#ifndef __RESIDUALPLOT_H__
#define __RESIDUALPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class ResidualPlot
    : public AbstractPlot
{
public:

    ResidualPlot( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "sns.residplot(" << ToArray( exogenous ) << "," << ToArray( endogenous );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    ResidualPlot &SetLowess( bool lowess )
    {
        mStream << ", lowess=" << GetBool( lowess );
        return *this;
    }

    ResidualPlot &SetOrder( size_t order )
    {
        mStream << ", order=" << order;
        return *this;
    }

    ResidualPlot &SetRobust( bool robust )
    {
        mStream << ", robust=" << GetBool( robust );
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif