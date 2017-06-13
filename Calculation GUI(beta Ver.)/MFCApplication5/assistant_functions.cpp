/*************************************************************
文件名：assistant_functions.cpp
作者：许郁杨 日期：2017/05/07
描述: 辅助功能函数
主要功能包括：比较大小求最值、计算最大公约数

作者：许郁杨 日期：2017/05/09
更新：新增命令行读写函数：从命令行中读取文件目录进行读入、写入操作

作者：许郁杨 日期：2017/05/10
更新：新增WriteFile函数，执行将语言资源的语句写入文件的功能
*************************************************************/
#include"stdafx.h"
#include<iostream>
#include<cstring>
#include<sstream>
#include<ctime>
#include<cassert>
#include<atlstr.h>
#include<fstream>
#include "assistant_functions.h"
#define RANDOM(equation,b) (rand()%(b-equation+1)+equation)//取得[a,b]内的随机整数
using namespace std;
//extern UINT g_idValue;

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

bool ifGenerateSeed = false;//标识是否已生成随机数种子
							/*生成[a,b]内的随机整数 日期：2017/05/07*/
int RandomNumber(int down, int up)
{
	if (!ifGenerateSeed)//如果未生成随机数种子
	{
		ifGenerateSeed = true;
		srand((unsigned)time(NULL));//生成随机数种子
	}
	return RANDOM(down, up);
}

/*对用户输入语言进行匹配，成功为true，失败为false 日期：2017/05/09*/
/*bool MatchLanguage(char language[])
{
	stringstream sstmp;
	string stmp;
	sstmp << language;
	sstmp >> stmp;//转换为string
	sstmp.clear();
	CString languageName;//用户输入语言
	languageName = stmp.c_str();//转换为CString
	CString languageList;//可选语言
	g_idValue = 0;
	languageList.LoadString(++g_idValue);
	int ntmp = 0;
	while (languageList != "End")
	{
		if (languageList == languageName)//语言匹配成功
		{
			ntmp = 1;
			g_idValue *= 1000;//跳转至对应语言资源
			break;
		}
		languageList.LoadString(++g_idValue);
	}
	if (ntmp == 0)//语言匹配失败
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*从文件中读入题目数量 日期：2017/05/09*/
/*int ReadFile(char *fileName)
{
	int problemNumber;//题目个数
	fstream istream;
	istream.open(fileName, ios::in);
	istream >> problemNumber;
	istream.close();
	return problemNumber;
}

/*写入语言资源内的语句 日期：2017/05/10*/
/*void WriteFile(char *fileName, int idValue)
{
	wfstream wostream;
	CString sentence;//资源语句
	sentence.LoadString(idValue);
	wostream.imbue(locale("CHS"));
	wostream.open(fileName, ios::app);
	wostream << (LPCTSTR)sentence;
	wostream.close();
}

/*写入最终结果 日期：2017/05/09*/
/*void PrintFinalResult(char *fileName, int correct, int wrong)
{
	CString sentence;//资源语句
	fstream ostream;
	wfstream wostream;

	ostream.open(fileName, ios::app);
	ostream << "********************************************************************" << endl;
	ostream << endl;
	ostream.close();

	WriteFile(fileName, ++g_idValue);

	ostream.open(fileName, ios::app);
	ostream << correct << endl;//写入正确题目数
	ostream.close();

	WriteFile(fileName, ++g_idValue);

	ostream.open(fileName, ios::app);
	ostream << wrong << endl;//写入错误题目数
	ostream.close();
}*/