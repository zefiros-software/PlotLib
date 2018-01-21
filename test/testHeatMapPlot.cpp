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

TEST(HeatMapPlot, HeatMapPlot)
{
    TestPlot< HeatMapPlot >("HeatMapPlot", []()
    {
        mat randMat = randu(100, 100);
        HeatMapPlot f(randMat);
        f.SetYTickLabel(10)
        .SetXTickLabel(10);
        return f;
    });
}

TEST(HeatMapPlot, HeatMapPlot_Constr2)
{
    TestPlot< HeatMapPlot >("HeatMapPlot_Constr2", []()
    {
        vec xVec = randn(200);
        vec yVec = randn(200);
        HeatMapPlot f(xVec, yVec, 5);
        f.Robust(true);
        return f;
    });
}

TEST(HeatMapPlot, HeatMapPlot_Constr3)
{
    TestPlot< HeatMapPlot >("HeatMapPlot_Constr3", []()
    {
        vec xVec = randn(200) * 1.5;
        vec yVec = randn(200);
        HeatMapPlot f(xVec, yVec, { 5, 6 });
        f.XTickLabel(false)
        .YTickLabel(false)
        .ColourBar(false);
        return f;
    });
}

TEST(HeatMapPlot, HeatMapPlot_Constr4)
{
    TestPlot< HeatMapPlot >("HeatMapPlot_Constr4", []()
    {
        vec xVec = randn(200) * 1.5;
        vec yVec = randn(200);
        HeatMapPlot f(xVec, yVec, 3, { -6, 6 }, { -3, 3 });
        f.Square(true)
        .Annotate(true)
        .SetFormat("f");
        return f;
    });
}


TEST(HeatMapPlot, HeatMapPlot_Constr5)
{
    TestPlot< HeatMapPlot >("HeatMapPlot_Constr5", []()
    {
        vec xVec = randn(200) * 1.5;
        vec yVec = randn(200);
        HeatMapPlot f(xVec, yVec, { 10, 5 }, { -6, 6 }, { -3, 3 });
        f.SetCentre(16)
        .SetMaxValue(32)
        .SetMinValue(0);
        return f;
    });
}

TEST(HeatMapPlot, HeatMapPlot_Small)
{
    TestPlot< HeatMapPlot >("HeatMapPlot_Small", []()
    {
        mat randMat = randu(3, 3);
        HeatMapPlot f(randMat);
        f.SetXTickLabels({ 1, 2, 3 })
        .SetYTickLabels({ 4, 5, 6 });
        return f;
    });
}

TEST(HeatMapPlot, HeatMapPlot_Mask)
{
    TestPlot< HeatMapPlot >("HeatMapPlot_Mask", []()
    {
        mat randMat = randu(2, 3);
        HeatMapPlot f(randMat);
        f.SetMask({ false, true, false })
        .SetAnnotate({{"first", "x", "second"}, {"third", "x", "fourth"}})
        .SetFormat("s");
        return f;
    });
}


TEST(HeatMapPlot, HeatMapPlot_Mask2)
{
    TestPlot< HeatMapPlot >("HeatMapPlot_Mask2", []()
    {
        mat randMat = randu(2, 2);
        HeatMapPlot f(randMat);
        f.SetMask({ {true, false}, {true, true} })
        .SetLineWidths(2)
        .SetLineColour("r")
        .SetColourMap(Palette::Diverging::PRGn);
        return f;
    });
}
