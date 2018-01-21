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

#include "plot/pvec.h"

#include "helper.h"

TEST(PVec, Construct)
{
    EXPECT_FALSE(std::is_constructible<PVec>::value);
}

TEST(PVec, FloatConstr)
{
    PVec v({ 0.1f, 2.0f, 8.0f });

    EXPECT_DOUBLE_EQ(0.1f, v.GetData()[0]);
    EXPECT_DOUBLE_EQ(2.0f, v.GetData()[1]);
    EXPECT_DOUBLE_EQ(8.0f, v.GetData()[2]);
    EXPECT_EQ(3, v.GetData().size());

    EXPECT_EQ(0, v.GetStrings().size());
}

TEST(PVec, DoubleConstr)
{
    PVec v({ 0.1, 2.0, 8.0 });

    EXPECT_DOUBLE_EQ(0.1, v.GetData()[0]);
    EXPECT_DOUBLE_EQ(2.0, v.GetData()[1]);
    EXPECT_DOUBLE_EQ(8.0, v.GetData()[2]);
    EXPECT_EQ(3, v.GetData().size());

    EXPECT_EQ(0, v.GetStrings().size());
}

TEST(PVec, IntConstr)
{
    PVec v({ 1, 2, 8 });

    EXPECT_DOUBLE_EQ(1, v.GetData()[0]);
    EXPECT_DOUBLE_EQ(2, v.GetData()[1]);
    EXPECT_DOUBLE_EQ(8, v.GetData()[2]);
    EXPECT_EQ(3, v.GetData().size());

    EXPECT_EQ(0, v.GetStrings().size());
}

TEST(PVec, IntStrConstr)
{
    PVec v({"1", "2", "8" });

    EXPECT_EQ("1", v.GetStrings()[0]);
    EXPECT_EQ("2", v.GetStrings()[1]);
    EXPECT_EQ("8", v.GetStrings()[2]);
    EXPECT_EQ(3, v.GetStrings().size());

    EXPECT_EQ(0, v.GetData().size());
}

TEST(PVec, Valarr)
{
    PVec v(std::valarray< int16_t > { 1, 2, 8 });

    EXPECT_DOUBLE_EQ(1, v.GetData()[0]);
    EXPECT_DOUBLE_EQ(2, v.GetData()[1]);
    EXPECT_DOUBLE_EQ(8, v.GetData()[2]);
    EXPECT_EQ(3, v.GetData().size());

    EXPECT_EQ(0, v.GetStrings().size());
}

TEST(PVec, Str)
{
    PVec v({ "1", "2", "8" });

    EXPECT_EQ("1", v.GetStrings()[0]);
    EXPECT_EQ("2", v.GetStrings()[1]);
    EXPECT_EQ("8", v.GetStrings()[2]);
    EXPECT_EQ(3, v.GetStrings().size());

    EXPECT_EQ(0, v.GetData().size());
}

TEST(PVec, Map)
{
    PVec v({ 1, 2, 8 }, { { 1, "1" }, { 2, "2" }, { 8, "8" } });

    EXPECT_EQ("1", v.GetStrings()[0]);
    EXPECT_EQ("2", v.GetStrings()[1]);
    EXPECT_EQ("8", v.GetStrings()[2]);
    EXPECT_EQ(3, v.GetStrings().size());

    EXPECT_EQ(0, v.GetData().size());
}

TEST(PVec, Linspace)
{
    PVec v(0, 2, 3);

    EXPECT_DOUBLE_EQ(0.0, v.GetData()[0]);
    EXPECT_DOUBLE_EQ(1.0, v.GetData()[1]);
    EXPECT_DOUBLE_EQ(2.0, v.GetData()[2]);
    EXPECT_EQ(3, v.GetData().size());

    EXPECT_EQ(0, v.GetStrings().size());
}

TEST(PVec, LinspaceFunc)
{
    PVec v(0, 2, 3, [](double x)
    {
        return x - 1;
    });

    EXPECT_DOUBLE_EQ(-1.0, v.GetData()[0]);
    EXPECT_DOUBLE_EQ(0.0, v.GetData()[1]);
    EXPECT_DOUBLE_EQ(1.0, v.GetData()[2]);
    EXPECT_EQ(3, v.GetData().size());

    EXPECT_EQ(0, v.GetStrings().size());
}

TEST(PVec, Func)
{
    PVec v({ 0, 2, 3 }, [](double x)
    {
        return x - 1;
    });

    EXPECT_DOUBLE_EQ(-1.0, v.GetData()[0]);
    EXPECT_DOUBLE_EQ(1.0, v.GetData()[1]);
    EXPECT_DOUBLE_EQ(2.0, v.GetData()[2]);
    EXPECT_EQ(3, v.GetData().size());

    EXPECT_EQ(0, v.GetStrings().size());
}

TEST(PVec, Arma)
{
    PVec v(arma::vec{ 0, 2, 3 });

    EXPECT_DOUBLE_EQ(0.0, v.GetData()[0]);
    EXPECT_DOUBLE_EQ(2.0, v.GetData()[1]);
    EXPECT_DOUBLE_EQ(3.0, v.GetData()[2]);
    EXPECT_EQ(3, v.GetData().size());

    EXPECT_EQ(0, v.GetStrings().size());
}

TEST(PVec, GetSizeDouble)
{
    PVec v({ 0, 2, 3, 4 });
    EXPECT_EQ(4, v.GetSize());
}

TEST(PVec, GetSizeStr)
{
    PVec v({ "0", "2", "3", "4" });
    EXPECT_EQ(4, v.GetSize());
}

TEST(PVec, Min)
{
    PVec v({ 0, 2, 3, 4, -2 });
    EXPECT_DOUBLE_EQ(-2.0, v.Min());
}

TEST(PVec, Max)
{
    PVec v({ 0, 2, 3, 4, -2 });
    EXPECT_DOUBLE_EQ(4.0, v.Max());
}