#include <stdio.h>
#include <string.h>
extern void Decrypt(void)
{
	static int d1=1;
	printf("-->��%d�ν��ܲ���<--\n",d1++);
	int t,m,i=0;
	char a[1000000],pw[100],b[1000000],file[100];
	memset(a,0,sizeof(a));
	memset(pw,0,sizeof(pw));
	memset(b,0,sizeof(b));
	printf("������Ҫ���ܵ��ļ�·��:");
	getchar();
	gets(file);
	printf("\n�ļ�Ԥ��:\n");
	FILE *fp1;
	fp1=fopen(file,"a+");
	char ch=fgetc(fp1);
	while(ch!=EOF)
	{
		a[i++]=ch;
		ch=fgetc(fp1);
	}
	fclose(fp1);
	puts(a);
	printf("\n������Ҫʹ�õ���Կ:");
	gets(pw);
	t=strlen(a);
	m=strlen(pw);
	for(int i=0;i<t;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')//�ж���������     A-Z
		{
			if(pw[i%m]>='A'&&pw[i%m]<='Z')//�ж�  ��Կ  ����
			{
				b[i]=(a[i]-pw[i%m]+25)%26+65;//���ܴ���
			}
			else if(pw[i%m]>='a'&&pw[i%m]<='z')
			{
				b[i]=(a[i]-pw[i%m]+57)%26+65;
			}
			else if(pw[i%m]>='0'&&pw[i%m]<='9')
			{
				b[i]=(a[i]-pw[i%m]+9)%26+65;
			}
			else
			{
				printf("Error\n");//�׳��쳣����ֹ����
				break;
			}
		}
		else if(a[i]>='a'&&a[i]<='z')//�ж���������     a-z
		{
			if(pw[i%m]>='A'&&pw[i%m]<='Z')//�ж�  ��Կ  ����
			{
				b[i]=(a[i]-pw[i%m]-7)%26+97;//���ܴ���
			}
			else if(pw[i%m]>='a'&&pw[i%m]<='z')
			{
				b[i]=(a[i]-pw[i%m]+25)%26+97;
			}
			else if(pw[i%m]>='0'&&pw[i%m]<='9')
			{
				b[i]=(a[i]-pw[i%m]-23)%26+97;
			}
			else
			{
				printf("Error\n");//�׳��쳣����ֹ����
				break;
			}
		}
		else if(a[i]>='0'&&a[i]<='9')//�ж���������     0-9
		{
			if(pw[i%m]>='A'&&pw[i%m]<='Z')//�ж�  ��Կ  ����
			{
				b[i]=(a[i]-48+10-(pw[i%m]-64)%10)%10+48;//���ܴ���
			}
			else if(pw[i%m]>='a'&&pw[i%m]<='z')
			{
				b[i]=(a[i]-48+10-(pw[i%m]-96)%10)%10+48;
			}
			else if(pw[i%m]>='0'&&pw[i%m]<='9')
			{
				b[i]=(a[i]-48+10-(pw[i%m]-48)%10)%10+48;
			}
			else
			{
				printf("Error\n");//�׳��쳣����ֹ����
				break;
			}
		}
		else
		{
			b[i]=a[i];//��������ĸ,����ԭ��
		}
	}
		printf("\n�ѽ��ܵ�����:\n");
		puts(b);//�������
		FILE *p1;
		p1=fopen(file,"w+");
		for(int j=0;j<t;j++)
		fputc(b[j],p1);
		fclose(p1);
		printf("\n����ɽ��ܵ������ѱ����� %s �У�\n",file);
		printf("\nPress enter key to continue...");
		while(getchar()!='\n');
}
