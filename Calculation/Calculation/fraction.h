/*************************************************************
�ļ�����fraction.h
���ߣ������� ���ڣ�2017/05/07
����: fraction.cpp��Ӧͷ�ļ�
*************************************************************/
#pragma once

#include"assistant_functions.h"
#include<iostream>
using namespace std;

class Fraction
{
private:
	int m_nnumerator, m_ndenominator;
	string m_snumerator, m_sdenominator;

public:
	Fraction();
	void GetFraction(int l, int h);
	bool HaveZero();
	bool IsInt();
	void TransferIntIntoFraction(int up, int down);

	void Simplify();
	string TransferIntoStringNoInt();
	string TransferIntoString();

	friend const Fraction operator +(Fraction frac1, Fraction frac2);
	friend const Fraction operator -(Fraction frac1, Fraction frac2);
	friend const Fraction operator *(Fraction frac1, Fraction frac2);
	friend const Fraction operator /(Fraction frac1, Fraction frac2);
};