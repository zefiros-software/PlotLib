#pragma once
#ifndef __ABSTRACTPLOT_H__
#define __ABSTRACTPLOT_H__

#include "plot/vec.h"
#include "plot/mat.h"

#include <sstream>
#include <string>
#include <vector>

class AbstractPlot
{
public:

    virtual ~AbstractPlot()
    {
    }

    virtual std::string ToString() const = 0;

    static std::string GetBool( bool boolean )
    {
        return boolean ? "True" : "False";
    }

    static std::string ToArray( const Vec &vec )
    {
        return ToArray( vec.GetData() );
    }

    static std::string ToArray( const Mat &vec )
    {
        return ToArray( vec.GetData() );
    }

    static std::string ToArray( const std::vector< double > &vec )
    {
        return "[" + ToString( vec.begin(), vec.end() ) + "]";
    }

    static std::string ToArray( const std::vector< std::vector< double > > &mat )
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

    static std::string ToArray( const std::vector<std::string> &vec )
    {
        return "[" + ToString( vec.begin(), vec.end(), "'" ) + "]";
    }

    static std::string ToArray( const std::vector<bool> &vec )
    {
        return "[" + ToString( vec.begin(), vec.end() ) + "]";
    }

protected:

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

#endif