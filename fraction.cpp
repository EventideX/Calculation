/*************************************************************
�ļ�����fraction.cpp 
���ߣ������� ���ڣ�2016/02/16
����: ������ 
��Ҫ���ܰ��������������ɡ�ת������������ 
*************************************************************/

#include"head.h"

int Fraction::greatestCommonDivisor(int x,int y) //���Լ�� 
{
	if (y==0) return x;
	else return greatestCommonDivisor(y,x%y);
}
Fraction::Fraction(){ }
Fraction Fraction::getFrac(int l,int h) //���ɷ��� 
{
	Fraction frac;
	int tmp1,tmp2;
	char tmpc[MAX];
	stringstream tmps5,tmps6;
	tmp1=getRand(l,h);
	tmp2=getRand(l,h);
	frac.numerator=Min(tmp1,tmp2);
	frac.denominator=Max(tmp1,tmp2);
	tmps5<<frac.numerator;
	tmps5>>frac.numerators;
	tmps6<<frac.denominator;
	tmps6>>frac.denominators;
	return frac;
}
Fraction Fraction::transFrac(int up,int down) //����ת��Ϊ���� 
{
	Fraction frac;
	stringstream tmps9,tmps10;
	frac.numerator=up;
	frac.denominator=down;
	tmps9<<frac.numerator;
	tmps9>>frac.numerators;
	tmps10<<frac.denominator;
	tmps10>>frac.denominators;
	return frac;
}
void Fraction::fixUp(Fraction frac) //ά����ĸΪ�� 
{
	if (frac.denominator<0)
	{
		frac.denominator=-frac.denominator;
		frac.numerator=-frac.numerator;
    }
}
Fraction Fraction::simplify(Fraction frac) //�������� 
{
	int tmp;
	char tmpc[MAX];
	stringstream tmps7,tmps8;
	fixUp(frac);
	if (frac.numerator==0) frac.denominator=1;
	else
	{
		tmp=greatestCommonDivisor(fabs(frac.numerator),fabs(frac.denominator));
		frac.numerator/=tmp;
		frac.denominator/=tmp;
	}
	tmps7<<frac.numerator;
	tmps7>>frac.numerators;
	tmps8<<frac.denominator;
	tmps8>>frac.denominators;
	return frac;
}
string Fraction::transString(Fraction frac) //����תΪ�ַ��������ж�������
{
	string str;
	str="("+frac.numerators+"\\"+frac.denominators+")";
	return str;
}
string Fraction::transToString(Fraction frac) //����תΪ�ַ������ж�������
{
	string str;
	if (frac.denominator==1) str=frac.numerators;
	else str="("+frac.numerators+"\\"+frac.denominators+")";
	return str;
}
const Fraction operator +(Fraction frac1,Fraction frac2) //�ӷ� 
{
	Fraction answer;
	answer.numerator=frac1.numerator*frac2.denominator+frac1.denominator*frac2.numerator;
	answer.denominator=frac1.denominator*frac2.denominator;
	return answer.simplify(answer);
}
const Fraction operator -(Fraction frac1,Fraction frac2) //���� 
{
	Fraction answer;
	answer.numerator=frac1.numerator*frac2.denominator-frac1.denominator*frac2.numerator;
	answer.denominator=frac1.denominator*frac2.denominator;
	return answer.simplify(answer);
}
const Fraction operator *(Fraction frac1,Fraction frac2) //�˷� 
{
	Fraction answer;
	answer.numerator=frac1.numerator*frac2.numerator;
	answer.denominator=frac1.denominator*frac2.denominator;
	return answer.simplify(answer);
}
const Fraction operator /(Fraction frac1,Fraction frac2) //���� 
{
	Fraction answer;
	answer.numerator=frac1.numerator*frac2.denominator;
	answer.denominator=frac1.denominator*frac2.numerator;
	return answer.simplify(answer);
}
