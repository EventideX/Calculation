/*************************************************************
�ļ�����generate.cpp
���ߣ��Ǽ��� ������ ���ڣ�2017/04/20
����: ���ɱ��ʽ
��Ҫ���ܰ������������������������������ɱ��ʽ������
*************************************************************/

#include"head.h"
extern UINT idValue;

int flag = 1, k = 0;
int randomNumber(int down, int up)//��������� 
{
	if (flag == 1)
	{
		flag = 0;
		srand((unsigned)time(NULL));//���� 
	}
	return random(down, up);
}
char randomOperation(int flag1)
{
	int tmp;
	if (flag1 == 'y') //����˳� 
	{
		tmp = randomNumber(1, 4);
		switch (tmp)
		{
		case 1:return '+';
			break;
		case 2:return '-';
			break;
		case 3:return '*';
			break;
		case 4:return '/';
			break;
		}
	}
	else
	{
		tmp = randomNumber(1, 2);
		switch (tmp)
		{
		case 1:return '+';
			break;
		case 2:return '-';
			break;
		}
	}
}
bool ifOnly(string str, vector<string> se) //�жϱ��ʽ�Ƿ��ظ� 
{
	int count = 0;
	for (int i = 0; i<se.size(); i++)
	{
		if (str != se[i]) count++;
		else break;
	}
	if (count == se.size()) return true;
	else return false;
}
vector<string> equation;
void generateExpression(int num, int low, int high, int flag0, char flag1, char flag2, char flag3)
{
	int i = 1, tmp;
	char sign;
	while (i <= num)
	{
		int flag4 = 1, number = flag0;
		string paras1, paras2, equ;
		for (int j = 0; j<number - 1; j++)
		{
			sign = randomOperation(flag1); //���������

			if (flag2 == 'y') //������� 
			{
				tmp = randomNumber(1, 3);
				switch (tmp)
				{
				case 1: //���������� 
				{
					stringstream tmps1, tmps2;
					tmps1 << randomNumber(low, high);
					tmps1 >> paras1;
					tmps2 << randomNumber(low, high);
					tmps2 >> paras2;
					break;
				}
				case 2: //����������� 
				{
					stringstream tmps;
					tmps << randomNumber(low, high);
					tmps >> paras1;
					Fraction frac2;
					frac2.getFrac(low, high);
					frac2.simplify();
					paras2 = frac2.transString();
					break;
				}
				case 3: //�����ͷ��� 
				{
					Fraction frac1, frac2;
					frac1.getFrac(low, high);
					frac1.simplify();
					frac2.getFrac(low, high);
					frac2.simplify();
					paras1 = frac1.transString();
					paras2 = frac2.transString();
					break;
				}
				}
			}
			else
			{
				stringstream tmps3, tmps4;
				tmps3 << randomNumber(low, high);
				tmps3 >> paras1;
				tmps4 << randomNumber(low, high);
				tmps4 >> paras2;
			}
			if (flag3 == 'y') //��������
			{
				tmp = randomNumber(1, 4);
				switch (tmp)
				{
				case 1: //������ 
				{
					if (flag4 == 1)
					{
						equ = paras1 + sign + paras2;
						flag4 = 0;
					}
					else equ = equ + sign + paras1;
					break;
				}
				case 2:
				{
					if (flag4 == 1)
					{
						equ = paras2 + sign + paras1;
						flag4 = 0;
					}
					else equ = paras1 + sign + equ;
					break;
				}
				case 3: //������ 
				{
					if (flag4 == 1)
					{
						equ = "[" + paras1 + sign + paras2 + "]";
						flag4 = 0;
					}
					else equ = "[" + equ + sign + paras1 + "]";
					break;
				}
				case 4:
				{
					if (flag4 == 1)
					{
						equ = "[" + paras2 + sign + paras1 + "]";
						flag4 = 0;
					}
					else equ = "[" + equ + sign + paras1 + "]";
					break;
				}
				}
			}
			else
			{
				tmp = randomNumber(1, 2);
				switch (tmp)
				{
				case 1:
				{
					if (flag4 == 1)
					{
						equ = paras1 + sign + paras2;
						flag4 = 0;
					}
					else equ = equ + sign + paras1;
					break;
				}
				case 2:
				{
					if (flag4 == 1)
					{
						equ = paras2 + sign + paras1;
						flag4 = 0;
					}
					else equ = paras1 + sign + equ;
				}
				}
			}
		}
		string result = calculateResult(equ);
		if ((ifOnly(equ, equation)) && (result != "non_comformance")) //�жϱ��ʽ�Ƿ��ظ��Լ��Ƿ���� 
		{
			equation.push_back(equ);
			checkAndPrint(equ, i, result);
			i++;
		}
	}
	idValue++;
}