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


TEST(ArrowPlot, ArrowPlot)
{
    TestPlot< ArrowPlot >("ArrowPlot", []()
    {
        ArrowPlot f(0, 0.1, 1, 0.5);
        return f;
    });
}


TEST(ArrowPlot, SetWidth)
{
    TestPlot< ArrowPlot >("ArrowPlot_SetWidth", []()
    {
        ArrowPlot f(0, 0.1, 0.7, 0.5);
        f.SetWidth(0.009);
        return f;
    });
}

TEST(ArrowPlot, LengthIncludesHead)
{
    TestPlot< ArrowPlot >("ArrowPlot_LengthIncludesHead", []()
    {
        ArrowPlot f(0, 0.1, 1, 0.5);
        f.LengthIncludesHead(true);
        return f;
    });
}

TEST(ArrowPlot, SetHead)
{
    TestPlot< ArrowPlot >("ArrowPlot_SetHead", []()
    {
        ArrowPlot f(0, 0.1, 0.8, 0.5);
        f.LengthIncludesHead(true)
        .SetHeadWidth(0.05)
        .SetHeadLength(0.05)
        .SetOverhang(-1);
        return f;
    });
}
TEST(ArrowPlot, HeadStartsAtZero)
{
    TestPlot< ArrowPlot >("ArrowPlot_HeadStartsAtZero", []()
    {
        ArrowPlot f(0, 0.1, 0.8, 0.5);
        f.SetShape(ArrowPlot::Shape::Left)
        .SetHeadWidth(0.08)
        .HeadStartsAtZero(true);
        return f;
    });
}