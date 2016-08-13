# PlotLib
PlotLib is an easy to use, C++ plotting library that produces scientific publication quality ready images.

# Status
OS          | Status
----------- | -------
Linux & OSX | [![Build Status](https://travis-ci.org/Zefiros-Software/PlotLib.svg?branch=master)](https://travis-ci.org/Zefiros-Software/PlotLib)
Windows     | [![Build status](https://ci.appveyor.com/api/projects/status/w46ca7on3w4mwv38?svg=true)](https://ci.appveyor.com/project/PaulVisscher/plotlib)

# Requirements
PlotLib makes use of [MatplotLib](http://matplotlib.org/) and [Seaborn](http://stanford.edu/~mwaskom/software/seaborn/) to produce its images.
PlotLib assumes that there is a full SciPy stack installed in the path. 

# [ZPM](zpm.zefiros.eu) Installation

In `.package.json`
```json
"requires": [
		{
			"name": "Zefiros-Software/PlotLib",
			"version": "^1.0.0"
		}
]
```

In `premake5.lua`
```lua
zpm.uses "Zefiros-Software/PlotLib"
```

## Manual Installation
The easiest installation is running [Anaconda](https://www.continuum.io/downloads).
Please note that Anaconda misses the Seaborn package which we install using:

```
pip install seaborn -U
```

## Bugs
When a bug is found please insert it in the issue tracker, so we can resolve it as quickly as we can.

## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Authors
* Mick van Duijn <mick.v.duijn@zefiros.eu>
* Paul Visscher <p.e.visscher@zefiros.eu>
* Koen Visscher <koen.visscher@zefiros.eu>

## Used By
We are interested to find out what projects use SerLib. We would love it to include your projects here, 
just shoot us a mail. :)

* Zefiros Engine 

## License
This project is licensed under the MIT license.

```
Copyright (c) 2015 Mick van Duijn, Koen Visscher and Paul Visscher

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```