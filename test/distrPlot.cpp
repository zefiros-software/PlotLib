#include "helper.h"

TEST( PX( DirectOLS ), Simple )
{
    vec ex = linspace( 0, 1, 1000 );
    vec distr = randn( 8873 );
    vec distr2 = randn( 8873 );
    Plot()
    .AddPlot( HexBinPlot( distr, distr2 ).SetColourMap( Palette( Palette::Colour::summer ) ) )
    .SetXLabel( "LOL" )
    .SetLegend( {"X", "Y"} )
    .Show();
}