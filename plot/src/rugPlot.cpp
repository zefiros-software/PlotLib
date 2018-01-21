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

#include "plot/rugPlot.h"

PLOTLIB_INLINE std::string RUGPlot::ToString()
{
    return mStream.str() + ")";
}

PLOTLIB_INLINE RUGPlot::RUGPlot(const PVec &a)
{
    AbstractPlot::mStream << "sns.rugplot(" << this->ToArray(a);
}

PLOTLIB_INLINE RUGPlot &RUGPlot::SetHeight(double height)
{
    this->AddArgument("height", height);
    return *this;
}

PLOTLIB_INLINE RUGPlot &RUGPlot::SetAxis(Axis axis)
{
    this->AddArgument("axis", this->GetString(axis == Axis::X ? "X" : "Y"));
    return *this;
}

PLOTLIB_INLINE RUGPlot &RUGPlot::SetLine(VLine &vline)
{
    mStream << ",**" << vline.ToString();
    return *this;
}

PLOTLIB_INLINE RUGPlot &RUGPlot::SetLine(HLine &hline)
{
    mStream << ",**" << hline.ToString();
    return *this;
}
