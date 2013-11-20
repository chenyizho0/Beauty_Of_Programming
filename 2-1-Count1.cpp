/*************************************************************************
    > File Name: 2-1-Count1.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2013年11月20日 星期三 21时02分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int Count1(int v) //log v 算法
{
	int num = 0;
	while(v)
	{
		num = num + (v & 1);
		v = v >> 1;
	}
	return num;
}

int Count2(int v) //复杂度为 1 的位数
{
	int num = 0;
	while(v)
	{
		v = v & (v-1);
		num++;
	}
	return num;
}

int main()
{
	int n;
	while(cin >> n)
	{
		cout << Count1(n) << endl;
		cout << Count2(n) << endl;
	}
	return 0;
}
