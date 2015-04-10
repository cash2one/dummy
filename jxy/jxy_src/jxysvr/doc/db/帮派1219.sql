ALTER TABLE `faction`
ADD COLUMN `UpdateTime`  datetime NOT NULL DEFAULT '2013-12-19 00:00:00' AFTER `FactionFundsSum`;

drop procedure if exists sp_AddRecharge;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_AddRecharge`(IN v_OrderID varchar(42),IN v_PlayerID int, IN v_Gold int, IN v_RMB int, IN v_SandBoxFlag int, v_Comment varchar(256))
    SQL SECURITY INVOKER
lable_1:
BEGIN   
		declare v_ErrCode int default 0;   
		declare v_ErrStr varchar(128) default  'Success!';  

		declare exit handler for sqlexception
		BEGIN
				set v_ErrCode = 3;
				set v_ErrStr = 'mysql error!';
				select v_ErrCode as ErrCode, v_ErrStr as ErrStr;
				rollback;
		END;

		set v_ErrCode = 0;
		set v_ErrStr = 'OrderID is OK!';
		#��������
		start transaction; 



		-- ��ⶩ���Ƿ����
		IF  EXISTS ( select 1 from `player_recharge` where OrderID = v_OrderID )THEN
					set v_ErrCode = 2;
					set v_ErrStr = 'OrderID is Processed!';
					select v_ErrCode as ErrCode, v_ErrStr as ErrStr;
					rollback;
					leave lable_1; 
		END IF;
		# �������Ƿ����
		IF NOT EXISTS ( select 1 from `players` where PlayerID = v_PlayerID )THEN
					set v_ErrCode = 13;
					set v_ErrStr = 'PlayerID is Not Exit!';
					select v_ErrCode as ErrCode, v_ErrStr as ErrStr;
					rollback;
					leave lable_1; 
		END IF;

		# ֱ�Ӹ�����ҵ����ݣ���Ϊ��ҵ����ݸ��²����ֵ��ͬһ�������С��п��ܴ���ʧ�ܵķ��գ���֤��ҵ�Ԫ��������������ύ�гɹ�
		#UPDATE players set Pay = Pay + v_Gold, Gold = Gold + v_Gold, TotalRMB = TotalRMB + v_RMB WHERE PlayerID = v_PlayerID;
		# �ڶ������в��붩����¼��
		INSERT INTO player_recharge(OrderID, PlayerID, Gold, RMB, SandBoxFlag, Comment, CreateTime) VALUES (v_OrderID, v_PlayerID, v_Gold, v_RMB, v_SandBoxFlag, v_Comment, now());
		#��������
		select v_ErrCode as ErrCode, v_ErrStr as ErrStr;
		commit; 
END