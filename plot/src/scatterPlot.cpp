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

#include "plot/scatterPlot.h"

PLOTLIB_INLINE ScatterPlot::ScatterPlot(const PVec &exogenous, const PVec &endogenous)
{
    mStream << "plt.scatter(" << this->ToArray(exogenous) << "," << this->ToArray(endogenous);
}

PLOTLIB_INLINE std::string ScatterPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetAlpha(double alpha)
{
    this->AddArgument("alpha", alpha);
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetScalar(double scalar)
{
    this->AddArgument("s", scalar);
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetScalar(const PVec &scalar)
{
    this->AddArgument("s", this->ToArray(scalar));
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetColour(const std::string &colour)
{
    this->AddArgument("cmap", this->GetString(colour));
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetEdgeColour(const std::string &colour)
{
    this->AddArgument("edgecolors", this->GetString(colour));
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetMarker(const std::string &marker)
{
    this->AddArgument("marker", this->GetString(marker));
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetVMin(double vmin)
{
    this->AddArgument("vmin", vmin);
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetVMax(double vmax)
{
    this->AddArgument("vmax", vmax);
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetLineWidth(const PVec &widths)
{
    this->AddArgument("linewidths", this->ToArray(widths));
    return *this;
}

PLOTLIB_INLINE ScatterPlot &ScatterPlot::SetLineWidth(double lineWidth)
{
    this->AddArgument("linewidths", lineWidth);
    return *this;
}
