@echo off

REM путь к тестируемой программе передаетс€ через первый аргумент командной строки
SET MyProgram="%~1"
set searchStringEmpty=""
set replacementEmpty=""
set searchString=A
set replacement=!
REM «ащита от запуска без аргумента задающего путь к программе
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM подаем на вход пустой файл input
%MyProgram% empty.txt "%TEMP%\output.txt" %searchString% %replacement% || goto err
fc empty.txt "%TEMP%\output.txt">nul || goto err
echo Test 1 passed

REM копируем отсутствующий файл
%MyProgram% MissingInput.txt "%TEMP%\output.txt" %searchString% %replacement% && goto err
echo Test 2 passed

REM подаем недостаточно аргументов
REM if output file is not specifiled, program must fail
%MyProgram% MissingInput.txt && goto err
echo Test 3 passed

REM подаем без аргументов
REM if input and output files is not specifiled, program must fail
%MyProgram% && goto err
echo Test 4 passed

REM подаем на вход пустую строку searchString
%MyProgram% OneSimbolReplaceable.txt "%TEMP%\output.txt" %searchStringEmpty% %replacement% || goto err
fc OneSimbolReplaceable.txt "%TEMP%\output.txt">nul || goto err
echo Test 5 passed

REM подаем на вход пограничные состо€ни€ положени€ искомой подстроки (начало конец строки регистр повторение подр€д)
%MyProgram% input.txt "%TEMP%\output.txt" %searchString% %replacement% || goto err
fc borderStatesOut.txt "%TEMP%\output.txt">nul || goto err
echo Test 6 passed

REM подаем на вход пустeую строку замены repalce
%MyProgram% OneSimbolReplaceable.txt "%TEMP%\output.txt" %searchString% %replacementEmpty% || goto err
fc empty.txt "%TEMP%\output.txt">nul || goto err
echo Test 7 passed


REM “есты прошли успешно
echo All tests passed successfuly
exit /B 0
REM ¬ случае ошибки
:err
echo Test failed
exit /B 1
