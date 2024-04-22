@echo off

SET MyProgram="%~1"

REM ���� � ����������� ��������� ���������� ����� ������ �������� ��������� ������
REM ������ �� ������� ��� ��������� ��������� ���� � ���������
 if %MyProgram%=="" (
	echo Please specify path to program
 	exit /B 1
 )

REM ������ ������������ ����������
REM if output file is not specifiled, program must fail
%MyProgram% MissingInput.txt && goto err
echo Test 1 passed

%MyProgram% fewNumbers.txt && goto err
echo Test 2 passed

%MyProgram% input.txt >"%TEMP%\output.txt"
exit
|| goto err
fc invertMatrix.txt "%TEMP%\output.txt" || goto err
echo Test 3 passed

REM ����� ������ �������
echo All tests passed successfuly
exit /B 0

REM � ������ ������
:err
echo Test failed
exit /B 1
