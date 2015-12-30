#pragma once
#ifndef __RUGPLOT_H__
#define __RUGPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class RUGPlot
    : public AbstractPlot
{
public:

    enum class Axis
    {
        X,
        Y
    };

    RUGPlot( const Vec &a )
    {
        mStream << "sns.rugplot(" << ToArray( a );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    RUGPlot &SetHeight( double height )
    {
        mStream << ", height=" << height;
        return *this;
    }

    RUGPlot &SetAxis( Axis axis )
    {
        mStream << ", kind='" << ( axis == Axis::X ? 'X' : 'Y' ) << "'";
        return *this;
    }

private:

    std::stringstream mStream;
};


#endif