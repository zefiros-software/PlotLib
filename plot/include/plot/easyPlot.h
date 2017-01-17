/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2017 Zefiros Software.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @endcond
 */

#pragma once
#ifndef __EASYPLOT_H__

#define __EASYPLOT_H__

#include "plot/distancedBarPlot.h"
#include "plot/scatterPlot.h"
#include "plot/linePlot.h"
#include "plot/barPlot.h"
#include "plot/plot.h"
#include "plot/pvec.h"

#include <valarray>
#include <vector>

namespace EasyPlot
{
    void ResidualPlot( ::Plot &plot, const PVec &exogenous, const PVec &endogenous, const PVec &fit );

    template< typename tBackHueFunc, typename tForeHueFunc >
    PLOTLIB_INLINE void BackgroundForegroundBarPlot( ::Plot &plot, const std::vector< PVec > &background,
                                                     const std::vector< PVec > &foreground, const std::vector< PVec > &x,
                                                     const Palette &backPalette, const Palette &forePalette, const tBackHueFunc &backHue, const tForeHueFunc &foreHue )
    {
        std::vector< std::pair< PVec, PVec > > backData;
        std::vector< std::pair< PVec, PVec > > foreData;
        std::vector< size_t > hueData;

        for ( size_t i = 0, end = background.size(); i < end; ++i )
        {
            std::valarray< double > backVal( background[i].GetData().data(), background[i].GetSize() );
            backVal += std::valarray< double >( foreground[i].GetData().data(), foreground[i].GetSize() );

            backData.emplace_back( PVec( x[i] ), PVec( backVal ) );
            foreData.emplace_back( PVec( x[i] ), PVec( foreground[i] ) );
            hueData.push_back( i );
        }

        plot.AddPlot( BarPlot( backData, hueData, backHue ).SetColourMap( backPalette ).SetHatch( "//" ) );
        plot.AddPlot( BarPlot( foreData, hueData, foreHue ).SetColourMap( forePalette ) );
        plot.SetLegend( Plot::Location::Best );
    }

    std::vector< int32_t > StackedBarPlot( ::Plot &plot, const std::vector< PVec > &xValues,
                                           const std::vector< PVec > &yValues );

    template< typename tFunc >
    PLOTLIB_INLINE void StackedBarPlot( ::Plot &plot, const std::vector< PVec > &xValues,
                                        const std::vector< PVec > &yValues, const Palette &palette, const tFunc &hueFunc )
    {

        plot.AddColourCycler( palette );        ;

        plot.AddCustomLegend( CustomLegend( palette, StackedBarPlot( plot, xValues, yValues ), hueFunc ) );
    }

    template< typename tFunc >
    PLOTLIB_INLINE void StackedDistancedBarPlot( ::Plot &plot, const std::vector< PVec > &gapWidths,
                                                 const std::vector< PVec > &barWidths,
                                                 const std::vector< PVec > &yValues,
                                                 const Palette &palette, const tFunc &hueFunc )
    {
        std::vector< PVec > yData;
        std::vector<double> lineX;
        std::vector<std::vector<double>> lineY( gapWidths.size() );

        lineX.push_back( 0 );

        for ( auto &yVec : lineY )
        {
            yVec.push_back( 0 );
        }

        std::valarray< double > yValData( yValues[0].GetData().data(), yValues[0].GetSize() );
        yData.emplace_back( PVec( yValues[0] ) );

        for ( auto height : yValData )
        {
            lineY[0].push_back( height );
            lineY[0].push_back( height );
        }

        for ( size_t i = 1, end = yValues.size(); i < end; ++i )
        {
            yValData += std::valarray< double >( yValues[i].GetData().data(), yValues[i].GetSize() );

            for ( auto height : yValData )
            {
                lineY[i].push_back( height );
                lineY[i].push_back( height );
            }

            yData.emplace_back( PVec( yValData ) );
        }


        std::vector<double> x;
        std::vector<double> widths;

        {
            double left = 0;

            for ( uint32_t j = 0; j < barWidths[0].GetSize(); ++j )
            {
                double maxGap = gapWidths[0].GetData()[j];
                double maxBar = barWidths[0].GetData()[j];

                for ( uint32_t i = 1; i < barWidths.size(); ++i )
                {
                    if ( gapWidths[i].GetData()[j] > maxGap )
                    {
                        maxGap = gapWidths[i].GetData()[j];
                    }

                    if ( barWidths[i].GetData()[j] > maxBar )
                    {
                        maxBar = barWidths[i].GetData()[j];
                    }
                }

                left += maxGap;
                lineX.push_back( left );
                x.push_back( left );
                widths.push_back( maxBar );

                left += maxBar;
                lineX.push_back( left );
            }
        }

        std::vector< int32_t > hueData;

        plot.AddColourCycler( palette );

        for ( int32_t i = ( int32_t )lineY.size() - 1; i >= 0; --i )
        {
            plot.AddPlot( LinePlot( lineX, lineY[i] ).SetColour( "black" ).SetWidth( 2.5 ).SetAlpha( 0.2 ).SetLineStyle( "--" ) );
            plot.AddPlot( LinePlot( lineX, lineY[i] ).UseColourCycler( plot.GetColourCycler() ).SetWidth(
                              1 ).SetLineStyle( "--" ) );
        }

        plot.AddColourCycler( palette );

        for ( int32_t i = ( int32_t )yValues.size() - 1; i >= 0; --i )
        {
            plot.AddPlot( DistancedBarPlot( x, yData[i], widths ).UseColourCycler( plot.GetColourCycler() ).SetZOrder( 1000 ) );
            hueData.push_back( i );
        }

        plot.AddCustomLegend( CustomLegend( palette, hueData, hueFunc ) );
    }
}

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/easyPlot.cpp"
#endif

#endif