/*************************************************************
文件名：assistant_functions.h
作者：许郁杨 日期：2017/05/07
描述: assistant_functions.cpp对应头文件
*************************************************************/
#pragma once

int Max(int x, int y);
int Min(int x, int y);
int GreatestCommonDivisor(int x, int y);
int RandomNumber(int down, int up);
bool MatchLanguage(char language[]);
int ReadFile(char *filename);
void PrintFinalResult(char *filename, int correct, int wrong);