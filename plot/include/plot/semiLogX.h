#pragma once
#ifndef __SEMILOGX_H__
#define __SEMILOGX_H__

#include "plot/abstractPlot.h"

#include <string>

class SemiLogX
    : public AbstractPlot
{
public:

    SemiLogX( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "plt.semilogx(" << ToArray( exogenous ) << "," << ToArray( endogenous );
    }

    SemiLogX( const Vec &exogenous, const Vec &endogenous, const std::string &marker )
    {
        mStream << "plt.semilogx(" << ToArray( exogenous ) << "," << ToArray( endogenous ) << ",marker=" << marker;
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    SemiLogX &SetAlpha( double alpha )
    {
        mStream << ", alpha=" << alpha;
        return *this;
    }

    SemiLogX &SetScalar( double scalar )
    {
        mStream << ", s=" << scalar;
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif