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

TEST( BoxPlot, BoxPlot )
{
    TestPlot< BoxPlot >( "BoxPlot", []()
    {
        vec randX = round( randu( 100 ) * 10 );
        vec randY = randu( 100 ) * 100;
        BoxPlot f( randX, randY );
        f.Notch( true );
        return f;
    } );
}

TEST( BoxPlot, Constr2 )
{
    TestPlot< BoxPlot >( "BoxPlot_Constr2", []()
    {
        Vec x = ( vec )( round( randu( 100 ) * 10 ) );
        BoxPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { x, ( vec )( randu( 100 ) * 100 )},
            { x, ( vec )( randu( 100 ) * 100 ) },
            { x, ( vec )( randn( 100 ) * 100 ) }
        } );
        f.SetWhis( 5 )
        .SetFlierSize( 6 )
        .SetLineWidth( 0.5 )
        .ShowMeans( true )
        .SetMean( Line2D().SetMarker( "*" ).SetMarkerFaceColour( "#3d2929" ) );
        return f;
    } );
}

TEST( BoxPlot, Constr3 )
{
    TestPlot< BoxPlot >( "BoxPlot_Constr3", []( Plot & plot )
    {
        plot.SetYLimit( 0, 110 );

        Vec x = ( vec )( round( randu( 100 ) * 10 ) );
        BoxPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { x, ( vec )( randu( 100 ) * 100 )},
            { x, ( vec )( randu( 100 ) * 100 ) },
        }, { "First", "Second" } );
        f.SetOrientation( BoxPlot::Orientation::Vertical )
        .SetWidth( 0.5 )
        .SetColour( "purple" )
        .SetSaturation( 1.0 )
        .SetLineWidth( 1.5 );
        return f;
    } );
}

TEST( BoxPlot, Orientation )
{
    TestPlot< BoxPlot >( "BoxPlot_Orientation", []( Plot & plot )
    {
        plot.SetXLimit( 0, 130 );

        vec x = round( randu( 100 ) * 10 );
        BoxPlot f( std::vector< std::pair< Vec, Vec > >
        {
            { ( vec )( randu( 100 ) * 100 ), x },
            { ( vec )( randu( 100 ) * 100 ), x },
        }, { "First", "Second" } );
        f.SetOrientation( BoxPlot::Orientation::Horizontal )
        .SetColourMap( Palette::Qualitative::Set2 )
        .SetOrder( ( vec )shuffle<vec>( { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ) )
        .SetHueOrder( { "Second", "First" } );
        return f;
    } );
}