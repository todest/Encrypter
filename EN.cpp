#include <stdio.h>
#include <string.h>
extern void EN(void)
{
	static int e2=1;
	printf("-->第%d次加密操作<--\n",e2++);
	int t,m;
	char a[10000],pw[100],b[10000];
	memset(a,0,sizeof(a));
	memset(pw,0,sizeof(pw));
	memset(b,0,sizeof(b));
	printf("请输入要加密的明文:");
	getchar();
	gets(a);
	printf("请输入要使用的密钥:");
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
		printf("已加密的密文:");
		puts(b);//输出密文
		printf("\n");
		printf("Press enter key to continue...");
		while(getchar()!='\n');
}
