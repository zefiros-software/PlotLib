#pragma once
#ifndef __LINEPLOT_H__
#define __LINEPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class LinePlot
    : public AbstractPlot
{
public:

    LinePlot( const Vec &exogenous )
    {
        mStream << "plt.plot(" << ToArray( exogenous );
    }

    LinePlot( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "plt.plot(" << ToArray( exogenous ) << "," << ToArray( endogenous );
    }

    LinePlot( const Vec &exogenous, const Vec &endogenous, const std::string &character )
    {
        mStream << "plt.plot(" << ToArray( exogenous ) << "," << ToArray( endogenous ) << "," << character;
    }

    LinePlot( const Vec &exogenous, const std::string &character )
    {
        mStream << "plt.plot(" << ToArray( exogenous ) << "," << character;
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    LinePlot &SetAlpha( double alpha )
    {
        mStream << ", alpha=" << alpha;
        return *this;
    }

    LinePlot &SetLabel( const std::string &label )
    {
        mStream << ", label='" << label << "'";
        return *this;
    }

private:

    std::stringstream mStream;
};


#endif