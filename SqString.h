#pragma once
#include <iostream>
using namespace std;

const int MaxSize = 30;

typedef struct
{
	char data[MaxSize];									//��Ŵ��ַ�
	int length;											//��Ŵ���
} SqString;												//˳������

void StrAssign(SqString& s, char cstr[]);				//���ɴ�
void DestroyStr(SqString& s);							//���ٴ�
void StrCopy(SqString& s, SqString t);					//���ĸ���
bool StrEqual(SqString s, SqString t);					//�жϴ����
int StrLength(SqString s);								//�󴮳�
SqString Concat(SqString s, SqString t);				//��������
SqString SubStr(SqString s, int i, int j);				//���Ӵ�,i��ʼ��������j���ַ���ɵĴ�
SqString InsStr(SqString s1, int i, SqString s2);		//�Ӵ��Ĳ���
SqString DelStr(SqString s, int i, int j);				//�Ӵ���ɾ��,ɾ����i��Ԫ�ؿ�ʼ����j���ַ�
SqString RepStr(SqString s, int i, int j, SqString t);	//�Ӵ����滻
void DispStr(SqString s);								//�����

void StrAssign(SqString& s, char cstr[])				//���ɴ�,sΪ�����Ͳ���
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;										//���ô��ĳ���
}

void DestroyStr(SqString& s)							//���ٴ�
{}

void StrCopy(SqString& s, SqString t)					//���ĸ���
{
	for (int i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}

bool StrEqual(SqString s, SqString t)					//�жϴ����
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

int StrLength(SqString s)								//�󴮳�
{
	return s.length;
}

SqString Concat(SqString s, SqString t)					//��������
{
	SqString str;									//��������
	for (int i = 0; i < s.length; i++)
		str.data[i] = s.data[i];					//��s���Ƶ�str
	for (int i = 0; i < t.length; i++)
		str.data[s.length + i] = t.data[i];			//��t���Ƶ�str
	str.length = s.length + t.length;

	return str;
}

SqString SubStr(SqString s, int i, int j)				//���Ӵ�,i��ʼ������j���ַ���ɵĴ�
{
	SqString str;									//�����Ӵ�
	str.length = 0;									//����Ϊ�մ�
	if (i > s.length || i + j - 1 > s.length || i <= 0 || j <= 0)	//��������ȷ
		return s;
	for (int k = i - 1; k < i - 1 + j; k++)						//���Ӵ�
		str.data[k - i + 1] = s.data[k];
	str.length = j;

	return str;
}

SqString InsStr(SqString s1, int i, SqString s2)		//�Ӵ��Ĳ���
{
	SqString str;									//��������
	str.length = 0;									//����Ϊ�մ�
	if (i <= 0 || i > s1.length + 1)				//��������ȷ
		return str;
	for (int k = 0; k < i - 1; k++)					//��s1��ǰi-1���ַ����Ƶ�str
		str.data[k] = s1.data[k];
	for (int k = 0; k < s2.length; k++)				//��s2���Ƶ�str
		str.data[i + k - 1] = s2.data[k];
	for (int k = i - 1; k < s1.length; k++)				//��s1ʣ�ಿ�ָ��Ƶ�str
		str.data[k + s2.length] = s1.data[k];
	str.length = s1.length + s2.length;

	return str;
}

SqString DelStr(SqString s, int i, int j)				//�Ӵ���ɾ��,ɾ����i��Ԫ�ؿ�ʼ������j���ַ�
{
	SqString str;								//��������
	str.length = 0;								//����Ϊ�մ�
	if (i <= 0 || j <= 0 || i + j - 1 > s.length || i > s.length)	//��������ȷ
		return str;
	for (int k = 0; k < i - 1; k++)				//��sǰi-1���ַ����Ƶ�str
		str.data[k] = s.data[i];
	for (int k = i + j - 1; k < s.length; k++)	//��ɾ����ĺ��沿�ָ��Ƶ�str
		str.data[k - j] = s.data[k];
	str.length = s.length - j;

	return str;
}

SqString RepStr(SqString s, int i, int j, SqString t)	//�Ӵ����滻
{
	SqString str;								//��������
	str.length = 0;								//����Ϊ�մ�
	if (i <= 0 || i + j - 1 > s.length || j <= 0 || i > s.length)	//��������ȷ
		return str;
	for (int k = 0; k < i - 1; k++)				//��sǰi-1���ַ����Ƶ�str
		str.data[k] = s.data[k];
	for (int k = 0; k < t.length; k++)			//��t���ַ����Ƶ�str
		str.data[k + i - 1] = t.data[k];
	for (int k = i + j - 1; k < s.length; k++)
		str.data[k - j + t.length] = s.data[k];

	str.length = s.length - j + t.length;

	return str;
}

void DispStr(SqString s)								//�����
{
	if (s.length > 0)
	{
		for (int i = 0; i < s.length; i++)
			cout << s.data[i];
		cout << endl;
	}
}