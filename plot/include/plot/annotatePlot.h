#pragma once
#ifndef __ANNOTATEPLOT_H__
#define __ANNOTATEPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class AnnotatePlot
    : public AbstractPlot
{
public:

    enum class Type
    {
        FigurePoints,
        FigurePixels,
        FigureFraction,
        AxesPoints,
        AxesPixels,
        AxesFraction,
        Data,
        OffsetPoints,
        Polar
    };

    AnnotatePlot()
    {
        mStream << "plt.annotate(";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    AnnotatePlot &SetLabel( const std::string &label )
    {
        mStream << ", s=" << label;
        return *this;
    }

    AnnotatePlot &SetXY( double x, double y )
    {
        mStream << ", xy=(" << x << "," << y << ")";
        return *this;
    }

    AnnotatePlot &SetXYText( double x, double y )
    {
        mStream << ", xytext=(" << x << "," << y << ")";
        return *this;
    }

    AnnotatePlot &SetXYCoordinates( Type type )
    {
        mStream << ", xycoords=" << GetType( type );
        return *this;
    }

    AnnotatePlot &SetTextCoordinates( Type type )
    {
        mStream << ", textcoords=" << GetType( type );
        return *this;
    }

private:

    std::stringstream mStream;

    std::string GetType( Type type )
    {
        switch ( type )
        {
        case Type::FigurePoints:
            return "'figure points'";

        case Type::FigurePixels:
            return "'figure pixels'";

        case Type::FigureFraction:
            return "'figure fraction'";

        case Type::AxesPoints:
            return "'axes points'";

        case Type::AxesPixels:
            return "'axes pixels'";

        case Type::AxesFraction:
            return "'axes fraction'";

        case Type::Data:
            return "'data'";

        case Type::OffsetPoints:
            return "'offset points'";

        case Type::Polar:
            return "'polar'";
        }

        return "''";
    }

};

#endif