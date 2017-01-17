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


TEST( EasyPlot, ResidualPlot )
{
    TestPlot( "EasyPlot_ResidualPlot", []( Plot & p )
    {
        vec x = randn( 20 );
        vec x2 = x + 0.5 * randn( 20 );
        EasyPlot::ResidualPlot( p, linspace( 0, 20, 20 ), x, x2 );
    } );
}

TEST( EasyPlot, StackedBarPlot )
{
    TestPlot( "EasyPlot_StackedBarPlot", []( Plot & p )
    {
        vec x = round( randu( 200 ) * 10 );
        vec x2 = round( randu( 200 ) * 10 );;
        EasyPlot::StackedBarPlot( p, { x, x2 }, { linspace( 0, 20, 200 ), linspace( 0, 20, 200 ) }, Palette::Diverging::RdYlBu,
                                  []( size_t v )
        {
            return std::to_string( v );
        } );
    } );
}

TEST( EasyPlot, StackedDistancedBarPlot )
{
    TestPlot( "EasyPlot_StackedDistancedBarPlot", []( Plot & p )
    {
        vec x = round( randu( 20 ) * 10 );
        vec x2 = round( randu( 20 ) * 10 );;
        EasyPlot::StackedDistancedBarPlot( p, { x, x2 }, { x, x2 }, { x, x2 },
                                           Palette::Diverging::RdYlBu,
                                           []( size_t v )
        {
            return std::to_string( v );
        } );
    } );
}

TEST( EasyPlot, BackgroundForegroundBarPlot )
{
    TestPlot( "EasyPlot_BackgroundForegroundBarPlot", []( Plot & p )
    {
        vec x = round( randu( 10 ) * 10 );
        vec x2 = round( randu( 10 ) * 10 );;
        EasyPlot::BackgroundForegroundBarPlot( p, { x, x2 }, { x, x2 }, { linspace( 0, 20, 10 ), linspace( 0, 20, 10 ) },
                                               Palette::Diverging::RdYlBu, Palette::Seaborn::Deep,
                                               []( size_t v )
        {
            return "Background-" + std::to_string( v );
        },
        []( uint32_t v )
        {
            return "Foreground-" + std::to_string( v );
        } );
    } );
}