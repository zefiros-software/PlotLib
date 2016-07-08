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
#ifndef __ANGLESPECTRUMPLOT_H__
#define __ANGLESPECTRUMPLOT_H__

#include "plot/abstractPlot.h"

/**
 * An angle spectrum plot, this is a wrapper for the
 * [`angle_spectrum`](http://matplotlib.org/api/pyplot_api.html#matplotlib.pyplot.angle_spectrum)
 * functionality.
 *
 * @details
 * @examples
 *
 * @snippet testAngleSpectrumPlot.cpp AngleSpectrumPlot
 *
 * ![Plot Example](AngleSpectrumPlot.png)
 *
 * @sa AbstractPlot
 */

class AngleSpectrumPlot
    : public AbstractPlot
{
public:

    /**
     * Specifies which side of the spectrum is returned.
     */

    enum class Sides
    {
        ///  Default is one-sided real and complex data.
        Default,
        /// One-sided spectrum.
        OneSided,
        /// Two-sided spectrum.
        TwoSided
    };

    /**
     * Constructor that plots the angle spectrum of @c vec.
     *
     * @param   vec The vector to analyse.
     *
     * @details
     * @examples
     *
     * @snippet testAngleSpectrumPlot.cpp AngleSpectrumPlot
     */

    AngleSpectrumPlot( const Vec &vec );

    virtual std::string ToString() const override;

    /**
     * Sets the sampling frequency, which is used to calculate the Fourier coefficients.
     * The default value is 2.
     *
     * @param   fs The frequency.
     *
     * @return This object (Fluent API).
     *
     * @details
     * @examples
     *
     * @snippet testAngleSpectrumPlot.cpp AngleSpectrumPlot_SamplingFrequency
     *
     * ![SetSamplingFrequency Example](AngleSpectrumPlot_SamplingFrequency.png)
     */

    AngleSpectrumPlot &SetSamplingFrequency( double fs );

    /**
     * Sets which side the spectrum should return.
     *
     * @param   sides The sides to return.
     *
     * @return This object (Fluent API).
     *
     * @details
     * @examples
     *
     * @title{Default Sided}
     * @snippet testAngleSpectrumPlot.cpp AngleSpectrumPlot_SetSides
     *
     * ![SetSamplingFrequency TwoSided Example](AngleSpectrumPlot_SetSides.png)
     *
     * @title{One Sided}
     * @snippet testAngleSpectrumPlot.cpp AngleSpectrumPlot_SetSides_OneSided
     *
     * ![SetSamplingFrequency OneSided Example](AngleSpectrumPlot_SetSides_OneSided.png)
     *
     * @title{Two Sided}
     * @snippet testAngleSpectrumPlot.cpp AngleSpectrumPlot_SetSides_TwoSided
     *
     * ![SetSamplingFrequency TwoSided Example](AngleSpectrumPlot_SetSides_TwoSided.png)
     */

    AngleSpectrumPlot &SetSides( Sides sides );

    /**
     * Sets the centre frequency (default 0). It offsets the
     *
     * @param   fc The frequency.
     *
     * @return This object (Fluent API).
     *
     * @details
     * @examples
     *
     * @snippet testAngleSpectrumPlot.cpp AngleSpectrumPlot_SetCentreFrequency
     *
     * ![SetCentreFrequence Example](AngleSpectrumPlot_SetCentreFrequency.png)
     */

    AngleSpectrumPlot &SetCentreFrequency( int32_t fc );

    /**
     * Sets the padding for the Fourier Transform.
     *
     * @param   pad The padding.
     *
     * @return This object (Fluent API).
     *
     * @details
     * @examples
     *
     * @snippet testAngleSpectrumPlot.cpp AngleSpectrumPlot_SetPadTo
     *
     * ![SetPadTo Example](AngleSpectrumPlot_SetPadTo.png)
     */

    AngleSpectrumPlot &SetPadTo( int32_t pad );

private:

    std::stringstream mStream;

    std::string GetSides( Sides sides );

};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/angleSpectrumPlot.cpp"
#endif

#endif