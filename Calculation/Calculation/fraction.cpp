/*************************************************************
文件名：fraction.cpp
作者：许郁杨 日期：2017/05/07
描述: 分数类
主要功能包括：分数的生成、转换和四则运算
*************************************************************/

#include"fraction.h"
#include<iostream>
#include<sstream>
using namespace std;

Fraction::Fraction() { }

/*生成分数 日期：2017/05/07*/
void Fraction::GetFraction(int l, int h)
{
	int ntmp1 = 0, ntmp2 = 0;
	stringstream sstmp1, sstmp2;
	while (Max(ntmp1, ntmp2) == 0)
	{
		ntmp1 = RandomNumber(l, h);
		ntmp2 = RandomNumber(l, h);
	}
	m_nnumerator = Min(ntmp1, ntmp2);
	m_ndenominator = Max(ntmp1, ntmp2);
	sstmp1 << m_nnumerator;
	sstmp1 >> m_snumerator;
	sstmp2 << m_ndenominator;
	sstmp2 >> m_sdenominator;
}

/*检查除数是否为零 日期：2017/05/07*/
bool Fraction::HaveZero()
{
	if (m_nnumerator == 0) return true;
	else return false;
}

/*检查是否可化简整数 日期：2017/05/07*/
bool Fraction::IsInt()
{
	if (m_ndenominator == 1) return true;
	else return false;
}

/*将整数转换为分数形式 日期：2017/05/07*/
void Fraction::TransferIntIntoFraction(int up, int down)
{
	stringstream sstmp1, sstmp2;
	m_nnumerator = up;
	m_ndenominator = down;
	sstmp1 << m_nnumerator;
	sstmp1 >> m_snumerator;
	sstmp2 << m_ndenominator;
	sstmp2 >> m_sdenominator;
	sstmp1.clear();
	sstmp2.clear();
}

/*化简分数 日期：2017/05/07*/
void Fraction::Simplify()
{
	int ntmp;
	stringstream sstmp1, sstmp2;
	if (m_ndenominator<0)
	{
		m_ndenominator = -m_ndenominator;
		m_nnumerator = -m_nnumerator;
	}
	if (m_nnumerator == 0) m_ndenominator = 1;
	else
	{
		ntmp = GreatestCommonDivisor(abs(m_ndenominator), abs(m_nnumerator));
		m_nnumerator /= ntmp;
		m_ndenominator /= ntmp;
	}
	sstmp1 << m_nnumerator;
	sstmp1 >> m_snumerator;
	sstmp2 << m_ndenominator;
	sstmp2 >> m_sdenominator;
	sstmp1.clear();
	sstmp2.clear();
}

/*将分数转换为字符串形式（不区分整数） 日期：2017/05/07*/
string Fraction::TransferIntoStringNoInt()
{
	string str;
	str = "(" + m_snumerator + "\\" + m_sdenominator + ")";
	return str;
}

/*将分数转换为字符串形式（区分整数） 日期：2017/05/07*/
string Fraction::TransferIntoString()
{
	string str;
	if (m_ndenominator == 1) str = m_snumerator;
	else str = "(" + m_snumerator + "\\" + m_sdenominator + ")";
	return str;
}

/*重载加法运算符 日期：2017/05/07*/
const Fraction operator +(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator + frac1.m_ndenominator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

/*重载减法运算符 日期：2017/05/07*/
const Fraction operator -(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator - frac1.m_ndenominator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

/*重载乘法运算符 日期：2017/05/07*/
const Fraction operator *(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

/*重载除法运算符 日期：2017/05/07*/
const Fraction operator /(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_nnumerator;
	answer.Simplify();
	return answer;
}