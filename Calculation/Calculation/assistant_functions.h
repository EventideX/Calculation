/*************************************************************
�ļ�����assistant_functions.h
���ߣ������� ���ڣ�2017/05/07
����: assistant_functions.cpp��Ӧͷ�ļ�
*************************************************************/
#pragma once

int Max(int x, int y);
int Min(int x, int y);
int GreatestCommonDivisor(int x, int y);
int RandomNumber(int down, int up);
bool MatchLanguage(char language[]);
int ReadFile(char *filename);
void PrintFinalResult(char *filename, int correct, int wrong);