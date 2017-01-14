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
#ifndef __FANCYARROWPROPERTIES_H__
#define __FANCYARROWPROPERTIES_H__

#include "plot/properties/patchProperties.h"

static const char *const __PlotLibFancyArrowPropertiesConnectionStyle[] =
{
    "angle",
    "angle3",
    "arc",
    "arc3",
    "bar"
};

template<class tBase, bool IsDictn >
class FancyArrowProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value >
class FancyArrowProperties
    : public PatchProperties< FancyArrowProperties< tBase, IsDict >, IsDict, true >
{
public:

    enum class ConnectionStyle
    {
        Angle,
        Angle3,
        Arc,
        Arc3,
        Bar
    };

    typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetPos( std::pair< double, double > a,
                                                                                                  std::pair< double, double> b )
    {
        this->AddArgument( "posA", this->ToTuple( a.first, a.second ) );
        this->AddArgument( "posB", this->ToTuple( b.first, b.second ) );

        return static_cast<typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetShrink( double a, double b )
    {
        this->AddArgument( "shrinkA", a );
        this->AddArgument( "shrinkB", b );

        return static_cast<typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetMutationScale( double scale )
    {
        this->AddArgument( "mutation_scale", scale );

        return static_cast<typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetMutationAspect( double aspect )
    {
        this->AddArgument( "mutation_aspect", aspect );

        return static_cast<typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetConnectionStyle( ConnectionStyle style )
    {
        this->AddArgument( "connectionstyle"
                           , this->GetString( __PlotLibFancyArrowPropertiesConnectionStyle[static_cast<size_t>( style )] ) );

        return static_cast<typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetArrowStyle( const std::string &style )
    {
        this->AddArgument( "arrowstyle", this->GetString( style ) );

        return static_cast<typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &SetDpiCorrection( double dpi )
    {
        this->AddArgument( "dpi_cor", dpi );

        return static_cast<typename PatchProperties<FancyArrowProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }
};

typedef FancyArrowProperties<> FancyArrow;


#endif