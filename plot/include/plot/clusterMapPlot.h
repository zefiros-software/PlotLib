/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Mick van Duijn, Koen Visscher and Paul Visscher
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
#ifndef __CLUSTERMAPPLOT_H__
#define __CLUSTERMAPPLOT_H__

#include "plot/abstractPlot.h"

class ClusterMapPlot
    : public AbstractPlot
{
public:

    enum Linkage
    {
        Single,
        Complete,
        Average,
        Weighted,
        Centroid,
        Median,
        Ward
    };

    enum class Metric
    {
        Euclidian,
        Minkowski,
        CityBlock,
        SEuclidean,
        SQEuclidean,
        Cosine,
        Correlation,
        Hamming,
        Jaccard,
        Chebyshev,
        Canberra,
        Braycurtis,
        Mahalanobis,
        Yule,
        Mathcing,
        Dice,
        Kulsinski,
        RogersTanimoto,
        RusselRao,
        Sokalsneath,
        WMinkowski
    };

    ClusterMapPlot( const ::PMat &map );

    virtual std::string ToString() override;

    ClusterMapPlot &SetMethod( Linkage linkage );

    ClusterMapPlot &SetMetric( Metric metric );

    ClusterMapPlot &ZScoreColumns( bool rows );

    ClusterMapPlot &StandardScale( bool rows );

    ClusterMapPlot &SetFigSize( const std::pair< size_t, size_t > &size );

    ClusterMapPlot &RowCluster( bool cluster );

    ClusterMapPlot &ColumnCluster( bool cluster );

    ClusterMapPlot &SetRowLinkage( const PVec &linkage );

    ClusterMapPlot &SetColumnLinkage( const PVec &linkage );

    ClusterMapPlot &SetMask( const std::vector< bool > &mask );

private:

    static std::string GetLinkage( Linkage linkage );

    static std::string GetMetric( Metric metric );
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/clusterMapPlot.cpp"
#endif

#endif