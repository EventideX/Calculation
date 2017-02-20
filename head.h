/*************************************************************
�ļ�����head.h 
���ߣ��Ǽ��� ���ڣ�2016/02/16
����: ͷ�ļ� ������
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
#define Min(x,y) (((x)<(y))?(x):(y))
#define Max(x,y) (((x)>(y))?(x):(y))
#define random(a,b) (rand()%(b-a+1)+a)   
#define MAX 1000
using namespace std;

/*generate.cpp*/ 
int getRand(int down,int up);
void getAndCalculate(int opt,int num,int low,int high,int flag0,char flag1,char flag2,char flag3);

/*Stack.cpp*/ 
void transEquation(string infix,char postfix[]);
string countEquation(string infix);

/*verify.cpp*/
bool ifOnly(string str,vector<string> se);
void checkAndOutput(string equ,int n,int opt,string result);
void finalOut(int opt);

/*fraction.cpp*/
class Fraction
{
	private:
		int numerator,denominator;
		string numerators,denominators;
		int greatestCommonDivisor(int x,int y);
	
	public:
		Fraction();
		Fraction(int numerator,int denominator);
		Fraction getFrac(int l,int h);
		bool checkZero(Fraction frac);
		bool checkInt(Fraction frac);
		Fraction transFrac(int up,int down);
		
		Fraction simplify(Fraction frac);
		string transString(Fraction frac);
		string transToString(Fraction frac);
		
		friend const Fraction operator +(Fraction frac1,Fraction frac2);  
        friend const Fraction operator -(Fraction frac1,Fraction frac2);  
        friend const Fraction operator *(Fraction frac1,Fraction frac2);  
        friend const Fraction operator /(Fraction frac1,Fraction frac2); 
};
