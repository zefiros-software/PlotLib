-- [[
-- @cond ___LICENSE___
--
-- Copyright (c) 2016-2018 Zefiros Software.
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
-- ]]
project "PlotLib"

    kind "StaticLib"

    if not zpm.setting("headerOnly") then
        zpm.export [[
            defines "PLOTLIB_NO_HEADER_ONLY"
        ]]
    
        
        files "plot/src/**.cpp"
    end

    if zpm.has("Zefiros-Software/Miniconda", "modules") then
        zpm.export [[
            defines "PLOTLIB_USE_ZPM_ANACONDA"
        ]]

    end

    if zpm.has("Zefiros-Software/Armadillo") then
        zpm.export [[
            defines "PLOTLIB_ARMA"
        ]]

    end

    zpm.export [[
        includedirs "plot/include/"
        cppdialect "C++11"
    ]]
