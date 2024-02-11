@echo off

REM путь к тестируемой программе передаетс€ через первый аргумент командной строки
SET MyProgram="%~1"

REM «ащита от запуска без аргумента задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM копируем пустой файл
%MyProgram% empty.txt "%TEMP%\output.txt" || goto err
fc empty.txt "%TEMP%\output.txt">nul || goto err
echo Test 1 passed

REM копируем не пустой файл
%MyProgram% nonEmpty.txt "%TEMP%\output.txt" || goto err
fc nonEmpty.txt "%TEMP%\output.txt">nul || goto err
echo Test 2 passed

REM копируем отсутствующий файл
%MyProgram% MissingFile.txt "%TEMP%\output.txt" && goto err
echo Test 3 passed

REM подаем недостаточно аргументов
REM if output file is not specifiled, program must fail
%MyProgram% MissingFile.txt && goto err
echo Test 4 passed

REM подаем без аргументов
REM if input and output files is not specifiled, program must fail
%MyProgram% && goto err
echo Test 5 passed


REM “есты прошли успешно
echo All tests passed successfuly
exit /B 0
REM ¬ случае ошибки
:err
echo Test failed
exit /B 1
