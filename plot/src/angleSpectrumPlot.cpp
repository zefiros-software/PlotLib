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

#include "plot/angleSpectrumPlot.h"

PLOTLIB_INLINE AngleSpectrumPlot::AngleSpectrumPlot( const PVec &vec )
{
    mStream << "plt.angle_spectrum( " << this->ToArray( vec );
}

PLOTLIB_INLINE std::string AngleSpectrumPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE AngleSpectrumPlot &AngleSpectrumPlot::SetSamplingFrequency( double fs )
{
    this->AddArgument( "Fs", fs );
    return *this;
}

PLOTLIB_INLINE AngleSpectrumPlot &AngleSpectrumPlot::SetSides( Sides sides )
{
    this->AddArgument( "sides", GetSides( sides ) );
    return *this;
}

PLOTLIB_INLINE AngleSpectrumPlot &AngleSpectrumPlot::SetCentreFrequency( int32_t fc )
{
    this->AddArgument( "Fc", fc );
    return *this;
}

PLOTLIB_INLINE AngleSpectrumPlot &AngleSpectrumPlot::SetPadTo( int32_t pad )
{
    this->AddArgument( "pad_to", pad );
    return *this;
}

PLOTLIB_INLINE std::string AngleSpectrumPlot::GetSides( Sides sides )
{
    switch ( sides )
    {
    case Sides::OneSided:
        return "'onesided'";

    case Sides::TwoSided:
        return "'twosided'";

    default:
        return "'default'";
    }
}
