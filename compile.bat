@echo off
setlocal

if "%~1"=="" (
    echo Ошибка: Укажите исходный файл.
    echo Пример: compile source_file dest_file
    exit /b 1
)

if "%~2"=="" (
    echo Ошибка: Укажите выходной файл.
    echo Пример: compile source_file dest_file
    exit /b 1
)

:: frontend
cd frontend/build
frontend.exe "../../%~1" "../../res_tree.txt"
cd ../..

:: middlend
cd middlend/build
middlend.exe "../../res_tree.txt" "../../res_tree.txt"
cd ../..

:: backend
cd backend/build
backend.exe "../../res_tree.txt" "../../%~2"
cd ../..

:: Возвращаемся обратно
cd ../../

endlocal