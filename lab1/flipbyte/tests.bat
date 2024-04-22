@echo off
SET MyProgram="%~1"
REM ���� � ����������� ��������� ���������� ����� ������ �������� ��������� ������
REM ������ �� ������� ��� ��������� ��������� ���� � ���������
REM if %MyProgram%=="" (
REM 	echo Please specify path to program
REM 	exit /B 1
REM )

REM ������ ������������ ����������
REM if output file is not specifiled, program must fail
%MyProgram% MissingInput.txt && goto err
echo Test 1 passed

REM ������ ��� ����������
REM if input and output files is not specifiled, program must fail
%MyProgram% && goto err
echo Test 2 passed

REM ����������� ��������  0 
%MyProgram% 0 > output.txt || goto err
fc output.txt 0.txt || goto err
echo Test 4 passed

REM ����������� ��������  255 
%MyProgram% 255 > output.txt || goto err
fc output.txt 255.txt || goto err
echo Test 5 passed

REM �������� �� ��������� ����������� 256 
%MyProgram% 256 > output.txt && goto err
echo Test 6 passed


REM �������� �� ��������� ����������� -1 
%MyProgram% -1 > output.txt && goto err
echo Test 7 passed

REM ����������� ��������  253 
%MyProgram% 253 > output.txt || goto err
fc output.txt 253.txt || goto err
echo Test 8 passed

REM 
%MyProgram% a > output.txt && goto err
echo Test 9 passed

REM ����� ������ �������
echo All tests passed successfuly
exit /B 0
REM � ������ ������
:err
echo Test failed
exit /B 1
