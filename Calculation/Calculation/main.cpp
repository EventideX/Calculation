/*************************************************************
文件名：main.cpp
作者：许郁杨 日期：2017/05/07
描述: 主函数

作者：许郁杨 日期：2017/05/09
更新：命令行输入输出

作者：许郁杨 日期：2017/05/10
更新：在文件中输出题目数量和用户答案，并补充了注释，对一些格式细节进行了调整
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
UINT g_idValue;//语言资源的字符串标识

int main(int argc, char *argv[])
{
	wcout.imbue(locale("CHS"));//设置区域
	cout << "Which language you would like to choose?\n";
	
	int i = 1;//语言序号
	g_idValue = 0;
	CString languageList;//可选语言
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
		char Language[kMax];//用户所选语言
		fgets(Language, kMax, stdin);
		isSupportLanguage = MatchLanguage(Language);
		if (!isSupportLanguage)//用户输入语言不受支持
		{
			cout << "Sorry, please choose other language：";
		}
	}

	int problemNumber;//题目个数
	problemNumber = ReadFile(argv[1]);

	CString sentence;//资源语句
	sentence.LoadString(g_idValue);
	wfstream wostream;
	wostream.imbue(locale("CHS"));
	wostream.open(argv[2], ios::out);
	wostream << (LPCTSTR)sentence << problemNumber << endl << endl << "********************************************************************" << endl << endl;
	wostream.close();

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
	wcout << (LPCTSTR)sentence << endl << endl;//输入'e'可退出程序

	g_idValue += 2;
	
	int correct = 0, wrong = 0;//答案正确、错误个数
	for (i = 1; i <= problemNumber; i++)
	{
		Expression expression;//生成的表达式
		string answer;//用户输入的答案
	    string result;//表达式的得数，正确答案
		string equation;//存储生成的等式

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

		if (answer == "e")//如果需要中途退出程序
		{
			PrintFinalResult(argv[2], correct, wrong);
			exit(0);
		}

		WriteFile(argv[2], g_idValue + 3);

		ostream.open(argv[2], ios::app);
		ostream << answer << endl;
		ostream.close();

		result = expression.CalculateResult();
		if (answer == result)//如果用户输入的答案正确
		{
			WriteFile(argv[2], g_idValue - 1);

			correct++;
		}
		else//如果用户输入的答案错误
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
	PrintFinalResult(argv[2], correct, wrong);//输出最终结果到文件
	return 0;
}