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

TEST( BarPlot, BarPlot )
{
    TestPlot< BarPlot >( "BarPlot", []()
    {
        vec randX = round( randu( 10 ) * 100 );
        vec randY = randu( 10 ) * 100;
        BarPlot f( randX, randY );
        return f;
    } );
}

TEST( BarPlot, Constr2 )
{
    TestPlot< BarPlot >( "BarPlot_Constr2", []()
    {
        Vec x = ( vec )( round( randu( 10 ) * 100 ) );
        BarPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { x, ( vec )( randu( 10 ) * 100 )},
            { x, ( vec )( randu( 10 ) * 100 ) },
            { x, ( vec )( randu( 10 ) * 100 ) }
        } );
        f.SetErrorWidth( 1.2 )
        .SetCapSize( 0.3 )
        .SetNBoot( 5000 );
        return f;
    } );
}

TEST( BarPlot, Constr3 )
{
    TestPlot< BarPlot >( "BarPlot_Constr3", []()
    {
        Vec x = ( vec )( round( randu( 8 ) * 100 ) );
        BarPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { x, ( vec )( randu( 8 ) * 100 )},
            { x, ( vec )( randu( 8 ) * 100 ) },
        }, { "First", "Second" } );
        f.SetHatch( "//" );
        return f;
    } );
}

TEST( BarPlot, Constr4 )
{
    TestPlot< BarPlot >( "BarPlot_Constr4", []()
    {
        Vec x = ( vec )( round( randu( 8 ) * 100 ) );
        BarPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { x, ( vec )( randu( 8 ) * 100 )},
            { x, ( vec )( randu( 8 ) * 100 ) },
        },
        std::vector< uint32_t > { 1, 2 },
        []( uint32_t d )
        {
            return std::to_string( d ) + "@@";
        } );
        f.SetConfidenceInterval( 0.0 );
        return f;
    } );
}

TEST( BarPlot, ColourCycler )
{
    TestPlotArg< BarPlot >( "BarPlot_ColourCycler", []( Plot & plot )
    {

        plot.AddColourCycler( Palette::Diverging::RdYlBu );
        Vec x = ( vec )( round( randu( 10 ) * 100 ) );
        BarPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { x, ( vec )( randu( 10 ) * 100 )},
            { x, ( vec )( randu( 10 ) * 100 ) },
            { x, ( vec )( randu( 10 ) * 100 ) },
            { x, ( vec )( randu( 10 ) * 100 ) },
            { x, ( vec )( randu( 10 ) * 100 ) }
        }, { "1", "2", "3", "4", "5" } );
        f.UseColourCycler( plot.GetColourCycler() );

        return f;
    } );
}

TEST( BarPlot, SetColourMap )
{
    TestPlot< BarPlot >( "BarPlot_SetColourMap", []()
    {
        vec x = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        BarPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { x, ( vec )( randu( 10 ) * 100 )},
            { x, ( vec )( randu( 10 ) * 100 ) },
            { x, ( vec )( randu( 10 ) * 100 ) },
            { x, ( vec )( randu( 10 ) * 100 ) },
            { x, ( vec )( randu( 10 ) * 100 ) }
        }, { "1", "2", "3", "4", "5" } );
        f.SetColourMap( Palette::Diverging::Coolwarm )
        .SetSaturation( 1.0 )
        .SetOrder( ( vec )shuffle<vec>( x ) )
        .SetHueOrder( { "5", "4", "3", "2", "1" } )
        .SetOrientation( BarPlot::Orientation::Vertical );

        return f;
    } );
}

TEST( BarPlot, Orientation )
{
    TestPlot< BarPlot >( "BarPlot_Orientation", []()
    {
        vec x = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        BarPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { ( vec )( randu( 10 ) * 100 ), x },
            { ( vec )( randu( 10 ) * 100 ), x },
            { ( vec )( randu( 10 ) * 100 ), x },
            { ( vec )( randu( 10 ) * 100 ), x },
            { ( vec )( randu( 10 ) * 100 ), x }
        } );
        f.SetOrientation( BarPlot::Orientation::Horizontal )
        .SetColour( "b" )
        .SetErrorColour( "r" );

        return f;
    } );
}