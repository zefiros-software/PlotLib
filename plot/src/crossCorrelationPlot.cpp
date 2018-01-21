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

#include "plot/crossCorrelationPlot.h"

static const char *const __PlotLibCrossCorrelationPlotDetrend[] =
{
    "detrend_none",
    "detrend_mean",
    "detrend_linear"
};

PLOTLIB_INLINE CrossCorrelationPlot::CrossCorrelationPlot(const PVec &x, const PVec &y)
    : mDefaultDetrend(Detrend::Mean)   // statistics default
{
    mStream << "plt.xcorr(" << this->ToArray(x) << "," << this->ToArray(y);
}

PLOTLIB_INLINE std::string CrossCorrelationPlot::ToString()
{
    this->AddArgument("detrend", __PlotLibCrossCorrelationPlotDetrend[static_cast<size_t>(mDefaultDetrend)]);
    return mStream.str() + " )";
}

PLOTLIB_INLINE CrossCorrelationPlot &CrossCorrelationPlot::Hold(bool hold)
{
    this->AddArgument("hold", GetBool(hold));
    return *this;
}

PLOTLIB_INLINE CrossCorrelationPlot &CrossCorrelationPlot::Normed(bool normed)
{
    this->AddArgument("normed", GetBool(normed));
    return *this;
}

PLOTLIB_INLINE CrossCorrelationPlot &CrossCorrelationPlot::VLines(bool vlines)
{
    this->AddArgument("usevlines", GetBool(vlines));
    return *this;
}

PLOTLIB_INLINE CrossCorrelationPlot &CrossCorrelationPlot::SetMaxLags(size_t maxlags)
{
    this->AddArgument("maxlags", maxlags);
    return *this;
}

PLOTLIB_INLINE CrossCorrelationPlot &CrossCorrelationPlot::SetDetrend(Detrend detrend)
{
    mDefaultDetrend = detrend;
    return *this;
}
