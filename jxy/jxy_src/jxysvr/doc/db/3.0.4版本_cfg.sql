/*
Navicat MySQL Data Transfer

Source Server         : 127.0.0.1
Source Server Version : 50613
Source Host           : 127.0.0.1:3306
Source Database       : ios_app_cfg

Target Server Type    : MYSQL
Target Server Version : 50613
File Encoding         : 65001

Date: 2014-02-27 10:19:01
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `formationprop2`
-- ----------------------------
DROP TABLE IF EXISTS `formationprop2`;
CREATE TABLE `formationprop2` (
  `FormationKindID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OpenIdx` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CoachIdxFlag` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VisableLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `UnlockLevel` smallint(5) unsigned NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of formationprop2
-- ----------------------------
INSERT INTO `formationprop2` VALUES ('1', '1', '0', '0', '0');
INSERT INTO `formationprop2` VALUES ('1', '3', '0', '0', '16');
INSERT INTO `formationprop2` VALUES ('1', '4', '1', '0', '0');
INSERT INTO `formationprop2` VALUES ('1', '6', '0', '0', '0');
INSERT INTO `formationprop2` VALUES ('2', '1', '0', '0', '0');
INSERT INTO `formationprop2` VALUES ('2', '3', '1', '0', '0');
INSERT INTO `formationprop2` VALUES ('2', '4', '0', '0', '0');
INSERT INTO `formationprop2` VALUES ('2', '6', '0', '0', '16');
INSERT INTO `formationprop2` VALUES ('3', '1', '0', '0', '0');
INSERT INTO `formationprop2` VALUES ('3', '3', '1', '0', '0');
INSERT INTO `formationprop2` VALUES ('3', '4', '0', '0', '0');
INSERT INTO `formationprop2` VALUES ('3', '6', '0', '0', '16');

-- ----------------------------
-- Table structure for `formationunlock`
-- ----------------------------
DROP TABLE IF EXISTS `formationunlock`;
CREATE TABLE `formationunlock` (
  `FormationID` smallint(5) NOT NULL,
  `VisibleLevel` smallint(5) NOT NULL,
  `UnlockLevel` smallint(5) NOT NULL,
  PRIMARY KEY (`FormationID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of formationunlock
-- ----------------------------
INSERT INTO `formationunlock` VALUES ('1', '1', '1');
INSERT INTO `formationunlock` VALUES ('2', '1', '1');
INSERT INTO `formationunlock` VALUES ('3', '1', '30');

-- ----------------------------
-- Table structure for `formationupgradeprop`
-- ----------------------------
DROP TABLE IF EXISTS `formationupgradeprop`;
CREATE TABLE `formationupgradeprop` (
  `FormationID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AttrKindName` varchar(30) NOT NULL DEFAULT '',
  `AttrKindID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AttrLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AttrKindValue` int(12) unsigned NOT NULL DEFAULT '0',
  `UpgradeSciencePoint` int(12) unsigned NOT NULL DEFAULT '0',
  `NeedPlayerLevel` smallint(5) unsigned NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of formationupgradeprop
-- ----------------------------
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '1', '100', '22000', '5');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '2', '200', '24000', '10');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '3', '300', '27000', '15');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '4', '400', '31000', '20');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '5', '500', '35000', '25');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '6', '600', '39000', '30');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '7', '700', '43000', '35');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '8', '800', '48000', '40');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '9', '900', '54000', '45');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '10', '1000', '60000', '50');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '11', '1100', '66000', '55');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '12', '1200', '72000', '60');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '13', '1300', '79000', '65');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '14', '1400', '87000', '70');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '15', '1500', '95000', '75');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '16', '1600', '103000', '80');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '17', '1700', '111000', '85');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '18', '1800', '120000', '90');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '19', '1900', '130000', '95');
INSERT INTO `formationupgradeprop` VALUES ('1', '�׻���', '2', '20', '2000', '0', '100');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '1', '500', '22000', '5');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '2', '1000', '24000', '10');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '3', '1500', '27000', '15');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '4', '2000', '31000', '20');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '5', '2500', '35000', '25');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '6', '3000', '39000', '30');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '7', '3500', '43000', '35');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '8', '4000', '48000', '40');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '9', '4500', '54000', '45');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '10', '5000', '60000', '50');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '11', '5500', '66000', '55');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '12', '6000', '72000', '60');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '13', '6500', '79000', '65');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '14', '7000', '87000', '70');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '15', '7500', '95000', '75');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '16', '8000', '103000', '80');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '17', '8500', '111000', '85');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '18', '9000', '120000', '90');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '19', '9500', '130000', '95');
INSERT INTO `formationupgradeprop` VALUES ('2', '������', '1', '20', '10000', '0', '100');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '1', '500', '22000', '5');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '2', '1000', '24000', '10');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '3', '1500', '27000', '15');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '4', '2000', '31000', '20');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '5', '2500', '35000', '25');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '6', '3000', '39000', '30');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '7', '3500', '43000', '35');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '8', '4000', '48000', '40');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '9', '4500', '54000', '45');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '10', '5000', '60000', '50');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '11', '5500', '66000', '55');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '12', '6000', '72000', '60');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '13', '6500', '79000', '65');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '14', '7000', '87000', '70');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '15', '7500', '95000', '75');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '16', '8000', '103000', '80');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '17', '8500', '111000', '85');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '18', '9000', '120000', '90');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '19', '9500', '130000', '95');
INSERT INTO `formationupgradeprop` VALUES ('3', '��ȸ��', '11', '20', '10000', '0', '100');

-- ----------------------------
-- Table structure for `luafile`
-- ----------------------------
DROP TABLE IF EXISTS `luafile`;
CREATE TABLE `luafile` (
  `Common1` text NOT NULL,
  `Common2` text NOT NULL,
  `Common3` text NOT NULL,
  `Common4` text NOT NULL,
  `Common5` text NOT NULL,
  `Calculate` text NOT NULL,
  `Activity` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of luafile
-- ----------------------------
INSERT INTO `luafile` VALUES ('', '', '', '', '', 'ECK_ATTACK=1; -- ����\r\nECK_DEFENCE=2; -- ����\r\nEAST_HP=0; --Ѫ��\r\nEAST_ATTACK=1; --����\r\n\r\n-- ǿ��ͭ��\r\nfunction GetStrengthenCoin(StrenthenLevel, DressLevel)\r\n	Coin = 0;\r\n	Type = DressLevel / 10;\r\n	if Type < 1 then\r\n		Coin = StrenthenLevel*StrenthenLevel*50+StrenthenLevel*50+50;\r\n	elseif Type < 3 then\r\n		Coin = StrenthenLevel*StrenthenLevel*60+StrenthenLevel*60+1060;\r\n	elseif Type < 5 then\r\n		Coin = StrenthenLevel*StrenthenLevel*72+StrenthenLevel*72+6272;\r\n	elseif Type < 7 then\r\n		Coin = StrenthenLevel*StrenthenLevel*86+StrenthenLevel*86+17526;\r\n	elseif Type < 8 then\r\n		Coin = StrenthenLevel*StrenthenLevel*130+StrenthenLevel*130+46289;\r\n	elseif Type < 9 then\r\n		Coin = StrenthenLevel*StrenthenLevel*195+StrenthenLevel*195+114933;\r\n	elseif Type < 10 then\r\n		Coin = StrenthenLevel*StrenthenLevel*292+StrenthenLevel*292+272339;\r\n	elseif Type < 11 then\r\n		Coin = StrenthenLevel*StrenthenLevel*438+StrenthenLevel*438+408058;\r\n	else\r\n		Coin = StrenthenLevel*StrenthenLevel*438+StrenthenLevel*438+408058;\r\n	end;\r\n\r\n	return Coin;\r\nend\r\n\r\n-- ��²��������ͭ��\r\nfunction GetCaptureWorkCoin(CaptureLevel)\r\n	Coin = (2000 * CaptureLevel) + 5000;\r\n	return Coin;\r\nend\r\n-- ��²������������\r\nfunction GetCaptureWorkScience(CaptureLevel)\r\n	Science = 16 * CaptureLevel;\r\n	return Science;\r\nend\r\n\r\n-- ������������ͭ��\r\nfunction GetRankEncourageCoin(Rank)\r\n	Coin = 0;\r\n	if Rank == 0 then\r\n		Coin = 30000;\r\n	elseif Rank <= 50 then\r\n		Coin = 500000 - 5000 * (Rank-1);\r\n	elseif Rank <= 100 then\r\n		Coin = 250000 - 1000 * (Rank - 50);\r\n    elseif Rank <= 200 then\r\n        Coin = 200000 - 500 * (Rank - 100);\r\n    elseif Rank <= 500 then\r\n		Coin = 150000 - 200 * (Rank - 200);\r\n    elseif Rank <= 1000 then\r\n        Coin = 90000 - 100 * (Rank - 500);\r\n    else\r\n        Coin = 30000;\r\n	end;\r\n\r\n	return Coin;\r\nend\r\n-- ����������������\r\nfunction GetRankEncourageScience(Rank)\r\n	Science = 0;\r\n	if Rank == 0 then\r\n		Science = 300;\r\n	elseif Rank <= 50 then\r\n		Science = 5000 - 50 * (Rank-1);\r\n	elseif Rank <= 100 then\r\n		Science = 2500 - 10 * (Rank - 50);\r\n    elseif Rank <= 200 then\r\n        Science = 2000 - 5 * (Rank - 100);\r\n    elseif Rank <= 500 then\r\n		Science = 1500 - 2 * (Rank - 200);\r\n    elseif Rank <= 1000 then\r\n        Science = 900 - 1 * (Rank - 500);\r\n    else\r\n        Science = 300;\r\n	end;\r\n\r\n	--  return Science;\r\n	return 0;\r\nend\r\n\r\n-- ����������������\r\nfunction GetRankEncourageJingJie(Rank)\r\n	JingJie = 0;\r\n	if Rank == 0 then\r\n		JingJie  = 300;\r\n	elseif Rank <= 50 then\r\n		JingJie  = 5000 - 50 * (Rank-1);\r\n	elseif Rank <= 100 then\r\n		JingJie  = 2500 - 10 * (Rank - 50);\r\n    elseif Rank <= 200 then\r\n        JingJie  = 2000 - 5 * (Rank - 100);\r\n    elseif Rank <= 500 then\r\n		JingJie = 1500 - 2 * (Rank - 200);\r\n    elseif Rank <= 1000 then\r\n        JingJie  = 900 - 1 * (Rank - 500);\r\n    else\r\n        JingJie  = 300;\r\n	end;\r\n\r\n	return JingJie ;\r\nend\r\n\r\n\r\n-- ��ս��������ͭ��\r\nfunction GetChallengeEncourageCoin(PlayerLevel, WinFlag)\r\n	Coin = 0;\r\n	if WinFlag == true then\r\n		Coin = PlayerLevel * 100 + 1000\r\n	else\r\n		Coin = (PlayerLevel * 100 + 1000) / 2;\r\n	end;\r\n\r\n	return Coin;\r\nend\r\n-- ��ս������������\r\nfunction GetChallengeEncourageScience(PlayerLevel, WinFlag)\r\n	Science = 0;\r\n	if WinFlag == 1 then\r\n		Science = PlayerLevel + 100\r\n	else\r\n		Science = (PlayerLevel + 100) / 2;\r\n	end;\r\n\r\n	-- return Science;\r\n	return 0;\r\nend\r\n-- ��ս������������\r\nfunction GetChallengeEncourageJingJie(PlayerLevel, WinFlag)\r\n	JingJie = 0;\r\n	if WinFlag == 1 then\r\n		JingJie = 2 * (PlayerLevel * PlayerLevel * 0.005 + PlayerLevel * 0.05 + 10);\r\n	else\r\n		JingJie = PlayerLevel * PlayerLevel * 0.005 + PlayerLevel * 0.05 + 10;\r\n	end;\r\n\r\n	return JingJie;\r\nend\r\n\r\n\r\n-- ҡǮ����������ͭ��\r\nfunction GetMoneyTreeProduceCoin(PlayerLevel)\r\n	Coin =  PlayerLevel * 2000 + 5000 ;\r\n	return Coin;\r\nend\r\n\r\n\r\n\r\n-- ���������������ӵ�����ֵ\r\nfunction GetAttrAddValue(Talent, HeroLevel, AttrType, CareerType)\r\n	AddValue = 0;\r\n    if ECK_DEFENCE == CareerType then\r\n        if AttrType == EAST_ATTACK then\r\n            AddValue = (HeroLevel * Talent * 1.5 + (HeroLevel * Talent * 7.5) / 5 ) * 0.4;\r\n        elseif AttrType == EAST_HP then\r\n            AddValue = ( HeroLevel * Talent * 7.5 + HeroLevel * Talent * 1.5 * 5 ) * 0.6;\r\n        else\r\n            AddValue = 0;\r\n        end;\r\n    elseif ECK_ATTACK == CareerType then\r\n        if EAST_ATTACK == AttrType then\r\n            AddValue = ( HeroLevel * Talent * 1.5 + ( HeroLevel * Talent * 7.5 / 5 )) * 0.6;\r\n        elseif EAST_HP == AttrType then\r\n            AddValue = ( HeroLevel * Talent * 7.5 + HeroLevel * Talent * 1.5 * 5 ) * 0.4;\r\n        else\r\n            AddValue = 0;\r\n		end;\r\n    else\r\n        AddValue = 0;\r\n    end;\r\n\r\n	return AddValue;\r\nend\r\n\r\n-- ����������������ͭ��\r\nfunction GetUpdateAttrCostCoin(Talent, AttrLevel, CoachFlag)\r\n	CostCoinValue = 0;\r\n	CostCoinOriValue = AttrLevel * AttrLevel  + AttrLevel * 400 + 1000;\r\n	if CoachFlag == true then\r\n		CostCoinValue = (CostCoinOriValue * 1 + CostCoinOriValue * 2.5 ) / 4.0;\r\n	else\r\n	    if Talent <= 10 then\r\n            CostCoinValue = CostCoinOriValue * 1;\r\n        elseif Talent <= 20 then\r\n            CostCoinValue = CostCoinOriValue * 1.5;\r\n        elseif Talent <= 30 then\r\n            CostCoinValue = CostCoinOriValue * 2.0;\r\n        elseif Talent <= 40 then\r\n            CostCoinValue = CostCoinOriValue * 2.5;\r\n        else\r\n			dwCostCoinValue = CostCoinOriValue * 3;\r\n		end;\r\n	end;\r\n\r\n	return CostCoinValue;\r\nend\r\n\r\n\r\n\r\nEGCF_MONEYTREE = 1 						--�в�\r\nEGCF_RACEBUYNUM = 2 					--������������ս����\r\nEGCF_PLUNDERBUYNUM = 3 				--�ӶṺ����ս����\r\nEGCF_PHYSTRENGTHBUYNUM = 4		--������������\r\nEGCF_CLIMBTOWERRESET = 5			--����ÿ���������ô���\r\n--EGCF_GENRANDOMGAS=6					--�������\r\n--EGCF_HEROEATJINGYANDAN = 7	--�����þ��鵤\r\nEGCF_RESETELITEINSTANCE = 8		--���þ�Ӣ����\r\n--EGCF_GENPURPLEGAS = 9				--��ɫ����\r\n--EGCF_AWAKENCALL = 11				--����ٻ�\r\nEGCF_GATHER_SCIENCE_COIN = 12 --ͭǮ�ۻ�\r\nEGCF_GATHER_SCIENCE_GOLD = 13 --Ԫ���ۻ�\r\nEGCF_BEG_BLUE_IMPRV_LUCK = 14 -- ����¶��������\r\nEGCF_SHADE_CHANGE_MONSTER = 15 --��������\r\nEGCF_FACTION_OPEN_GOLD = 17 ---�����ƽ�ģʽ\r\nEGCF_FACTION_CLOSE_MONSTER = 18 --����\r\nEGCF_FACTION_CREATE_BY_COIN = 19 --ͭǮ��������\r\nEGCF_FACTION_CREATE_BY_GOLD = 20 --Ԫ����������\r\n\r\nEGCF_PLUNDERDRIVEAWAY = 101		--����\r\nEGCF_GENCOIN = 102 						--�ۻ�ͭǮ\r\nEGCF_GENGOLD = 103 						--�ۻ�Ԫ��\r\nEGCF_GENUPGOLD = 104 					--�ۻ�Ԫ�����\r\nEGCF_GENUPGOLDFULL = 105 			--�ۻ�Ԫ������\r\n\r\n\r\n\r\n\r\n\r\n--���Ԫ������\r\n\r\nfunction GetCostByFunc(byVipLevel, nFunc, nCnt, nIdx )\r\n	if nFunc==EGCF_MONEYTREE then -- �в�\r\n		if byVipLevel < 5 then\r\n			return byVipLevel * 3 + 2\r\n		else\r\n			return ( byVipLevel - 4) * 5 + 15\r\n		end\r\n	elseif nFunc == EGCF_RACEBUYNUM then --������������ս����\r\n		if byVipLevel < 5 then\r\n			return byVipLevel * 3 + 5\r\n		else\r\n			return ( byVipLevel - 4) * 5 + 15\r\n		end\r\n	elseif nFunc == EGCF_PLUNDERBUYNUM then --��������ս����\r\n		if byVipLevel < 5 then\r\n			return byVipLevel * 3 + 5\r\n		else\r\n			return ( byVipLevel - 4) * 5 + 15\r\n		end\r\n	elseif nFunc == EGCF_PLUNDERDRIVEAWAY then --����\r\n		if nCnt>=0 and nCnt<6 then\r\n			return 10+nCnt*2\r\n		elseif nCnt>=6 and nCnt<10 then\r\n			return (nCnt-5)*5+20\r\n		elseif nCnt>=10 then\r\n			return 50\r\n		end\r\n\r\n  elseif nFunc==EGCF_PHYSTRENGTHBUYNUM then -- ����\r\n	if byVipLevel < 5 then\r\n		  return byVipLevel * 5 + 20\r\n	elseif byVipLevel <= 10 then\r\n	    return ( byVipLevel - 4 ) * 10 + 40\r\n    end\r\n\r\n	elseif nFunc==EGCF_CLIMBTOWERRESET then --����\r\n		if byVipLevel < 4 then\r\n			return 0\r\n		else\r\n			return (byVipLevel - 2) * nIdx\r\n		end\r\n	elseif nFunc == EGCF_RESETELITEINSTANCE then --��Ӣ\r\n		if byVipLevel < 3 then\r\n			if nIdx <= 2 then\r\n				return 50\r\n			elseif nIdx <= 4 then\r\n				return 60\r\n			elseif nIdx == 5 then\r\n				return 70\r\n			elseif nIdx == 6 then\r\n				return 80\r\n			elseif nIdx == 7 then\r\n				return 90\r\n			elseif nIdx == 8 then\r\n				return 100\r\n			else\r\n				return 100\r\n			end\r\n		else\r\n			if nIdx <= 2 then\r\n				return 70+(byVipLevel-3)*20\r\n			elseif nIdx <= 4 then\r\n				return 80+(byVipLevel-3)*20\r\n			elseif nIdx == 5 then\r\n				return 90+(byVipLevel-3)*20\r\n			elseif nIdx == 6 then\r\n				return 100+(byVipLevel-3)*20\r\n			elseif nIdx == 7 then\r\n				return 110+(byVipLevel-3)*20\r\n			elseif nIdx == 8 then\r\n				return 120+(byVipLevel-3)*20\r\n			else\r\n				return 120+(byVipLevel-3)*20\r\n			end\r\n		end\r\n	elseif nFunc==EGCF_GATHER_SCIENCE_COIN then -- ͭǮ�ۻ����ĵ�ͭǮ\r\n		if byVipLevel < 5 then\r\n			return byVipLevel * 300 + 20000\r\n		else\r\n			return ( byVipLevel - 4) * 500 + 150000\r\n		end\r\n	elseif nFunc==EGCF_GATHER_SCIENCE_GOLD then -- ͭǮ�ۻ����ĵ�Ԫ��\r\n		if byVipLevel < 5 then\r\n			return byVipLevel * 30 + 200\r\n		else\r\n			return ( byVipLevel - 4) * 500 + 1500\r\n		end\r\n	elseif nFunc == EGCF_BEG_BLUE_IMPRV_LUCK then -- Ԫ���������ĵ�Ԫ��\r\n		if nIdx >= 1 and nIdx <= 3 then\r\n			return 0\r\n		elseif nIdx >= 4 and nIdx <= 9 then\r\n			return (nIdx-3)*2 + 8\r\n		elseif nIdx >=10 and nIdx <= 15 then\r\n			return (nIdx-2-3) * 5\r\n		elseif nIdx > 15 then\r\n		    return 50	\r\n		else \r\n			return 0\r\n		end	\r\n	elseif nFunc == EGCF_SHADE_CHANGE_MONSTER then --��������\r\n		if nIdx >= 1 and nIdx <= 2 then\r\n			return 10\r\n		elseif nIdx >= 3 and nIdx <= 4 then\r\n			return 15\r\n		elseif nIdx >=5 and nIdx <= 6 then\r\n			return 20\r\n		elseif nIdx >= 7 and nIdx <= 8 then\r\n		    return 25\r\n		elseif nIdx >= 9 then \r\n				return 30\r\n		else \r\n			return 0\r\n		end	\r\n	elseif nFunc == EGCF_FACTION_OPEN_GOLD then --�����ƽ�ģʽ\r\n	    return 200\r\n	elseif nFunc == EGCF_FACTION_CLOSE_MONSTER then --����\r\n			return 20\r\n	elseif nFunc == EGCF_FACTION_CREATE_BY_COIN then --������������ͭǮ\r\n			return 5000000\r\n	elseif nFunc == EGCF_FACTION_CREATE_BY_GOLD then --������������Ԫ��\r\n      return 250\r\n	elseif nFunc==EGCF_GENCOIN then -- ͭǮ�ۻ����ĵ�Ԫ��\r\n		return math.floor((nCnt * nCnt *100 + nCnt * 5000 + 40000) / 5000) * 5000;\r\n	elseif nFunc==EGCF_GENGOLD then -- Ԫ���ۻ����ĵ�Ԫ��\r\n		if nCnt <= 7 then\r\n			return 20 + nCnt * 5\r\n		elseif nCnt <= 12 then\r\n			return 50 + (nCnt - 7) * 10\r\n		else \r\n			return 100;\r\n		end\r\n	elseif nFunc==EGCF_GENUPGOLD then -- ˢ�����ĵ�ͭǮ\r\n		if nCnt < 3 then\r\n			return 0\r\n		elseif nCnt < 8 then\r\n			return (nCnt - 2) * 2\r\n		else \r\n			return 10;\r\n		end\r\n	elseif nFunc==EGCF_GENUPGOLDFULL then -- �ۻ�һ���ɳ����ĵ�Ԫ��\r\n		return 100\r\n	else\r\n		return 0\r\n	end\r\nend\r\n\r\n\r\n\r\n-- ���ܻ�ȡ�������ֵ\r\nEOF_GATHER_SCIENCE_COIN = 1 --ͭǮ�ۻ�\r\nEOF_GATHER_SCIENCE_GOLD = 2 --Ԫ���ۻ�\r\nEOF_BLUE = 3 				--����\r\nEOF_PURPLE = 4 				--����\r\nfunction GetObtainByFunc(byVipLevel, byLevel, nFunc, nCnt, nIdx)\r\n	if nFunc==EGCF_GATHER_SCIENCE_COIN then\r\n		if byVipLevel < 5 then\r\n			return 2*(byVipLevel+1)\r\n		elseif byVipLevel < 8 then\r\n			return 5*(byVipLevel-4)+10\r\n		else\r\n			return 10*(byVipLevel-8)+30\r\n		end\r\n	elseif nFunc == EGCF_GATHER_SCIENCE_GOLD then\r\n		if byVipLevel < 5 then\r\n			return 2*(byVipLevel+1)\r\n		else\r\n			return 10\r\n		end\r\n	elseif nFunc == EOF_BLUE then\r\n		return 2*(byLevel+1) * nCnt\r\n	elseif nFunc == EOF_PURPLE then\r\n		return 10*(byLevel+1) * nCnt\r\n	end\r\nend\r\n\r\n\r\nfunction GetGenGasNum( byVipLevel, byLevel, byTownIdx, byInstanceIdx)\r\n	if (byLevel < 35 or byTownIdx < 2) or (byTownIdx == 2 and byInstanceIdx < 3)  then\r\n		return 6;\r\n	elseif (byLevel < 40 or byTownIdx < 2) or (byTownIdx == 2 and byInstanceIdx < 3) then\r\n		return 8;\r\n	elseif (byLevel < 45 or byTownIdx < 3) or (byTownIdx == 3 and byInstanceIdx < 4) then\r\n		return 10;\r\n	elseif (byLevel < 50 or byTownIdx < 3) or (byTownIdx == 3 and byInstanceIdx < 9) then\r\n		return 12;\r\n	elseif (byLevel < 55 or byTownIdx < 4) or (byTownIdx == 4 and byInstanceIdx < 5) then\r\n		return 14;\r\n	elseif (byLevel < 60 or byTownIdx < 5) or (byTownIdx == 5 and byInstanceIdx < 1) then\r\n		return 16;\r\n	elseif (byLevel < 65 or byTownIdx < 5) or (byTownIdx == 5 and byInstanceIdx < 6) then\r\n		return 18;\r\n	elseif (byLevel < 70 or byTownIdx < 6) or (byTownIdx == 6 and byInstanceIdx < 2) then\r\n		return 20;\r\n	elseif (byLevel < 75 or byTownIdx < 6) or (byTownIdx == 6 and byInstanceIdx < 7) then\r\n		return 22;\r\n	elseif (byLevel < 80 or byTownIdx < 7) or (byTownIdx == 7 and byInstanceIdx < 3) then\r\n		return 24;\r\n	elseif (byLevel < 85 or byTownIdx < 7) or (byTownIdx == 7 and byInstanceIdx < 8) then\r\n		return 26;\r\n	elseif (byLevel < 90 or byTownIdx < 8) or (byTownIdx == 8 and byInstanceIdx < 4) then\r\n		return 28;\r\n	else \r\n		return 30\r\n	end;\r\nend\r\n\r\n-- ���ܾۻ�ı���\r\nfunction GetGatherScienceIncrease(nIdx)\r\n	return nIdx * 3;\r\nend\r\n\r\n\r\n\r\nGSIP_DOWN = 1 			--����\r\nGSIP_EQUIT= 2 			--���\r\nGSIP_UP = 3 			--����\r\n\r\n\r\n-- ���ܾۻ�ı���\r\nfunction GetGatherScienceIncreasePer(nIdx, nFunc)\r\n	if nIdx == 1 then\r\n		if nFunc == GSIP_DOWN then\r\n			return 10;\r\n		elseif nFunc == GSIP_EQUIT then\r\n			return 10;\r\n		elseif nFunc == GSIP_UP then\r\n			return 80;\r\n		else \r\n			return 0;\r\n		end \r\n	elseif nIdx == 2 then\r\n		if nFunc == GSIP_DOWN then\r\n			return 20;\r\n		elseif nFunc == GSIP_EQUIT then\r\n			return 20;\r\n		elseif nFunc == GSIP_UP then\r\n			return 60;\r\n		else \r\n			return 0;\r\n		end \r\n	elseif nIdx == 3 then\r\n		if nFunc == GSIP_DOWN then\r\n			return 30;\r\n		elseif nFunc == GSIP_EQUIT then\r\n			return 30;\r\n		elseif nFunc == GSIP_UP then\r\n			return 40;\r\n		else \r\n			return 0;\r\n		end \r\n	elseif nIdx == 4 then\r\n		if nFunc == GSIP_DOWN then\r\n			return 0;\r\n		elseif nFunc == GSIP_EQUIT then\r\n			return 40;\r\n		elseif nFunc == GSIP_UP then\r\n			return 60;\r\n		else \r\n			return 0;\r\n		end \r\n	end \r\nend\r\n\r\n-- ����ٻ�����\r\nfunction GetAwakenCallNum()\r\n	return 5;\r\nend\r\n\r\n-- ��������ת����������(��������������)\r\nfunction GetBlueNumToPerPurple()\r\n	return 100;\r\nend\r\n-- ÿ�ε�����ֵ\r\nfunction GetClickBlueValue()\r\n	return 1000;\r\nend\r\n\r\n-- ��������ջ�Ԫ��\r\nfunction GetMaintownCrownGold(PlayerLevel)\r\n	return 0;\r\nend\r\n-- ��������ջ�ͭǮ\r\nfunction GetMaintownCrownCoin(PlayerLevel)\r\n	return 2000 * PlayerLevel + 10000;\r\nend\r\n-- ��������ջ񾳽��\r\nfunction GetMaintownCrownJingJie(PlayerLevel)\r\n	return 500;\r\nend\r\n\r\n-- ������վ����\r\nfunction GetMaintownLevyJingJie(PlayerLevel)\r\n	return 25;\r\nend\r\n-- �����������ͭǮ\r\nfunction GetMaintownLevyCoin(PlayerLevel)\r\n	return 200 * PlayerLevel + 1000;\r\nend\r\n\r\n-- ���Ҹ�����Ƿ�����ʾ,1��Ҫ��ʾ��0����Ҫ\r\nfunction GetBoxGoodsPrompt(BoxGoodsID)\r\n	if BoxGoodsID== 40001 or  BoxGoodsID== 40002 or  BoxGoodsID== 40003 or  BoxGoodsID== 40004 or  BoxGoodsID== 40005 or  BoxGoodsID== 40006 or  BoxGoodsID== 40007 then\r\n		return 1\r\n	else\r\n		return 0\r\n	end\r\nend\r\n\r\n-- ��������ռ���ȡ��������ʱ��\r\nfunction GetPassIncGenGasNumTime(DayPassSecond)\r\n	TimeSec = 12 * 3600 + 1800;\r\n	if DayPassSecond < TimeSec then\r\n		return TimeSec;\r\n	end\r\n 	TimeSec = 18 * 3600 + 1800;\r\n	if DayPassSecond < TimeSec then\r\n		return TimeSec;\r\n	end\r\nend\r\n\r\n\r\n-- ��ȡbossս��������\r\nfunction GetBossBTopEncCoin(PlayerLevel, Top)\r\n	Coin = 0;\r\n	if Top == 1 then\r\n		Coin = PlayerLevel*20000+1000000;\r\n	elseif Top == 2 then\r\n		Coin = PlayerLevel*10000+500000;\r\n	elseif Top == 3 then\r\n		Coin = PlayerLevel*5000+250000;\r\n	end;\r\n\r\n	return Coin;\r\nend;\r\n\r\n-- ��ȡbossս��������\r\nfunction GetBossBTopEncJingJie(PlayerLevel, Top)\r\n	JingJie = 0;\r\n	if Top == 1 then\r\n		JingJie = 2000;\r\n	elseif Top == 2 then\r\n		JingJie = 1000;\r\n	elseif Top == 3 then\r\n		JingJie = 500;\r\n	end;\r\n\r\n	return JingJie;\r\nend;\r\n\r\n-- ��ȡbossս��ɱ����\r\nfunction GetBossBKillEncCoin(BossLevel)\r\n	Coin = (BossLevel - 20) * 100000 + 1000000;\r\n	if Coin < 0 then\r\n		Coin = 0;\r\n	end;\r\n\r\n	return Coin;\r\nend;\r\n\r\n-- ��ȡbossս��ɱ����\r\nfunction GetBossBKillEncJingJie(BossLevel)\r\n	return 0;\r\nend;\r\n\r\n-- ��ȡbossս�˺�����\r\nfunction GetBossBHurtEncCoin(PlayerLevel, HurtValue)\r\n	Coin = HurtValue / 10;\r\n	MaxCoin = PlayerLevel * 100;\r\n	if Coin > MaxCoin then\r\n		Coin = MaxCoin\r\n	end;\r\n\r\n	if Coin < 1 then\r\n		Coin = 1;\r\n	end;\r\n\r\n	return Coin;\r\nend;\r\n\r\n-- ��ȡbossս�˺�����\r\nfunction GetBossBHurtEncJingJie(PlayerLevel, HurtValue)\r\n	JingJie = HurtValue / 1000;\r\n	MaxJingJie = 30;\r\n	if JingJie > MaxJingJie then\r\n		JingJie = MaxJingJie\r\n	end;\r\n\r\n	if JingJie < 1 then\r\n		JingJie = 1;\r\n	end;\r\n\r\n	return JingJie;\r\nend;\r\n\r\n-- ��ȡbossսӢ�۽���\r\nfunction GetBossBHeroHurtEncCoin()\r\n	return 100000;\r\nend;\r\n\r\n-- ��ȡbossսӢ�۽���\r\nfunction GetBossBHeroHurtEncJingJie()\r\n	return 200;\r\nend;\r\n\r\n-- ��ȡbossս�������\r\nfunction GetInspireRate(GoldInspireFlag, IncPowerRate)\r\n	Rate = 0;\r\n	if GoldInspireFlag == 1 then\r\n		Rate = 20;\r\n	else\r\n		--math.randomseed(os.time())\r\n		math.randomseed(tostring(os.time()):reverse():sub(1, 6))\r\n		--temp =  LuaRandomReseed(0, 100);\r\n		if IncPowerRate == 0 then\r\n			if LuaRandomReseed(100) < 50 then\r\n				Rate = 20;\r\n			end;\r\n		elseif IncPowerRate <= 20 then\r\n			if LuaRandomReseed(100) < 40 then\r\n				Rate = 20;\r\n			end;\r\n		elseif IncPowerRate <= 40 then\r\n			if LuaRandomReseed(100) < 30 then\r\n				Rate = 20;\r\n			end;\r\n		elseif IncPowerRate <= 60 then\r\n			if LuaRandomReseed(100) < 20 then\r\n				Rate = 20;\r\n			end;\r\n		elseif IncPowerRate <= 80 then\r\n			if LuaRandomReseed(100) < 10 then\r\n				Rate = 20;\r\n			end;\r\n		else\r\n			Rate = 0;\r\n		end;\r\n	end;\r\n\r\n	return Rate;\r\nend;\r\n\r\n\r\n-- ��ȡbossսÿ����������ٷֱ�\r\nfunction GetIncRateByStory()\r\n	return 20;\r\nend;\r\n\r\n-- ��ȡbossսÿ��Ԫ������ٷֱ�\r\nfunction GetIncRateByGold()\r\n	return 20;\r\nend;\r\n\r\n-- ��ȡ���������������\r\nfunction GetRdchallengeEncJingJie(Ret, MyLevel, EnemyLevel)\r\n	if Ret == 0 then\r\n		return (EnemyLevel / MyLevel) * ( MyLevel * MyLevel * 0.01 + MyLevel * 0.1 + 20);\r\n	else\r\n		return (EnemyLevel / MyLevel) * ( MyLevel * MyLevel * 0.01 + MyLevel * 0.1 + 20) / 2;\r\n	end;\r\nend;\r\n\r\n-- ��ȡ���������������\r\nfunction GetRdchallengeEncPurpleGas(Ret, MyLevel, EnemyLevel)\r\n	if Ret == 0 then\r\n		return (EnemyLevel / MyLevel) * ( MyLevel * MyLevel * 0.01 + MyLevel * 0.1 + 20) * 5;\r\n	else\r\n		return (EnemyLevel / MyLevel) * ( MyLevel * MyLevel * 0.01 + MyLevel * 0.1 + 20) * 5 / 2;\r\n	end;\r\nend;\r\n\r\nfunction GetMeltGold(Science)\r\n	MaxScience = Science;\r\n	MinScience = Science/3;\r\n	Gap = MaxScience - MinScience;\r\n	Ret = 0;\r\n    if  Gap < 1000 then\r\n		Ret = Gap / 20;\r\n	elseif  Gap < 5000 then\r\n		Ret = 1000 / 20 +( Gap - 1000 ) / 50;\r\n	elseif  Gap < 50000 then\r\n		Ret = 1000 / 20 +( 5000 - 1000 ) / 50 + ( Gap - 5000 ) / 100;\r\n	else\r\n		Ret = 1000 / 20 +( 5000 - 1000 ) / 50 + ( 50000 - 5000 ) / 100 + ( Gap - 50000 ) / 200;\r\n	end;\r\n\r\n	if Ret % 1 > 0 then\r\n		Ret = Ret + 1;\r\n	end\r\n	return Ret;\r\n\r\nend;\r\n\r\n-- ��������������ȡ����¶����\r\nfunction GetBegBlueMaxTimes(Layer)\r\n    BegblueCnt = 0;\r\n    \r\n    if Layer >= 0 then\r\n        BegblueCnt = math.floor(Layer/10) + 5; \r\n    -- elseif Layer >=55 and Layer <= 100 then\r\n    --    BegblueCnt = math.floor(Layer/5);\r\n    else\r\n        BegblueCnt = 0;\r\n    end;\r\n\r\n	-- test\r\n	-- BegblueCnt = 1000;\r\n    \r\n    return BegblueCnt;\r\nend;\r\n\r\n-- ��������n�����������¶������ʾ\r\nfunction GetClimbTowerPrompt(Layer)\r\n    MoreTowerLayer = 0;\r\n    \r\n    if Layer >= 0 then\r\n        MoreTowerLayer = math.floor(Layer/10 + 1)*10 - Layer; \r\n    -- elseif Layer >=50 and Layer < 100 then\r\n    --     MoreTowerLayer = math.floor(Layer/5 + 1)*5 - Layer; \r\n    else\r\n        MoreTowerLayer = 0;\r\n    end;\r\n    \r\n    return MoreTowerLayer;\r\nend;\r\n\r\n\r\n-- ����¶ÿ����Ѹ��˴�������\r\nfunction GetFreeImproveLuckTimes()\r\n    return 3;\r\nend;\r\n\r\n-- ��ȡ����¶�Ƿ���Ա���\r\nfunction GetBegBlueIsIgnoreXnMultiple()\r\n    return 0;\r\nend;\r\n\r\n-- ÿ�տ���������ۻ�Ĵ���\r\nfunction GetTotalFreeCommonUpGasNum()\r\n		return 3;\r\nend;\r\n\r\n-- ����ս�����bossս�˺�ֵ\r\nfunction GetBossBHurtValueByPower(Power)\r\n	HurtValue = 0;\r\n    if  Power <= 100000 then\r\n		HurtValue = Power/10;		\r\n	elseif  Power <= 500000 then	\r\n		-- HurtValue = (Power - 100000)/20 + 100000/10;\r\n		HurtValue = (Power - 100000)/20 + 10000;		\r\n	elseif  Power <= 2000000 then\r\n		-- HurtValue = (Power - 500000)/30 + (500000 - 100000)/20 + 100000/10;\r\n		HurtValue = (Power - 500000)/30 + 30000;		\r\n	elseif  Power <= 5000000 then\r\n		-- HurtValue = (Power - 2000000)/40 +  (2000000 - 500000)/30 + (500000 - 100000)/20 + 100000/10;\r\n		HurtValue = (Power - 2000000)/40 +  80000;\r\n		\r\n	else\r\n		-- HurtValue = (Power - 5000000)/50 +  (5000000 - 2000000)/40 + (2000000 - 500000)/30 + (500000 - 100000)/20 + 100000/10;\r\n		HurtValue = (Power - 5000000)/50 + 155000;\r\n	end;\r\n	return HurtValue;\r\nend;\r\n\r\n--��ѻ��ִ���\r\nfunction GetFreeRefreshNum()\r\n		return 10\r\nend\r\n\r\n--������ĵ�Ԫ��\r\nFindMonsterGold = 100\r\nfunction GetGoldByFindMonster()\r\n		return FindMonsterGold\r\nend;\r\n\r\n\r\n--��ȡ�Ʊ��ʽ�������ͭǮ\r\nCoinByBadWine = 10000\r\nfunction GetCoinByBadWine()\r\n		return CoinByBadWine\r\nend\r\n\r\n--����һ������ͭǮ\r\nCoinEveryTimeValues = 100000\r\nGoldEveryTimeValues = 20\r\nBaseFundsByCoin = 100\r\nBaseFundsByGold = 500\r\nBaseDoorsTributeByCoin = 100\r\nBaseDoorsTributeByGold = 500\r\n--����һ������ͭǮ\r\nfunction GetCostCoinByDonate(FactionLevel)\r\n		return CoinEveryTimeValues\r\nend\r\n\r\n--����һ������Ԫ��\r\nfunction GetCostGoldByDonate(FactionLevel)\r\n	  return GoldEveryTimeValues\r\nend\r\n\r\n--����һ��ͭǮ��ȡ�����ʽ�\r\nfunction GetFundsByDonateCoin(FactionLevel)\r\n		return BaseFundsByCoin\r\nend\r\n\r\n--����һ��Ԫ����ȡ�����ʽ�\r\nfunction GetFundsByDonateGold(FactionLevel)\r\n		return BaseFundsByGold\r\nend\r\n\r\n--����һ��ͭǮ��ȡ�Ź�\r\nfunction GetDoorsTributeByDonateCoin(FactionLevel)\r\n		return BaseDoorsTributeByCoin\r\nend\r\n\r\n--����һ��Ԫ����ȡ�Ź�\r\nfunction GetDoorsTributeByDonateGold(FactionLevel)\r\n		return BaseDoorsTributeByGold\r\nend\r\n\r\n--�Ź�����ֵı�����ϵ\r\nDoorsTributeIntegral = 100\r\nfunction GetDoorsTributeIntegral()\r\n		return DoorsTributeIntegral\r\nend\r\n\r\n--�ƽ�ģʽ�ı�����\r\nGoldModeMulti = 2\r\nfunction GetGoldModeMulti()\r\n		return GoldModeMulti\r\nend\r\n\r\n--�������ɼ��ʱ��\r\nJoinFactionInterval = 14400\r\nfunction GetJoinFactionInterval()\r\n		return JoinFactionInterval\r\nend\r\n\r\n--��ͨ�һ��Ź����ĵ�ͭǮ\r\nfunction GetNormalFindBackDoorsTribute( LeftDoorsTribute )\r\n		return LeftDoorsTribute * 100\r\nend\r\n\r\n--�����һ��Ź����ĵ�Ԫ��\r\nfunction GetPerfectFindBackDoorsTribute( LeftDoorsTribute )\r\n		return LeftDoorsTribute / 100\r\nend\r\n\r\n--���ύ��������\r\nfunction GetMaxExprience( VipLevel, FactionLevel)\r\n		if FactionLevel < 4 then\r\n				return 0\r\n		else\r\n				return (10000 * (FactionLevel - 3) * (VipLevel / 10 + 1) * (VipLevel / 10 + 1) * (VipLevel / 10 + 1)) / 1000 * 1000\r\n		end\r\nend\r\n\r\n--����ÿ�����ӻ���\r\nfunction GetExprienceAddBase( PlayerLevel, FactionLevel)\r\n		if PlayerLevel < 25 then\r\n				return 0\r\n		elseif FactionLevel < 4 then\r\n				return 0\r\n		else\r\n				return ((PlayerLevel / 10 + 1) * 2 * FactionLevel) / 10\r\n		end\r\nend', 'activityInfo =\r\n{\r\n	-- DspDate活动显示时间, StartDate活动开始时间，EndDate活动持续名称，Name活动名称\r\n	{ID=1, DspDate=\"0\", StartDate=\"0\", EndDate=\"0\", Name=\"首充活动\"}, \r\n	{ID=2, DspDate=\"2013/3/28 17:23:37\", StartDate=\"2013/11/28 17:23:37\", EndDate=\"2015/11/28 00:00:00\", Name=\"冲击�?0名\\"}, \r\n};\r\n\r\nfunction CkFirstRecharge(player, id)\r\n	if player.CkActivityHaveDoNum(id) > 0 then\r\n		return ACTIVITY_ERR_ACTIVITY_HAVE_FINISH;\r\n	end;\r\n	\r\n	if 0 == player.GetDT_PLAYER_BASE_DATA().dwTotalAmount then\r\n		return ACTIVITY_ERR_ACTIVITY_CON_NOT_MATCH;\r\n	end\r\n	\r\n	player.ActivityEncourage(id, EBKIND_COIN, 1000, 0);\r\n	\r\n	return 0;\r\nend\r\n\r\n\r\nfunction CkRecharge1000(player)\r\n	if nil == player then\r\n		return\r\n	end  \r\nend\r\n\r\n-- 获取活动描述信息\r\nfunction GetActivityInfo(player, id)\r\n	if nil == player then\r\n		return \"\"; \r\n	end;\r\n		\r\n	if 1 == ID then\r\n		 return \"首次充值可获极品伙伴\\";\r\n	elseif 2 == ID then\r\n		return \"�?�?8日前竞技场前3名的玩家可领取神秘大奖\\";\r\n	else\r\n		return \"\";\r\n	end;\r\n	return \"\";\r\nend\r\n\r\n-- 获取活动显示数字信息\r\nfunction GetActivityDspNum(player, id)\r\n	if nil == player then\r\n		return \"\"; \r\n	end;\r\n		\r\n	if 1 == ID then\r\n		 return 8;\r\n	elseif 2 == ID then\r\n		return 5;\r\n	else\r\n		return 0;\r\n	end;\r\n	return 0;\r\nend\r\n\r\n-- 获取活动前往ID\r\nfunction GetActivityForewordID(player, id)\r\n	if nil == player then\r\n		return \"\"; \r\n	end;\r\n		\r\n	if 1 == ID then\r\n		 return 8;\r\n	elseif 2 == ID then\r\n		return 5;\r\n	else\r\n		return 0;\r\n	end;\r\n	return 0;\r\nend\r\n\r\n-- 获取活动前往信息\r\nfunction GetActivityForewordInfo(player, id)\r\n	if nil == player then\r\n		return \"\"; \r\n	end;\r\n		\r\n	if 1 == ID then\r\n		 return \"好吧\";\r\n	elseif 2 == ID then\r\n		return \"可以\";\r\n	else\r\n		return \"\";\r\n	end;\r\n	return \"\";\r\nend\r\n\r\n-- 检测活动完成条件是否达到，完成则给奖励\r\nfunction CkFinishActivity(player, id)\r\n	if nil == player then\r\n		return ACTIVITY_ERR_PLAYER_NULL; \r\n	end;\r\n			\r\n	if 1 == ID then\r\n		 CkFirstRecharge(player);\r\n	elseif 2 == ID then\r\n		CkRecharge1000(player);\r\n	else\r\n		return ACTIVITY_ERR_INVALID_ID;\r\n	end;\r\n	\r\n	return ACTIVITY_ERR_INVALID_ID;\r\nend\r\n');

INSERT INTO msgdefprop(msgdefprop.CliRegionType,msgdefprop.MsgKey,msgdefprop.Msg) VALUES(0,"BB_ENCOURAGE_MESSA","���{x}��Ц��������{y}��¶");

INSERT INTO msgdefprop(msgdefprop.CliRegionType,msgdefprop.MsgKey,msgdefprop.Msg) VALUES(0,"BB_ENCOURAGE_MESSB","�����{x}��Ц�������ɶ�����{y}��¶");

INSERT INTO msgdefprop(msgdefprop.CliRegionType,msgdefprop.MsgKey,msgdefprop.Msg) VALUES(0,"BB_ENCOURAGE_MESSC","���տ���ȡЦ�������Ѿ�����");

DROP TABLE IF EXISTS `begblueencourageprop`;
CREATE TABLE `begblueencourageprop` (
  `SmileNum` int(11) NOT NULL,
  `Blue` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of begblueencourageprop
-- ----------------------------
INSERT INTO `begblueencourageprop` VALUES ('10', '1000');
INSERT INTO `begblueencourageprop` VALUES ('20', '2000');
INSERT INTO `begblueencourageprop` VALUES ('30', '4000');
INSERT INTO `begblueencourageprop` VALUES ('40', '6000');
INSERT INTO `begblueencourageprop` VALUES ('60', '14000');
INSERT INTO `begblueencourageprop` VALUES ('80', '26000');
INSERT INTO `begblueencourageprop` VALUES ('100', '44000');

ALTER TABLE singlepram ADD COLUMN ExprienceAddInterval smallint(5) unsigned NOT NULL DEFAULT 3;
ALTER TABLE singlepram ADD COLUMN ChangeFactionIcon smallint(5) unsigned NOT NULL DEFAULT 100;
REPLACE INTO `msgdefprop` VALUES ('0', 'YOU_NEED_REEDIT_YOUR_NAME', '�����ԭ�������ǳ�������ҷ����˳�ͻ��������ȡ��', '');