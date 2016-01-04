#pragma once
#ifndef __DISTPLOT_H__
#define __DISTPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/vec.h"

#include <string>

class DistrPlot
    : public AbstractPlot
{
public:

    DistrPlot( const Vec &a )
    {
        mStream << "sns.distplot(" << ToArray( a );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    DistrPlot &SetBins( bool log = false )
    {
        mStream << ", bins=" << ( log ? "'log'" : "None" );
        return *this;
    }

    DistrPlot &SetBins( const Vec &seq )
    {
        const bool isSingular = seq.GetSize() == 1;
        mStream << ", bins=" << isSingular ? std::to_string( seq.GetData()[0] ) : ToArray( seq );
        return *this;
    }

    DistrPlot &SetHist( bool hist )
    {
        mStream << ", hist=" << GetBool( hist );
        return *this;
    }

    DistrPlot &SetKDE( bool kde )
    {
        mStream << ", kde=" << GetBool( kde );
        return *this;
    }

    DistrPlot &SetRUG( bool rug )
    {
        mStream << " , rug=" << GetBool( rug );
        return *this;
    }

    DistrPlot &SetVerical( bool vertical )
    {
        mStream << " , vertical=" << GetBool( vertical );
        return *this;
    }

    DistrPlot &SetNormHist( bool normHist )
    {
        mStream << " , norm_hist=" << GetBool( normHist );
        return *this;
    }

    DistrPlot &SetAxLabel( const std::string &axlabel )
    {
        mStream << " , axlabel='" << axlabel  << "'";
        return *this;
    }

    DistrPlot &SetAxLabel()
    {
        mStream << " , axlabel=False";
        return *this;
    }

    DistrPlot &SetLabel( const std::string &label )
    {
        mStream << " , label='" << label << "'";
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif