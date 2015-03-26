#  @File Name: setup mysql binlog.sh
#  @Author: hongkunan
#  @Company: heihuo
#  @Created Time: 2013/12/4 15:56:54

#!/bin/bash

source ../jxy/util.sh

set +e

set mysqlservice=mysqld

mycnf="/etc/my.cnf"
#now=`date '+%Y-%m-%d_%Hh%Mm%Ss'`
now=`date '+%Y-%m-%d'`

# ������Ϣ
masterhost=192.168.4.106
masterport=3306
masterusr=root
masterpwd=123456

# �ӿ���Ϣ
slavehost=127.0.0.1
slaveport=3306
slaveusr=root
slavepwd=123456

# ��������ӿ���˺�
slavegrantusr=slave
slavegrantpwd=123456

# ����binlog��dump·��
dump_dir="/home/psy/proj/mysql/masterdump/$now"

# ȡip��ַ���һ��
serverid=109
expire_logs_days=7
log=log

force_setup_slave=1

# ���ݿ��б�
declare -a dbs=(
    ios_app_cfg
    ios_app_s001
    ios_app_s001_log
    ios_app_s002
    ios_app_s002_log
    ios_app_s003
    ios_app_s003_log
    ios_app_s004
    ios_app_s004_log
)

echo 0. check environment
    # ����������������·���Ƿ����
    if [ -d $dump_dir ] ;then
        echo_ok "check success: $dump_dir exist!"
    else
        echo "detecting $dump_dir not exist, create $dump_dir directory!"
        mkdir $dump_dir

		if [ ! -d $dump_dir ] ;then
			echo "error: create directory $dump_dir fail, exiting!"
			exit
		fi
    fi

    # ���my.cnf�����ļ��Ƿ����
    if [ -f $mycnf ]; then
        echo_ok "check success: ${mycnf} exist!"
    else
        echo_err "error: ${mycnf} not exist"
        exit
    fi

    # ����Ƿ��ܳɹ��������⣨ͨ������Ƿ�ɹ�ִ��ָ����䣩
    echo "connecting to masterdb $masterusr@[${masterhost}:${masterport}]......"
mysql -h$masterhost -u$masterusr -p$masterpwd << _EOFMYSQL_ > $log
    # ��ѯlog-bin�Ŀ������������������log�ļ�
    show variables like 'log_%';
_EOFMYSQL_

    # �Ƿ�ɹ�����
    if [ "$?" -eq "0" ]; then
        echo_ok "check success: connect to masterdb $masterusr@[${masterhost}:${masterport}] success"
    else
        echo "error: can not connect to masterdb $masterusr@[${masterhost}:${masterport}]" 
        exit
    fi

    # ��������Ƿ�ɹ�����logbin��ͨ����show variables like 'log_%'���صĽ���в���log_bin on�ַ������жϣ�
    logbinon=$(grep -i "log_bin.on" $log)
    if [ "$?" -eq "0" ]; then
        echo_ok "check success: detecting masterdb $masterusr@[${masterhost}:${masterport}]  log-bin = on"
    else
        echo "error: detecting masterdb $masterusr@[${masterhost}:${masterport}] log-bin = off"
        exit
    fi

	# ��������Ƿ��ѿ���master���������ģ��������δ����master����ִ��show master status;��佫�᷵��: Empty set (0.00 sec)���ӿ�ͬ��show slave status;��
mysql -h$masterhost -u$masterusr -p$masterpwd << _EOFMYSQL_ > $log
	show master status\G
_EOFMYSQL_

	master_status=$(grep -i "Empty set*" $log)
    if [ "$?" -ne "0" ] && [ -z "$master_status"]; then
		echo_ok "check success: detecting masterdb $masterusr@[${masterhost}:${masterport}] 's master = on: "
		echo "/-------------------------------------------------------------------------------------------"
		cat $log
		echo "-------------------------------------------------------------------------------------------/"
	else
		cat $log
		echo "error: detecting masterdb $masterusr@[${masterhost}:${masterport}] 's master = off, exit"
		exit
	fi

    # ����Ƿ��ܳɹ����ϴӿ�
	echo "connecting to slavedb $slaveusr@[${slavehost}:${slaveport}] ......"
mysql -h$slavehost -u$slaveusr -p$slavepwd << _EOFMYSQL_
_EOFMYSQL_

    # �Ƿ�ɹ����Ӵӿ�
    if [ "$?" -eq "0" ]; then
        echo_ok "check success: connect to slavedb $slaveusr@[${slavehost}:${slaveport}] success"
    else
        echo "error: can not connect to slavedb $slaveusr@[${slavehost}:${slaveport}]"
        exit
    fi

	# ���ӿ��Ƿ��Ѿ����óɹ�
mysql -h$slavehost -u$slaveusr -p$slavepwd << _EOFMYSQL_ > $log
	show slave status\G
_EOFMYSQL_

	slave_status=$(grep -i "Empty set*" $log)
    if [ "$?" -ne "0" ] && [ -z "$slave_status" ]; then
        echo_ok "detecting slave = on:"
		echo "/-------------------------------------------------------------------------------------------"
		cat $log
		echo "-------------------------------------------------------------------------------------------/"

		if [ $force_setup_slave -eq 0 ]; then
			echo_ok "Complete & exiting!"
			exit
		else
			echo "force_setup_slave = $force_setup_slave != 0, fore to setup slave, continue......"
		fi
	else
		echo 'detecting slave=off, start configuring....'
	fi

echo 1.configure $mycnf

	# 5.6�汾���������Ѿ�����Ҫ��my.cnf���master-host֮����ֶ��ˣ�����ͨ��change master to master-host=...... ���������
	#server-id=$serverid
	#master-host=$masterhost
	#master-port=$masterport
	#master-user=$slaveusr
	#master-password=$slavepwd

	pre_server_id=$(grep -i "server-id*=*" $mycnf)
	if [ "$?" -eq "0" ]; then
		echo_ok "ok: detecting existing $pre_server_id!"
	else
		echo "appending server-id = $serverid"
cat << _EOF_ >> $mycnf
server-id = $serverid
_EOF_
	fi

	pre_expire_logs_day=$(grep -i "expire_logs_days*=*" $mycnf)
	if [ "$?" -eq "0" ]; then
		echo_ok "ok: detecting existing $pre_expire_logs_day!"
	else
		echo "appending expire_logs_days = $expire_logs_days"
cat << _EOF_ >> $mycnf
expire_logs_days = $expire_logs_days
_EOF_
	fi

# Binary Logging.
# �Զ������ı���Щ��û��Ҫ������
# replicate-ignore-table=ios_app_cfg.xxx
# �Զ������Ĵ�����룬�Է����Ƴ����ж�
# slave-skip-errors = 1032,1062,126,1114,1146,1048,1396 rem �Զ������Ĵ�����룬�Է����Ƴ����ж�

	# ������Ҫ���ӵ����ݿ���
	for db in ${dbs[@]}
	do
		pre_do_db=$(grep -i "replicate-do-db*=*$db$" $mycnf)
		if [ "$?" -eq "0" ]; then
			echo_ok "ok: detecting existing $pre_do_db"
		else
			echo "appending replicate-do-db=$db"
cat << _EOF_ >> $mycnf
replicate-do-db=$db
_EOF_
# ����_EOF_һ��Ҫ��������ߣ���Ȼ����ʾ����
		fi
	done

	echo "configure $mycnf done"

echo 2. flush masterdb log
mysql -h$masterhost -u$masterusr  -p$masterpwd << _EOFMYSQL_
    #flush tables with read lock;
	flush logs;
_EOFMYSQL_

echo 3. start backup masterdb
    # ���ݸ������ݿ⵽ָ��Ŀ¼
    for db in ${dbs[@]}
    do
		dump_file=$dump_dir/$db.sql

        echo backingup $db -> $dump_file ......

		# �����г�ȡ��Ҳ�ɻ�������������Ȼ��һ��dump�������ڴ����Ƚ������ڴ�
		# --quick����row-by-rowģʽ��Ҳ��ʹ�á�opt(����--quick)��--skip-quick��ʹ�û������
		# --dump-slave������change master���
		# --apply-slave-statements: ָ����dump-slaveʱ����change master toǰ�����stop slave/start slave
		# --include-master-host-port�������ɵ�change master���master_host/master_portѡ��
		# --master-data(1|2)�������ڴ���slave����ѡ������change master to ������binlog�ľ���λ�ã��ڵ���slave��Ͳ������ֹ�����change master to��Ϣ�����ֵΪ2����ע�͵ķ�ʽ���ɣ�
		#					  ��ѡ����Զ���ֹ��lock-tablesͬʱ���lock-all-tables(����ָ���ˡ�single-transaction)��
		#					  ��ҪreloadȨ�ޣ����������˶�������־
		# --lock-tables/-l������ÿ������dump��db����ǰ�����������б���MyISAM����read local��InnoDB��ò���--single-transaction
		# --single-transaction��ֻ�����������������Ҫ�����ı���������뼶������Ϊrepeatable read����dump����ǰִ��start transaction

        mysqldump -h$masterhost -u$masterusr -p$masterpwd --lock-tables --single-transaction --skip-quick --master-data=1 --include-master-host-port --flush-logs --database $db >$dump_file
		# --default-character-set=utf8 --set-charset=utf8  
		#--dump-slave=1 --apply-slave-statements 

        # ����Ƿ񱸷ݳɹ���ͨ���Ƿ���ڶ�Ӧ��dump�ļ����жϣ�
        if [ -f $dump_file ]; then
            echo_ok "success: backup $db -> $dump_file success!"
        else
            echo_err "error: backup $db -> $dump_file fail!"
			echo_err "exiting: unlocking masterdb [${masterhost}:${masterport}] ....."

mysql -h$masterhost -u$masterusr  -p$masterpwd << _EOFMYSQL_
    #unlock tables;
_EOFMYSQL_

			echo_err "back up is failed, please recheck the configuration"
            exit
        fi
    done

echo 4. unlock masterdb
mysql -h$masterhost -u$masterusr  -p$masterpwd << _EOFMYSQL_
    # unlock tables;
_EOFMYSQL_
	echo "[${masterhost}:${masterport}] is unlocked"

echo 5. recovering from masterdb
mysql -h$slavehost -u$slaveusr -p$slavepwd << _EOFMYSQL_
	stop slave;

	# ������е�slaveͬ����Ϣ
	reset slave all;

	change master to master_host='${masterhost}', master_user='${slavegrantusr}', master_password='${slavegrantpwd}';#, master_log_file='${masterlog}', master_log_pos=${dump_pos};
_EOFMYSQL_

	# ��ָ��dumpĿ¼��ԭ�������ݿ�
    for db in ${dbs[@]}
    do
		dump_file=$dump_dir/$db.sql

        echo "recoving from $db <- $dump_file"
		# mysqldump -h$masterhost -u$masterusr -p$masterpwd --database $db <$dump_file
        mysql -h$slavehost -u$slaveusr -p$slavepwd <$dump_file

        # ����Ƿ�ԭ���ݳɹ�
        if [ "$?" -eq "0"  ]; then
            echo_ok "recover form $db <- $dump_file success"
        else
            echo_err "recover form $db <- $dump_file fail"
            exit
        fi
    done

echo 6. restart mysql
	service $mysqlservice restart

echo 7. start slave

mysql -h$slavehost -u$slaveusr -p$slavepwd << _EOFMYSQL_
	# �����ӿ�����
	start slave; 
_EOFMYSQL_

# ��� �鿴�ӿ�״̬
mysql -h$slavehost -u$slaveusr -p$slavepwd << _EOFMYSQL_ > $log
	show slave status\G
_EOFMYSQL_

	slave_status=$(grep -i "Empty set*" $log)
    if [ "$?" -ne "0" ] && [ -z "$slave_status" ]; then
        echo_ok "detecting slave = on:"
		echo "/-------------------------------------------------------------------------------------------"
		cat $log
		echo "-------------------------------------------------------------------------------------------/"
		echo_ok "All successfule! Complete & exiting!"
		exit
    else
		cat $log
        echo_err 'error: detecting slave = off, fail to configure slave, please recheck the configuration.'
	fi
	
