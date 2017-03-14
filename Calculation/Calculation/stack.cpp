/*************************************************************
�ļ�����stack.cpp
���ߣ������� ���ڣ�2016/02/16
����: ջ
��Ҫ���ܰ�������׺ת��Ϊ��׺�������׺
*************************************************************/

#include"head.h"

//�����ջ 
void transEquation(string infix, char postfix[]) //��׺תΪ��׺ 
{
	int i = 0, j = 0; stack<char> stored;
	while (i<infix.size())
		//while (infix[i]!='\0')
	{
		if ((infix[i] >= '0') && (infix[i] <= '9')) //�ж����� 
		{
			while ((infix[i] >= '0') && (infix[i] <= '9'))
			{
				postfix[j] = infix[i];
				i++;
				j++;
			}
			postfix[j] = '!'; //��ʶ�������� 
			j++;
		}
		if (infix[i] == '(') //�жϷ��� 
		{
			while (infix[i] != ')') //��������Ϊ���� 
			{
				postfix[j] = infix[i];
				i++;
				j++;
			}
			postfix[j] = infix[i];
			i++;
			j++;
		}
		if ((infix[i] == '+') || (infix[i] == '-')) //�ж�'+'��'-' 
		{
			while ((!stored.empty()) && (stored.top() != '['))
			{
				postfix[j] = stored.top();
				j++;
				stored.pop();
			}
			stored.push(infix[i]);
		}
		if ((infix[i] == '*') || (infix[i] == '/')) //�ж�'*'��'/' 
		{
			while ((!stored.empty()) && (stored.top() != '[') && ((stored.top() == '*') || (stored.top() == '/')))
			{
				postfix[j] = stored.top();
				j++;
				stored.pop();
			}
			stored.push(infix[i]);
		}
		if (infix[i] == '[') stored.push(infix[i]); //�ж�'[' 
		if (infix[i] == ']') //�ж�']' 
		{
			while (stored.top() != '[')
			{
				postfix[j] = stored.top();
				j++;
				stored.pop();
			}
			stored.pop();
		}
		i++;
	}
	while (!stored.empty()) //��������� 
	{
		postfix[j] = stored.top();
		j++;
		stored.pop();
	}
	postfix[j] = '\0'; //��ֹ�� 
}
//��ջ 
string countEquation(string infix) //�����׺��ֵ 
{
	int i = 0, point = -1, check = 0;
	char postfix[MAX]; Fraction figure[MAX];
	transEquation(infix, postfix);
	while ((postfix[i] != '\0') && (i<1000))
	{
		if ((postfix[i] >= '0') && (postfix[i] <= '9')) //������ջ 
		{
			double k = 0; //int�������� 
			while ((postfix[i] >= '0') && (postfix[i] <= '9'))
			{
				k = 10 * k + postfix[i] - '0';
				i++;
			}
			point++;
			figure[point] = figure[point].transFrac(k, 1);
		}
		else
			if (postfix[i] == '(') //������ջ 
			{
				double up = 0, down = 0; //int�������� 
				i++;
				while (postfix[i] != '\\')
				{
					up = 10 * up + postfix[i] - '0';
					i++;
				}
				i++;
				while (postfix[i] != ')')
				{
					down = 10 * down + postfix[i] - '0';
					i++;
				}
				point++;
				figure[point] = figure[point].transFrac(up, down);
			}
			else
			{
				point--;
				switch (postfix[i])
				{
				case '+':figure[point] = figure[point] + figure[point + 1];
					break;
				case '-':figure[point] = figure[point] - figure[point + 1];
					break;
				case '*':figure[point] = figure[point] * figure[point + 1];
					break;
				case '/':if (figure[point + 1].checkZero(figure[point + 1])) check = 1; //��ʶ���� 
					figure[point] = figure[point] / figure[point + 1];
				}
			}
		i++;
	}
	if ((check == 0) && (figure[point].checkInt(figure[point]))) return figure[point].transToString(figure[point]); //�ж��Ƿ���� 
	else return "non_comformance";
}