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
#ifndef __ENGINE_YARROWPROPERTIES_H__
#define __ENGINE_YARROWPROPERTIES_H__

#include "plot/properties/patchProperties.h"

template<class tBase, bool IsDict >
class YArrowProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value >
class YArrowProperties
    : public PatchProperties< YArrowProperties< tBase, IsDict >, IsDict, true >
{
public:

    tReturn &SetXYTip( double x, double y )
    {
        AddArgument( "xytip", ToTuple( x, y ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetXYBase( double x, double y )
    {
        AddArgument( "xybase", ToTuple( x, y ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetWidth( double width )
    {
        AddArgument( "width", width );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetFraction( double frac )
    {
        AddArgument( "frac", frac );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetHeadWidth( double headWidth )
    {
        AddArgument( "headwidth", headWidth );

        return static_cast<tReturn &>( *this );
    }
};

typedef YArrowProperties<> YArrow;

#endif