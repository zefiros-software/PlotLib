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

#pragma once
#ifndef __HEXBINPLOT_H__
#define __HEXBINPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/palette.h"

class HexBinPlot
    : public AbstractPlot
{
public:

    enum class BinType
    {
        Logarithmic,
        None
    };

    enum class Scale
    {
        Linear,
        Logarithmic
    };

    HexBinPlot( const Vec &x, const Vec &y );

    virtual std::string ToString() override;


    HexBinPlot &SetGridSize( const std::pair< size_t, size_t > &size );

    HexBinPlot &SetGridSize( size_t size );

    HexBinPlot &SetBins( size_t bins );

    HexBinPlot &SetBins( BinType type );

    HexBinPlot &SetBins( const Vec &bins );

    HexBinPlot &SetXScale( Scale scale );

    HexBinPlot &SetScale( Scale scale );

    HexBinPlot &SetMinCount( size_t minCount );

    HexBinPlot &SetMarginals( bool marginals );

    HexBinPlot &SetExtent( size_t left, size_t right, size_t bottom, size_t top );

    HexBinPlot &SetColourMap( Palette pallet );

    HexBinPlot &SetMinValue( double value );

    HexBinPlot &SetMaxValue( double value );

    HexBinPlot &SetLineWidths( double value );

    HexBinPlot &SetAlpha( double value );

private:

    static std::string GetScale( Scale scale );
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/hexBinPlot.cpp"
#endif

#endif