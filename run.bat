@echo off
setlocal

cd SPU
cd src
cd ../build

compiler.exe "../../%~1"

spu.exe

cd ../../

endlocal