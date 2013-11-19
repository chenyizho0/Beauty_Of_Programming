/*************************************************************************
    > File Name: bop.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2013年11月19日 星期二 17时13分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int x, int y)
{
	if(x < y)
		return gcd(y,x);
	if(y == 0)
		return x;
	if(x & 1 == 0)
	{
		if(y & 1 == 0)
			return gcd(x >> 1, y >> 1) << 1;
		else
			return gcd(x >> 1,y);
	}
	else
	{
		if(y & 1 == 0)
			return gcd(x,y >> 1);
		else
			return gcd(y,x-y);

	}

}

int gcd1(int x,int y)
{
	int ans = 1;
	while(1)
	{
		if(x < y)
		{
			int tmp = x;
			x = y;
			y = tmp;
		}
		if(y == 0)break;
		if(x & 2 == 0)
		{
			if(y & 2 == 0)
			{
				x >> 1;
				y >> 1;
				ans << 1;
			}
			else
			{
				x >> 1;
			}
		}
		else
		{
			if(y & 1 == 0)
				y >> 1;
			else
				x = x - y;
		}
	}
	return ans * x;
}

int gcd2(int x, int y)
{
	if(x < y)
		return gcd2(y,x);
	if(y == 0)
		return x;
	return gcd2(y,x-y);
}

int main()
{
	int a,b;
	while(1)
	{
		cin >> a >> b;
		if(a == 0 && b == 0)
			break;
		//cout << gcd(a,b) << endl; //递归实现
		//cout << gcd1(a,b) << endl;   //迭代实现
		cout << gcd2(a,b) << endl;   //相减
	}
	return 0;
}
