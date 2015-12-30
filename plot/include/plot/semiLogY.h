#pragma once
#ifndef __SEMILOGY_H__
#define __SEMILOGY_H__

#include "plot/abstractPlot.h"

#include <string>

class SemiLogY
    : public AbstractPlot
{
public:

    SemiLogY( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "plt.semilogy(" << ToArray( exogenous ) << "," << ToArray( endogenous );
    }

    SemiLogY( const Vec &exogenous, const Vec &endogenous, const std::string &marker )
    {
        mStream << "plt.semilogy(" << ToArray( exogenous ) << "," << ToArray( endogenous ) << ",marker=" << marker;
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    SemiLogY &SetAlpha( double alpha )
    {
        mStream << ", alpha=" << alpha;
        return *this;
    }

    SemiLogY &SetScalar( double scalar )
    {
        mStream << ", s=" << scalar;
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif