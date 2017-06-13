/*************************************************************
文件名：expression.h
作者：许郁杨 日期：2017/05/08
描述: expression.cpp对应头文件
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