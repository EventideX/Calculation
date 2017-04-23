/*************************************************************
�ļ�����fraction.cpp
���ߣ������� ���ڣ�2017/02/16
����: ������
��Ҫ���ܰ��������������ɡ�ת������������
*************************************************************/

#include"head.h"

int Fraction::greatestCommonDivisor(int x, int y) //���Լ�� 
{
	if (y == 0) return x;
	else return greatestCommonDivisor(y, x%y);
}
Fraction::Fraction() { }
void Fraction::getFrac(int l, int h) //���ɷ��� 
{
	int tmp1 = 0, tmp2 = 0;
	char tmpc[MAX];
	stringstream tmps5, tmps6;
	while (Max(tmp1, tmp2) == 0) //��ֹ��ĸΪ�� 
	{
		tmp1 = randomNumber(l, h);
		tmp2 = randomNumber(l, h);
	}
	numerator = Min(tmp1, tmp2);
	denominator = Max(tmp1, tmp2);
	tmps5 << numerator;
	tmps5 >> numerators;
	tmps6 << denominator;
	tmps6 >> denominators;
}
bool Fraction::checkZero() //��ֹ����Ϊ�� 
{
	if (numerator == 0) return true;
	else return false;
}
bool Fraction::checkInt()
{
	if (denominator == 1) return true;
	else return false;
}
void Fraction::transFrac(int up, int down) //����ת��Ϊ���� 
{
	stringstream tmps9, tmps10;
	numerator = up;
	denominator = down;
	tmps9 << numerator;
	tmps9 >> numerators;
	tmps10 << denominator;
	tmps10 >> denominators;
}
void Fraction::simplify() //�������� 
{
	int tmp;
	char tmpc[MAX];
	stringstream tmps7, tmps8;
	if (denominator<0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
	if (numerator == 0) denominator = 1;
	else
	{
		tmp = greatestCommonDivisor(abs(denominator), abs(numerator));
		numerator /= tmp;
		denominator /= tmp;
	}
	tmps7 << numerator;
	tmps7 >> numerators;
	tmps8 << denominator;
	tmps8 >> denominators;
}
string Fraction::transString() //����תΪ�ַ��������ж�������
{
	string str;
	str = "(" + numerators + "\\" + denominators + ")";
	return str;
}
string Fraction::transToString() //����תΪ�ַ������ж�������
{
	string str;
	if (denominator == 1) str = numerators;
	else str = "(" + numerators + "\\" + denominators + ")";
	return str;
}
const Fraction operator +(Fraction frac1, Fraction frac2) //�ӷ� 
{
	Fraction answer;
	answer.numerator = frac1.numerator*frac2.denominator + frac1.denominator*frac2.numerator;
	answer.denominator = frac1.denominator*frac2.denominator;
	answer.simplify();
	return answer;
}
const Fraction operator -(Fraction frac1, Fraction frac2) //���� 
{
	Fraction answer;
	answer.numerator = frac1.numerator*frac2.denominator - frac1.denominator*frac2.numerator;
	answer.denominator = frac1.denominator*frac2.denominator;
	answer.simplify();
	return answer;
}
const Fraction operator *(Fraction frac1, Fraction frac2) //�˷� 
{
	Fraction answer;
	answer.numerator = frac1.numerator*frac2.numerator;
	answer.denominator = frac1.denominator*frac2.denominator;
	answer.simplify();
	return answer;
}
const Fraction operator /(Fraction frac1, Fraction frac2) //���� 
{
	Fraction answer;
	answer.numerator = frac1.numerator*frac2.denominator;
	answer.denominator = frac1.denominator*frac2.numerator;
	answer.simplify();
	return answer;
}