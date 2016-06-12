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

local result, errorCode = os.outputof( "conda --version" )

-- check if installed
if result:gsub( "conda %d+%.%d+%.%d+", "" ) == result then

    if os.get() == "windows" then

        zpm.util.download( "repo.continuum.io/archive/Anaconda3-4.0.0-Windows-x86_64.exe", zpm.temp, "*" )
        local file = string.format( "%s/%s", zpm.temp, "Anaconda3-4.0.0-Windows-x86_64.exe" )
        os.execute( file )

        os.remove( file )

    elseif os.get() == "osx" then

        zpm.util.download( "repo.continuum.io/archive/Anaconda3-4.0.0-MacOSX-x86_64.sh", zpm.temp, "*" )
        local file = string.format( "%s/%s", zpm.temp, "Anaconda3-4.0.0-MacOSX-x86_64.sh" )
        os.execute( string.format( "bash %s", file ) )

        os.remove( file )

    elseif os.get() == "linux" then

        zpm.util.download( "repo.continuum.io/archive/Anaconda3-4.0.0-Linux-x86_64.sh", zpm.temp, "*" )
        local file = string.format( "%s/%s", zpm.temp, "Anaconda3-4.0.0-Linux-x86_64.sh" )
        os.execute( string.format( "bash %s", file ) )

        os.remove( file )

    else
        errorf( "This os '%s' is currently not supported!", os.get() ) 
    end

else
    os.execute( "conda update conda" )
end