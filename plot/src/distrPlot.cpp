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

#include "plot/distrPlot.h"
#include "plot/vec.h"

PLOTLIB_INLINE DistrPlot::DistrPlot( const Vec &a )
{
    mStream << "sns.distplot(" << ToArray( a );
}

PLOTLIB_INLINE std::string DistrPlot::ToString() const
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetBins( const Vec &seq )
{
    const bool isSingular = seq.GetSize() == 1;
    mStream << ", bins=" << isSingular ? std::to_string( seq.GetData()[0] ) : ToArray( seq );
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetBins( bool log /*= false */ )
{
    mStream << ", bins=" << ( log ? "'log'" : "None" );
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetHist( bool hist )
{
    mStream << ", hist=" << GetBool( hist );
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetKDE( bool kde )
{
    mStream << ", kde=" << GetBool( kde );
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetRUG( bool rug )
{
    mStream << " , rug=" << GetBool( rug );
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetVerical( bool vertical )
{
    mStream << " , vertical=" << GetBool( vertical );
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetNormHist( bool normHist )
{
    mStream << " , norm_hist=" << GetBool( normHist );
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetAxLabel()
{
    mStream << " , axlabel=False";
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetAxLabel( const std::string &axlabel )
{
    mStream << " , axlabel='" << axlabel << "'";
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetLabel( const std::string &label )
{
    mStream << " , label='" << label << "'";
    return *this;
}
