/*************************************************************
�ļ�����print.cpp
���ߣ��Ǽ��� ������ ���ڣ�2017/04/20
����: �����������
��Ҫ���ܰ��������ء�����𰸡������
*************************************************************/

#include"head.h"
extern UINT idValue;

int correct = 0, wrong = 0;
void checkAndPrint(string equ, int n, string result) //����𰸲������ȷ�� 
{
	string ans;
	CString str;
	cout << "(" << n << ") " << equ << "=";
	wcout.imbue(locale("CHS"));
	cin >> ans;
	if (ans == result)
	{
		str.LoadString(idValue);
		wcout << (LPCTSTR)str << endl;
		correct++;
	}
	else
	{
		str.LoadString(idValue + 1);
		wcout << (LPCTSTR)str;
		cout << result << endl;
		wrong++;
	}
	cout << endl;
}
void print() //���������� 
{
	CString str;
	cout << "********************************************************************" << endl;
	cout << endl;
	wcout.imbue(locale("CHS"));
	str.LoadString(++idValue);
	wcout << (LPCTSTR)str;
	cout << correct << endl;
	str.LoadString(++idValue);
	wcout << (LPCTSTR)str;
	cout << wrong << endl;
}