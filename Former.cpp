#include <windows.h>
#include <stdio.h>
#include <time.h>
void Former()
{
 	time_t t;
    time(&t);
	system("@echo off");
	system("color 9");
	printf("  Name:                Encrypter\n");
	printf("  Developer:           郭永航-赵猛-何雪雅\n");
	printf("  Current Time:        %s\n",ctime(&t));
	printf("  Tips: 此版本支持(A-Z,a-z,0-9)\n");
	printf("  Copyright(c)2017. All Rights Reserved. 版权所有.\n");
	printf("┌---------------------------------------------------------┐\n");
	printf("┊   输入数字执行以下功能:                                 ┊\n");
	printf("┊   1 .  加密 文件 内容                                   ┊\n");
	printf("┊   2 .  解密 文件 内容                                   ┊\n");
	printf("┊   3 .  加密 文本 内容                                   ┊\n");
	printf("┊   4 .  解密 文本 内容                                   ┊\n");
	printf("┊   0 .  退出 程序                                        ┊\n");
	printf("└---------------------------------------------------------┘\n\n");
}
