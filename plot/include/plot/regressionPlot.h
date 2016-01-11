#pragma once
#ifndef __REGRESSIONPLOT_H__
#define __REGRESSIONPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class RegressionPlot
    : public AbstractPlot
{
public:

    RegressionPlot( const Vec &exogenous, const Vec &endogenous )
    {
        mStream << "sns.regplot(np.array(" << ToArray( exogenous ) << "),np.array(" << ToArray( endogenous ) << ")";
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    RegressionPlot &SetXBins( size_t bins )
    {
        mStream << ", x_bins=" << bins;
        return *this;
    }

    RegressionPlot &SetXBins( const Vec &bins )
    {
        mStream << ", x_bins=" << ToArray( bins );
        return *this;
    }

    RegressionPlot &SetXConfidenceInterval( size_t ci )
    {
        assert( ci <= 100 );
        mStream << ", x_ci=" << ci;
        return *this;
    }
    RegressionPlot &SetConfidenceInterval( size_t ci )
    {
        assert( ci <= 100 );
        mStream << ", ci=" << ci;
        return *this;
    }

    RegressionPlot &SetScatter( bool scatter )
    {
        mStream << ", scatter=" << GetBool( scatter );
        return *this;
    }

    RegressionPlot &SetFitRegression( bool fit )
    {
        mStream << ", fit_reg=" << GetBool( fit );
        return *this;
    }

    RegressionPlot &SetNBoots( size_t nboots )
    {
        mStream << ", n_boots=" << nboots;
        return *this;
    }

    RegressionPlot &SetOrder( size_t order )
    {
        mStream << ", order=" << order;
        return *this;
    }

    RegressionPlot &SetLogistic( bool logistic )
    {
        mStream << ", logistic=" << GetBool( logistic );
        return *this;
    }

    RegressionPlot &SetLowess( bool lowess )
    {
        mStream << ", lowess=" << GetBool( lowess );
        return *this;
    }

    RegressionPlot &SetRobust( bool robust )
    {
        mStream << ", robust=" << GetBool( robust );
        return *this;
    }

    RegressionPlot &SetLogX( bool logx )
    {
        mStream << ", logx=" << GetBool( logx );
        return *this;
    }

    RegressionPlot &SetXPartial( const Mat &mat )
    {
        mStream << ", x_partial=" << ToArray( mat );
        return *this;
    }

    RegressionPlot &SetYPartial( const Mat &mat )
    {
        mStream << ", y_partial=" << ToArray( mat );
        return *this;
    }

    RegressionPlot &SetTruncate( bool trunc )
    {
        mStream << ", truncate=" << GetBool( trunc );
        return *this;
    }

    RegressionPlot &SetXJitter( double jitter )
    {
        mStream << ", x_jitter=" << jitter;
        return *this;
    }

    RegressionPlot &SetYJitter( double jitter )
    {
        mStream << ", y_jitter=" << jitter;
        return *this;
    }

    RegressionPlot &SetLabel( const std::string &label )
    {
        mStream << ", label=" << label;
        return *this;
    }

    RegressionPlot &SetColour( const std::string &colour )
    {
        mStream << ", color='" << colour << "'";
        return *this;
    }

    RegressionPlot &SetMarker( const std::string &marker )
    {
        mStream << ", markers = '" << marker << "'";
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif