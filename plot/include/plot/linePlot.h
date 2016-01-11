#pragma once
#ifndef __LINEPLOT_H__
#define __LINEPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class LinePlot
    : public AbstractPlot
{
public:

    LinePlot( const Vec &endogenous )
    {
        mStream << "plt.plot(" << ToArray( endogenous );
    }

    LinePlot( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "plt.plot(" << ToArray( exogenous ) << "," << ToArray( endogenous );
    }

    LinePlot( const Vec &exogenous, const Vec &endogenous, const std::string &character )
    {
        mStream << "plt.plot(" << ToArray( exogenous ) << "," << ToArray( endogenous ) << "," << character;
    }

    LinePlot( const Vec &endogenous, const std::string &character )
    {
        mStream << "plt.plot(" << ToArray( endogenous ) << "," << character;
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

    LinePlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
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