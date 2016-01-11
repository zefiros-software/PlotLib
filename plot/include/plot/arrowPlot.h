#pragma once
#ifndef __ARROWPLOT_H__
#define __ARROWPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class ArrowPlot
    : public AbstractPlot
{
public:

    enum class Shape
    {
        Full,
        Left,
        Right
    };

    ArrowPlot( double x, double y, double dx, double dy )
    {
        mStream << "plt.arrow(" << x << "," << y << "," << dx << "," << dy;
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    ArrowPlot &SetWidth( double width )
    {
        mStream << ", width=" << width;
        return *this;
    }

    ArrowPlot &SetLengthIncludesHead( bool includes )
    {
        mStream << ", length_includes_head=" << GetBool( includes );
        return *this;
    }

    ArrowPlot &SetHeadWidth( double width )
    {
        mStream << ", head_width=" << width;
        return *this;
    }

    ArrowPlot &SetHeadLength( double length )
    {
        mStream << ", head_length=" << length;
        return *this;
    }

    ArrowPlot &SetShape( Shape shape )
    {
        mStream << ", shape=" << GetShape( shape );
        return *this;
    }

    ArrowPlot &SetOverhang( double overhang )
    {
        mStream << ", overhang=" << overhang;
        return *this;
    }

    ArrowPlot &SetHeadStartsAtZero( bool starts )
    {
        mStream << ", head_starts_at_zero=" << GetBool( starts );
        return *this;
    }

private:

    std::stringstream mStream;

    std::string GetShape( Shape shape )
    {
        switch ( shape )
        {
        case Shape::Full:
            return "'full'";

        case Shape::Left:
            return "'left'";

        case Shape::Right:
            return "'right'";
        }

        return "''";
    }

};

#endif