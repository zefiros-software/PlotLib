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
#ifndef __ABSTRACTPLOT_H__
#define __ABSTRACTPLOT_H__

#include "plot/define.h"

#include <sstream>
#include <string>
#include <vector>

class Vec;
class Mat;

/**
 * An abstract plot from which every plot type should inherit.
 * It provides utility classes to make easy python conversions.
 */

class AbstractPlot
{
public:

    AbstractPlot();

    AbstractPlot( const AbstractPlot &other );

    virtual ~AbstractPlot();

    /**
     * Convert this object into a string representation capable of python execution.
     *
     * @return A std::string that represents this object.
     */

    virtual std::string ToString() = 0;

    std::string ToString( const std::string &body ) const;

    static std::string GetString( const std::string &str );

    /**
     * Gets a boolean python representation.
     *
     * @param   boolean The boolean to convert.
     *
     * @return The bool.
     */

    static std::string GetBool( bool boolean );

    template< typename tT, typename tU >
    static std::string ToTuple( const tT &x, const tU &y )
    {
        std::stringstream ss;
        ss << "(" << x << "," << y << ")";
        return ss.str();
    }

    template< typename tT, typename tU, typename tV, typename tZ >
    static std::string ToTuple( const tT &x, const tU &y, const tV &z, const tZ &w )
    {
        std::stringstream ss;
        ss << "(" << x << "," << y << "," << z << "," << w << ")";
        return ss.str();
    }

    /**
     * Convert this vector into python representation.
     *
     * @param   vec The vector to convert.
     *
     * @return An array that represents the data in this object.
     */

    static std::string ToArray( const Vec &vec );

    /**
     * Convert this matrix into python representation.
     *
     * @param   mat The matrix to convert.
     *
     * @return An array that represents the data in this object.
     */

    static std::string ToArray( const ::Mat &mat );

    /**
     * Convert this vector into python representation.
     *
     * @param   mat The matrix to convert.
     *
     * @return An array that represents the data in this object.
     */

    static std::string ToArray( const std::vector< std::vector< double > > &mat );

    /**
     * Convert this vector into python representation.
     *
     * @param   vec The vector to convert.
     *
     * @return An array that represents the data in this object.
     */

    static std::string ToArray( const std::vector< double > &vec );

    /**
     * Convert this vector into python representation.
     *
     * @param   vec The vector to convert.
     *
     * @return An array that represents the data in this object.
     */

    static std::string ToArray( const std::vector< uint32_t > &vec );

    /**
     * Convert this vector into python representation.
     *
     * @param   vec The vector to convert.
     *
     * @return An array that represents the data in this object.
     */

    static std::string ToArray( const std::vector<std::string> &vec );

    /**
     * Convert this vector into python representation.
     *
     * @param   vec The vector to convert.
     *
     * @return An array that represents the data in this object.
     */

    static std::string ToArray( const std::vector<bool> &vec );

    /**
     * Convert this vector into python representation.
     *
     * @param   mat The matrix to convert.
     *
     * @return An array that represents the data in this object.
     */

    static std::string ToArray( const std::vector< std::vector< std::string > > &mat );

protected:

    std::stringstream mStream;

    uint32_t mCount;
    bool mIsDictionary;

    template< typename tT >
    void AddArgument( const std::string &name, const tT &value )
    {
        std::stringstream ss;

        if ( mIsDictionary )
        {
            if ( mCount++ != 0 )
            {
                ss << ", ";
            }

            ss << "'" << name << "' : " << value;
        }
        else
        {
            ss << "," << name << "=" << value;
        }

        mStream << ss.str();
    }

    /**
     * Convert the object into a python array representation.
     *
     * @tparam  tT Type of the t.
     * @param   begin     The begin.
     * @param   end       The end.
     * @param   delimiter The delimiter.
     *
     * @return The given data converted to a std::string.
     */

    template<typename tT>
    static std::string ToString( tT begin, tT end, const std::string &delimiter = "" )
    {
        std::stringstream ss;
        bool first = true;

        for ( ; begin != end; ++begin )
        {
            if ( !first )
            {
                ss << ", ";
            }

            ss << delimiter << *begin << delimiter;
            first = false;
        }

        return ss.str();
    }
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/abstractPlot.cpp"
#endif

#endif