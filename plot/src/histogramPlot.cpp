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

#include "plot/histogramPlot.h"

PLOTLIB_INLINE HistogramPlot::HistogramPlot(const PVec &vec)
{
    mStream << "plt.hist(" << this->ToArray(vec);
}

PLOTLIB_INLINE std::string HistogramPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetBins(const PVec &bins)
{
    mStream << ", bins=" << this->ToArray(bins);
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetBins(size_t value)
{
    mStream << ", bins=" << value;
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetRange(double min, double max)
{
    mStream << ", range=(" << min << "," << max << ")";
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetNormed(bool normed)
{
    mStream << ", normed=" << GetBool(normed);
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetWeights(const PVec &weights)
{
    mStream << ", weights=" << this->ToArray(weights);
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetCumulative(bool cumulative)
{
    mStream << ", normed=" << GetBool(cumulative);
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetBottom(const PVec &bottom)
{
    mStream << ", bottom=" << this->ToArray(bottom);
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetBottom(double bottom)
{
    mStream << ", bottom=" << bottom;
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetType(Type type)
{
    mStream << ", histtype =" << GetType(type);
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetAllignment(Alignment align)
{
    mStream << ", histtype =" << GetAlignment(align);
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetOrientation(Orientation orientation)
{
    mStream << ", orientation  = " << (orientation == Orientation::Horizontal ? "'horizontal'" : "'vertical'");
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetRelativeWidth(double rwidth)
{
    mStream << ", rwidth=" << rwidth;
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetLogarithmic(bool log)
{
    mStream << ", log=" << GetBool(log);
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetColour(const std::string &colour)
{
    mStream << ", color = '" << colour << "'";
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetLabel(const std::string &label)
{
    mStream << ", label='" << label << "'";
    return *this;
}

PLOTLIB_INLINE HistogramPlot &HistogramPlot::SetStacked(bool stacked)
{
    mStream << ", stacked=" << GetBool(stacked);
    return *this;
}

PLOTLIB_INLINE std::string HistogramPlot::GetType(Type type)
{
    switch (type)
    {
    case Type::Bar:
        return "'bar'";

    case Type::BarStacked:
        return "'barstacked'";

    case Type::Step:
        return "'step'";

    case Type::StepFilled:
        return "'stepfilled'";
    }

    return "''";
}

PLOTLIB_INLINE std::string HistogramPlot::GetAlignment(Alignment align)
{
    switch (align)
    {
    case Alignment::Left:
        return "'left'";

    case Alignment::Middle:
        return "'mid'";

    case Alignment::Right:
        return "'right'";
    }

    return "''";
}
