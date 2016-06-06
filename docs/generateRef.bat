@echo off
rmdir /s /q out
%~dp0..\\assets\\Zefiros-Software\\SerLib\\Zefiros-Software\\Doxygen\\bin\\doxygen.exe reference.doxy 
%~dp0..\\assets\\Zefiros-Software\\SerLib\\Zefiros-Software\\Doxygen\\hhc.exe out\\html\\index.hhp