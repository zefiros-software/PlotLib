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

TEST( InteractPlot, InteractPlot )
{
    TestPlot< InteractPlot >( "InteractPlot", []()
    {
        vec x1 = randn( 300 );
        vec x2 = x1 / 5 + randn( 300 );
        vec y = 0.5  + 0.25 * x1 + -1 * x2 + 2 * x1 % x2 + randn( 300 );
        InteractPlot f( x1, x2, y );
        f.SetLevels( 20 )
        .SetScatter( Line().SetMarkerFaceColour( "g" ) )
        .SetContour( Contour().SetLineWidths( 10 ) );
        return f;
    } );
}

TEST( InteractPlot, InteractPlot2 )
{
    TestPlot< InteractPlot >( "InteractPlot2", []()
    {
        vec x1 = randn( 300 );
        vec x2 = x1 / 5 + randn( 300 );
        vec y = 0.5 + 0.25 * x1 + -1 * x2 + 2 * x1 % x2 + randn( 300 );
        InteractPlot f( x1, x2, y );
        f.SetLevels( { -5, 0, 1, 2, 3, 4, 5, 10, 20 } )
        .Filled( true )
        .ColourBar( false )
        .SetColourMap( Palette::Colour::Viridis );
        return f;
    } );
}