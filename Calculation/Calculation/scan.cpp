/*************************************************************
�ļ�����scan.cpp
���ߣ������� ���ڣ�2017/04/20
����: ��ʼ����
��Ҫ���ܰ����������ʼ����
*************************************************************/

#include"head.h"
UINT idValue;

void scan()
{
	int i, j, k, num, low, high, flag0, tmp;
	char flag1, flag2, flag3;
	CString langName, langList, langStr;
	string Lang;

	wcout.imbue(locale("CHS")); //��������
	cout << "Which language you would like to choose?\n";
	i = 1;
	idValue = 0;

	langList.LoadString(++idValue); //���������б�
	while (langList != "End") //�����ѡ�����б�
	{
		cout << i << '.';
		wcout << (LPCTSTR)langList << endl;
		i++;
		langList.LoadString(++idValue);
	}
	cout << "Please input the name of the language��";

	tmp = 0;
	idValue = 0;
	while (tmp == 0)
	{
		char tmpc[MAX];
		fgets(tmpc, MAX, stdin); //�����û���ѡ����
		stringstream tmpcs;
		tmpcs << tmpc;
		tmpcs >> Lang; //ת��Ϊstring
		tmpcs.clear();
		langName = Lang.c_str(); //ת��ΪCString
		langList.LoadString(++idValue);
		while (langList != "End")
		{
			if (langList == langName)
			{
				tmp = 1;
				idValue *= 1000; //��ת����Ӧ������Դ
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
	cin >> num; //������Ŀ����

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> low >> high; //�����������ֵ��Χ

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag0; //������ʽ��������

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag1; //�Ƿ�����˳�

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag2; //�Ƿ��������

	langStr.LoadString(++idValue);
	wcout << (LPCTSTR)langStr;
	cin >> flag3; //�Ƿ���������

	idValue++;

	cout << endl << "********************************************************************" << endl;
	cout << "                                                                    " << endl;

	generateExpression(num, low, high, flag0, flag1, flag2, flag3);
}