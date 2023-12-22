
CREATE DATABASE IF NOT EXISTS `testDemo3`;
USE `testDemo3`;

CREATE TABLE IF NOT EXISTS `runnable` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '可运行任务id',
  `name` varchar(255) DEFAULT NULL COMMENT '名称',
  `classpath` varchar(255) DEFAULT NULL COMMENT '可运行任务类地址',
  `params` longtext COMMENT '可运行任务参数实例',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

INSERT INTO `runnable` (`id`, `name`, `classpath`, `params`) VALUES
	(1, '自定义任务1', 'com.spring.demo30.runnable.impl.MyRunnable1', NULL,
	(2, '自定义任务2', 'com.spring.demo30.runnable.impl.MyRunnable1', NULL);


CREATE TABLE IF NOT EXISTS `schedule_task` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '任务主键id',
  `name` varchar(255) DEFAULT NULL COMMENT '任务名称',
  `desc` longtext COMMENT '任务描述',
  `expr` varchar(255) DEFAULT NULL COMMENT '任务Cron表达式',
  `status` int(11) DEFAULT '0' COMMENT '任务状态，0停用，1启用',
  `runnableId` int(11) DEFAULT NULL COMMENT '定时任务的id',
  `params` longtext COMMENT '定时任务参数',
  `create_time` datetime DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
  `update_time` datetime DEFAULT NULL COMMENT '更新时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COMMENT='定时任务';

INSERT INTO `schedule_task` (`id`, `name`, `desc`, `expr`, `status`, `runnableId`, `params`, `create_time`, `update_time`) VALUES
	(1, '自定义任务1', '自定义任务1', '* * * * * ? *', 0, 1, NULL, '2022-05-12 15:03:19', NULL);
s