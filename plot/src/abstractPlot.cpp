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

#include "plot/abstractPlot.h"

#include "plot/vec.h"
#include "plot/mat.h"

PLOTLIB_INLINE AbstractPlot::~AbstractPlot()
{
}

PLOTLIB_INLINE std::string AbstractPlot::GetBool( bool boolean )
{
    return boolean ? "True" : "False";
}

PLOTLIB_INLINE std::string AbstractPlot::ToArray( const Vec &vec )
{
    const std::vector< std::string > vecStr = vec.GetStrings();
    return vecStr.size() ? ToArray( vecStr ) : ToArray( vec.GetData() );
}

PLOTLIB_INLINE std::string AbstractPlot::ToArray( const Mat &mat )
{
    const std::vector<std::vector< std::string > > matStr = mat.GetStrings();
    return matStr.size() ? ToArray( matStr ) : ToArray( mat.GetData() );
}

PLOTLIB_INLINE std::string AbstractPlot::ToArray( const std::vector< std::vector< double > > &mat )
{
    std::stringstream stream;
    stream << "[";
    bool first = true;

    for ( auto vec : mat )
    {
        if ( !first )
        {
            stream << ",";
        }

        stream << "[" + ToString( vec.begin(), vec.end() ) + "]";
        first = false;
    }

    return stream.str() + "]";
}

PLOTLIB_INLINE std::string AbstractPlot::ToArray( const std::vector< double > &vec )
{
    return "[" + ToString( vec.begin(), vec.end() ) + "]";
}

PLOTLIB_INLINE std::string AbstractPlot::ToArray( const std::vector<std::string> &vec )
{
    return "[" + ToString( vec.begin(), vec.end(), "'" ) + "]";
}

PLOTLIB_INLINE std::string AbstractPlot::ToArray( const std::vector<bool> &vec )
{
    return "[" + ToString( vec.begin(), vec.end() ) + "]";
}

PLOTLIB_INLINE std::string AbstractPlot::ToArray( const std::vector< std::vector< std::string > > &mat )
{
    std::stringstream stream;
    stream << "[";
    bool first = true;

    for ( auto vec : mat )
    {
        if ( !first )
        {
            stream << ",";
        }

        stream << "[" + ToString( vec.begin(), vec.end(), "'" ) + "]";
        first = false;
    }

    return stream.str() + "]";
}
