/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Mick van Duijn, Koen Visscher and Paul Visscher
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

#include "plot/properties/line2dProperties.h"
#include "plot/annotatePlot.h"

PLOTLIB_INLINE AnnotatePlot::AnnotatePlot( const std::string &label, double x, double y )
{
    mStream << "plt.annotate( s='" << label << "', xy=(" << x << "," << y << ")";
}

PLOTLIB_INLINE std::string AnnotatePlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE AnnotatePlot &AnnotatePlot::SetXYText( double x, double y )
{
    this->AddArgument( "xytext", this->ToTuple( x, y ) );
    return *this;
}

PLOTLIB_INLINE AnnotatePlot &AnnotatePlot::SetXYCoordinates( Type type )
{
    this->AddArgument( "xycoords", GetType( type ) );
    return *this;
}

PLOTLIB_INLINE AnnotatePlot &AnnotatePlot::SetTextCoordinates( Type type )
{
    this->AddArgument( "textcoords", GetType( type ) );
    return *this;
}

PLOTLIB_INLINE AnnotatePlot &AnnotatePlot::SetArrowProps( FancyArrow &props )
{
    this->AddArgument( "arrowprops", props.ToString() );
    return *this;
}

PLOTLIB_INLINE AnnotatePlot &AnnotatePlot::SetArrowProps( YArrow &props )
{
    this->AddArgument( "arrowprops", props.ToString() );
    return *this;
}

PLOTLIB_INLINE std::string AnnotatePlot::GetType( Type type )
{
    switch ( type )
    {
    case Type::FigurePoints:
        return "'figure points'";

    case Type::FigurePixels:
        return "'figure pixels'";

    case Type::FigureFraction:
        return "'figure fraction'";

    case Type::AxesPoints:
        return "'axes points'";

    case Type::AxesPixels:
        return "'axes pixels'";

    case Type::AxesFraction:
        return "'axes fraction'";

    case Type::Data:
        return "'data'";

    case Type::OffsetPoints:
        return "'offset points'";

    case Type::Polar:
        return "'polar'";
    }

    return "''";
}
