/*************************************************************
�ļ�����main.cpp
���ߣ��Ǽ��� ���ڣ�2016/02/16
����: ��ʼ���� 
��Ҫ���ܰ����������л�������ѡ�� ����
*************************************************************/

#include"head.h"

int main()
{
	int i,j,k,num,low,high,opt,flag0;
	char flag1,flag2,flag3,tmp;
	
	cout<<"����Ҫѡ����������/Which language you would like to choose?\n";
	cout<<"���� 1 �л����� ������ 2 �л�Ӣ��./input 1 for Chinese ; input 2 for English: ";
	cin>>opt;
	 
	if(opt==1)
	{
		cout<<"��������Ŀ��(1~1000)��";
		cin>>num;
		
		cout<<"��������ʽ�е����ִ�С�ľ���ֵ��Χ(�磺1 100)��";
		cin>>low>>high;
		
		cout<<"��������ʽ��������������ָ���(2~10)��"; 
		cin>>flag0;
		
		cout<<"�Ƿ�����˳�(y/n):";
		cin>>flag1;
		
		cout<<"�Ƿ��������(y/n)(������Դ����ŵļٷ�������ʽ���,���� (13\\5) ):";
		cin>>flag2;
		
		cout<<"�Ƿ���������(y/n):";
		cin>>flag3;
		
		cout<<"********************************************************************"<<endl;
		cout<<"                                                                    "<<endl;
	}
    if(opt==2)
	{
		cout<<"Please input a number as the amount of the calculation questions: ";
		cin>>num;
		
		cout<<"Please input the size range of the numbers'absolute value in the equation.(e.g 1 100): ";
		cin>>low>>high;
		
		cout<<"Please input the number of the figures that are included in the equation(2~10): ";
		cin>>flag0;
		
		cout<<"Would you permit the  multiplication and division as a part of the equation?(y/n): ";
		cin>>flag1;
		
		cout<<"Would you permit the fraction as a part of the equation?(y/n): ";
		cin>>flag2;
		
		cout<<"Would you permit the parenthesis--() as a part of the equation?(y/n): ";
		cin>>flag3;
		
		cout<<"********************************************************************"<<endl;
		cout<<"                                                                    "<<endl;
	}
	getAndCalculate(opt,num,low,high,flag0,flag1,flag2,flag3);
	return 0;
}
