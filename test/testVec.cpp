#include "plot/vec.h"

#include "helper.h"

TEST( Vec, Construct )
{
    EXPECT_FALSE( std::is_constructible<Vec>::value );
}

TEST( Vec, FloatConstr )
{
    Vec v( { 0.1f, 2.0f, 8.0f } );

    EXPECT_DOUBLE_EQ( 0.1f, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2.0f, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 8.0f, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( Vec, DoubleConstr )
{
    Vec v( { 0.1, 2.0, 8.0 } );

    EXPECT_DOUBLE_EQ( 0.1, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 8.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( Vec, IntConstr )
{
    Vec v( { 1, 2, 8 } );

    EXPECT_DOUBLE_EQ( 1, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 8, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( Vec, IntStrConstr )
{
    Vec v( {"1", "2", "8" } );

    EXPECT_EQ( "1", v.GetStrings()[0] );
    EXPECT_EQ( "2", v.GetStrings()[1] );
    EXPECT_EQ( "8", v.GetStrings()[2] );
    EXPECT_EQ( 3, v.GetStrings().size() );

    EXPECT_EQ( 0, v.GetData().size() );
}

TEST( Vec, Valarr )
{
    Vec v( std::valarray< int16_t > { 1, 2, 8 } );

    EXPECT_DOUBLE_EQ( 1, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 8, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( Vec, Str )
{
    Vec v( { "1", "2", "8" } );

    EXPECT_EQ( "1", v.GetStrings()[0] );
    EXPECT_EQ( "2", v.GetStrings()[1] );
    EXPECT_EQ( "8", v.GetStrings()[2] );
    EXPECT_EQ( 3, v.GetStrings().size() );

    EXPECT_EQ( 0, v.GetData().size() );
}

TEST( Vec, Map )
{
    Vec v( { 1, 2, 8 }, { { 1, "1" }, { 2, "2" }, { 8, "8" } } );

    EXPECT_EQ( "1", v.GetStrings()[0] );
    EXPECT_EQ( "2", v.GetStrings()[1] );
    EXPECT_EQ( "8", v.GetStrings()[2] );
    EXPECT_EQ( 3, v.GetStrings().size() );

    EXPECT_EQ( 0, v.GetData().size() );
}

TEST( Vec, Linspace )
{
    Vec v( 0, 2, 3 );

    EXPECT_DOUBLE_EQ( 0.0, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 1.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 2.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( Vec, LinspaceFunc )
{
    Vec v( 0, 2, 3, []( double x )
    {
        return x - 1;
    } );

    EXPECT_DOUBLE_EQ( -1.0, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 0.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 1.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( Vec, Func )
{
    Vec v( { 0, 2, 3 }, []( double x )
    {
        return x - 1;
    } );

    EXPECT_DOUBLE_EQ( -1.0, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 1.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 2.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( Vec, Arma )
{
    Vec v( arma::vec{ 0, 2, 3 } );

    EXPECT_DOUBLE_EQ( 0.0, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 3.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( Vec, GetSizeDouble )
{
    Vec v( { 0, 2, 3, 4 } );
    EXPECT_EQ( 4, v.GetSize() );
}

TEST( Vec, GetSizeStr )
{
    Vec v( { "0", "2", "3", "4" } );
    EXPECT_EQ( 4, v.GetSize() );
}

TEST( Vec, Min )
{
    Vec v( { 0, 2, 3, 4, -2 } );
    EXPECT_DOUBLE_EQ( -2.0, v.Min() );
}

TEST( Vec, Max )
{
    Vec v( { 0, 2, 3, 4, -2 } );
    EXPECT_DOUBLE_EQ( 4.0, v.Max() );
}