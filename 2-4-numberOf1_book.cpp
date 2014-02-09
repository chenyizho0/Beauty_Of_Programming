/*************************************************************************
    > File Name: 2-4-numberOf1_book.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月09日 星期日 23时47分28秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

long long count(long long n)
{
	long long high,low;
	high = n/10;
	low = 0;
	long long ans = 0;
	long long tmp = 1;
	while(n)
	{
		//cout << "n%10 " << n%10 << "high " << high << "low " << low << "tmp " << tmp << endl;
		switch(n%10)
		{
			case 0:
				ans += high*tmp;
				break;
			case 1:
				ans += high*tmp + (low+1);
				break;
			default:
				ans += (high+1)*tmp;
				break;
		}
		high /= 10;
		low += tmp*(n%10);
		tmp *= 10;
		n /= 10;
	}
	return ans;
}

int main()
{
	fstream inout;
	inout.open("test2.txt");
	for(int i = 0;i <= 99999;i++)
	inout << count(i) << endl;
	inout.close();
	cout << count(999999999999) << endl;
	for(long long i = 1;i <= 999999999999;i++)
	{
		if(count(i) == i)
		{
			cout << i << endl;
		}
	}
	return 0;
}
