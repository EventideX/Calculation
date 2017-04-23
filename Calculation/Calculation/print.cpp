/*************************************************************
文件名：print.cpp
作者：盖嘉轩 许郁杨 日期：2017/04/20
描述: 检验和输出结果
主要功能包括：判重、检验答案、输出答案
*************************************************************/

#include"head.h"
extern UINT idValue;

int correct = 0, wrong = 0;
void checkAndPrint(string equ, int n, string result) //检验答案并输出正确答案 
{
	string ans;
	CString str;
	cout << "(" << n << ") " << equ << "=";
	wcout.imbue(locale("CHS"));
	cin >> ans;
	if (ans == "e")
	{
		print();
		exit(0);
	}
	if (ans == result)
	{
		str.LoadString(idValue - 1);
		wcout << (LPCTSTR)str << endl;
		correct++;
	}
	else
	{
		str.LoadString(idValue);
		wcout << (LPCTSTR)str;
		cout << result << endl;
		wrong++;
	}
	cout << endl;
}
void print() //输出正误个数 
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