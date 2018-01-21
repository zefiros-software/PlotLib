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

#include "plot/heatMapPlot.h"

PLOTLIB_INLINE HeatMapPlot::HeatMapPlot(const PVec &x, const PVec &y, size_t bins /*= 50 */)
{
    mStream << "heatmap, yedges, xedges = np.histogram2d( "
            << this->ToArray(x) << ", " << this->ToArray(y) << ", bins=" << bins << ")\n";
    mStream << "sns.heatmap(heatmap";

    mXTickLabels = "xedges";
    mYTickLabels = "yedges";
}

PLOTLIB_INLINE HeatMapPlot::HeatMapPlot(const PVec &x, const PVec &y, std::pair< size_t, size_t > bins)
{
    mStream << "heatmap, yedges, xedges = np.histogram2d( "
            << this->ToArray(x) << ", " << this->ToArray(y) << ", bins=(" << bins.first << "," << bins.second << "))\n";
    mStream << "sns.heatmap(heatmap";

    mXTickLabels = "xedges";
    mYTickLabels = "yedges";
}

PLOTLIB_INLINE HeatMapPlot::HeatMapPlot(const PVec &x, const PVec &y, size_t bins, std::pair< double, double > xextent,
                                        std::pair<double, double> yextent)
{
    mStream << "heatmap, yedges, xedges = np.histogram2d( "
            << this->ToArray(x) << ", " << this->ToArray(y) << ", bins=" << bins << ","
            << "range=[[" << xextent.first << "," << yextent.second << "],[" << yextent.first << "," << yextent.second << "]])\n";
    mStream << "sns.heatmap(heatmap";

    mXTickLabels = "xedges";
    mYTickLabels = "yedges";
}

PLOTLIB_INLINE HeatMapPlot::HeatMapPlot(const PVec &x, const PVec &y, std::pair< size_t, size_t > bins,
                                        std::pair< double, double > xextent, std::pair<double, double> yextent)
{
    mStream << "heatmap, yedges, xedges = np.histogram2d( "
            << this->ToArray(x) << ", " << this->ToArray(y) << ", bins=(" << bins.first << "," << bins.second << "), "
            << "range=[[" << xextent.first << "," << xextent.second << "],[" << yextent.first << "," << yextent.second <<  "]])\n";
    mStream << "sns.heatmap(heatmap";

    mXTickLabels = "xedges";
    mYTickLabels = "yedges";
}

PLOTLIB_INLINE HeatMapPlot::HeatMapPlot(const PMat &map)
{
    mStream << "sns.heatmap(" << this->ToArray(map);
}

PLOTLIB_INLINE std::string HeatMapPlot::ToString()
{
    if (!mXTickLabels.empty())
    {
        this->AddArgument("xticklabels", mXTickLabels);
    }

    if (!mYTickLabels.empty())
    {
        this->AddArgument("yticklabels", mYTickLabels);
    }

    return mStream.str() + " )";
}

