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
	printf("  Developer:           ������-����-��ѩ��\n");
	printf("  Current Time:        %s\n",ctime(&t));
	printf("  Tips: �˰汾֧��(A-Z,a-z,0-9)\n");
	printf("  Copyright(c)2017. All Rights Reserved. ��Ȩ����.\n");
	printf("��---------------------------------------------------------��\n");
	printf("��   ��������ִ�����¹���:                                 ��\n");
	printf("��   1 .  ���� �ļ� ����                                   ��\n");
	printf("��   2 .  ���� �ļ� ����                                   ��\n");
	printf("��   3 .  ���� �ı� ����                                   ��\n");
	printf("��   4 .  ���� �ı� ����                                   ��\n");
	printf("��   0 .  �˳� ����                                        ��\n");
	printf("��---------------------------------------------------------��\n\n");
}
