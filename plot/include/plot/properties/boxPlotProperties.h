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
#ifndef __BOXPLOTPROPERTIES_H__
#define __BOXPLOTPROPERTIES_H__

#include "plot/properties/line2dProperties.h"

template<class tBase, bool IsDict, bool IsBase >
class BoxPlotProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class BoxPlotProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, BoxPlotProperties< tBase, IsDict >, tBase & >::type tReturn;

    tReturn &SetX( const PVec &x )
    {
        this->AddArgument( "x", this->ToArray( x ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &Notch( bool notch )
    {
        this->AddArgument( "notch", GetBool( notch ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetMarkerSymbol( const std::string &symbol )
    {
        this->AddArgument( "sym", this->GetString( symbol ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetWhis( double whis )
    {
        this->AddArgument( "whis", whis );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetBootstrap( uint32_t bootstrap )
    {
        this->AddArgument( "bootstrap", bootstrap );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetMedians( const PVec &medians )
    {
        this->AddArgument( "usermedians", this->ToArray( medians ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetConfidenceIntervals( const PMat &intervals )
    {
        this->AddArgument( "conf_intervals", this->ToArray( intervals ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetPositions( const std::vector< uint32_t > &positions )
    {
        this->AddArgument( "positions", this->ToArray( positions ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetWidths( double widths )
    {
        this->AddArgument( "widths", widths );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetWidths( const PVec &widths )
    {
        this->AddArgument( "widths", this->ToArray( widths ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetLabels( const std::vector< std::string > &labels )
    {
        this->AddArgument( "labels", this->ToArray( labels ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &ShowMeans( bool showmeans )
    {
        this->AddArgument( "showmeans", GetBool( showmeans ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &ShowBox( bool showbox )
    {
        this->AddArgument( "showbox", GetBool( showbox ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &ShowFliers( bool showfliers )
    {
        this->AddArgument( "showfliers", GetBool( showfliers ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &MeanLine( bool meanline )
    {
        this->AddArgument( "meanline", GetBool( meanline ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &ManageXTicks( bool manage )
    {
        this->AddArgument( "manage_xticks", GetBool( manage ) );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetBox( Line2D &properties )
    {
        this->AddArgument( "boxprops", properties.ToString() );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetWhisker( Line2D &properties )
    {
        this->AddArgument( "whiskerprops", properties.ToString() );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetCap( Line2D &properties )
    {
        this->AddArgument( "capprops", properties.ToString() );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetFlier( Line2D &properties )
    {
        this->AddArgument( "flierprops", properties.ToString() );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetMedian( Line2D &properties )
    {
        this->AddArgument( "medianprops", properties.ToString() );

        return static_cast<tBase &>( *this );
    }

    tReturn &SetMean( Line2D &properties )
    {
        this->AddArgument( "meanprops", properties.ToString() );

        return static_cast<tBase &>( *this );
    }
};

#endif