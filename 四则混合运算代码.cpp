#include <iostream>
#include <random>
#include <math.h>
#include <iomanip>
#include <stdio.h>

int random_0(int range)//生成整数
{
	return rand() % range + 1;
}
float random_1(int range)//生成小数
{
	float xiaoshu;
	L0:
	xiaoshu=((float)(rand() % 100) / 100) + rand() % range;
	if (xiaoshu == 0)
	{
		goto L0;
	}
	return xiaoshu;
}
char GetOperation(int oper)//生成随机运算符oper=1加减 =0加减乘除
{

	L1:switch (oper)
	{
	    case 0:oper = random_0(4) + 1; goto L1; break;
	    case 1:oper = random_0(2) + 1; goto L1; break;
		case 2:return '+'; break;
		case 3:return '-'; break;
		case 4:return '*'; break;
		case 5:return '/'; break;

		default:return 0; break;
	}
}
void haveparen(int range,int oper,int num,int text)//有括号的算式
{
	int parenl/*左括号*/, parenr/*右括号*/,shuzi0,zifu;
	float shuzi1;
	FILE *fp;
	fp = fopen("testlby.txt", "a");
	parenl = random_0(3);                            //随机右括号
	parenr = random_0(4-parenl)+1+parenl;            //随机左括号
	if (num == 1)                                    //有括号整数算式
	{
		for (int i = 1; i <= 4; i++)
		{
			if (parenl == i)                         //打印右括号
			{
				printf("(");
				if (text == 0)
				{
					fprintf(fp, "(");
				}
			}
			printf("%d", shuzi0 = random_0(range));    //打印数字
			if (text == 0)
			{
				fprintf(fp, "%d", shuzi0);
			}
			if (parenr == i + 1)                        //打印左括号
			{
				printf(")");
				if (text == 0)
				{
					fprintf(fp, ")");
				}
			}
			if (i + 1 == 5)                                //打印等号结束算式
			{
				printf("=\n");
				if (text == 0)
				{
					fprintf(fp, "=\n");
				}
				break;
			}
			char a = GetOperation(oper);                  //打印运算符号
			printf("%c", a);
			if (text == 0)
			{
				fprintf(fp, "%c", a);
			}
		}
	}
	
	if (num == 0)                                   //有括号小数
	{
		for (int i = 1; i <= 4; i++)
		{
			if (parenl == i)
			{
				printf("(");
				if (text == 0)
				{
					fprintf(fp, "(");
				}
			}
			shuzi1 = random_1(range);
			printf("%.2f", shuzi1);
			if (text == 0)
			{
				fprintf(fp, "%.2f",shuzi1 );
			}
			if (parenr == i + 1)
			{
				printf(")");
				if (text == 0)
				{
					fprintf(fp, ")");
				}
				
			}
			if (i + 1 == 5)
			{
				printf("=\n");
				if (text == 0)
				{
					fprintf(fp, "=\n");
				}
				break;
			}
			char a = GetOperation(oper);
			printf("%c",a);
			if (text == 0)
			{
				fprintf(fp, "%c", a);
			}
			
		}
	}
	

}
void noparen(int range, int oper, int num,int text)//无括号算式
{
	int shuzi0;
	float shuzi1;
	FILE *fp;
	fp = fopen("testlby.txt", "a");
	if (num == 1)                                 //无括号整数
	{
		for (int i = 1; i <= 4; i++)
		{
			shuzi0 = random_0(range);
			printf("%d", shuzi0);
			if (text == 0)
			{
				fprintf(fp, "%d",shuzi0);
			}
			if (i + 1 == 5)
			{
				printf("=\n");
				if (text == 0)
				{
					fprintf(fp, "=\n");
				}
				break;
			}
			char a = GetOperation(oper);
			printf("%c", a);
			if (text == 0)
			{
				fprintf(fp, "%c",a);
			}
		}
	}
	if (num == 0)                                     //无括号小数
	{
		for (int i = 1; i <= 4; i++)
		{
			shuzi1 = random_1(range);
			printf("%.2f", shuzi1);
			if (text == 0)
			{
				fprintf(fp, "%.2f", shuzi1);
			}
			if (i + 1 == 5)
			{
				printf("=\n");
				if (text == 0)
				{
					fprintf(fp, "=\n");
				}
				break;
			}
			char a = GetOperation(oper);
			printf("%c", a);
			if (text == 0)
			{
				fprintf(fp, "%c", a);
			}
		}
	}


}
int Scan(int &count, int &range, int &oper, int &num, int &text)
{
	int paren;
	printf("自动生成四则运算练习题程序\n");
	printf("输入出题数量(最大100)：\n");
	scanf("%d", &count);
	if (count > 100)
	{
		count = 100;
	}
	else if (count <= 0)
	{
		printf("错误的题目数量\n");
		return -1;
	}
	printf("输入最大值(默认最大9999)：\n");
	scanf("%d", &range);
	if (range > 9999)
	{
		count = 9999;
	}
	else if (range <= 0)
	{
		printf("错误的数字范围\n");
		return -1;
	}
	printf("算式中是否有小数(0小数1整数)：\n");
	scanf("%d", &num);
	if (num != 0 && num != 1)
	{
		printf("默认为整数\n");
		num = 1;
	}
	printf("算式中是否有乘除(0有1无)：\n");
	scanf("%d", &oper);
	if (oper != 0 && oper != 1)
	{
		printf("默认无乘除\n");
		oper = 0;
	}
	printf("算式中是否有括号(0有1无)：\n");
    scanf("%d", &paren);
	if (paren != 0 && paren != 1)
	{ 
		printf("默认无括号\n");
		paren = 1;
	}
	printf("是否输出文件(0是1否)：\n");
	scanf("%d", &text);
	if (text != 0 && text != 1)
	{
		printf("默认不输出\n");
		text = 1;
	}
	return paren;
}
int main()
{
	int count/*算式数量*/, range/*数字范围*/, oper/*括号有无*/, num/*是否小数*/, text/*是否文件*/;
	int i=Scan(count,range,oper,num,text);
	fp = fopen("testlby.txt","w");
	if (fclose(fp))
	{
		printf("error cant remake");
	}
	if (i == 0)
	{
		for (int j = 0; j < count; j++)
		{
			haveparen(range, oper, num, text);//有括号

		}
	}
	else if (i == 1)
	{
		for (int j = 0; j < count; j++)
		{ 
		    noparen(range, oper, num, text);//没括号
		}
	}
	else
	{
		return 0;
	}
	return 0;
}
