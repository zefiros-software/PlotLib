/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2017 Zefiros Software.
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

TEST(ResidualPlot, ResidualPlot)
{
    TestPlot< ResidualPlot >("ResidualPlot", []()
    {
        vec x = 2 + randn(100);
        vec y = 2 + 1.5 * x + 2 * randn(100);
        ResidualPlot f(x, y);
        f.Lowess(true)
        .Robust(true)
        .SetLabel("Resid")
        .SetLine(Line().SetLineWidth(5));
        return f;
    });
}

TEST(ResidualPlot, ResidualPlot2)
{
    TestPlot< ResidualPlot >("ResidualPlot2", []()
    {
        vec x = 2 + randn(100);
        vec y = 2 + 3 * square(x)  + 2 * randn(100);
        ResidualPlot f(x, y);
        f.SetOrder(1)
        .SetColour("g")
        .SetScatter(Scatter().SetSize(3.0))
        .SetLine(Line().SetLineWidth(5));
        return f;
    });
}