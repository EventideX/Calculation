﻿/*************************************************************
文件名：generate.cpp
作者：盖嘉轩 日期：2016/02/16
描述: 生成表达式 
主要功能包括：生成随机数、生成表达式 
*************************************************************/

#include"head.h"

int flag=1,k=0;
int getRand(int down,int up)//生成随机数 
{
	if (flag==1)
	{
		flag=0;
		srand((unsigned)time(NULL));//种子 
    }
    return random(down,up);
}
vector<string> equation;
void getAndCalculate(int opt,int num,int low,int high,int flag0,char flag1,char flag2,char flag3)
{
	int i=1,tmp;
	char sign;
	while (i<=num)
	{
		int flag4=1,number=flag0;
		string paras1,paras2,equ;
		for (int j=0;j<number-1;j++)
		{
			if (flag1=='y') //允许乘除 
			{
				tmp=getRand(1,4);
				switch (tmp)
				{
					case 1:sign='+';
					       break;
					case 2:sign='-';
					       break;
					case 3:sign='*';
					       break;
					case 4:sign='/';
					       break;
				}
			}
			else
			{
				tmp=getRand(1,2);
				switch (tmp)
				{
					case 1:sign='+';
					       break;
					case 2:sign='-';
					       break;
				}
			}
			if (flag2=='y') //允许分数 
			{
				tmp=getRand(1,3);
				switch (tmp)
				{
					case 1: //整数和整数 
					{
    				    stringstream tmps1,tmps2;
     	    			tmps1<<getRand(low,high);
	        			tmps1>>paras1;
		        		tmps2<<getRand(low,high);
			        	tmps2>>paras2;
		  				break;
				    }
					case 2: //整数和真分数 
					{
						stringstream tmps;
						tmps<<getRand(low,high);
						tmps>>paras1;
						Fraction frac2=frac2.simplify(frac2.getFrac(low,high));
						paras2=frac2.transString(frac2);
						break;
					}
					case 3: //分数和分数 
					{
						Fraction frac1=frac1.simplify(frac1.getFrac(low,high));
						Fraction frac2=frac2.simplify(frac2.getFrac(low,high));
						paras1=frac1.transString(frac1);
						paras2=frac2.transString(frac2);
						break;
					}
				}
			}
			else
			{
				stringstream tmps3,tmps4;
				tmps3<<getRand(low,high);
				tmps3>>paras1;
				tmps4<<getRand(low,high);
				tmps4>>paras2;
			}
			if (flag3=='y') //允许括号
			{
				tmp=getRand(1,4);
				switch (tmp)
				{
					case 1: //无括号 
					{
						if (flag4==1)
						{
							equ=paras1+sign+paras2;
							flag4=0;
						}
						else equ=equ+sign+paras1;
					    break;
					}
					case 2:
					{
						if (flag4==1)
						{
							equ=paras2+sign+paras1;
							flag4=0;
						}
						else equ=paras1+sign+equ;
					    break;
					}
					case 3: //有括号 
					{
						if (flag4==1)
						{
							equ="["+paras1+sign+paras2+"]";
							flag4=0;
						}
						else equ="["+equ+sign+paras1+"]";
					    break;
					}
					case 4:
					{
						if (flag4==1)
						{
							equ="["+paras2+sign+paras1+"]";
							flag4=0;
						}
						else equ="["+equ+sign+paras1+"]";
						break;
					}
				}
			}
			else
			{
				tmp=getRand(1,2);
				switch (tmp)
				{
					case 1:
					{
						if (flag4==1)
						{
							equ=paras1+sign+paras2;
							flag4=0;
						}
						else equ=equ+sign+paras1;
					    break;
					}
					case 2:
					{
						if (flag4==1)
						{
							equ=paras2+sign+paras1;
							flag4=0;
						}
						else equ=paras1+sign+equ;
					}
				}
			}
		}
		string result=countEquation(equ);
		if ((ifOnly(equ,equation))&&(result!="non_comformance")) //判断表达式是否重复以及是否除零 
		{
			equation.push_back(equ);
            checkAndOutput(equ,i,opt,result);
			i++;
		}
	}
    finalOut(opt);
}
