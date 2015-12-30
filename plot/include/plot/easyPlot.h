#pragma once
#ifndef __EASYPLOT_H__
#define __EASYPLOT_H__

#include "plot/scatterPlot.h"
#include "plot/linePlot.h"
#include "plot/plot.h"
#include "plot/vec.h"

namespace EasyPlot
{
    Plot ResidualPlot( const Vec &exogenous, const Vec &endogenous, const Vec &fit )
    {
        ::Plot plot;
        plot.SubPlot( 1, 2, 1 )
        .AddPlot( LinePlot( exogenous, endogenous ) )
        .AddPlot( LinePlot( exogenous, fit ) )
        .SetXLabel( "X-Samples" )
        .SetYLabel( "Y-Value" )
        .SetTitle( "Residual Plot" )
        .SetLegend( { "Actual", "Fit" } )
        .SetXLimit( exogenous.Min(), exogenous.Max() );

        auto resid = endogenous.GetData();
        auto f = fit.GetData();

        for ( size_t i = 0, size = resid.size(); i < size; ++i )
        {
            resid[i] -= f[i];
        }

        plot.SubPlot( 1, 2, 2 )
        .AddPlot( ScatterPlot( exogenous, resid ) )
        .SetXLabel( "X-Samples" )
        .SetYLabel( "Residual" )
        .SetLegend( { "Residual" } )
        .SetXLimit( exogenous.Min(), exogenous.Max() );

        return plot;
    }
}

#endif