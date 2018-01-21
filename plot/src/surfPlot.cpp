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

#include "plot/surfPlot.h"
#include "plot/properties/heatMapProperties.h"

PLOTLIB_INLINE SurfPlot::SurfPlot(const PVec &x, const std::vector<PVec> &y, const std::vector<PVec> &z)
    : SurfPlot()
{
    mStream << "X=[";

    for (auto &Y : y)
    {
        mStream << this->ToArray(x) << ",";
    }

    mStream << "]\n"
            << "Y=[";

    for (auto &Y : y)
    {
        mStream << this->ToArray(Y) << ",";
    }

    mStream << "]\n"
            << "Z=[";


    for (auto &Z : z)
    {
        mStream << this->ToArray(Z) << ",";
    }

    mStream << "]\n"
            << "surf = ax.plot_surface( X, Y, Z";
}

PLOTLIB_INLINE SurfPlot::SurfPlot(const PVec &x, const PVec &y, const std::vector<PVec> &z)
    : SurfPlot()
{
    mStream << "X=[";

    for (auto &Z : z)
    {
        mStream << this->ToArray(x) << ",";
    }

    mStream << "]\n"
            << "Y=[";

    for (auto &Y : y.GetData())
    {
        mStream << this->ToArray(std::vector<double>(x.GetSize(), Y)) << ",";
    }

    mStream << "]\n"
            << "Z=[";


    for (auto &Z : z)
    {
        mStream << this->ToArray(Z) << ",";
    }

    mStream << "]\n"
            << "surf = ax.plot_surface( X, Y, Z";
}

PLOTLIB_INLINE SurfPlot::SurfPlot(const PMat &x, const PMat &y, const PMat &z)
    : SurfPlot()
{
    mStream << "X=" << this->ToArray(x) << "\n"
            << "Y=" << this->ToArray(y) << "\n"
            << "Z=" << this->ToArray(z) << "\n"
            << "surf = ax.plot_surface( X, Y, Z";
}

PLOTLIB_INLINE std::string SurfPlot::ToString()
{
    if (!mHasColourMap)
    {
        SetColourMap(ColourMap::Diverging::Coolwarm);
    }

    return mStream.str() +
           ", antialiased = True )\n" +
           (mShowColourBar ? "fig.colorbar( surf, shrink = 0.5, aspect = 5 )" : "");
}

PLOTLIB_INLINE SurfPlot &SurfPlot::SetColourMap(const ColourMap &pallet)
{
    this->AddArgument("cmap", pallet.ToString());
    mHasColourMap = true;
    return *this;
}

PLOTLIB_INLINE SurfPlot &SurfPlot::ColourBar(bool bar)
{
    mShowColourBar = bar;
    return *this;
}


PLOTLIB_INLINE SurfPlot::SurfPlot()
    : mHasColourMap(false),
      mShowColourBar(false)
{
    mStream << "\nfrom mpl_toolkits.mplot3d import Axes3D\n"
            << "from matplotlib import cm\n\n"
            << "fig = plt.figure()\n"
            << "ax = fig.gca(projection='3d')\n";
}
