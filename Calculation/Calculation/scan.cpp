/*************************************************************
文件名：scan.cpp
作者：许郁杨 日期：2017/04/20
描述: 初始界面
主要功能包括：读入初始数据
*************************************************************/

#include"head.h"
UINT idValue;

void scan()
{
	int i, j, k, num, low, high, flag0, tmp;
	char flag1, flag2, flag3;
	CString langName, langList, langStr;
	string Lang;

	wcout.imbue(locale("CHS")); //设置区域
	cout << "Which language you would like to choose?\n";
	i = 1;
	idValue = 0;

	langList.LoadString(++idValue); //载入语言列表
	while (langList != "End") //输出可选语言列表
	{
		cout << i << '.';
		wcout << (LPCTSTR)langList << endl;
		i++;
		langList.LoadString(++idValue);
	}
	cout << "Please input the name of the language：";

	tmp = 0;
	idValue = 0;
	while (tmp == 0)
	{
		char tmpc[MAX];
		fgets(tmpc, MAX, stdin); //读入用户所选语言
		stringstream tmpcs;
		tmpcs << tmpc;
		tmpcs >> Lang; //转换为string
		tmpcs.clear();
		langName = Lang.c_str(); //转换为CString
		langList.LoadString(++idValue);
		while (langList != "End")
		{
			if (langList == langName)
			{
				tmp = 1;
				idValue *= 1000; //跳转至对应语言资源
				break;
			}
			langList.LoadString(++idValue);
		}
		if (tmp == 0)
		{
			idValue = 1;
			cout << "Sorry, please choose other language：";
		}
	}

	langStr.LoadString(idValue);
	wcout << endl << (LPCTSTR)langStr;
	cin >> num; //读入题目个数

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> low >> high; //读入参数绝对值范围

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag0; //读入表达式参数个数

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag1; //是否允许乘除

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag2; //是否允许分数

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag3; //是否允许括号

	idValue++;

	cout << endl << "********************************************************************" << endl;
	cout << "                                                                    " << endl;

	generateExpression(num, low, high, flag0, flag1, flag2, flag3);
}