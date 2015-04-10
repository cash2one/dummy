/*
    �����ű�
    Date: 2014-1-20 15:21:22
    @author by ���غ�
*/

# ���������Ĵ洢����
DROP PROCEDURE IF EXISTS `union_databases`;
DROP PROCEDURE IF EXISTS `union_table`;
DROP PROCEDURE IF EXISTS `union_table_check`;
DROP PROCEDURE IF EXISTS `union_table_delrebolt`;
DROP PROCEDURE IF EXISTS `exec_sql`;
DROP PROCEDURE IF EXISTS `exec_sql_print`;

DELIMITER $$
# �ϲ�2�����ݿ�
# ����union_databases('ios_app_s003', '��3��', 'ios_app_s004', '��4��')
# ����db1:	    ���ݿ�1����ios_app_s001
# ����db1_desc: �����ݿ�1�����������1��
# ����db2:		���ݿ�2����ios_app_s002
# ����db2_desc: �����ݿ�2�����������2��
CREATE DEFINER=`root`@`%` PROCEDURE `union_databases`(IN  db1 varchar(64), IN db1_desc varchar(64), IN db2 varchar(64), IN db2_desc varchar(64))
lable_1:
BEGIN
	declare v_sqlstr varchar(1024) default ''; 

	IF db1 is null or db2 is null or db1_desc is null or db2_desc is null then
		select '����' as '��������յĲ���';
		leave lable_1; 
	END IF;

	IF LENGTH(trim(db1))<1 or LENGTH(trim(db2))<1 or LENGTH(trim(db1_desc))<1 or LENGTH(trim(db2_desc))<1 then
		select '����' as '����������ַ���';
		leave lable_1; 
	END IF;

	#��������
	start transaction; 

    #
	#ALTER TABLE `faction`
	#ADD COLUMN `Ext`  smallint NULL DEFAULT 0 COMMENT '�Ƿ���޸�����' AFTER `LastAuditTime`;

	#�������
	call union_table_check(db1, db2, 'faction', 'FactionID');
	IF  @g_int >= 1  THEN
					select '����Id�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	call union_table_check(db1, db2, 'faction', 'FactionPlayerID');
	IF  @g_int >= 1  THEN
					select '��������ظ�';
					rollback;
					leave lable_1; 
	END IF;

	call union_table_check(db1, db2, 'myrecharge', 'OrderID');
	IF  @g_int >= 1  THEN
					select '��ֵ�����ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_bags', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_bags', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '��ұ����ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;
	
	#ɾ��
	call union_table_delrebolt(db1, 'player_builds', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_builds', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '��ҽ����ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#���
	call union_table_check(db1, db2, 'player_cdkey', 'CdKey');
	IF  @g_int >= 1  THEN
					select '���CDKEY�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	call union_table_check(db1, db2, 'player_consume', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '������Ѽ�¼�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_ext', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_ext', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '�����չ��Ϣ�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_hero_ext', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_hero_ext', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '����佫��չ��Ϣ�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_heros', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_heros', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '����佫��Ϣ�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_instances', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_instances', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '��Ҹ�����Ϣ�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_pvp', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_pvp', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '���PVP��Ϣ�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_recharge', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_recharge', 'OrderID');
	IF  @g_int >= 1  THEN
					select '��ҳ�ֵ��¼�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_relation', 'pidA');
	#���
	call union_table_check(db1, db2, 'player_relation', 'pidA');
	IF  @g_int >= 1  THEN
					select '��ҹ�ϵ�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'player_tasks', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'player_tasks', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '��������ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'players', 'PlayerID');
	#���
	call union_table_check(db1, db2, 'players', 'PlayerID');
	IF  @g_int >= 1  THEN
					select '�����Ϣ�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'private_chat_log', 'sendPid');
	#���
	call union_table_check(db1, db2, 'private_chat_log', 'sendPid');
	IF  @g_int >= 1  THEN
					select '��������ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'send_flower_log', 'sendPid');
	#���
	call union_table_check(db1, db2, 'send_flower_log', 'sendPid');
	IF  @g_int >= 1  THEN
					select '����ͻ���¼�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	#ɾ��
	call union_table_delrebolt(db1, 'send_flower_log', 'sendPid');
	#���
	call union_table_check(db1, db2, 'send_flower_log', 'sendPid');
	IF  @g_int >= 1  THEN
					select '����ͻ���¼�ظ�' as 'ģ����Ϣ', @g_int as '����';
					rollback;
					leave lable_1; 
	END IF;

	###################################################
	##�������Ƿ�����
	set 		v_sqlstr = concat('select f1.FactionName as ���Ʒ�����ͻ������, CONCAT(f1.FactionName, \'(', db1_desc, ')\') as ', db1_desc, '���������������, CONCAT(f2.FactionName, \'(', db2_desc, ')\') as ', db2_desc, '��������������� from ', db1, '.faction f1 inner join ', db2, '.faction f2 on f1.FactionName = f2.FactionName and f1.FactionName is not null and f1.FactionName <> \'\'');
	call exec_sql_print(v_sqlstr);

    set 		v_sqlstr = concat('UPDATE ', db1, '.faction f1 inner join ', db2, '.faction f2 on f1.FactionName = f2.FactionName and f1.FactionName is not null and f1.FactionName <> \'\' set f1.FactionName = CONCAT(f1.FactionName, \'(', db1_desc, ')\'), f1.Ext = 1, f2.FactionName = CONCAT(f2.FactionName, \'(', db2_desc, ')\'), f2.Ext = 1;');
	call exec_sql_print(v_sqlstr);

	##�������ǳ��Ƿ�����
	set 		v_sqlstr = concat('select p1.DispName as �ǳƷ�����ͻ�����, CONCAT(p1.DispName, \'(', db1_desc, ')\') as ', db1_desc, '�����������ǳ�, CONCAT(p2.DispName, \'(', db2_desc, ')\') as ', db2_desc, '�����������ǳ� from ', db1, '.players p1 inner join ', db2, '.players p2 on p1.DispName = p2.DispName and p1.DispName is not null and p1.DispName <> \'\'');
	call exec_sql_print(v_sqlstr);

	set 		v_sqlstr = concat('UPDATE ', db1, '.players p1 inner join ', db2, '.players p2 on p1.DispName = p2.DispName and p1.DispName is not null and p1.DispName <> \'\' set p1.DispName = CONCAT(p1.DispName, \'(', db1_desc, ')\'), p1.ExtData = 3, p2.DispName = CONCAT(p2.DispName, \'(', db2_desc, ')\'), p2.ExtData = 3');
	call exec_sql_print(v_sqlstr);

	###################################################
	#���ݲ���
	call union_table(db1, db2, 'faction');
	call union_table(db1, db2, 'factionplayer');

	call union_table(db1, db2, 'myrecharge');
	call union_table(db1, db2, 'player_bags');

	call union_table(db1, db2, 'player_builds');
	call union_table(db1, db2, 'player_cdkey');

	call union_table(db1, db2, 'player_ext');
	call union_table(db1, db2, 'player_hero_ext');

	call union_table(db1, db2, 'player_heros');
	call union_table(db1, db2, 'player_instances');

	call union_table(db1, db2, 'player_pvp');
	call union_table(db1, db2, 'player_recharge');

	call union_table(db1, db2, 'player_relation');
	call union_table(db1, db2, 'player_tasks');

	call union_table(db1, db2, 'players');
	call union_table(db1, db2, 'private_chat_log');

	call union_table(db1, db2, 'send_flower_log');

	## ɾ����ʱ��
	set 		v_sqlstr = concat('drop table if exists ', db1, '.`conflict_faction`');
	call exec_sql_print(v_sqlstr);
	set 		v_sqlstr = concat('drop table if exists ', db1, '.`conflict_player`');
	call exec_sql_print(v_sqlstr);

	## ������ͻ������ʱ���洢���ɱ��ڵ���������ͻ��¼������֮��ļ�⣨���Ӳ�ѯ��Ч��̫��̫���ˣ�
	set 		v_sqlstr = concat('create table ', db1, '.`conflict_faction` as (select FactionName from ', db1, '.Faction group by FactionName having count(FactionName) > 1)');
	call exec_sql_print(v_sqlstr);

	## ������ͻ�����ʱ���洢��ұ��ڵ��ǳƳ�ͻ��¼
	set 		v_sqlstr = concat('create table ', db1, '.`conflict_player` as (select DispName from ', db1, '.players group by DispName having count(DispName) > 1)');
	call exec_sql_print(v_sqlstr);

    ## �ٴμ��������ƣ�����������������ڰ������ƺ���ϰ���ID
    set 		v_sqlstr = concat('update ', db1, '.faction f inner join ', db1, '.conflict_faction c on f.FactionName = c.FactionName and f.FactionName is not null and f.FactionName <> \'\' set f.FactionName = CONCAT(f.FactionName, \'(\', f.FactionID, \')\'), f.Ext = 1');
	call exec_sql_print(v_sqlstr);

    ## �ٴμ������ǳƣ����������������������ǳƺ�������ID
    set 		v_sqlstr = concat('update ', db1, '.players p inner join ', db1, '.conflict_player c on p.DispName = c.DispName and p.DispName is not null and p.DispName <> \'\' set p.DispName = CONCAT(p.DispName, \'(\', p.PlayerID, \')\'), p.ExtData = 3');
	call exec_sql_print(v_sqlstr);

	## ɾ����������ʱ��
	set 		v_sqlstr = concat('drop table if exists ', db1, '.`conflict_faction`');
	call exec_sql_print(v_sqlstr);
	set 		v_sqlstr = concat('drop table if exists ', db1, '.`conflict_player`');
	call exec_sql_print(v_sqlstr);

	commit; 
END
$$

CREATE DEFINER=`root`@`%` PROCEDURE `union_table`(`db1` varchar(64),`db2` varchar(64), `mytable` varchar(64))
BEGIN
	declare v_sqlstr  varchar(1024) default ''; 

	#Routine body goes here...
	set 		v_sqlstr = concat('INSERT into ', db1, '.', mytable, ' select * from ', db2, '.', mytable, ';');
	call exec_sql_print(v_sqlstr);
END
$$

#���������Ƿ����ظ����ֶ�
CREATE DEFINER=`root`@`%` PROCEDURE `union_table_check`(`db1` varchar(64),`db2` varchar(64),`mytable` varchar(64),`mycolumn` varchar(64))
BEGIN
	declare v_sqlstr  varchar(1024) default ''; 

	set 		@g_int = 0;
	set 		v_sqlstr = concat('select count(1) into @g_int from ',  db1, '.', mytable,' t1 inner join ', db2, '.', mytable, ' t2 on t1.', mycolumn, '= t2.', mycolumn, ';');
	call exec_sql(v_sqlstr);

	# ��ӡ����ͻ��id
	IF  @g_int >= 1  THEN
		set 		v_sqlstr = concat('select \'', mytable, '\' as ������ͻ�ı�, \'', mycolumn, '\' as ������ͻ���ֶ�, t1.', mycolumn, ' as ֵ from ', db1, '.', mytable,' t1 inner join ', db2, '.', mytable, ' t2 on t1.', mycolumn, '= t2.', mycolumn, ';');
		call exec_sql_print(v_sqlstr);
	END IF;
END
$$

#ɾ��������
CREATE DEFINER=`root`@`%` PROCEDURE `union_table_delrebolt`(`db1` varchar(64), `mytable` varchar(64),`mycolumn` varchar(64))
BEGIN
	declare v_sqlstr  varchar(1024) default ''; 
	set 		v_sqlstr = concat('delete from ', db1, '.', mytable, ' where ', mycolumn, ' <= 1010');
	call exec_sql(v_sqlstr);
END
$$

#ִ��sql���
CREATE DEFINER=`root`@`%` PROCEDURE `exec_sql`(`v_sqlstr` varchar(1024))
BEGIN
	set 		@sqlstr = v_sqlstr;
	prepare m_str from @sqlstr;
	execute m_str;
END
$$

#ִ��sql��䲢��ӡ
CREATE DEFINER=`root`@`%` PROCEDURE `exec_sql_print`(`v_sqlstr` varchar(1024))
BEGIN
	select v_sqlstr;
	call exec_sql(v_sqlstr);
END
$$

# �����ɱ�����ӱ�ʶ�ֶ�
DROP PROCEDURE if exists AddCloumn;
CREATE PROCEDURE AddCloumn ()
BEGIN
	declare v_sqlstr  varchar(1024) default ''; 
	set 		@g_cur_db = '';
	set 		v_sqlstr = concat('select database() into @g_cur_db');
	call exec_sql(v_sqlstr);

	-- ���ԭ�����ֶ��Ƿ���ڣ��粻����������ֶ�
	if exists(select 1 from information_schema.columns where table_schema = @g_cur_db and table_name = 'faction' and column_name = 'Ext') then
		select 1 as ���ɱ��Ext�ֶ��Ѵ���;
	else
		-- Ȼ����ֱ��������ֶ�
		ALTER TABLE `faction` ADD column `Ext` smallint(6) NOT NULL DEFAULT '0' COMMENT '�����Ƿ���Ҫ����ע����������1��/0��';
	end if;
END
$$

DELIMITER ;
call AddCloumn();
DROP PROCEDURE if exists AddCloumn;