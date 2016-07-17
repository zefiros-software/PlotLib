# Cross Correlation Plot
A plot annotation that implements the
[`xcorr`](http://matplotlib.org/api/pyplot_api.html#matplotlib.pyplot.xcorr)
functionality.

<p align="center"><img src="/images/CrossCorrelationPlot.png" alt="Plot Example"></p>

# Interface
The `CrossCorrelationPlot` is:
````cpp
class CrossCorrelationPlot
{
    CrossCorrelationPlot( const Vec &x, const Vec &y );
    CrossCorrelationPlot &Hold( bool hold );
    CrossCorrelationPlot &Normed( bool normed );
    CrossCorrelationPlot &VLines( bool vlines );
    CrossCorrelationPlot &SetMaxLags( size_t maxlags );
}
````

## Functions

### `CrossCorrelationPlot( const Vec &x, const Vec &y )`
Plots the Crosscorrelation of `vec`.

* `x` The vector to analyse.
* `y` The vector to analyse.

----

### `CrossCorrelationPlot &Hold( bool hold )`
Default `true`.

----

### `CrossCorrelationPlot &Normed( bool normed )`
Normalises the data by the Cross-correlation at the 0th lag.

* `normed` Whether it is normalised.

----

### `CrossCorrelationPlot &VLines( bool vlines )`
Whether we plot the Cross-correlation using vertical lines or not.

* `vlines` Whether we want to use vertical lines.

----

### `CrossCorrelationPlot &SetMaxLags( size_t maxlags )`
Sets the maximum amount of lags we plot.

* `maxlags` The amount of lags to plot.

----

# Other Arguments
This object is a [`Line2D`](../../properties/line2d) class, and shares its
properties when `vlines` is true.

----

# Examples

```cpp
vec xVec = randu( 200 );
vec yVec = randu( 200 );
CrossCorrelationPlot f( xVec, yVec );
```
<p align="center"><img src="/images/CrossCorrelationPlot.png" alt="Plot Example"></p>

----

```cpp
vec xVec = randu( 200 );
vec yVec = randu( 200 );
CrossCorrelationPlot f( xVec, yVec );
f.SetLineWidth( 3 )
.SetColour( "b" )
.Hold( false )
.Normed( true );
```
<p align="center"><img src="/images/CrossCorrelationPlot_SetHold.png" alt="Plot Example"></p>

----

```cpp
vec xVec = randu( 200 );
vec yVec = randu( 200 );
CrossCorrelationPlot f( xVec, yVec );
f.SetMarker( "." )
.VLines( false )
.SetMaxLags( 100 );
```
<p align="center"><img src="/images/CrossCorrelationPlot_SetVLines.png" alt="Plot Example"></p>