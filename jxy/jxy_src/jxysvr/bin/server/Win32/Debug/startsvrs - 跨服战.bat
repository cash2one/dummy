@echo off

call :startcommonsvrs s000
call :startsvrs s001
call :startsvrs s002
call :startsvrs s003
call :startsvrs s004

call :startgatesvr s001
rem call :startgatesvr s002
rem call :startgatesvr s003
rem call :startgatesvr s004

rem start "" "gmserver\gmserver.exe"
rem start "" "loginserver\loginserver.exe"
rem start "" "monitorserver\monitorserver.exe"

rem pause
exit



:startcommonsvrs
    rem start ������һ���Ǳ������� �ڶ����ǽ���·��

    set svrdir=%1

    echo ------------------��ʼ����%svrdir%�µķ�����-----------------------

    echo ����%svrdir%�µ�gmserver������
    start "%svrdir%\gmserver\gmserver.exe" "%svrdir%\gmserver\gmserver.exe"
    
    echo ����%svrdir%�µ�pkserver������
    start "%svrdir%\pkserver\pkserver.exe" "%svrdir%\pkserver\pkserver.exe"

    echo.
goto :eof

:startsvrs
    set svrdir=%1

    echo ------------------��ʼ����%svrdir%�µķ�����-----------------------

    echo ����%svrdir%�µ�gameserver������
    start "%svrdir%\gameserver\1\gameserver.exe" "%svrdir%\gameserver\1\gameserver.exe"

    rem echo ����%svrdir%�µ�gateserver������
    rem start "%svrdir%\gateserver\gateserver.exe" "%svrdir%\gateserver\gateserver.exe"

    rem echo ����%svrdir%�µ�monitorserver������
    rem start "%svrdir%\gameserver\monitorserver.exe" "%svrdir%\monitorserver\monitorserver.exe"

    echo.
goto :eof

:startgatesvr
    set svrdir=%1

    echo ------------------��ʼ����%svrdir%�µ����ط�����-----------------------

    echo ����%svrdir%�µ�gateserver������
    start "%svrdir%\gateserver\gateserver.exe" "%svrdir%\gateserver\gateserver.exe"

    echo.
goto :eof