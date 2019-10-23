#include <stdio.h>
#include <windows.h>
extern void Encrypt();
extern void Decrypt();
extern void EN();
extern void DE();
extern void Former();
int main()
{
	Former();
	while(true)
	{
		char n;
		scanf("%c",&n);
		if(n=='1')
		{
			Encrypt();
			system("CLS");
			Former();
		}
		else if(n=='2')
		{
			Decrypt();
			system("CLS");
			Former();
		}
		else if(n=='3')
		{
			EN();
			system("CLS");
			Former();
		}
		else if(n=='4')
		{
			DE();
			system("CLS");
			Former();
		}
		else if(n=='0')
		return 0;
		else
		{
			printf("输入格式错误,请重新输入！！！\n");
			continue;
		}
	}
}
