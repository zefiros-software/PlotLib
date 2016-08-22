--[[ @cond ___LICENSE___
-- Copyright (c) 2016 Koen Visscher, Paul Visscher and individual contributors.
--
-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to deal
-- in the Software without restriction, including without limitation the rights
-- to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-- copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:
--
-- The above copyright notice and this permission notice shall be included in
-- all copies or substantial portions of the Software.
--
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
-- THE SOFTWARE.
--
-- @endcond
--]]

local zefiros = require( "Zefiros-Software/Zefiros-Defaults", "@head" )

workspace "PlotLib"

	zefiros.setDefaults( "plot", {
		headerOnly = true,
        noHeaderOnlySwitch = "PLOTLIB_NO_HEADER_ONLY"
    } )

	floatingpoint "Fast"

    defines {
        "PLOTLIB_USE_ZPM_ANACONDA",
        "PLOTLIB_HEADLESS"
    }

    filter "not HeaderOnly*"
        defines "PLOTLIB_NO_HEADER_ONLY"

    filter {}

	project "plot-test"

        defines "PLOTLIB_ARMA"

		zpm.uses "Zefiros-Software/Armadillo"
    
	    debugdir "docs/images/"
            
        filter "not HeaderOnly*"
            links "plot"

        filter {}
            
    project "plot"
            
        filter "not HeaderOnly*"                
            files { 
                "plot/src/**.cpp",
                }

        filter {}