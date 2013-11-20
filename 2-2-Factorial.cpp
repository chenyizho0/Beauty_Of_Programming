/*************************************************************************
    > File Name: 2-2-Factorial.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2013年11月20日 星期三 23时22分07秒
 ************************************************************************/

#include<iostream>
using namespace std;

int count(int N)
{
	int ans = 0;
	while(N)
	{
		ans = ans + N/5;
		N = N/5;
	}
	return ans;
}

int count1(int N)
{
	int ans = 0;
	while(N)
	{
		N = N >> 1;
		ans = ans + N;
	}
	return ans+1;
}

int count2(int N)
{
	int ans = 0;
	int tmpN = N;
	while(N)
	{
		N = N & (N-1);
		ans++;
	}
	ans = tmpN - ans;
	return ans+1;
}

int main()
{
	int N;
	while(cin >> N)
	{
		int ans = 1;
		for(int i = 1;i <= N;i++)
			ans = (ans * i);
		int tmp = ans;
		while(tmp)
		{
			cout <<( tmp & 1) << " ";
			tmp = tmp >> 1;
		}
		cout << endl;
		cout << ans << endl;
		cout << count(N) << endl;
		cout << count1(N) << endl;
		cout << count2(N) << endl;
	}
	return 0;
}
