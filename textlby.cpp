#include <iostream>
#include <random>
#include <math.h>
#include <iomanip>
#include <stdio.h>

int random_0(int range)//��������
{
	return rand() % range + 1;
}
float random_1(int range)//����С��
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
char GetOperation(int oper)//������������oper=5�Ӽ� =6�Ӽ��˳�
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
void haveparen(int range,int oper,int num,int text)//�����ŵ���ʽ
{
	int parenl/*������*/, parenr/*������*/,shuzi0,zifu;
	float shuzi1;
	FILE *fp;
	fp = fopen("testlby.txt", "w");
	parenl = random_0(3);                            //���������
	parenr = random_0(4-parenl)+1+parenl;            //���������
	if (num == 1)                                    //������������ʽ
	{
		for (int i = 1; i <= 4; i++)
		{
			if (parenl == i)                         //��ӡ������
			{
				printf("(");
				if (text == 0)
				{
					fprintf(fp, "(");
				}
			}
			printf("%d", shuzi0 = random_0(range));    //��ӡ����
			if (text == 0)
			{
				fprintf(fp, "%d", shuzi0);
			}
			if (parenr == i + 1)                        //��ӡ������
			{
				printf(")");
				if (text == 0)
				{
					fprintf(fp, ")");
				}
			}
			if (i + 1 == 5)                                //��ӡ�ȺŽ�����ʽ
			{
				printf("=\n");
				if (text == 0)
				{
					fprintf(fp, "=\n");
				}
				break;
			}
			char a = GetOperation(oper);                  //��ӡ�������
			printf("%c", a);
			if (text == 0)
			{
				fprintf(fp, "%c", a);
			}
		}
	}
	
	if (num == 0)                                   //������С��
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
void noparen(int range, int oper, int num,int text)//��������ʽ
{
	int shuzi0;
	float shuzi1;
	FILE *fp;
	fp = fopen("testlby.txt", "w");
	if (num == 1)                                 //����������
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
	if (num == 0)                                     //������С��
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
	printf("�Զ���������������ϰ�����\n");
	printf("�����������(���100)��\n");
	scanf("%d", &count);
	if (count > 100)
	{
		count = 100;
	}
	else if (count <= 0)
	{
		printf("�������Ŀ����\n");
		return -1;
	}
	printf("�������ֵ(Ĭ�����9999)��\n");
	scanf("%d", &range);
	if (range > 9999)
	{
		count = 9999;
	}
	else if (count <= 0)
	{
		printf("��������ַ�Χ\n");
		return -1;
	}
	printf("��ʽ���Ƿ���С��(0С��1����)��\n");
	scanf("%d", &num);
	if (num != 0 && num != 1)
	{
		printf("Ĭ��Ϊ����\n");
		num = 1;
	}
	printf("��ʽ���Ƿ��г˳�(0��1��)��\n");
	scanf("%d", &oper);
	if (oper != 0 && oper != 1)
	{
		printf("Ĭ���޳˳�\n");
		oper = 0;
	}
	printf("��ʽ���Ƿ�������(0��1��)��\n");
    scanf("%d", &paren);
	if (paren != 0 && paren != 1)
	{ 
		printf("Ĭ��������\n");
		paren = 1;
	}
	printf("�Ƿ�����ļ�(0��1��)��\n");
	scanf("%d", &text);
	if (text != 0 && text != 1)
	{
		printf("Ĭ�ϲ����\n");
		text = 1;
	}
	return paren;
}
int main()
{
	int count/*��ʽ����*/, range/*���ַ�Χ*/, oper/*��������*/, num/*�Ƿ�С��*/, text/*�Ƿ��ļ�*/;
	int i=Scan(count,range,oper,num,text);
	if (i == 0)
	{
		for (int j = 0; j < count; j++)
		{
			haveparen(range, oper, num, text);//������

		}
	}
	else if (i == 1)
	{
		for (int j = 0; j < count; j++)
		{ 
		    noparen(range, oper, num, text);//û����
		}
	}
	else
	{
		return 0;
	}
	return 0;
}