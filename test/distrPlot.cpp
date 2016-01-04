#include "helper.h"

TEST( PX( DirectOLS ), Simple )
{
    vec ex = linspace( 0, 1, 1000 );
    vec distr = randn( 1000 );
    vec distr2 = randn( 1000 );
    Plot()
    .AddPlot( InteractPlot( distr, distr2, ex ).SetFilled( true ).SetColourMap( CubeHelixPalette() ).SetLogistic( true ) )
    .SetXLabel( "LOL" )
    .SetLegend( {"X", "Y"} )
    .Show();
}