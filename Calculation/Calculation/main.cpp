/*************************************************************
�ļ�����main.cpp
���ߣ��Ǽ��� ������ ���ڣ�2017/03/14
����: ��ʼ����
��Ҫ���ܰ����������л�������ѡ��
*************************************************************/

#include"head.h"
UINT idValue;

int main()
{
	int i, j, k, num, low, high, flag0, tmp;
	char flag1, flag2, flag3;
	CString langName, langList, langStr;
	string Lang;

	wcout.imbue(locale("CHS"));
	cout << "Which language you would like to choose?\n";
	i = 1;
	idValue = 0;
	langList.LoadString(++idValue);
	while (langList != "End")
	{
		cout << i << '.';
		wcout << (LPCTCH)langList << endl;
		i++;
		langList.LoadString(++idValue);
	}
	cout << "Please input the name of the language��";
	
	tmp = 0;
	idValue = 0;
	while (tmp == 0)
	{	
		char tmpc[MAX];
		fgets(tmpc, MAX, stdin);
		stringstream tmpcs;
		tmpcs << tmpc;
		tmpcs >> Lang;
		langName = Lang.c_str();
		langList.LoadString(++idValue);
		while (langList != "End")
		{
			if (langList == langName)
			{
				tmp = 1;
				idValue *= 1000;
				break;
			}
			langList.LoadString(++idValue);
		}
		if (tmp == 0)
		{
			idValue = 1;
			cout << "Sorry, please choose other language��";
		}
	}

	langStr.LoadString(idValue);
	wcout << endl << (LPCTSTR)langStr;
	cin >> num;

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> low >> high;

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag0;

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag1;

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag2;

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag3;

	idValue++;

	cout << endl << "********************************************************************" << endl;
	cout << "                                                                    " << endl;

	getAndCalculate(num, low, high, flag0, flag1, flag2, flag3);
	return 0;
}