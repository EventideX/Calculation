/*************************************************************
�ļ�����verify.cpp
���ߣ��Ǽ��� ���ڣ�2016/02/16
����: ����������� 
��Ҫ���ܰ��������ء�����𰸡������ 
*************************************************************/

#include"head.h"

int correct=0,wrong=0;
bool ifOnly(string str,vector<string> se) //�жϱ��ʽ�Ƿ��ظ� 
{
	int count=0;
	for (int i=0;i<se.size();i++)
	{
		if (str!=se[i]) count++;
		else break;
	}
	    if (count==se.size()) return true;
		else return false;
}
void checkAndOutput(string equ,int n,int opt,string result) //����𰸲������ȷ�� 
{
	string ans;
	cout<<"("<<n<<") "<<equ<<"=";
	cin>>ans;
	if (ans==result)
	{
		if(opt==2)cout<<"Correct Answer!"<<endl;
		else cout<<"��ȷ"<<endl;
		correct++;
	}
	else
	{
		if(opt==2)cout<<"Wrong Answer! The correct answer is "<<result<<endl;
		else cout<<"������ȷ��Ϊ��"<<result<<endl;
		wrong++;
	}
}
void finalOut(int opt) //���������� 
{
	cout<<"********************************************************************"<<endl;
	cout<<"                                                                    "<<endl;
	if(opt==2) cout<<"  "<<correct<<" answers are correct, "<<wrong<<" answers are wrong.";
	else cout<<"������"<<correct<<"���⣬������"<<wrong<<"����";	
}
