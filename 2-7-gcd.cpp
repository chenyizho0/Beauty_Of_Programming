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


int main()
{
	int a,b;
	while(1)
	{
		cin >> a >> b;
		if(a == 0 && b == 0)
			break;
		cout << gcd(a,b) << endl;
	}
	return 0;
}
