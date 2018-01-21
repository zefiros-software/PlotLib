/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016-2018 Zefiros Software.
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

#include "plot/easyPlot.h"

PLOTLIB_INLINE void EasyPlot::ResidualPlot(::Plot &plot, const PVec &exogenous, const PVec &endogenous,
                                           const PVec &fit)
{
    plot.SubPlot(2, 1, 1)
    .AddPlot(LinePlot(exogenous, endogenous))
    .AddPlot(LinePlot(exogenous, fit))
    .SetXLabel("X-Samples")
    .SetYLabel("Y-Value")
    .SetTitle("Residual Plot")
    .SetLegend({ "Actual", "Fit" })
    .SetXLimit(exogenous.Min(), exogenous.Max());

    auto resid = endogenous.GetData();
    auto f = fit.GetData();

    for (size_t i = 0, size = resid.size(); i < size; ++i)
    {
        resid[i] = abs(resid[i] - f[i]);
    }

    plot.SubPlot(2, 1, 2)
    .AddPlot(ScatterPlot(exogenous, resid))
    .SetXLabel("X-Samples")
    .SetYLabel("Norm Residual")
    .SetLegend({ "Residual" })
    .SetYScale(SymLogScale())
    .SetXLimit(exogenous.Min(), exogenous.Max());
    plot.SetTightLayout();
}

PLOTLIB_INLINE std::vector< int32_t > EasyPlot::StackedBarPlot(::Plot &plot, const std::vector< PVec > &xValues,
                                                               const std::vector< PVec > &yValues)
{
    std::vector< PVec > yData;

    std::valarray< double > yValData(yValues[0].GetData().data(), yValues[0].GetSize());
    yData.emplace_back(PVec(yValues[0]));

    for (size_t i = 1, end = yValues.size(); i < end; ++i)
    {
        yValData += std::valarray< double >(yValues[i].GetData().data(), yValues[i].GetSize());
        yData.emplace_back(PVec(yValData));
    }

    std::vector< int32_t > hueData;

    for (int32_t i = (int32_t)yValues.size() - 1; i >= 0; --i)
    {
        plot.AddPlot(BarPlot(PVec(xValues[i]), yData[i]).UseColourCycler(plot.GetColourCycler())
                     .SetCapSize(0.5)
                     .SetErrorWidth(1.2));
        hueData.push_back(i);
    }

    return hueData;
}
