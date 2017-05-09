/*************************************************************
�ļ�����assistant_functions.cpp
���ߣ������� ���ڣ�2017/05/07
����: �������ܺ���
��Ҫ���ܰ������Ƚϴ�С����ֵ���������Լ��
*************************************************************/
#include<iostream>
#include<cstring>
#include<sstream>
#include<ctime>
#include<cassert>
#include<atlstr.h>
#include<fstream>
#include "assistant_functions.h"
#define RANDOM(a,b) (rand()%(b-a+1)+a)//ȡ��[a,b]�ڵ��������
using namespace std;
extern UINT g_idValue;

/*�Ƚϴ�С��ϴ�ֵ ���ڣ�2017/05/07*/
int Max(int x, int y)
{
	if (x > y) return x;
	else return y;
}

/*�Ƚϴ�С���Сֵ ���ڣ�2017/05/07*/
int Min(int x, int y)
{
	if (x > y) return y;
	else return x;
}

/*�������Լ�� ���ڣ�2017/05/07*/
int GreatestCommonDivisor(int x, int y)
{
	if (y == 0) return x;
	else return GreatestCommonDivisor(y, x%y);
}

int flag = 1;
/*����[a,b]�ڵ�������� ���ڣ�2017/05/07*/
int RandomNumber(int down, int up)
{
	if (flag == 1)
	{
		flag = 0;
		srand((unsigned)time(NULL));//��������
	}
	return RANDOM(down, up);
}

bool MatchLanguage(char language[])
{
	stringstream sstmp;
	string stmp;
	sstmp << language;
	sstmp >> stmp;//ת��Ϊstring
	sstmp.clear();
	CString languageName;
	languageName = stmp.c_str();//ת��ΪCString
	CString languageList;
	g_idValue = 0;
	languageList.LoadString(++g_idValue);
	int ntmp = 0;
	while (languageList != "End")
	{
		if (languageList == languageName)
		{
			ntmp = 1;
			g_idValue *= 1000;//��ת����Ӧ������Դ
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

int ReadFile(char *filename)//filename�Ǿ���·��
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