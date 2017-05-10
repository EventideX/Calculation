/*************************************************************
�ļ�����fraction.cpp
���ߣ������� ���ڣ�2017/05/07
����: ������
��Ҫ���ܰ��������������ɡ�ת������������

���ߣ������� ���ڣ�2017/05/10
���£�������ע�ͣ��Ը�ʽ�Ű����һЩ����
*************************************************************/

#include"fraction.h"
#include<iostream>
#include<sstream>
using namespace std;

Fraction::Fraction() { }

/*���ɷ��� ���ڣ�2017/05/07*/
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

/*�������Ƿ�Ϊ�㣬��Ϊtrue����Ϊfalse ���ڣ�2017/05/07
  ���£���ʽ���� ���ڣ�2017/05/10*/
bool Fraction::isDivisorZero()
{
	if (m_nnumerator == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*����Ƿ�ɻ�����������Ϊtrue����Ϊfalse ���ڣ�2017/05/07
  ���£�ע�Ͳ��䣬��ʽ���� ���ڣ�2017/05/10*/
bool Fraction::IsInt()
{
	if (m_ndenominator == 1)//�������Ϊһ,���ɻ���Ϊ����
	{
		return true;
	}
	else//������ɻ���Ϊ����
	{
		return false;
	}
}

/*������ת��Ϊ������ʽ ���ڣ�2017/05/07*/
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

/*������� ���ڣ�2017/05/07
  ���£�ע�Ͳ��䣬��ʽ���� ���ڣ�2017/05/10*/
void Fraction::Simplify()
{
	int ntmp;
	stringstream sstmp1, sstmp2;
	if (m_ndenominator < 0)//�����ĸΪ����
	{
		m_ndenominator = -m_ndenominator;
		m_nnumerator = -m_nnumerator;
	}
	if (m_nnumerator == 0)//�������Ϊ��
	{
		m_ndenominator = 1;
	}
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

/*������ת��Ϊ�ַ�����ʽ�������������� ���ڣ�2017/05/07*/
string Fraction::TransferIntoStringNoInt()
{
	string str;
	str = "(" + m_snumerator + "\\" + m_sdenominator + ")";
	return str;
}

/*������ת��Ϊ�ַ�����ʽ������������ ���ڣ�2017/05/07
  ���£�ע�Ͳ��䣬��ʽ���� ���ڣ�2017/05/10*/
string Fraction::TransferIntoString()
{
	string str;
	if (m_ndenominator == 1)//�����ĸΪһ
	{
		str = m_snumerator;
	}
	else
	{
		str = "(" + m_snumerator + "\\" + m_sdenominator + ")";
	}
	return str;
}

/*���ؼӷ������ ���ڣ�2017/05/07*/
const Fraction operator +(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator + frac1.m_ndenominator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

/*���ؼ�������� ���ڣ�2017/05/07*/
const Fraction operator -(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator - frac1.m_ndenominator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

/*���س˷������ ���ڣ�2017/05/07*/
const Fraction operator *(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

/*���س�������� ���ڣ�2017/05/07*/
const Fraction operator /(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_nnumerator;
	answer.Simplify();
	return answer;
}