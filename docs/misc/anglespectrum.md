# Angle Spectrum Plot
An **angle spectrum** plot, this is a wrapper for the
[angle_spectrum](http://matplotlib.org/api/pyplot_api.html#matplotlib.pyplot.angle_spectrum)
functionality.

<p align="center"><img src="/images/AngleSpectrumPlot.png" alt="Plot Example"></p>

# Interface
The `AngleSpectrumPlot` is:
````cpp
class AngleSpectrumPlot
{
    AngleSpectrumPlot( const Vec &vec );
    AngleSpectrumPlot &SetSamplingFrequency( double fs );
    AngleSpectrumPlot &SetSides( Sides sides );
    AngleSpectrumPlot &SetCentreFrequency( int32_t fc );
    AngleSpectrumPlot &SetPadTo( int32_t pad );
}
````

## Functions

### `AngleSpectrumPlot( const Vec &vec )`
Constructor that plots the **angle spectrum** of `vec`.

* `vec` The **vector** to analyse.

----

### `SetSamplingFrequency( double fs )`
Sets the **sampling frequency**, which is used to calculate the Fourier coefficients.
The **default** value is 2.

* `fs` The **frequency**.

----

### `SetSides( Sides sides )`
Sets which **side** the spectrum should return.

* `sides` The **sides** to return.

**Where** `sides` is one of:

 * `AngleSpectrumPlot::Sides::Default`
 * `AngleSpectrumPlot::Sides::OneSided`
 * `AngleSpectrumPlot::Sides::TwoSided`

----

### `SetCentreFrequency( int32_t fc )`
Sets the **centre frequency** (default 0). 

* `fc` The frequency.

----

### `SetPadTo( int32_t pad )`
Sets the **padding** for the Fourier Transform.

* `pad` The padding.

----

# Other Arguments
This object is a [`Line2D`](../../properties/line2d) class, and shares its
properties.

----

# Examples

```cpp
vec randVec = randu( 20 ) ;
AngleSpectrumPlot f( randVec );
```
<p align="center"><img src="/images/AngleSpectrumPlot.png" alt="Plot Example"></p>

----

```cpp
vec randVec = randu( 20 );
AngleSpectrumPlot f( randVec );
f.SetSamplingFrequency( 10 );
```
<p align="center"><img src="/images/AngleSpectrumPlot_SamplingFrequency.png" alt="SetSamplingFrequency Example"></p>

----

```cpp
vec randVec = randu( 20 );
AngleSpectrumPlot f( randVec );
f.SetSides( AngleSpectrumPlot::Sides::TwoSided );
```
<p align="center"><img src="/images/AngleSpectrumPlot_SetSides.png" alt="SetSamplingFrequency Example"></p>

----

```cpp
vec randVec = randu( 20 );
AngleSpectrumPlot f( randVec );
f.SetCentreFrequency( 5 );
```
<p align="center"><img src="/images/AngleSpectrumPlot_SetCentreFrequency.png" alt="SetCentreFrequency Example"></p>

----

```cpp
vec randVec = randu( 20 );
AngleSpectrumPlot f( randVec );
f.SetPadTo( 2 );
```
<p align="center"><img src="/images/AngleSpectrumPlot_SetPadTo.png" alt="SetPadTo Example"></p>