/*************************************************************************
    > File Name: 2-7-floatToFraction.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2013年11月20日 星期三 20时00分31秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int gcd(int a,int b)
{
	if( a < b)
		return gcd(b,a);
	if(b == 0)
		return a;
	if( a & 1 == 0)
	{
		if(b & 1 == 0)
			return gcd(a >> 1, b >> 1) << 1;
		else
			return gcd(a >> 1,b);
	}
	else
	{
		if(b & 1 == 0)
			return gcd(a,b>>1);
		else
			return gcd(b,a-b);
	}
}

void FloatToFraction(string s)
{
	int IntNum = 0;//整数部分
	int A = 0; //小数点后不循环部分
	int B = 0;//小数点后循环部分
	int kind = 0;
	int n = 1;
	int m = 1;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '.')
		{
			kind = 1;
			continue;
		}
		if(s[i] == '(')
		{
			kind = 2;
			continue;
		}
		if(s[i] == ')')
			break;
		if(kind == 0)
		{
			IntNum = IntNum * 10 + s[i] - '0';
		}
		if(kind == 1)
		{
			A = A * 10 + s[i] - '0';
			n=n*10;
		}
		if(kind == 2)
		{
			B = B * 10 + s[i] - '0';
			m=m*10;
		}
	}
	int numerator = A*(m-1)+B;//分子
	int denominator = n*(m-1);//分母
	int g = gcd(numerator,denominator);
	numerator = numerator / g;
	denominator = denominator / g;
	numerator = numerator + denominator*IntNum;
	cout << numerator << "/" << denominator << endl;
}

int main()
{
	string s;
	while(cin >> s)
	{
		FloatToFraction(s);
	}
}
