@echo off

REM путь к тестируемой программе передается через 1 аргумент командной строки
SET MyProgram="%~1"
REM Защита от запуска без аргумента задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)


REM Copy empty file
%MyProgram% empty.txt "%TEMP%\output.txt" || goto err
fc empty.txt "%TEMP%\output.txt" || goto err


REM Тесты прошли успешно
exit /B 0
REM В случае ошибки
:err
echo Test failed
exit /B 1
