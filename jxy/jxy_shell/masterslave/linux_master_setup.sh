#  @File Name: setup mysql binlog.sh
#  @Author: hongkunan
#  @Company: 
#  @Created Time: Sun 03 Nov 2013 05:56:54 AM PST

#!/bin/bash

set mysqlservice=mysqld

set masterdir="/root/master"
mycnf="/etc/my.cnf"
masterlog=$masterdir/"mysql_bin_log"

masterusr=root
masterpwd=123456
masterport=3306

slavehost=192.168.4.109
slavegrantusr=slave
slavegrantpwd=123456

echo 0. check the environment
    # �������binlog·���Ƿ����
    if [ -d masterdir ] ;then
        echo "check success: ${masterdir} exist!"
    else
        echo "check fail: ${masterdir} not exist!"
        exit
    fi
    
    # ���my.cnf�����ļ��Ƿ����
    if [ -f $mycnf ]; then
        echo "check success: ${mycnf} exist!"
    else
        echo "check fail: ${mycnf} not exist"
        exit
    fi

echo 1. configure $mycnf

	pre_logbin=$(grep -i "log-bin=*" $mycnf)
    if [ "$?" -eq "0" ]; then
        echo "check success: binlog = on"
        echo "pre logbin: ${pre_logbin}"
    else
        echo 'detecting binlog = off'
        
        cat << _EOF_ >> $mycnf

            # Binary Logging.
            log-bin=$masterlog
            server-id=1
            binlog-do-db=ios_app_cfg
            binlog-do-db=ios_app_pay
            binlog-do-db=ios_app_user
            binlog-do-db=ios_app_s001
            binlog-do-db=ios_app_s001_log
        _EOF_
    fi

echo 2. grant privileges on masterdb
	# ִ����Ȩ��䣬���ڽ���ʱ�Ѳ�ѯ��������log�ļ�
    mysql -u$masterusr  -p$masterpwd << _EOFMYSQL_ > log
        grant all privileges on *.* to root@"%" identified by '$masterpwd';
        flush privileges;

        grant replication slave on *.* to '$slavegrantusr'@'${slavehost}' identified by '$slavegrantpwd';
        show variables like 'log_%';
    _EOFMYSQL_

	# �Ƿ�ɹ�����logbin��ͨ����show variables like 'log_%'���صĽ���в���log_bin on�ַ������жϣ�
    logbinon=$(grep -i "log_bin.on" $mycnf)
    if [ "$?" -eq "0" ]; then
        echo "log-bin enable success"	
    else
		echo 'log-bin enable fail, please recheck all the path'
		exit
	fi

	echo $logbinon

echo 3. restart mysql
    service $mysqlservice restart