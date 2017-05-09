/*************************************************************
�ļ�����main.cpp
���ߣ������� ���ڣ�2017/05/07
����: ������
*************************************************************/
#include"expression.h"
#include"assistant_functions.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cassert>
#include<atlstr.h>
#include<fstream>
using namespace std;
UINT g_idValue;

int main(int argc, char *argv[])
{
	wcout.imbue(locale("CHS"));//��������
	cout << "Which language you would like to choose?\n";
	
	int i = 1;
	g_idValue = 0;
	CString languageList;
	languageList.LoadString(++g_idValue);//���������б�
	while (languageList != "End")//�����ѡ�����б�
	{
		cout << i << '.';
		wcout << (LPCTSTR)languageList << endl;
		i++;
		languageList.LoadString(++g_idValue);
	}
	cout << "Please input the name of the language��";

	bool isSupportLanguage = false;//�ж��û�����������Ƿ�֧��
	g_idValue = 0;
	while (!isSupportLanguage)
	{
		char Language[kMax];
		fgets(Language, kMax, stdin);//�����û���ѡ����
		isSupportLanguage = MatchLanguage(Language);
		if (!isSupportLanguage)
		{
			cout << "Sorry, please choose other language��";
		}
	}

	int problemNumber;
	problemNumber = ReadFile(argv[1]);//��Ŀ����

	CString sentence;
	int low, high;//��������ֵ��Χ
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> low >> high;

	int parameterNumber;//���ʽ��������
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> parameterNumber;

	char ifMultiplyDivide;//�Ƿ�����˳�(Y/N)
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> ifMultiplyDivide;

	char ifFraction;//�Ƿ��������(Y/N)
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> ifFraction;

	char ifBracket;//�Ƿ���������(Y/N)
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> ifBracket;

	cout << endl << "********************************************************************" << endl;
	cout << endl;

	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence << endl << endl;

	g_idValue += 2;
	
	int correct = 0, wrong = 0;
	for (i = 1; i <= problemNumber; i++)
	{
		Expression expression;
		string answer, result;
		string equation;

		equation = expression.GenerateInfixExpression(low, high, parameterNumber, ifMultiplyDivide, ifFraction, ifBracket);
		cout << "(" << i << ") " << equation << "=";
		cin >> answer;
		cout << endl;

		fstream ostream;
		wfstream wostream;

		wostream.imbue(locale("CHS"));

		ostream.open(argv[2], ios::app);
		ostream << "(" << i << ") " << equation << endl;
		ostream.close();

		if (answer == "e")
		{
			PrintFinalResult(argv[2], correct, wrong);
			exit(0);
		}
		result = expression.CalculateResult();
		if (answer == result)
		{
			sentence.LoadString(g_idValue - 1);

			wostream.open(argv[2], ios::app);
			wostream << (LPCTSTR)sentence << endl;
			wostream.close();

			correct++;
		}
		else
		{
			sentence.LoadString(g_idValue);

			wostream.open(argv[2], ios::app);
			wostream << (LPCTSTR)sentence;
			wostream.close();

			ostream.open(argv[2], ios::app);
			ostream << result << endl;
			ostream.close();

			wrong++;
		}
		ostream.open(argv[2], ios::app);
		ostream << endl;
		ostream.close();
	}
	PrintFinalResult(argv[2], correct, wrong);
	return 0;
}