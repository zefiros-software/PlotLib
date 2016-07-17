# Arrow Plot
A plot annotation that implements the
[`arrow`](http://matplotlib.org/api/pyplot_api.html#matplotlib.pyplot.arrow)
functionality.

<p align="center"><img src="/images/ArrowPlot.png" alt="Plot Example"></p>

# Interface
The `ArrowPlot` is:
````cpp
class ArrowPlot
{
    ArrowPlot( double x, double y, double dx, double dy );
    ArrowPlot &SetWidth( double width );
    ArrowPlot &LengthIncludesHead( bool includes );
    ArrowPlot &SetHeadWidth( double width );
    ArrowPlot &SetHeadLength( double length );
    ArrowPlot &SetShape( Shape shape );
    ArrowPlot &SetOverhang( double overhang );
    ArrowPlot &HeadStartsAtZero( bool starts );
}
````

## Functions

### `ArrowPlot( double x, double y, double dx, double dy )`
Plots an **arrow** from point with an offset.

* `x` **X-coordinate** to start drawing from
* `y` **Y-coordinate** to start drawing from
* `dx` **X-offset** to start drawing from the origin.
* `dy` **Y-offset** to start drawing from the origin.

----

### `ArrowPlot &SetWidth( double width )`
Sets the **width** of the arrow. Default `0.001`.

* `width` The **width** of the arrow.

----

### `ArrowPlot &LengthIncludesHead( bool includes )`
Sets whether the head of the arrow is **included** in the length.
Default is `false`.

* `includes` Whether the length is **included**.

----

### `ArrowPlot &SetHeadWidth( double width )`
Sets the width of the head. Default is `width*3`.

* `width` The **width** of the head.

----

### `ArrowPlot &SetHeadLength( double length )`
Sets the length of the head. Default is `head_width*1.5`.

* `length` The **length** of the head.

----

### `ArrowPlot &SetShape( Shape shape )`
Sets the **shape** of the arrow.

* `shape` The **shape** of the head.

**Where** `shape` is one of:

* `ArrowPlot::Shape::Full`
* `ArrowPlot::Shape::Left`
* `ArrowPlot::Shape::Right`

----

### `ArrowPlot &SetOverhang( double overhang )`
Sets the arrow overhang. Default is `0`.

* `overhang` The arrow overhang.

----

### `ArrowPlot &HeadStartsAtZero( bool starts )`
Whether to start drawing the head at the first coordinate or to end at it. Default `false`.

* `starts` Start or end the head at the coordinate.

----

# Other Arguments
This object is a [`Patch`](../../properties/patch) class, and shares its
properties.

----

# Examples

```cpp
ArrowPlot f( 0, 0.1, 1, 0.5 );
```
<p align="center"><img src="/images/ArrowPlot.png" alt="Plot Example"></p>

----

```cpp
ArrowPlot f( 0, 0.1, 0.7, 0.5 );
f.SetWidth( 0.009 );
```
<p align="center"><img src="/images/ArrowPlot_SetWidth.png" alt="Plot Example"></p>

----

```cpp
ArrowPlot f( 0, 0.1, 1, 0.5 );
f.LengthIncludesHead( true );
```
<p align="center"><img src="/images/ArrowPlot_LengthIncludesHead.png" alt="Plot Example"></p>

----

```cpp
ArrowPlot f( 0, 0.1, 0.8, 0.5 );
f.LengthIncludesHead( true )
.SetHeadWidth( 0.05 )
.SetHeadLength( 0.05 )
.SetOverhang( -1 );
```
<p align="center"><img src="/images/ArrowPlot_SetHead.png" alt="Plot Example"></p>

----

```cpp
ArrowPlot f( 0, 0.1, 0.8, 0.5 );
f.SetShape( ArrowPlot::Shape::Left )
.SetHeadWidth( 0.08 )
.HeadStartsAtZero( true );
```
<p align="center"><img src="/images/ArrowPlot_HeadStartsAtZero.png" alt="Plot Example"></p>