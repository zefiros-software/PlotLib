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

#pragma once
#ifndef __PREDICTION_HELPER_H__
#define __PREDICTION_HELPER_H__

#define CONCATEXT( a, b ) a ## b
#define CONCAT( a, b ) CONCATEXT( a, b )
#define GTEST_DONT_DEFINE_TEST 1

# define TEST(test_case_name, test_name) GTEST_TEST( CONCAT( PREFIX, test_case_name ), test_name)

#include <armadillo>

#include "plot/plotting.h"

#include <gtest/gtest.h>

using namespace arma;

template< typename tPlot >
void TestPlot( const std::string &str, std::function< tPlot( void ) > fn )
{
    Plot p;
    //p.Set( Plot::Context::Notebook )
    p.AddPlot( fn() )
    .Save( str + ".png" );
}

template< typename tPlot >
void TestPlotArg( const std::string &str, std::function< tPlot( Plot & ) > fn )
{
    Plot p;
    //p.Set( Plot::Context::Notebook )
    p.AddPlot( fn( p ) )
    .Save( str + ".png" );
}

void TestPlot( const std::string &str, std::function< void( Plot & ) > fn );

#endif