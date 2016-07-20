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

#include "plot/interactPlot.h"
#include "plot/vec.h"

PLOTLIB_INLINE InteractPlot::InteractPlot( const Vec &endogenous, const Vec &endogenous2, const Vec &exogenous )
{
    mStream << "sns.interactplot(" << ToArray( endogenous ) << "," << ToArray( endogenous2 ) << "," << ToArray( exogenous );
}

PLOTLIB_INLINE std::string InteractPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE InteractPlot &InteractPlot::Filled( bool filled )
{
    this->AddArgument( "filled", GetBool( filled ) );
    return *this;
}

PLOTLIB_INLINE InteractPlot &InteractPlot::SetColourMap( ColourMap pallet )
{
    this->AddArgument( "cmap", pallet.ToString() );
    return *this;
}

PLOTLIB_INLINE InteractPlot &InteractPlot::ColourBar( bool bar )
{
    this->AddArgument( "colorbar", GetBool( bar ) );
    return *this;
}

PLOTLIB_INLINE InteractPlot &InteractPlot::SetLevels( const Vec &levels )
{
    this->AddArgument( "levels", ToArray( levels ) );
    return *this;
}

PLOTLIB_INLINE InteractPlot &InteractPlot::SetLevels( size_t levelCount )
{
    this->AddArgument( "levels", levelCount );
    return *this;
}

PLOTLIB_INLINE InteractPlot &InteractPlot::Logistic( bool logistic )
{
    this->AddArgument( "logistic", GetBool( logistic ) );
    return *this;
}

PLOTLIB_INLINE InteractPlot &InteractPlot::SetScatter( Line &scatter )
{
    this->AddArgument( "scatter_kws", scatter.ToString() );
    return *this;
}

PLOTLIB_INLINE InteractPlot &InteractPlot::SetContour( Contour &contour )
{
    this->AddArgument( "contour_kws", contour.ToString() );
    return *this;
}
