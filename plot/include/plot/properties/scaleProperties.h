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
#ifndef __SCALEPROPERTIES_H__
#define __SCALEPROPERTIES_H__

#include "plot/abstractPlot.h"

#include <cassert>

template<class tBase, bool IsDict, bool IsBase >
class ScaleProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class ScaleProperties
    : public AbstractPlot
{
public:

    typedef typename std::conditional < IsDict &&!IsBase, ScaleProperties< tBase, IsDict >, tBase & >::type tReturn;

    ScaleProperties()
    {
        //mIsDictionary = IsDict;
    }

};

template < typename tBase = void *,
           bool IsDict = std::is_same< tBase, void * >::value,
           bool IsBase = false  >
class LinearScaleProperties
    : public ScaleProperties< LinearScaleProperties< tBase, IsDict >, IsDict, true >
{
public:

    virtual std::string ToString() override
    {
        if ( PlotLib::Identity( IsBase ) )
        {
            this->AddArgument( "value", this->GetString( "linear" ) );
        }

        return AbstractPlot::ToString( this->mStream.str() );
    }
};

template < typename tBase = void *,
           bool IsDict = std::is_same< tBase, void * >::value,
           bool IsBase = false  >
class LogScaleProperties
    : public ScaleProperties< LogScaleProperties< tBase, IsDict >, IsDict, true >
{
public:

    enum class NonPos
    {
        Mask,
        Clip
    };

    virtual std::string ToString() override
    {
        if ( PlotLib::Identity( IsBase ) )
        {
            this->AddArgument( "value", this->GetString( "log" ) );
        }

        return AbstractPlot::ToString( this->mStream.str() );
    }

    typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetBaseY( double base )
    {
        assert( base > 1 );
        this->AddArgument( "basey", base );

        return static_cast<typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetSubsY( const PVec &subsy )
    {
        this->AddArgument( "subsy", this->ToArray( subsy ) );

        return static_cast<typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetNonPosY( NonPos nonpos )
    {
        this->AddArgument( "nonposy", this->GetString( nonpos == NonPos::Clip ? "clip" : "mask" ) );

        return static_cast<typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetBaseX( double base )
    {
        assert( base > 1 );
        this->AddArgument( "basex", base );

        return static_cast<typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetSubsX( const PVec &subsy )
    {
        this->AddArgument( "subsx", this->ToArray( subsy ) );

        return static_cast<typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetNonPosX( NonPos nonpos )
    {
        this->AddArgument( "nonposx", this->GetString( nonpos == NonPos::Clip ? "clip" : "mask" ) );

        return static_cast<typename ScaleProperties<LogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }
};

template < typename tBase = void *,
           bool IsDict = std::is_same< tBase, void * >::value,
           bool IsBase = false  >
class LogitScaleProperties
    : public ScaleProperties< LogitScaleProperties< tBase, IsDict >, IsDict, true >
{
public:

    enum class NonPos
    {
        Mask,
        Clip
    };

    virtual std::string ToString() override
    {
        if ( PlotLib::Identity( IsBase ) )
        {
            this->AddArgument( "value", this->GetString( "logit" ) );
        }

        return AbstractPlot::ToString( this->mStream.str() );
    }

    typename ScaleProperties<LogitScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetNonPos( NonPos nonpos )
    {
        this->AddArgument( "nonpos", this->GetString( nonpos == NonPos::Clip ? "clip" : "mask" ) );

        return static_cast<typename ScaleProperties<LogitScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

};

template < typename tBase = void *,
           bool IsDict = std::is_same< tBase, void * >::value,
           bool IsBase = false  >
class SymLogScaleProperties
    : public ScaleProperties< SymLogScaleProperties< tBase, IsDict >, IsDict, true >
{
public:

    virtual std::string ToString() override
    {
        if ( PlotLib::Identity( IsBase ) )
        {
            this->AddArgument( "value", this->GetString( "symlog" ) );
        }

        return AbstractPlot::ToString( this->mStream.str() );
    }

    typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetBaseY( double base )
    {
        assert( base > 1 );
        this->AddArgument( "basey", base );

        return static_cast<typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetSubsY( const PVec &subsy )
    {
        this->AddArgument( "subsy", this->ToArray( subsy ) );

        return static_cast<typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetBaseX( double base )
    {
        assert( base > 1 );
        this->AddArgument( "basex", base );

        return static_cast<typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetSubsX( const PVec &subsy )
    {
        this->AddArgument( "subsx", this->ToArray( subsy ) );

        return static_cast<typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetLinThresholdX( double min,
                                                                                                             double max )
    {
        this->AddArgument( "linthreshx", this->ToTuple( min, max ) );

        return static_cast<typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetLinThresholdY( double min,
                                                                                                             double max )
    {
        this->AddArgument( "linthreshy", this->ToTuple( min, max ) );

        return static_cast<typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetLinScaleX( double min,
                                                                                                         double max )
    {
        this->AddArgument( "linscalex", this->ToTuple( min, max ) );

        return static_cast<typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }

    typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &SetLinScaleY( double min,
                                                                                                         double max )
    {
        this->AddArgument( "linscaley", this->ToTuple( min, max ) );

        return static_cast<typename ScaleProperties<SymLogScaleProperties<tBase, IsDict>, IsDict, true>::tReturn &>( *this );
    }
};

typedef LinearScaleProperties<> LinearScale;
typedef LogScaleProperties<> LogScale;
typedef LogitScaleProperties<> LogitScale;
typedef SymLogScaleProperties<> SymLogScale;

#endif