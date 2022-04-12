#include "SqString.h"

int main()
{
	char a[30], b[30], c[30], d[30];

	//创建串
	SqString s1, s2, s3, s4, s5;

	//赋值
	cout << "请分别输入四个串" << endl;

	cin >> a >> b >> c >> d;
	
	StrAssign(s1, a), StrAssign(s2, b), StrAssign(s3, c), StrAssign(s4, d);

	//输出四个串
	cout << "s1: ", DispStr(s1);
	cout << "s2: ", DispStr(s2);
	cout << "s3: ", DispStr(s3);
	cout << "s4: ", DispStr(s4);

	//串的复制
	StrCopy(s5, s1);
	cout << "将s1复制到s5" << endl;
	cout << "s5: ", DispStr(s5);

	//串的连接
	SqString s12 = Concat(s1, s2);
	cout << "将s1与s2连接" << endl;
	cout << "s12: ", DispStr(s12);

	//求子串
	SqString s1son = SubStr(s1, 2, 5);
	cout << "s1从第二个字符开始连续5个字符组成的子串为: ", DispStr(s1son);

	//子串的删除
	SqString s2son = DelStr(s2, 2, 3);
	cout << "删除s2从第二个字符开始连续3个字符后的串为: ", DispStr(s2son);

	//子串的替换
	SqString s34 = RepStr(s3, 3, 4, s4);
	cout << "s3从第三个字符开始连续4个字符被s4替换后: ", DispStr(s34);

	return 0;
}