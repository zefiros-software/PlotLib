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
#ifndef __HEATMAPPROPERTIES_H__
#define __HEATMAPPROPERTIES_H__

#include "plot/properties/colourBarProperties.h"
#include "plot/properties/textProperties.h"
#include "plot/palette.h"

template<class tBase, bool IsDict, bool IsBase >
class HeatMapPlotProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class HeatMapPlotProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, HeatMapPlotProperties< tBase, IsDict >, tBase & >::type tReturn;

    tReturn &SetMinValue( double value )
    {
        this->AddArgument( "vmin", value );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetMaxValue( double value )
    {
        this->AddArgument( "vmax", value );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetCentre( double value )
    {
        this->AddArgument( "center", value );
        return static_cast<tBase &>( *this );
    }

    tReturn &Robust( bool robust )
    {
        this->AddArgument( "center", GetBool( robust ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &Annotate( bool annotate )
    {
        this->AddArgument( "annot", GetBool( annotate ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetAnnotate( const PMat &annot )
    {
        this->AddArgument( "annot", "pd.DataFrame(" + this->ToArray( annot ) + ")" );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetFormat( const std::string &fmt )
    {
        this->AddArgument( "fmt", this->GetString( fmt ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetLineWidths( double value )
    {
        this->AddArgument( "linewidths", value );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetLineColour( const std::string &colour )
    {
        this->AddArgument( "linecolor", this->GetString( colour ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetColourMap( Palette pallet )
    {
        pallet.SetColourMap( true );
        this->AddArgument( "color", pallet.ToString() );
        return static_cast<tBase &>( *this );
    }

    tReturn &Square( bool square )
    {
        this->AddArgument( "square", GetBool( square ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &YTickLabel( bool enable )
    {
        mYTickLabels = GetBool( enable );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetYTickLabels( const PVec &names )
    {
        mYTickLabels = this->ToArray( names );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetYTickLabel( uint32_t offset )
    {
        mYTickLabels = std::to_string( offset );
        return static_cast<tBase &>( *this );
    }

    tReturn &XTickLabel( bool enable )
    {
        mXTickLabels = GetBool( enable );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetXTickLabels( const PVec &names )
    {
        mXTickLabels = this->ToArray( names );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetXTickLabel( uint32_t offset )
    {
        mXTickLabels = std::to_string( offset );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetMask( const std::vector< bool > &mask )
    {
        this->AddArgument( "mask", this->ToArray( mask ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetMask( const PMat &mask )
    {
        this->AddArgument( "mask", "pd.DataFrame(" + this->ToArray( mask ) + ")" );
        return static_cast<tBase &>( *this );
    }

    tReturn &ColourBar( bool enable )
    {
        this->AddArgument( "cbar", GetBool( enable ) );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetColourBar( ColourBarProps &prop )
    {
        this->AddArgument( "cbar_kws", prop.ToString() );
        return static_cast<tBase &>( *this );
    }

    tReturn &SetText( Text &prop )
    {
        this->AddArgument( "annot_kws", prop.ToString() );
        return static_cast<tBase &>( *this );
    }

protected:

    std::string mXTickLabels;
    std::string mYTickLabels;
};

#endif