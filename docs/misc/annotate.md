# Annotate Plot
A plot annotation that implements the
[`annotate`](http://matplotlib.org/api/pyplot_api.html#matplotlib.pyplot.annotate)
functionality.

<p align="center"><img src="/images/AnnotatePlot.png" alt="Plot Example"></p>

# Interface
The `AnnotatePlot` is:
````cpp
class AnnotatePlot
{
    AnnotatePlot( const std::string &label, double x, double y );
    AnnotatePlot &SetXY( double x, double y );
    AnnotatePlot &SetXYText( double x, double y );
    AnnotatePlot &SetXYCoordinates( Type type );
    AnnotatePlot &SetTextCoordinates( Type type );
}
````

## Functions

### `AnnotatePlot( const std::string &label, double x, double y )`
Constructs the annotation with text `label` and position `x` and `y`.

* `label` The text to annotate.
* `x` The x-coordinate.
* `y` The y-coordinate.

----

### `AnnotatePlot &SetXYText( double x, double y )`
Set the text position in the plot to annotate.

* `x` The x-coordinate.
* `y` The y-coordinate.

----

### `AnnotatePlot &SetXYCoordinates( Type type )`
Sets how the coordinates for the position are interpreted.

* `type` Specifies coordinate type.

**Where** `type` is one of:

* `AnnotatePlot::Type::FigurePoints`
* `AnnotatePlot::Type::FigurePixels`
* `AnnotatePlot::Type::FigureFraction`
* `AnnotatePlot::Type::AxesPoints`
* `AnnotatePlot::Type::AxesPixels`
* `AnnotatePlot::Type::AxesFraction`
* `AnnotatePlot::Type::Data`
* `AnnotatePlot::Type::OffsetPoints`
* `AnnotatePlot::Type::Pola`

----

### `AnnotatePlot &SetTextCoordinates( Type type )`
Sets how the coordinates for the text position are interpreted.

* `type` Specifies coordinate type.

**Where** `type` is one of:

* `AnnotatePlot::Type::FigurePoints`
* `AnnotatePlot::Type::FigurePixels`
* `AnnotatePlot::Type::FigureFraction`
* `AnnotatePlot::Type::AxesPoints`
* `AnnotatePlot::Type::AxesPixels`
* `AnnotatePlot::Type::AxesFraction`
* `AnnotatePlot::Type::Data`
* `AnnotatePlot::Type::OffsetPoints`
* `AnnotatePlot::Type::Pola`

----

# Examples

```cpp
AnnotatePlot f( "Hello World!", 0.5, 0.5 );
```
<p align="center"><img src="/images/AnnotatePlot.png" alt="Plot Example"></p>

----

```cpp
AnnotatePlot f( "Hello World!", 0.0, 0.0 );
f.SetXYText( 0.2, 0.2 );
```
<p align="center"><img src="/images/AnnotatePlot_SetXYText.png" alt="Plot Example"></p>

----

```cpp
AnnotatePlot f( "Hello World!", 0.0, 0.0 );
f.SetXYText( 20, 50 )
.SetXYCoordinates( AnnotatePlot::Type::AxesPixels )
.SetTextCoordinates( AnnotatePlot::Type::AxesPixels );
```
<p align="center"><img src="/images/AnnotatePlot_SetType.png" alt="Plot Example"></p>