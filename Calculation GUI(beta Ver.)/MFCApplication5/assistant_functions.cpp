/*************************************************************
�ļ�����assistant_functions.cpp
���ߣ������� ���ڣ�2017/05/07
����: �������ܺ���
��Ҫ���ܰ������Ƚϴ�С����ֵ���������Լ��

���ߣ������� ���ڣ�2017/05/09
���£����������ж�д���������������ж�ȡ�ļ�Ŀ¼���ж��롢д�����

���ߣ������� ���ڣ�2017/05/10
���£�����WriteFile������ִ�н�������Դ�����д���ļ��Ĺ���
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
#define RANDOM(equation,b) (rand()%(b-equation+1)+equation)//ȡ��[a,b]�ڵ��������
using namespace std;
//extern UINT g_idValue;

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

bool ifGenerateSeed = false;//��ʶ�Ƿ����������������
							/*����[a,b]�ڵ�������� ���ڣ�2017/05/07*/
int RandomNumber(int down, int up)
{
	if (!ifGenerateSeed)//���δ�������������
	{
		ifGenerateSeed = true;
		srand((unsigned)time(NULL));//�������������
	}
	return RANDOM(down, up);
}

/*���û��������Խ���ƥ�䣬�ɹ�Ϊtrue��ʧ��Ϊfalse ���ڣ�2017/05/09*/
/*bool MatchLanguage(char language[])
{
	stringstream sstmp;
	string stmp;
	sstmp << language;
	sstmp >> stmp;//ת��Ϊstring
	sstmp.clear();
	CString languageName;//�û���������
	languageName = stmp.c_str();//ת��ΪCString
	CString languageList;//��ѡ����
	g_idValue = 0;
	languageList.LoadString(++g_idValue);
	int ntmp = 0;
	while (languageList != "End")
	{
		if (languageList == languageName)//����ƥ��ɹ�
		{
			ntmp = 1;
			g_idValue *= 1000;//��ת����Ӧ������Դ
			break;
		}
		languageList.LoadString(++g_idValue);
	}
	if (ntmp == 0)//����ƥ��ʧ��
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*���ļ��ж�����Ŀ���� ���ڣ�2017/05/09*/
/*int ReadFile(char *fileName)
{
	int problemNumber;//��Ŀ����
	fstream istream;
	istream.open(fileName, ios::in);
	istream >> problemNumber;
	istream.close();
	return problemNumber;
}

/*д��������Դ�ڵ���� ���ڣ�2017/05/10*/
/*void WriteFile(char *fileName, int idValue)
{
	wfstream wostream;
	CString sentence;//��Դ���
	sentence.LoadString(idValue);
	wostream.imbue(locale("CHS"));
	wostream.open(fileName, ios::app);
	wostream << (LPCTSTR)sentence;
	wostream.close();
}

/*д�����ս�� ���ڣ�2017/05/09*/
/*void PrintFinalResult(char *fileName, int correct, int wrong)
{
	CString sentence;//��Դ���
	fstream ostream;
	wfstream wostream;

	ostream.open(fileName, ios::app);
	ostream << "********************************************************************" << endl;
	ostream << endl;
	ostream.close();

	WriteFile(fileName, ++g_idValue);

	ostream.open(fileName, ios::app);
	ostream << correct << endl;//д����ȷ��Ŀ��
	ostream.close();

	WriteFile(fileName, ++g_idValue);

	ostream.open(fileName, ios::app);
	ostream << wrong << endl;//д�������Ŀ��
	ostream.close();
}*/