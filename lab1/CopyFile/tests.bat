@echo off

REM ���� � ����������� ��������� ���������� ����� ������ �������� ��������� ������
SET MyProgram="%~1"

REM ������ �� ������� ��� ��������� ��������� ���� � ���������
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
)

REM �������� ������ ����
%MyProgram% empty.txt "%TEMP%\output.txt" || goto err
fc empty.txt "%TEMP%\output.txt">nul || goto err
echo Test 1 passed

REM �������� �� ������ ����
%MyProgram% nonEmpty.txt "%TEMP%\output.txt" || goto err
fc nonEmpty.txt "%TEMP%\output.txt">nul || goto err
echo Test 2 passed

REM �������� ������������� ����
%MyProgram% MissingFile.txt "%TEMP%\output.txt" && goto err
echo Test 3 passed

REM ������ ������������ ����������
REM if output file is not specifiled, program must fail
%MyProgram% MissingFile.txt && goto err
echo Test 4 passed

REM ������ ��� ����������
REM if input and output files is not specifiled, program must fail
%MyProgram% && goto err
echo Test 5 passed


REM ����� ������ �������
echo All tests passed successfuly
exit /B 0
REM � ������ ������
:err
echo Test failed
exit /B 1
