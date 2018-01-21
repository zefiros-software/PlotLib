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

#include "plot/pointPlot.h"
#include "plot/palette.h"

#include <assert.h>

PLOTLIB_INLINE PointPlot::PointPlot(const std::vector< std::pair< PVec, PVec >> &data,
                                    const std::vector< std::string > &hue)
{
    mStream << "x = []\ny = []\nh = []\n";
    mStream << "x = x ";

    for (auto &tup : data)
    {
        assert(tup.first.GetSize() == tup.second.GetSize());
        mStream << "+ " << this->ToArray(tup.first);
    }

    mStream << "\ny = y ";

    for (auto &tup : data)
    {
        mStream << "+ " << this->ToArray(tup.second);
    }

    size_t i = 0;

    mStream << "\nh = h ";

    for (auto &tup : data)
    {
        mStream << "+ " << this->ToArray(std::vector< std::string >(tup.first.GetSize(), hue[i++]));
    }

    mStream << "\nsns.pointplot( x, y, h";
}

PLOTLIB_INLINE PointPlot::PointPlot(const std::vector< std::pair< PVec, PVec >> &data)
{
    mStream << "x = []\ny = []\n";
    mStream << "x = x ";

    for (auto &tup : data)
    {
        mStream << "+ " << this->ToArray(tup.first);
    }

    mStream << "\ny = y ";

    for (auto &tup : data)
    {
        mStream << "+ " << this->ToArray(tup.second);
    }

    mStream << "\nsns.pointplot( x, y";
}

PLOTLIB_INLINE PointPlot::PointPlot(const PVec &x, const PVec &y)
{
    mStream << "sns.pointplot(" << this->ToArray(x) << "," << this->ToArray(y);
}

PLOTLIB_INLINE std::string PointPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE PointPlot &PointPlot::SetOrder(const PVec &order)
{
    mStream << ", order=" << this->ToArray(order);
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetHueOrder(const std::vector< std::string > &order)
{
    mStream << ", hue_order=" << this->ToArray(order);
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetConfidenceInterval(double ci)
{
    mStream << ", ci=" << ci;
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetNBoot(size_t bootstrap)
{
    mStream << ", n_boot=" << bootstrap;
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetMarkers(const std::vector< std::string > &markers)
{
    mStream << ", markers=" << this->ToArray(markers);
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetLineStyles(const std::vector< std::string > &styles)
{
    mStream << ", linestyles=" << this->ToArray(styles);
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetDodge(bool dodge)
{
    mStream << ", dodge=" << GetBool(dodge);
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetDodge(double dodge)
{
    mStream << ", dodge=" << dodge;
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetJoin(bool join)
{
    mStream << ", dodge=" << GetBool(join);
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetScale(double scale)
{
    mStream << ", scale=" << scale;
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetOrientation(Orientation orientation)
{
    mStream << ", orient=" << (orientation == Orientation::Horizontal ? "'h'" : "'v'");
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetColour(const std::string &colour)
{
    mStream << ", color='" << colour << "'";
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetColourMap(const Palette &pallet)
{
    mStream << ", palette =" << pallet.ToString();
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetErrorWidth(double width)
{
    mStream << ", errwidth = " << width;
    return *this;
}

PLOTLIB_INLINE PointPlot &PointPlot::SetCapSize(double size)
{
    mStream << ", capsize = " << size;
    return *this;
}
