#pragma once
#ifndef __DISTPLOT_H__
#define __DISTPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/vec.h"

#include <string>

class DistPlot
    : public AbstractPlot
{
public:

    DistPlot( const Vec &a )
    {
        mStream << "sns.distplot(" << ToArray( a );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    DistPlot &SetBins( bool log = false )
    {
        mStream << ", bins=" << ( log ? "'log'" : "None" );
        return *this;
    }

    DistPlot &SetBinsSize( const Vec &seq )
    {
        const bool isSingular = seq.GetSize() == 1;
        mStream << ", bins=" << isSingular ? std::to_string( seq.GetData()[0] ) : ToArray( seq );
        return *this;
    }

    DistPlot &SetHist( bool hist )
    {
        mStream << ", hist=" << GetBool( hist );
        return *this;
    }

    DistPlot &SetKDE( bool kde )
    {
        mStream << ", kde=" << GetBool( kde );
        return *this;
    }

    DistPlot &SetRUG( bool rug )
    {
        mStream << " , rug=" << GetBool( rug );
        return *this;
    }

    DistPlot &SetVerical( bool vertical )
    {
        mStream << " , vertical=" << GetBool( vertical );
        return *this;
    }

    DistPlot &SetNormHist( bool normHist )
    {
        mStream << " , norm_hist=" << GetBool( normHist );
        return *this;
    }

    DistPlot &SetAxLabel( const std::string &axlabel )
    {
        mStream << " , axlabel='" << axlabel  << "'";
        return *this;
    }

    DistPlot &SetAxLabel()
    {
        mStream << " , axlabel=False";
        return *this;
    }

    DistPlot &SetLabel( const std::string &label )
    {
        mStream << " , label='" << label << "'";
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif