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

#include "plot/plotting.h"

#include "helper.h"

TEST(SurfPlot, SurfPlot)
{
    TestPlot< SurfPlot >("SurfPlot", []()
    {
        vec X = linspace(-5.0, 5.0, 40);
        vec Y = linspace(-5.0, 5.0, 40);

        std::vector<PVec> y;
        std::vector<PVec> z;


        for (size_t i = 0, size = X.size(); i < size; ++i)
        {
            vec yRow(size, fill::ones);
            yRow *= Y[i];
            double ySq = Y[i] * Y[i];
            y.push_back(yRow);
            z.push_back((vec)arma::sin(arma::sqrt(X % X + ySq)));
        }

        SurfPlot f(X, y, z);

        return f.ColourBar(true);
    });
}

TEST(SurfPlot, SurfPlot2)
{
    TestPlot< SurfPlot >("SurfPlot2", []()
    {
        vec X = linspace(-5.0, 5.0, 40);
        vec Y = linspace(-5.0, 5.0, 40);

        std::vector<PVec> z;


        for (size_t i = 0, size = X.size(); i < size; ++i)
        {
            double ySq = Y[i] * Y[i];
            z.push_back((vec)arma::sin(arma::sqrt(X % X + ySq)));
        }

        SurfPlot f(X, Y, z);

        return f;
    });
}

TEST(SurfPlot, SurfPlot3)
{
    TestPlot< SurfPlot >("SurfPlot3", []()
    {
        vec X = linspace(-5.0, 5.0, 40);
        vec Y = linspace(-5.0, 5.0, 40);

        std::vector<PVec> x;
        std::vector<PVec> y;
        std::vector<PVec> z;


        for (size_t i = 0, size = X.size(); i < size; ++i)
        {
            vec yRow(size, fill::ones);
            yRow *= Y[i];
            double ySq = Y[i] * Y[i];
            x.push_back(X);
            y.push_back(yRow);
            z.push_back((vec)arma::sin(arma::sqrt(X % X + ySq)));
        }

        PMat xMat(x);
        PMat yMat(y);
        PMat zMat(z);

        SurfPlot f(xMat, yMat, zMat);

        return f.ColourBar(true);
    });
}
