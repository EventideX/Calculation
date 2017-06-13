/*************************************************************
文件名：Expression.cpp
作者：许郁杨 日期：2017/05/08
描述: 表达式类
主要功能包括：表达式的生成、计算

作者：许郁杨 日期：2017/05/10
更新：补充了注释，对格式排版进行一些调整
*************************************************************/
#include"stdafx.h"
#include"expression.h"
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;

Expression::Expression() { }

/*随机生成一个运算符 日期：2017/05/07
更新：注释补充，格式调整 日期：2017/05/10*/
char Expression::RandomOperation(char ifMultiplyDivide)
{
	int tmp;
	if (ifMultiplyDivide == 'y')//允许乘除 
	{
		tmp = RandomNumber(1, 4);
		switch (tmp)
		{
		case 1:
		{
			return '+';
			break;
		}
		case 2:
		{
			return '-';
			break;
		}
		case 3:
		{
			return '*';
			break;
		}
		case 4:
		{
			return '/';
			break;
		}
		}
	}
	else//不允许乘除
	{
		tmp = RandomNumber(1, 2);
		switch (tmp)
		{
		case 1:
		{
			return '+';
			break;
		}
		case 2:
		{
			return '-';
			break;
		}
		}
	}
}

/*判断表达式是否唯一，重复为false，唯一为true 日期：2017/05/07
更新：注释补充，格式调整 日期：2017/05/10*/
bool Expression::IsOnly(string expression)
{
	int count = 0;
	for (unsigned i = 0; i < m_expressionUint.size(); i++)
	{
		if (expression != m_expressionUint[i])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == m_expressionUint.size())//如果为唯一
	{
		return true;
	}
	else//如果重复
	{
		return false;
	}
}

/*生成一个中缀表达式 日期：2017/05/07
更新：注释补充，格式调整 日期：2017/05/10*/
string Expression::GenerateInfixExpression(int low, int high, int parameterNumber, char ifMultiplyDivide, char ifFraction, char ifBracket)
{
	string expression;//表达式
	for (; ;)
	{
		string parameter1, parameter2;//表达式的参数
		bool ifFirst = true;//是否已生成第一个小表达式，是为true，否为false
		for (int j = 0; j < parameterNumber - 1; j++)
		{
			int ntmp;
			char sign = RandomOperation(ifMultiplyDivide);//运算符

			if (ifFraction == 'y')//允许分数 
			{
				ntmp = RandomNumber(1, 3);
				switch (ntmp)
				{
				case 1://整数和整数 
				{
					stringstream sstmp1, sstmp2;
					sstmp1 << RandomNumber(low, high);
					sstmp1 >> parameter1;
					sstmp2 << RandomNumber(low, high);
					sstmp2 >> parameter2;
					sstmp1.clear();
					sstmp2.clear();
					break;
				}
				case 2://整数和真分数 
				{
					stringstream sstmp;
					sstmp << RandomNumber(low, high);
					sstmp >> parameter1;
					sstmp.clear();
					Fraction fraction2;
					fraction2.GetFraction(low, high);
					fraction2.Simplify();
					parameter2 = fraction2.TransferIntoStringNoInt();
					break;
				}
				case 3://分数和分数 
				{
					Fraction fraction1, fraction2;
					fraction1.GetFraction(low, high);
					fraction1.Simplify();
					fraction2.GetFraction(low, high);
					fraction2.Simplify();
					parameter1 = fraction1.TransferIntoStringNoInt();
					parameter2 = fraction2.TransferIntoStringNoInt();
					break;
				}
				}
			}
			else//不允许分数
			{
				stringstream sstmp1, sstmp2;
				sstmp1 << RandomNumber(low, high);
				sstmp1 >> parameter1;
				sstmp2 << RandomNumber(low, high);
				sstmp2 >> parameter2;
				sstmp1.clear();
				sstmp2.clear();
			}
			if (ifBracket == 'y')//允许括号
			{
				ntmp = RandomNumber(1, 4);
				switch (ntmp)
				{
				case 1://无括号
				{
					if (ifFirst)
					{
						expression = parameter1 + sign + parameter2;
						ifFirst = false;
					}
					else
					{
						expression = expression + sign + parameter1;
					}
					break;
				}
				case 2://无括号
				{
					if (ifFirst)
					{
						expression = parameter2 + sign + parameter1;
						ifFirst = false;
					}
					else
					{
						expression = parameter1 + sign + expression;
					}
					break;
				}
				case 3://有括号
				{
					if (ifFirst)
					{
						expression = "[" + parameter1 + sign + parameter2 + "]";
						ifFirst = false;
					}
					else
					{
						expression = "[" + expression + sign + parameter1 + "]";
					}
					break;
				}
				case 4://有括号
				{
					if (ifFirst)
					{
						expression = "[" + parameter2 + sign + parameter1 + "]";
						ifFirst = false;
					}
					else
					{
						expression = "[" + expression + sign + parameter1 + "]";
					}
					break;
				}
				}
			}
			else//不允许括号
			{
				ntmp = RandomNumber(1, 2);
				switch (ntmp)
				{
				case 1:
				{
					if (ifFirst)
					{
						expression = parameter1 + sign + parameter2;
						ifFirst = false;
					}
					else
					{
						expression = expression + sign + parameter1;
					}
					break;
				}
				case 2:
				{
					if (ifFirst)
					{
						expression = parameter2 + sign + parameter1;
						ifFirst = false;
					}
					else
					{
						expression = parameter1 + sign + expression;
					}
				}
				}
			}
		}
		m_infix = expression;
		if ((IsOnly(expression)) && (CalculateResult() != "non_comformance"))//判断新生成的表达式是否重复以及是否出现除0的情况
		{
			m_expressionUint.push_back(expression);
			break;
		}
	}
	return expression;
}

/*将中缀表达式转化为后缀表达式 日期：2017/05/07
更新：注释补充，格式调整 日期：2017/05/10*/
void Expression::TransferInfixIntoPostfix()
{
	unsigned i = 0;
	int j = 0;
	stack<char> signStack;//符号栈
	while (i < m_infix.size())
	{
		if ((m_infix[i] >= '0') && (m_infix[i] <= '9'))//判断数字 
		{
			while ((m_infix[i] >= '0') && (m_infix[i] <= '9'))
			{
				m_postfix[j] = m_infix[i];
				i++;
				j++;
			}
			m_postfix[j] = '!';//标识单个整数 
			j++;
		}
		if (m_infix[i] == '(')//判断分数 
		{
			while (m_infix[i] != ')')//将分数作为整体 
			{
				m_postfix[j] = m_infix[i];
				i++;
				j++;
			}
			m_postfix[j] = m_infix[i];
			i++;
			j++;
		}
		if ((m_infix[i] == '+') || (m_infix[i] == '-'))//判断'+'、'-' 
		{
			while ((!signStack.empty()) && (signStack.top() != '['))
			{
				m_postfix[j] = signStack.top();
				j++;
				signStack.pop();
			}
			signStack.push(m_infix[i]);
		}
		if ((m_infix[i] == '*') || (m_infix[i] == '/'))//判断'*'、'/' 
		{
			while ((!signStack.empty()) && (signStack.top() != '[') && ((signStack.top() == '*') || (signStack.top() == '/')))
			{
				m_postfix[j] = signStack.top();
				j++;
				signStack.pop();
			}
			signStack.push(m_infix[i]);
		}
		if (m_infix[i] == '[')//判断'['
		{
			signStack.push(m_infix[i]);
		}
		if (m_infix[i] == ']')//判断']' 
		{
			while (signStack.top() != '[')
			{
				m_postfix[j] = signStack.top();
				j++;
				signStack.pop();
			}
			signStack.pop();
		}
		i++;
	}
	while (!signStack.empty())//当有残余运算符时 
	{
		m_postfix[j] = signStack.top();
		j++;
		signStack.pop();
	}
	m_postfix[j] = '\0';//设置终止符 
}

/*计算后缀表达式的值 日期：2017/05/07
更新：注释补充，格式调整 日期：2017/05/10*/
string Expression::CalculateResult()
{
	int i = 0;
	int point = -1;//栈顶指针
	bool ifDivideZero = false;//是否除零，是为true，否为false
	Fraction numberStack[kMax];//数栈
	TransferInfixIntoPostfix();
	while ((m_postfix[i] != '\0') && (i<1000))
	{
		if ((m_postfix[i] >= '0') && (m_postfix[i] <= '9'))//整数入栈 
		{
			double k = 0;//int会计算出错 
			while ((m_postfix[i] >= '0') && (m_postfix[i] <= '9'))
			{
				k = 10 * k + m_postfix[i] - '0';
				i++;
			}
			point++;
			numberStack[point].TransferIntIntoFraction(k, 1);
		}
		else
			if (m_postfix[i] == '(')//分数入栈 
			{
				double up = 0, down = 0;//int会计算出错 
				i++;
				while (m_postfix[i] != '\\')
				{
					up = 10 * up + m_postfix[i] - '0';
					i++;
				}
				i++;
				while (m_postfix[i] != ')')
				{
					down = 10 * down + m_postfix[i] - '0';
					i++;
				}
				point++;
				numberStack[point].TransferIntIntoFraction(up, down);
			}
			else//进行计算
			{
				point--;
				switch (m_postfix[i])
				{
				case '+':
				{
					numberStack[point] = numberStack[point] + numberStack[point + 1];
					break;
				}
				case '-':
				{
					numberStack[point] = numberStack[point] - numberStack[point + 1];
					break;
				}
				case '*':
				{
					numberStack[point] = numberStack[point] * numberStack[point + 1];
					break;
				}
				case '/':
				{
					if (numberStack[point + 1].isDivisorZero())//如果除数为零
					{
						ifDivideZero = true;
					}
					numberStack[point] = numberStack[point] / numberStack[point + 1];
				}
				}
			}
		i++;
	}
	if ((!ifDivideZero) && (numberStack[point].IsInt()))//如果没有除零以及得数为整数
	{
		return numberStack[point].TransferIntoString();
	}
	else
	{
		return "non_comformance";
	}
}