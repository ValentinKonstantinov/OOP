@echo off

REM путь к тестируемой программе передается через первый аргумент командной строки
SET MyProgram="%~1"

REM Защита от запуска без аргумента задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM подаем на вход пустой файл input
%MyProgram% empty.txt "%TEMP%\output.txt" searchFile.txt replaceFile.txt || goto err
fc empty.txt "%TEMP%\output.txt">nul || goto err
echo Test 1 passed

REM подаем на вход пустой файл маску 
%MyProgram% nonEmptyOneSimbolReplace.txt "%TEMP%\output.txt" searchFileEmpty.txt replaceFile.txt || goto err
fc nonEmptyOneSimbolReplace.txt "%TEMP%\output.txt">nul || goto err
echo Test 2 passed

REM копируем отсутствующий файл
%MyProgram% MissingInput.txt "%TEMP%\output.txt" searchFileEmpty.txt replaceFile.txt && goto err
%MyProgram% nonEmptyOneSimbolReplace.txt "%TEMP%\output.txt" MissingSearchFileEmpty.txt replaceFile.txt && goto err
echo Test 3 passed

REM подаем недостаточно аргументов
REM if output file is not specifiled, program must fail
%MyProgram% MissingInput.txt && goto err
echo Test 4 passed

REM подаем без аргументов
REM if input and output files is not specifiled, program must fail
%MyProgram% && goto err
echo Test 5 passed

REM подаем на вход пустой файл замены repalce
%MyProgram% nonEmptyOneSimbolReplace.txt "%TEMP%\output.txt" searchFile.txt replaceFileEmpty.txt || goto err
fc replaceFileEmpty.txt "%TEMP%\output.txt">nul || goto err
echo Test 6 passed

REM подаем на вход пограничные состояния положения искомой подстроки (начало конец строки регистр повторение подряд)
%MyProgram% input.txt "%TEMP%\output.txt" searchFile.txt replaceFile.txt || goto err
fc borderStatesOut.txt "%TEMP%\output.txt">nul || goto err
echo Test 7 passed

REM Тесты прошли успешно
echo All tests passed successfuly
exit /B 0
REM В случае ошибки
:err
echo Test failed
exit /B 1
