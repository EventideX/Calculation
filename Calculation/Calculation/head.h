/*************************************************************
文件名：head.h
作者：盖嘉轩 许郁杨 日期：2017/04/20
描述: 头文件
*************************************************************/

#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>
#include<ctime>
#include<vector>
#include<stack>
#include<cassert>
#include<atlstr.h>
#define Min(x,y) (((x)<(y))?(x):(y))
#define Max(x,y) (((x)>(y))?(x):(y))
#define random(a,b) (rand()%(b-a+1)+a)   
#define MAX 1000
using namespace std;

/*scan.cpp*/
void scan();

/*generate.cpp*/
int randomNumber(int down, int up);
char randomOperation(int flag1);
bool ifOnly(string str, vector<string> se);
void generateExpression(int num, int low, int high, int flag0, char flag1, char flag2, char flag3);

/*calculate.cpp*/
void transExpression(string infix, char postfix[]);
string calculateResult(string infix);

/*print.cpp*/
void checkAndPrint(string equ, int n, string result);
void print();

/*fraction.cpp*/
class Fraction
{
private:
	int numerator, denominator;
	string numerators, denominators;
	int greatestCommonDivisor(int x, int y);

public:
	Fraction();
	void getFrac(int l, int h);
	bool checkZero();
	bool checkInt();
	void transFrac(int up, int down);

	void simplify();
	string transString();
	string transToString();

	friend const Fraction operator +(Fraction frac1, Fraction frac2);
	friend const Fraction operator -(Fraction frac1, Fraction frac2);
	friend const Fraction operator *(Fraction frac1, Fraction frac2);
	friend const Fraction operator /(Fraction frac1, Fraction frac2);
};