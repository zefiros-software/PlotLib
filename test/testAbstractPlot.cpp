#include "plot/abstractPlot.h"

#include "helper.h"

TEST( PX( AbstractPlot ), Construct )
{
    EXPECT_FALSE( std::is_constructible<AbstractPlot>::value );
}

TEST( PX( AbstractPlot ), GetBool )
{
    EXPECT_EQ( "True", AbstractPlot::GetBool( true ) );
    EXPECT_EQ( "False", AbstractPlot::GetBool( false ) );
}

TEST( PX( AbstractPlot ), ToArray_Vec )
{
    EXPECT_EQ( "[1, 2, 3]", AbstractPlot::ToArray( Vec{ 1, 2, 3 } ) );
}

TEST( PX( AbstractPlot ), ToArray_Vec2 )
{
    EXPECT_EQ( "[1, 2, 3, 4]", AbstractPlot::ToArray( Vec{ 1, 2, 3, 4 } ) );
}

TEST( PX( AbstractPlot ), ToArray_VecStr )
{
    EXPECT_EQ( "['1', '2', '3']", AbstractPlot::ToArray( Vec{ "1", "2", "3" } ) );
}

TEST( PX( AbstractPlot ), ToArray_VecEmptyStr )
{
    EXPECT_EQ( "[]", AbstractPlot::ToArray( Vec( std::vector<std::string >() ) ) );
}

TEST( PX( AbstractPlot ), ToArray_VecEmpty )
{
    EXPECT_EQ( "[]", AbstractPlot::ToArray( Vec( std::vector< double >() ) ) );
}

TEST( PX( AbstractPlot ), ToArray_Mat )
{
    EXPECT_EQ( "[[1, 2],[3, 4]]",
    AbstractPlot::ToArray( ::Mat{ { 1, 2 }, { 3, 4 } } ) );
}

TEST( PX( AbstractPlot ), ToArray_Mat2 )
{
    EXPECT_EQ( "[[1, 2, 3],[4, 5, 6]]",
    AbstractPlot::ToArray( ::Mat{ { 1, 2, 3 }, { 4, 5 , 6 } } ) );
}

TEST( PX( AbstractPlot ), ToArray_MatStr )
{
    ::Mat m( { { "1", "2" }, { "3", "4" } } );
    EXPECT_EQ( "[['1', '2'],['3', '4']]",
               AbstractPlot::ToArray( m ) );
}

TEST( PX( AbstractPlot ), ToArray_Mat_Empty )
{
    EXPECT_EQ( "[]",
               AbstractPlot::ToArray( ::Mat( std::vector< std::vector< double > >() ) ) );
}

TEST( PX( AbstractPlot ), ToArray_MatStr_Empty )
{
    EXPECT_EQ( "[]",
               AbstractPlot::ToArray( ::Mat( std::vector< std::vector< std::string > >() ) ) );
}