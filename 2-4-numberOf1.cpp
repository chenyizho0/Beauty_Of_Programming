/*************************************************************************
    > File Name: 2-4-numberOf1.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月09日 星期日 02时26分25秒
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int arr[10];
int K[10];
int D[10];
int len;
int count1(int k)
{
	int ans = 0;
	for(int i = 0;i <= k;i++)
	{
		if(arr[i] == 1)ans++;
	}
	return ans;
}
int percount(int k)
{
	int ans = 0;
	ans = ans + arr[k]*K[len-k-1];
	if(arr[k] > 1)
	{
		ans = ans + D[len-k-1];
	}
	if(k!=len-1)ans = ans + count1(k-1)*(arr[k])*D[len-k-1];
	else ans = ans + count1(k-1)*(arr[k]+1)*D[len-k-1];
	return ans;
}
int count(int n)
{
	int ans = 0;
	len = 0;
	while(n)
	{
		arr[len++] = n%10;
		n = n/10;
	}
	int tmparr[10];
	for(int i = 0;i < len;i++)
	{
		tmparr[i] = arr[i];
	}
	for(int i = 0;i < len;i++)
	{
		arr[i] = tmparr[len-1-i];
	}
	for(int i = 0;i < len;i++)
	{
		ans = ans + percount(i);
	}
	if(arr[len-1] == 1)ans++;
	return ans;
}

int main()
{
	int tmp = 1;
	for(int i = 0;i < 10;i++)
	{
		D[i] = tmp;
		tmp = tmp*10;
		cout << i << " " << D[i] << endl;
	}
	cout << endl;
	K[0] = 0;
	K[1] = 1;
	for(int i = 2;i < 10;i++)
	{
		K[i] = (9*i+1)*D[i-2];
	}
	for(int i = 1;i < 10;i++)
	{
		K[i] = K[i] + K[i-1];
	}
	fstream inout;
	inout.open("test2.txt");
	for(int n = 1;n <= 99999;n++)
	inout << n << " " <<  count(n) << endl;
}
