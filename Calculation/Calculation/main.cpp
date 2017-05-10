/*************************************************************
�ļ�����main.cpp
���ߣ������� ���ڣ�2017/05/07
����: ������

���ߣ������� ���ڣ�2017/05/09
���£��������������

���ߣ������� ���ڣ�2017/05/10
���£����ļ��������Ŀ�������û��𰸣���������ע�ͣ���һЩ��ʽϸ�ڽ����˵���
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
UINT g_idValue;//������Դ���ַ�����ʶ

int main(int argc, char *argv[])
{
	wcout.imbue(locale("CHS"));//��������
	cout << "Which language you would like to choose?\n";
	
	int serialNumber = 1;//�������
	g_idValue = 0;
	CString languageList;//��ѡ����
	languageList.LoadString(++g_idValue);//���������б�
	while (languageList != "End")//�����ѡ�����б�
	{
		cout << serialNumber << '.';
		wcout << (LPCTSTR)languageList << endl;
		serialNumber++;
		languageList.LoadString(++g_idValue);
	}
	cout << "Please input the name of the language��";

	bool isSupportLanguage = false;//�ж��û�����������Ƿ�֧��
	g_idValue = 0;
	while (!isSupportLanguage)
	{
		char Language[kMax];//�û���ѡ����
		fgets(Language, kMax, stdin);
		isSupportLanguage = MatchLanguage(Language);
		if (!isSupportLanguage)//�û��������Բ���֧��
		{
			cout << "Sorry, please choose other language��";
		}
	}

	int problemNumber;//��Ŀ����
	problemNumber = ReadFile(argv[1]);

	CString sentence;//��Դ���
	sentence.LoadString(g_idValue);
	wfstream wostream;
	wostream.imbue(locale("CHS"));
	wostream.open(argv[2], ios::out);
	wostream << (LPCTSTR)sentence << problemNumber << endl << endl << "********************************************************************" << endl << endl;
	wostream.close();

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
	wcout << (LPCTSTR)sentence << endl << endl;//����'e'���˳�����

	g_idValue += 2;
	
	int correct = 0, wrong = 0;//����ȷ���������
	for (int i = 1; i <= problemNumber; i++)
	{
		Expression expression;//���ɵı��ʽ
		string answer;//�û�����Ĵ�
	    string result;//���ʽ�ĵ�������ȷ��
		string equation;//�洢���ɵĵ�ʽ

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

		if (answer == "e")//�����Ҫ��;�˳�����
		{
			PrintFinalResult(argv[2], correct, wrong);
			exit(0);
		}

		WriteFile(argv[2], g_idValue + 3);

		ostream.open(argv[2], ios::app);
		ostream << answer << endl;
		ostream.close();

		result = expression.CalculateResult();
		if (answer == result)//����û�����Ĵ���ȷ
		{
			WriteFile(argv[2], g_idValue - 1);

			correct++;
		}
		else//����û�����Ĵ𰸴���
		{
			WriteFile(argv[2], g_idValue);

			ostream.open(argv[2], ios::app);
			ostream << result << endl;
			ostream.close();

			wrong++;
		}
		ostream.open(argv[2], ios::app);
		ostream << endl;
		ostream.close();
	}
	cout << "********************************************************************" << endl;
	PrintFinalResult(argv[2], correct, wrong);//������ս�����ļ�
	return 0;
}