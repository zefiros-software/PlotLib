#pragma once
#ifndef __HISTOGRAMPLOT_H__
#define __HISTOGRAMPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class HistogramPlot
    : public AbstractPlot
{
public:

    enum class Type
    {
        Bar,
        BarStacked,
        Step,
        StepFilled
    };

    enum class Alignment
    {
        Left,
        Middle,
        Right
    };

    enum class Orientation
    {
        Vertical,
        Horizontal
    };

    HistogramPlot( const Vec &vec )
    {
        mStream << "plt.hist(" << ToArray( vec );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    HistogramPlot &SetBins( size_t value )
    {
        mStream << ", bins=" << value;
        return *this;
    }

    HistogramPlot &SetBins( const Vec &bins )
    {
        mStream << ", bins=" << ToArray( bins );
        return *this;
    }

    HistogramPlot &SetRange( double min, double max )
    {
        mStream << ", range=(" << min << "," << max << ")";
        return *this;
    }

    HistogramPlot &SetNormed( bool normed )
    {
        mStream << ", normed=" << GetBool( normed );
        return *this;
    }

    HistogramPlot &SetWeights( const Vec &weights )
    {
        mStream << ", weights=" << ToArray( weights );
        return *this;
    }

    HistogramPlot &SetCumulative( bool cumulative )
    {
        mStream << ", normed=" << GetBool( cumulative );
        return *this;
    }

    HistogramPlot &SetBottom( double bottom )
    {
        mStream << ", bottom=" << bottom;
        return *this;
    }

    HistogramPlot &SetBottom( const Vec &bottom )
    {
        mStream << ", bottom=" << ToArray( bottom );
        return *this;
    }

    HistogramPlot &SetType( Type type )
    {
        mStream << ", histtype =" << GetType( type );
        return *this;
    }

    HistogramPlot &SetAllignment( Alignment align )
    {
        mStream << ", histtype =" << GetAlignment( align );
        return *this;
    }

    HistogramPlot &SetOrientation( Orientation orientation )
    {
        mStream << ", orientation  = " << ( orientation == Orientation::Horizontal ? "'horizontal'" : "'vertical'" );
        return *this;
    }

    HistogramPlot &SetRelativeWidth( double rwidth )
    {
        mStream << ", rwidth=" << rwidth;
        return *this;
    }

    HistogramPlot &SetLogarithmic( bool log )
    {
        mStream << ", log=" << GetBool( log );
        return *this;
    }

    HistogramPlot &SetColour( const std::string &colour )
    {
        mStream << ", color = '" << colour << "'";
        return *this;
    }

    HistogramPlot &SetLabel( const std::string &label )
    {
        mStream << ", label='" << label << "'";
        return *this;
    }

    HistogramPlot &SetStacked( bool stacked )
    {
        mStream << ", stacked=" << GetBool( stacked );
        return *this;
    }

private:

    std::stringstream mStream;

    std::string GetType( Type type )
    {
        switch ( type )
        {
        case Type::Bar:
            return "'bar'";

        case Type::BarStacked:
            return "'barstacked'";

        case Type::Step:
            return "'step'";

        case Type::StepFilled:
            return "'stepfilled'";
        }

        return "''";
    }

    std::string GetAlignment( Alignment align )
    {
        switch ( align )
        {
        case Alignment::Left:
            return "'left'";

        case Alignment::Middle:
            return "'mid'";

        case Alignment::Right:
            return "'right'";
        }

        return "''";
    }

};

#endif