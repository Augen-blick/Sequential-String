#pragma once
#include <iostream>
using namespace std;

const int MaxSize = 30;

typedef struct
{
	char data[MaxSize];									//存放串字符
	int length;											//存放串长
} SqString;												//顺序串类型

void StrAssign(SqString& s, char cstr[]);				//生成串
void DestroyStr(SqString& s);							//销毁串
void StrCopy(SqString& s, SqString t);					//串的复制
bool StrEqual(SqString s, SqString t);					//判断串相等
int StrLength(SqString s);								//求串长
SqString Concat(SqString s, SqString t);				//串的连接
SqString SubStr(SqString s, int i, int j);				//求子串,i开始的连续的j个字符组成的串
SqString InsStr(SqString s1, int i, SqString s2);		//子串的插入
SqString DelStr(SqString s, int i, int j);				//子串的删除,删除第i个元素开始连续j个字符
SqString RepStr(SqString s, int i, int j, SqString t);	//子串的替换
void DispStr(SqString s);								//输出串

void StrAssign(SqString& s, char cstr[])				//生成串,s为引用型参数
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;										//设置串的长度
}

void DestroyStr(SqString& s)							//销毁串
{}

void StrCopy(SqString& s, SqString t)					//串的复制
{
	for (int i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}

bool StrEqual(SqString s, SqString t)					//判断串相等
{
	if (s.length != t.length)
		return false;

	for (int i = 0; i < s.length; i++)
	{
		if (s.data[i] != t.data[i])
			return false;
	}
	return true;
}

int StrLength(SqString s)								//求串长
{
	return s.length;
}

SqString Concat(SqString s, SqString t)					//串的连接
{
	SqString str;									//定义结果串
	for (int i = 0; i < s.length; i++)
		str.data[i] = s.data[i];					//将s复制到str
	for (int i = 0; i < t.length; i++)
		str.data[s.length + i] = t.data[i];			//将t复制到str
	str.length = s.length + t.length;

	return str;
}

SqString SubStr(SqString s, int i, int j)				//求子串,i开始的连续j个字符组成的串
{
	SqString str;									//定义子串
	str.length = 0;									//设置为空串
	if (i > s.length || i + j - 1 > s.length || i <= 0 || j <= 0)	//参数不正确
		return s;
	for (int k = i - 1; k < i - 1 + j; k++)						//求子串
		str.data[k - i + 1] = s.data[k];
	str.length = j;

	return str;
}

SqString InsStr(SqString s1, int i, SqString s2)		//子串的插入
{
	SqString str;									//定义结果串
	str.length = 0;									//设置为空串
	if (i <= 0 || i > s1.length + 1)				//参数不正确
		return str;
	for (int k = 0; k < i - 1; k++)					//将s1的前i-1个字符复制到str
		str.data[k] = s1.data[k];
	for (int k = 0; k < s2.length; k++)				//将s2复制到str
		str.data[i + k - 1] = s2.data[k];
	for (int k = i - 1; k < s1.length; k++)				//将s1剩余部分复制到str
		str.data[k + s2.length] = s1.data[k];
	str.length = s1.length + s2.length;

	return str;
}

SqString DelStr(SqString s, int i, int j)				//子串的删除,删除第i个元素开始的连续j个字符
{
	SqString str;								//定义结果串
	str.length = 0;								//设置为空串
	if (i <= 0 || j <= 0 || i + j - 1 > s.length || i > s.length)	//参数不正确
		return str;
	for (int k = 0; k < i - 1; k++)				//将s前i-1个字符复制到str
		str.data[k] = s.data[k];
	for (int k = i + j - 1; k < s.length; k++)	//将删除后的后面部分复制到str
		str.data[k - j] = s.data[k];
	str.length = s.length - j;

	return str;
}

SqString RepStr(SqString s, int i, int j, SqString t)	//子串的替换
{
	SqString str;								//定义结果串
	str.length = 0;								//设置为空串
	if (i <= 0 || i + j - 1 > s.length || j <= 0 || i > s.length)	//参数不正确
		return str;
	for (int k = 0; k < i - 1; k++)				//将s前i-1个字符复制到str
		str.data[k] = s.data[k];
	for (int k = 0; k < t.length; k++)			//将t的字符复制到str
		str.data[k + i - 1] = t.data[k];
	for (int k = i + j - 1; k < s.length; k++)
		str.data[k - j + t.length] = s.data[k];

	str.length = s.length - j + t.length;

	return str;
}

void DispStr(SqString s)								//输出串
{
	if (s.length > 0)
	{
		for (int i = 0; i < s.length; i++)
			cout << s.data[i];
		cout << endl;
	}
}
