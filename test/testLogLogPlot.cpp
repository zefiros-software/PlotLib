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

TEST( LogLogPlot, LogLogPlot )
{
    TestPlot< LogLogPlot >( "LogLogPlot", []()
    {
        LogLogPlot f( ( vec )linspace( 0, 100, 300 ), ( vec )abs( randn( 300 ) ) );
        f.SetScale( LogScale()
                    .SetNonPosY( LogScale::NonPos::Clip )
                    .SetNonPosX( LogScale::NonPos::Clip ) );
        return f;
    } );
}

TEST( LogLogPlot, LogLogPlot2 )
{
    TestPlot< LogLogPlot >( "LogLogPlot2", []()
    {
        LogLogPlot f( ( vec )linspace( 0, 100, 300 ), ( vec )( abs( randn( 300 ) ) + 0.5 ) );
        f.SetScale( LogScale()
                    .SetBaseY( 10 )
                    .SetSubsY( { 0, 1, 2 } )
                    .SetBaseX( 10 )
                    .SetSubsX( { 0, 1, 2 } ) );
        return f;
    } );
}