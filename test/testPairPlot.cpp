/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Mick van Duijn, Koen Visscher and Paul Visscher
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

TEST( PairPlot, PairPlot )
{
    TestPlot< PairPlot >( "PairPlot", []()
    {
        PairPlot f( ( mat )randn( 3, 300 ), { "first", "second", "third" } );
        f.SetDiagonalType( PairPlot::DiagonalType::KernelDensity )
        .SetMarker( "*" );
        return f;
    } );
}

TEST( PairPlot, PairPlot2 )
{
    TestPlot< PairPlot >( "PairPlot2", []()
    {
        PairPlot f( { ( mat )randn( 3, 50 ), ( mat )randn( 3, 50 ), ( mat )randn( 3, 50 ) },
        { "x", "y", "z" },
        { "First", "Second", "Third" } );
        f.SetMarkers( { "*", "o", "D" } )
        .SetSize( 3 );
        return f;
    } );
}

TEST( PairPlot, PairPlot3 )
{
    TestPlot< PairPlot >( "PairPlot3", []()
    {
        PairPlot f( { ( mat )randn( 3, 50 ), ( mat )randn( 3, 50 ), ( mat )randn( 3, 50 ) },
        { "x", "y", "z" },
        { "First", "Second", "Third" } );
        f.SetYVars( { "x", "y" } )
        .SetXVars( { "x", "z" } )
        .SetType( PairPlot::Type::Regression )
        .SetAspect( 2 );
        return f;
    } );
}