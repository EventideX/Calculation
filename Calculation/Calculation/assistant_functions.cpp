/*************************************************************
文件名：assistant_functions.cpp
作者：许郁杨 日期：2017/05/07
描述: 辅助功能函数
主要功能包括：比较大小求最值、计算最大公约数
*************************************************************/
#include<iostream>
#include<cstring>
#include<sstream>
#include<ctime>
#include<cassert>
#include<atlstr.h>
#include<fstream>
#include "assistant_functions.h"
#define RANDOM(a,b) (rand()%(b-a+1)+a)//取得[a,b]内的随机整数
using namespace std;
extern UINT g_idValue;

/*比较大小求较大值 日期：2017/05/07*/
int Max(int x, int y)
{
	if (x > y) return x;
	else return y;
}

/*比较大小求较小值 日期：2017/05/07*/
int Min(int x, int y)
{
	if (x > y) return y;
	else return x;
}

/*计算最大公约数 日期：2017/05/07*/
int GreatestCommonDivisor(int x, int y)
{
	if (y == 0) return x;
	else return GreatestCommonDivisor(y, x%y);
}

int flag = 1;
/*生成[a,b]内的随机整数 日期：2017/05/07*/
int RandomNumber(int down, int up)
{
	if (flag == 1)
	{
		flag = 0;
		srand((unsigned)time(NULL));//生成种子
	}
	return RANDOM(down, up);
}

bool MatchLanguage(char language[])
{
	stringstream sstmp;
	string stmp;
	sstmp << language;
	sstmp >> stmp;//转换为string
	sstmp.clear();
	CString languageName;
	languageName = stmp.c_str();//转换为CString
	CString languageList;
	g_idValue = 0;
	languageList.LoadString(++g_idValue);
	int ntmp = 0;
	while (languageList != "End")
	{
		if (languageList == languageName)
		{
			ntmp = 1;
			g_idValue *= 1000;//跳转至对应语言资源
			break;
		}
		languageList.LoadString(++g_idValue);
	}
	if (ntmp == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int ReadFile(char *filename)//filename是绝对路径
{
	int problemNumber;
	fstream istream;
	istream.open(filename, ios::in);
	istream >> problemNumber;
	istream.close();
	return problemNumber;
}

void PrintFinalResult(char *filename, int correct, int wrong)
{
	CString sentence;
	fstream ostream;
	wfstream wostream;

	ostream.open(filename, ios::app);
	ostream << "********************************************************************" << endl;
	ostream << endl;
	ostream.close();

	wostream.imbue(locale("CHS"));
	sentence.LoadString(++g_idValue);

	wostream.open(filename, ios::app);
	wostream << (LPCTSTR)sentence;
	wostream.close();

	ostream.open(filename, ios::app);
	ostream << correct << endl;
	ostream.close();

	sentence.LoadString(++g_idValue);

	wostream.open(filename, ios::app);
	wostream << (LPCTSTR)sentence;
	wostream.close();

	ostream.open(filename, ios::app);
	ostream << wrong << endl;
	ostream.close();
}