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

#include "helper.h"

#pragma once
#ifndef __TESTMAT_H__
#define __TESTMAT_H__

TEST( Mat, ConstructVec )
{
    ::Mat m( std::vector< std::vector< double > > { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } );
    EXPECT_EQ( 3, m.GetData().size() );

    EXPECT_EQ( 3, m.GetData()[0].size() );
    EXPECT_DOUBLE_EQ( 1, m.GetData()[0][0] );
    EXPECT_DOUBLE_EQ( 2, m.GetData()[0][1] );
    EXPECT_DOUBLE_EQ( 3, m.GetData()[0][2] );

    EXPECT_EQ( 3, m.GetData()[1].size() );
    EXPECT_DOUBLE_EQ( 4, m.GetData()[1][0] );
    EXPECT_DOUBLE_EQ( 5, m.GetData()[1][1] );
    EXPECT_DOUBLE_EQ( 6, m.GetData()[1][2] );

    EXPECT_EQ( 3, m.GetData()[2].size() );
    EXPECT_DOUBLE_EQ( 7, m.GetData()[2][0] );
    EXPECT_DOUBLE_EQ( 8, m.GetData()[2][1] );
    EXPECT_DOUBLE_EQ( 9, m.GetData()[2][2] );


    EXPECT_EQ( 0, m.GetStrings().size() );

    EXPECT_EQ( m.GetData().size(), m.GetSize() );

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ( dim, m.GetDimension() );
}

TEST( Mat, ConstructInit )
{
    ::Mat m( { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } );
    EXPECT_EQ( 3, m.GetData().size() );

    EXPECT_EQ( 3, m.GetData()[0].size() );
    EXPECT_DOUBLE_EQ( 1, m.GetData()[0][0] );
    EXPECT_DOUBLE_EQ( 2, m.GetData()[0][1] );
    EXPECT_DOUBLE_EQ( 3, m.GetData()[0][2] );

    EXPECT_EQ( 3, m.GetData()[1].size() );
    EXPECT_DOUBLE_EQ( 4, m.GetData()[1][0] );
    EXPECT_DOUBLE_EQ( 5, m.GetData()[1][1] );
    EXPECT_DOUBLE_EQ( 6, m.GetData()[1][2] );

    EXPECT_EQ( 3, m.GetData()[2].size() );
    EXPECT_DOUBLE_EQ( 7, m.GetData()[2][0] );
    EXPECT_DOUBLE_EQ( 8, m.GetData()[2][1] );
    EXPECT_DOUBLE_EQ( 9, m.GetData()[2][2] );


    EXPECT_EQ( 0, m.GetStrings().size() );

    EXPECT_EQ( m.GetData().size(), m.GetSize() );

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ( dim, m.GetDimension() );
}

TEST( Mat, ConstructArma )
{
    ::Mat m( mat{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } } );
    EXPECT_EQ( 3, m.GetData().size() );

    EXPECT_EQ( 3, m.GetData()[0].size() );
    EXPECT_DOUBLE_EQ( 1, m.GetData()[0][0] );
    EXPECT_DOUBLE_EQ( 2, m.GetData()[0][1] );
    EXPECT_DOUBLE_EQ( 3, m.GetData()[0][2] );

    EXPECT_EQ( 3, m.GetData()[1].size() );
    EXPECT_DOUBLE_EQ( 4, m.GetData()[1][0] );
    EXPECT_DOUBLE_EQ( 5, m.GetData()[1][1] );
    EXPECT_DOUBLE_EQ( 6, m.GetData()[1][2] );

    EXPECT_EQ( 3, m.GetData()[2].size() );
    EXPECT_DOUBLE_EQ( 7, m.GetData()[2][0] );
    EXPECT_DOUBLE_EQ( 8, m.GetData()[2][1] );
    EXPECT_DOUBLE_EQ( 9, m.GetData()[2][2] );


    EXPECT_EQ( 0, m.GetStrings().size() );

    EXPECT_EQ( m.GetData().size(), m.GetSize() );

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ( dim, m.GetDimension() );
}

TEST( Mat, ConstructArma2 )
{
    ::Mat m( mat{ { 1, 2, 3 }, { 4, 5, 6 } } );
    EXPECT_EQ( 2, m.GetData().size() );

    EXPECT_EQ( 3, m.GetData()[0].size() );
    EXPECT_DOUBLE_EQ( 1, m.GetData()[0][0] );
    EXPECT_DOUBLE_EQ( 2, m.GetData()[0][1] );
    EXPECT_DOUBLE_EQ( 3, m.GetData()[0][2] );

    EXPECT_EQ( 3, m.GetData()[1].size() );
    EXPECT_DOUBLE_EQ( 4, m.GetData()[1][0] );
    EXPECT_DOUBLE_EQ( 5, m.GetData()[1][1] );
}

TEST( Mat, ConstructStr )
{
    ::Mat m( { { "1", "2", "3" }, { "4", "5", "6" }, { "7", "8", "9" } } );
    EXPECT_EQ( 3, m.GetStrings().size() );

    EXPECT_EQ( 3, m.GetStrings()[0].size() );
    EXPECT_EQ( "1", m.GetStrings()[0][0] );
    EXPECT_EQ( "2", m.GetStrings()[0][1] );
    EXPECT_EQ( "3", m.GetStrings()[0][2] );

    EXPECT_EQ( 3, m.GetStrings()[1].size() );
    EXPECT_EQ( "4", m.GetStrings()[1][0] );
    EXPECT_EQ( "5", m.GetStrings()[1][1] );
    EXPECT_EQ( "6", m.GetStrings()[1][2] );

    EXPECT_EQ( 3, m.GetStrings()[2].size() );
    EXPECT_EQ( "7", m.GetStrings()[2][0] );
    EXPECT_EQ( "8", m.GetStrings()[2][1] );
    EXPECT_EQ( "9", m.GetStrings()[2][2] );


    EXPECT_EQ( 0, m.GetData().size() );

    EXPECT_EQ( m.GetStrings().size(), m.GetSize() );

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ( dim, m.GetDimension() );
}

TEST( Mat, ConstructMap )
{
    ::Mat m( { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } },
    { { 1, "1" }, { 2, "2" }, { 3, "3" } } );
    EXPECT_EQ( 3, m.GetStrings().size() );

    EXPECT_EQ( 3, m.GetStrings()[0].size() );
    EXPECT_EQ( "1", m.GetStrings()[0][0] );
    EXPECT_EQ( "2", m.GetStrings()[0][1] );
    EXPECT_EQ( "3", m.GetStrings()[0][2] );

    EXPECT_EQ( 3, m.GetStrings()[1].size() );
    EXPECT_EQ( "1", m.GetStrings()[1][0] );
    EXPECT_EQ( "2", m.GetStrings()[1][1] );
    EXPECT_EQ( "3", m.GetStrings()[1][2] );

    EXPECT_EQ( 3, m.GetStrings()[2].size() );
    EXPECT_EQ( "1", m.GetStrings()[2][0] );
    EXPECT_EQ( "2", m.GetStrings()[2][1] );
    EXPECT_EQ( "3", m.GetStrings()[2][2] );

    EXPECT_EQ( 0, m.GetData().size() );

    EXPECT_EQ( m.GetStrings().size(), m.GetSize() );

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ( dim, m.GetDimension() );
}

TEST( Mat, ConstructVecCheckDim )
{
    EXPECT_DEATH( ::Mat m( std::vector< std::vector< double > > { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8 } } ),
    "Assertion failed: vec.size\\(\\) == size" );
}

TEST( Mat, ConstructInitCheckDim )
{
    EXPECT_DEATH( ::Mat m( { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8 } } ),
    "Assertion failed: vec.size\\(\\) == size" );
}

TEST( Mat, ConstructStrCheckDim )
{
    EXPECT_DEATH( ::Mat m( { { "1", "2", "3" }, { "4", "5", "6" }, { "7", "8" } } ),
    "Assertion failed: vec.size\\(\\) == size" );
}

TEST( Mat, ConstructMapCheckDim )
{
    EXPECT_DEATH( ::Mat m( { {1, 2, 3}, {1, 2, 3}, {1, 2} },
    { {1, "1"}, {2, "2"}, {3, "3"} } ),
    "Assertion failed: vec.size\\(\\) == size" );
}

#endif