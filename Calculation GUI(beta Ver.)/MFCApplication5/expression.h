/*************************************************************
�ļ�����expression.h
���ߣ������� ���ڣ�2017/05/08
����: expression.cpp��Ӧͷ�ļ�
*************************************************************/
#pragma once

#include"fraction.h"
#include"assistant_functions.h"
#include<iostream>
#include<vector>
using namespace std;
const int kMax = 1000;

class Expression
{
private:
	vector<string> m_expressionUint;
	string m_infix;
	char m_postfix[kMax];

public:
	Expression();
	char RandomOperation(char ifMultiplyDivide);
	string GenerateInfixExpression(int low, int high, int parameterNumber, char ifMultiplyDivide, char ifFraction, char ifBracket);
	void TransferInfixIntoPostfix();
	string CalculateResult();
	bool IsOnly(string expression);
};