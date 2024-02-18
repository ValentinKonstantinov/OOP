@echo off

REM ���� � ����������� ��������� ���������� ����� ������ �������� ��������� ������
SET MyProgram="%~1"
set searchStringEmpty=""
set replacementEmpty=""
set searchString=A
set replacement=!
REM ������ �� ������� ��� ��������� ��������� ���� � ���������
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM ������ �� ���� ������ ���� input
%MyProgram% empty.txt "%TEMP%\output.txt" %searchString% %replacement% || goto err
fc empty.txt "%TEMP%\output.txt">nul || goto err
echo Test 1 passed

REM �������� ������������� ����
%MyProgram% MissingInput.txt "%TEMP%\output.txt" %searchString% %replacement% && goto err
echo Test 2 passed

REM ������ ������������ ����������
REM if output file is not specifiled, program must fail
%MyProgram% MissingInput.txt && goto err
echo Test 3 passed

REM ������ ��� ����������
REM if input and output files is not specifiled, program must fail
%MyProgram% && goto err
echo Test 4 passed

REM ������ �� ���� ������ ������ searchString
%MyProgram% OneSimbolReplaceable.txt "%TEMP%\output.txt" %searchStringEmpty% %replacement% || goto err
fc OneSimbolReplaceable.txt "%TEMP%\output.txt">nul || goto err
echo Test 5 passed

REM ������ �� ���� ����������� ��������� ��������� ������� ��������� (������ ����� ������ ������� ���������� ������)
%MyProgram% input.txt "%TEMP%\output.txt" %searchString% %replacement% || goto err
fc borderStatesOut.txt "%TEMP%\output.txt">nul || goto err
echo Test 6 passed

REM ������ �� ���� ����e�� ������ ������ repalce
%MyProgram% OneSimbolReplaceable.txt "%TEMP%\output.txt" %searchString% %replacementEmpty% || goto err
fc empty.txt "%TEMP%\output.txt">nul || goto err
echo Test 7 passed


REM ����� ������ �������
echo All tests passed successfuly
exit /B 0
REM � ������ ������
:err
echo Test failed
exit /B 1
