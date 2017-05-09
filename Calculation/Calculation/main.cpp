/*************************************************************
文件名：main.cpp
作者：许郁杨 日期：2017/05/07
描述: 主函数
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
UINT g_idValue = 0;

int main(int argc, char *argv[])
{
	wcout.imbue(locale("CHS"));//设置区域
	cout << "Which language you would like to choose?\n";
	
	int i = 1;
	CString languageList;
	languageList.LoadString(++g_idValue);//载入语言列表
	while (languageList != "End")//输出可选语言列表
	{
		cout << i << '.';
		wcout << (LPCTSTR)languageList << endl;
		i++;
		languageList.LoadString(++g_idValue);
	}
	cout << "Please input the name of the language：";

	bool isSupportLanguage = false;//判断用户输入的语言是否支持
	g_idValue = 0;
	while (!isSupportLanguage)
	{
		char Language[kMax];
		fgets(Language, kMax, stdin);//读入用户所选语言
		isSupportLanguage = MatchLanguage(Language);
		if (!isSupportLanguage)
		{
			cout << "Sorry, please choose other language：";
		}
	}

	int problemNumber = ReadFile(argv[1]);//题目个数
	CString sentence;
	//sentence.LoadString(g_idValue);
	//wcout << endl << (LPCTSTR)sentence;
	//cin >> problemNumber;

	int low, high;//参数绝对值范围
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> low >> high;

	int parameterNumber;//表达式参数个数
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> parameterNumber;

	char ifMultiplyDivide;//是否允许乘除(Y/N)
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> ifMultiplyDivide;

	char ifFraction;//是否允许分数(Y/N)
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> ifFraction;

	char ifBracket;//是否允许括号(Y/N)
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
		fstream ostream;
		ostream.open(argv[2], ios::app);
		ostream << "(" << i << ") " << equation << endl;
		if (answer == "e")
		{
			PrintFinalResult(argv[2], correct, wrong);
			exit(0);
		}
		result = expression.CalculateResult();
		if (answer == result)
		{
			sentence.LoadString(g_idValue - 1);
			ostream << (LPCTSTR)sentence << endl;
			correct++;
		}
		else
		{
			sentence.LoadString(g_idValue);
			ostream << (LPCTSTR)sentence;
			ostream << result << endl;
			wrong++;
		}
		cout << endl;
		//ostream << Resource[13] << ": " << answer << endl;
		//ostream << Resource[14] << ": " << result << endl << endl;

		ostream.close();
	}
	PrintFinalResult(argv[2], correct, wrong);
	return 0;
}