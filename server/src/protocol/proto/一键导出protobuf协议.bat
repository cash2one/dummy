@echo off
set protoc=protoc.exe
rem set protoc=..\..\..\3rd\protobuf\protoc-2.5.0-win32\protoc.exe
set gen_dir=..
set cur_dir=%~dp0

echo 0. ���ԭ������

rem del /Q /S *.h
rem del /Q /S *.cpp
rem del /Q /S *.xsd
del /Q /S %gen_dir%\*.h
del /Q /S %gen_dir%\*.cpp

rem �������������е�һЩ���ŵ�˵��
rem %~dp0 =��ǰ�̷�+·������: d:\xxx\xxx
rem ͬʱ�����������forѭ����
rem %%s   =��ȫ�ļ�·����  ��: d:\abc.txt�����е�s�����Ǳ����ĸ����%%x
rem %%~nxs=�ļ�������չ��  ��: abc.txt
rem %%~ns =�ļ���������չ����: abc

echo 1. ����protobuf�ļ�
    for /F %%x in ('dir /b /a-d /s "*.proto"') do (
        echo ���ڴ���[ %%~nxx ]
        %protoc% %%~nxx --cpp_out=%gen_dir%/
    )

pause