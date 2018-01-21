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


TEST(AnnotatePlot, AnnotatePlot)
{
    TestPlot< AnnotatePlot >("AnnotatePlot", []()
    {
        AnnotatePlot f("Hello World!", 0.5, 0.5);
        return f;
    });
}


TEST(AnnotatePlot, Construct)
{
    AnnotatePlot("", 0, 0);
}

TEST(AnnotatePlot, ToString)
{
    EXPECT_EQ("plt.annotate( s='Hello World', xy=(0.5,0.5) )", AnnotatePlot("Hello World", 0.5, 0.5).ToString());
}


TEST(AnnotatePlot, SetXYText)
{
    TestPlot< AnnotatePlot >("AnnotatePlot_SetXYText", []()
    {
        AnnotatePlot f("Hello World!", 0.0, 0.0);
        f.SetXYText(0.4, 0.4)
        .SetArrowProps(FancyArrow().SetArrowStyle("<|-|>").SetLineWidth(2));
        return f;
    });
}


TEST(AnnotatePlot, SetType)
{
    TestPlot< AnnotatePlot >("AnnotatePlot_SetType", []()
    {
        AnnotatePlot f("Hello World!", 0.0, 0.0);
        f.SetXYText(200, 50)
        .SetArrowProps(YArrow().SetWidth(10))
        .SetXYCoordinates(AnnotatePlot::Type::AxesPixels)
        .SetTextCoordinates(AnnotatePlot::Type::AxesPixels);
        return f;
    });
}