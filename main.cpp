#include "SqString.h"

int main()
{
	char a[30], b[30], c[30], d[30];

	//������
	SqString s1, s2, s3, s4, s5;

	//��ֵ
	cout << "��ֱ������ĸ���" << endl;

	cin >> a >> b >> c >> d;
	
	StrAssign(s1, a), StrAssign(s2, b), StrAssign(s3, c), StrAssign(s4, d);

	//����ĸ���
	cout << "s1: ", DispStr(s1);
	cout << "s2: ", DispStr(s2);
	cout << "s3: ", DispStr(s3);
	cout << "s4: ", DispStr(s4);

	//���ĸ���
	StrCopy(s5, s1);
	cout << "��s1���Ƶ�s5" << endl;
	cout << "s5: ", DispStr(s5);

	//��������
	SqString s12 = Concat(s1, s2);
	cout << "��s1��s2����" << endl;
	cout << "s12: ", DispStr(s12);

	//���Ӵ�
	SqString s1son = SubStr(s1, 2, 5);
	cout << "s1�ӵڶ����ַ���ʼ����5���ַ���ɵ��Ӵ�Ϊ: ", DispStr(s1son);

	//�Ӵ���ɾ��
	SqString s2son = DelStr(s2, 2, 3);
	cout << "ɾ��s2�ӵڶ����ַ���ʼ����3���ַ���Ĵ�Ϊ: ", DispStr(s2son);

	//�Ӵ����滻
	SqString s34 = RepStr(s3, 3, 4, s4);
	cout << "s3�ӵ������ַ���ʼ����4���ַ���s4�滻��: ", DispStr(s34);

	return 0;
}