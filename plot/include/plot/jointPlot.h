#pragma once
#ifndef __JOINTPLOT_H__
#define __JOINTPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class JointPlot
    : public AbstractPlot
{
public:

    enum class Kind
    {
        Scatter,
        Regression,
        Residual,
        KernelDensity,
        Hexbin
    };

    JointPlot( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "xl=" << ToArray( exogenous ) << "\n"
                << "yl=" << ToArray( endogenous ) << "\n";
        mStream << "sns.jointplot(x='x',y='y',data=pd.DataFrame.from_dict({'x': xl,'y': yl})";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    JointPlot &SetKind( Kind kind )
    {
        mStream << ", kind=\"" << GetKind( kind ) << "\"";
        return *this;
    }

    JointPlot &SetSize( size_t size )
    {
        mStream << ", size=" << size;
        return *this;
    }

    JointPlot &SetRatio( double ratio )
    {
        mStream << ", ratio=" << ratio;
        return *this;
    }

    JointPlot &SetSpace( double space )
    {
        mStream << ", space=" << space;
        return *this;
    }

    JointPlot &SetXLimit( const std::pair<double, double> &x )
    {
        mStream << ", xlim=(" << x.first << "," << x.second << ")";
        return *this;
    }

    JointPlot &SetYLimit( const std::pair<double, double> &y )
    {
        mStream << ", ylim=(" << y.first << "," << y.second << ")";
        return *this;
    }

private:

    std::stringstream mStream;

    static std::string GetKind( Kind kind )
    {
        switch ( kind )
        {
        case Kind::Scatter:
            return "scatter";

        case Kind::Regression:
            return "reg";

        case Kind::Residual:
            return "res";

        case Kind::KernelDensity:
            return "kde";

        case Kind::Hexbin:
            return "hex";
        }

        return "";
    }
};

#endif