#pragma once
#ifndef __INTERACTPLOT_H__
#define __INTERACTPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/vec.h"

#include <string>
#include "palette.h"

class InteractPlot
    : public AbstractPlot
{
public:

    InteractPlot( const Vec &endogenous, const Vec &endogenous2, const Vec &exogenous )
    {
        mStream << "sns.interactplot(" << ToArray( endogenous ) << "," << ToArray( endogenous2 ) << "," << ToArray( exogenous );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    InteractPlot &SetFilled( bool filled )
    {
        mStream << ", filled =" << GetBool( filled );
        return *this;
    }

    InteractPlot &SetColourMap( Palette pallet )
    {
        pallet.SetColourMap( true );
        mStream << ", cmap =" << pallet.ToString();
        return *this;
    }

    InteractPlot &SetColourBar( bool bar )
    {
        mStream << ", colorbar =" << GetBool( bar );
        return *this;
    }

    InteractPlot &SetLevels( size_t levelCount )
    {
        mStream << ", levels =" << levelCount;
        return *this;
    }

    InteractPlot &SetLevels( const Vec &levels )
    {
        mStream << ", levels =" << ToArray( levels );
        return *this;
    }

    InteractPlot &SetLogistic( bool logistic )
    {
        mStream << ", logistic =" << GetBool( logistic );
        return *this;
    }

private:

    std::stringstream mStream;
};

#endif