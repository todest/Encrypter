#include <stdio.h>
#include <string.h>
extern void Encrypt(void)
{
	static int e1=1;
	printf("-->第%d次加密操作<--\n",e1++);
	int t,m,i=0;
	char a[1000000],pw[100],b[1000000];
	memset(a,0,sizeof(a));
	memset(pw,0,sizeof(pw));
	memset(b,0,sizeof(b));
	printf("请输入要加密的文件路径:");
	getchar();
	FILE *fp;
	char file[100];
	gets(file);
	printf("\n文件预览:\n");
	fp=fopen(file,"a+");
	char ch=fgetc(fp);
	while(ch!=EOF)
	{
		a[i++]=ch;
		ch=fgetc(fp);
	}
	fclose(fp);
	puts(a);
	printf("\n请输入要使用的密钥:");
	gets(pw);
	t=strlen(a);
	m=strlen(pw);
	for(int i=0;i<t;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')//判断明文类型     A-Z
		{
			if(pw[i%m]>='A'&&pw[i%m]<='Z')//判断  密钥  序列
			{
				b[i]=(a[i]+pw[i%m]-130+1)%26+65;//加密处理
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
				printf("Error\n");//抛出异常；终止加密
				break;
			}
		}
		else if(a[i]>='a'&&a[i]<='z')//判断明文类型     a-z
		{
			if(pw[i%m]>='A'&&pw[i%m]<='Z')//判断  密钥  序列
			{
				b[i]=(a[i]+pw[i%m]-162+1)%26+97;//加密处理
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
				printf("Error\n");//抛出异常；终止加密
				break;
			}
		}
		else if(a[i]>='0'&&a[i]<='9')//判断明文类型     0-9
		{
			if(pw[i%m]>='A'&&pw[i%m]<='Z')//判断  密钥  序列
			{
				b[i]=(a[i]+pw[i%m]-112)%10+48;//加密处理
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
				printf("Error!!!\n");//抛出异常；终止加密
				break;
			}
		}
		else
		{
			b[i]=a[i];//遇到非字母,保留原样
		}
	}
		printf("\n已加密的密文:\n");
		puts(b);
		FILE *p;
		p=fopen(file,"w+");
		for(int j=0;j<t;j++)
		fputc(b[j],p);
		fclose(p);
		printf("\n已完成加密的密文已保存至 %s 中！\n",file);
		printf("\nPress enter key to continue...");
		while(getchar()!='\n');
}
