#include "helper.h"

TEST( PX( DirectOLS ), Simple )
{
    vec ex = linspace( 0, 1, 1000 );
    vec distr = randi<vec>( 1000, distr_param( 0, 20 ) );
    vec distr2 = randn( 1000 );
    Plot()
    .AddPlot( BoxPlot( {{distr, distr2}, {distr, distr2}}, {"Male", "Female"} ) )
    .SetXLabel( "LOL" )
    .SetLegend( {"X", "Y"} )
    .Show();
}