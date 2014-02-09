/*************************************************************************
    > File Name: 2-4-test.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月09日 星期日 05时07分28秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int count(int n)
{
	int ans = 0;
	while(n)
	{
		if(n%10==1)ans++;
		n = n/10;
	}
	return ans;
}

int main()
{
	fstream inout;
	inout.open("test1.txt");
		int ans = 0;
		for(int i = 1;i <= 99999;i++)
		{
			ans = ans + count(i);
			inout << i << "  " << ans << endl;
		}
	inout.close();
}
