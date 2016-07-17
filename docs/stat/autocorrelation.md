# Auto Correlation Plot
A plot annotation that implements the
[`acorr`](http://matplotlib.org/api/pyplot_api.html#matplotlib.pyplot.acorr)
functionality.

<p align="center"><img src="/images/AutoCorrelationPlot.png" alt="Plot Example"></p>

# Interface
The `AutoCorrelationPlot` is:
````cpp
class AutoCorrelationPlot
{
    AutoCorrelationPlot( const Vec &vec );
    AutoCorrelationPlot &Hold( bool hold );
    AutoCorrelationPlot &Normed( bool normed );
    AutoCorrelationPlot &VLines( bool vlines );
    AutoCorrelationPlot &SetMaxLags( size_t maxlags );
}
````

## Functions

### `AutoCorrelationPlot( const Vec &vec )`
Plots the autocorrelation of `vec`.

* `vec` The vector to analyse.

----

### `AutoCorrelationPlot &Hold( bool hold )`
Default `true`.

----

### `AutoCorrelationPlot &Normed( bool normed )`
Normalises the data by the auto-correlation at the 0th lag.

* `normed` Whether it is normalised.

----

### `AutoCorrelationPlot &VLines( bool vlines )`
Whether we plot the auto-correlation using vertical lines or not.

* `vlines` Whether we want to use vertical lines.

----

### `AutoCorrelationPlot &SetMaxLags( size_t maxlags )`
Sets the maximum amount of lags we plot.

* `maxlags` The amount of lags to plot.

----

# Other Arguments
This object is a [`Line2D`](../../properties/line2d) class, and shares its
properties when `vlines` is true.

----

# Examples

```cpp
vec randVec = randu( 200 );
AutoCorrelationPlot f( randVec );
```
<p align="center"><img src="/images/AutoCorrelationPlot.png" alt="Plot Example"></p>

----

```cpp
vec randVec = randu( 200 );
AutoCorrelationPlot f( randVec );
f.SetLineWidth( 3 )
.SetColour( "b" )
.Hold( false )
.Normed( true );
```
<p align="center"><img src="/images/AutoCorrelationPlot_SetHold.png" alt="Plot Example"></p>

----

```cpp
vec randVec = randu( 200 );
AutoCorrelationPlot f( randVec );
f.SetMarker( "." )
.VLines( false )
.SetMaxLags( 100 );
```
<p align="center"><img src="/images/AutoCorrelationPlot_SetVLines.png" alt="Plot Example"></p>