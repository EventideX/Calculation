#include"head.h"
//#include"fraction.h"
int main()
{
	int opt;
	int i,j,k,num,low,high;
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
	
	cout<<"�Ƿ�����˳�(y/n):";
	cin>>flag1;
	//if (tmp=="y") flag1=1;
	//else flag1=0;
	
	cout<<"�Ƿ��������(y/n)(������Լٷ�������ʽ���,����13\\5):";
	cin>>flag2;
	
	cout<<"�Ƿ���������(y/n):";
	cin>>flag3;
	
	cout<<"********************************************************************"<<endl;
	cout<<"                                                                    "<<endl;
  }
    if(opt==2)
  {
  	cout<<"Please enter a number as the amount of the calculation questions: ";
  	cin>>num;
  	
  	cout<<"Please enter the size range of the numbers'absolute value in the equation.(e.g 1 100): ";
  	cin>>low>>high;
  	
  	cout<<"Would you permit the  multiplication and division as a part of the equation?(y/n): ";
  	cin>>flag1;
  	
  	cout<<"Would you permit the fraction as a part of the equation?(y/n): ";
  	cin>>flag2;
  	
  	cout<<"Would you permit the parenthesis--() as a part of the equation?(y/n): ";
  	cin>>flag3;
  	
  	cout<<"********************************************************************"<<endl;
  	cout<<"                                                                    "<<endl;
  }
	getAndCalculate(opt,num,low,high,flag1,flag2,flag3);
	return 0;
}
