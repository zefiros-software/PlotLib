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
#ifndef __VLINEPROPERTIES_H__
#define __VLINEPROPERTIES_H__

#include "plot/properties/line2dProperties.h"

template<class tBase, bool IsDict, bool IsBase >
class VLineProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class VLineProperties
    : public Line2DProperties< VLineProperties< tBase, IsDict >, IsDict, true >
{
public:

    virtual std::string ToString() override
    {
        if ( !mColour.empty() )
        {
            AddArgument( "color", mColour );
        }

        return Line2DProperties< VLineProperties< tBase, IsDict >, IsDict, true >::ToString();
    }

    PLOTLIB_INLINE VLineProperties &SetYMin( double ymin )
    {
        AddArgument( "ymin", ymin );
        return *this;
    }

    PLOTLIB_INLINE VLineProperties &SetYMax( double ymax )
    {
        AddArgument( "ymax", ymax );
        return *this;
    }

    PLOTLIB_INLINE VLineProperties &SetColour( const std::string &colour )
    {
        mColour = GetString( colour );
        return *this;
    }

protected:

    std::string mColour;

};

typedef VLineProperties<> VLine;

#endif