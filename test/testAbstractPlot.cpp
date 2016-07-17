/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Koen Visscher, Paul Visscher and individual contributors.
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

TEST( AbstractPlot, Construct )
{
    EXPECT_FALSE( std::is_constructible<AbstractPlot>::value );
}

TEST( AbstractPlot, GetBool )
{
    EXPECT_EQ( "True", AbstractPlot::GetBool( true ) );
    EXPECT_EQ( "False", AbstractPlot::GetBool( false ) );
}

TEST( AbstractPlot, ToArray_Vec )
{
    EXPECT_EQ( "[1, 2, 3]", AbstractPlot::ToArray( Vec{ 1, 2, 3 } ) );
}

TEST( AbstractPlot, ToArray_Vec2 )
{
    EXPECT_EQ( "[1, 2, 3, 4]", AbstractPlot::ToArray( Vec{ 1, 2, 3, 4 } ) );
}


TEST( AbstractPlot, ToArray_IntVec )
{
    EXPECT_EQ( "[1, 2, 3, 4]", AbstractPlot::ToArray( std::vector<uint32_t> { 1, 2, 3, 4 } ) );
}

TEST( AbstractPlot, ToArray_VecStr )
{
    EXPECT_EQ( "['1', '2', '3']", AbstractPlot::ToArray( Vec{ "1", "2", "3" } ) );
}

TEST( AbstractPlot, ToArray_VecBool )
{
    EXPECT_EQ( "[1, 1, 0]", AbstractPlot::ToArray( std::vector<bool> { true, true, false } ) );
}

TEST( AbstractPlot, ToArray_VecEmptyStr )
{
    EXPECT_EQ( "[]", AbstractPlot::ToArray( Vec( std::vector<std::string >() ) ) );
}

TEST( AbstractPlot, ToArray_VecEmpty )
{
    EXPECT_EQ( "[]", AbstractPlot::ToArray( Vec( std::vector< double >() ) ) );
}

TEST( AbstractPlot, ToArray_Mat )
{
    EXPECT_EQ( "[[1, 2],[3, 4]]",
    AbstractPlot::ToArray( ::Mat{ { 1, 2 }, { 3, 4 } } ) );
}

TEST( AbstractPlot, ToArray_Mat2 )
{
    EXPECT_EQ( "[[1, 2, 3],[4, 5, 6]]",
    AbstractPlot::ToArray( ::Mat{ { 1, 2, 3 }, { 4, 5, 6 } } ) );
}

TEST( AbstractPlot, ToArray_MatStr )
{
    ::Mat m( { { "1", "2" }, { "3", "4" } } );
    EXPECT_EQ( "[['1', '2'],['3', '4']]", AbstractPlot::ToArray( m ) );
}

TEST( AbstractPlot, ToArray_Mat_Empty )
{
    EXPECT_EQ( "[]", AbstractPlot::ToArray( ::Mat( std::vector< std::vector< double > >() ) ) );
}

TEST( AbstractPlot, ToArray_MatStr_Empty )
{
    EXPECT_EQ( "[]", AbstractPlot::ToArray( ::Mat( std::vector< std::vector< std::string > >() ) ) );
}