#include <stdio.h>
#include <string.h>
extern void Encrypt(void)
{
	static int e1=1;
	printf("-->��%d�μ��ܲ���<--\n",e1++);
	int t,m,i=0;
	char a[1000000],pw[100],b[1000000];
	memset(a,0,sizeof(a));
	memset(pw,0,sizeof(pw));
	memset(b,0,sizeof(b));
	printf("������Ҫ���ܵ��ļ�·��:");
	getchar();
	FILE *fp;
	char file[100];
	gets(file);
	printf("\n�ļ�Ԥ��:\n");
	fp=fopen(file,"a+");
	char ch=fgetc(fp);
	while(ch!=EOF)
	{
		a[i++]=ch;
		ch=fgetc(fp);
	}
	fclose(fp);
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
				b[i]=(a[i]+pw[i%m]-130+1)%26+65;//���ܴ���
			}
			else if(pw[i%m]>='a'&&pw[i%m]<='z')
			{
				b[i]=(a[i]+pw[i%m]-162+1)%26+65;
			}
			else if(pw[i%m]>='0'&&pw[i%m]<='9')
			{
				b[i]=(a[i]+pw[i%m]-113)%26+65;
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
				b[i]=(a[i]+pw[i%m]-162+1)%26+97;//���ܴ���
			}
			else if(pw[i%m]>='a'&&pw[i%m]<='z')
			{
				b[i]=(a[i]+pw[i%m]-194+1)%26+97;
			}
			else if(pw[i%m]>='0'&&pw[i%m]<='9')
			{
				b[i]=(a[i]+pw[i%m]-145)%26+97;
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
				b[i]=(a[i]+pw[i%m]-112)%10+48;//���ܴ���
			}
			else if(pw[i%m]>='a'&&pw[i%m]<='z')
			{
				b[i]=(a[i]+pw[i%m]-114)%10+48;
			}
			else if(pw[i%m]>='0'&&pw[i%m]<='9')
			{
				b[i]=(a[i]+pw[i%m]-96)%10+48;
			}
			else
			{
				printf("Error!!!\n");//�׳��쳣����ֹ����
				break;
			}
		}
		else
		{
			b[i]=a[i];//��������ĸ,����ԭ��
		}
	}
		printf("\n�Ѽ��ܵ�����:\n");
		puts(b);
		FILE *p;
		p=fopen(file,"w+");
		for(int j=0;j<t;j++)
		fputc(b[j],p);
		fclose(p);
		printf("\n����ɼ��ܵ������ѱ����� %s �У�\n",file);
		printf("\nPress enter key to continue...");
		while(getchar()!='\n');
}
