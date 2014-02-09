/*************************************************************************
    > File Name: 2-10-maxmin1.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月10日 星期一 03时04分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[100];

int main()
{
	int n;
	cout << "please input the array number ";
	cin >> n;
	cout << "please input the various " << endl;
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	int tmp;
	for(int i = 1;i < n;i = i+2)
	{
		if(arr[i-1] > arr[i])
		{
			tmp = arr[i-1];
			arr[i-1] = arr[i];
			arr[i] = tmp;
		}
	}
	int max = -100000,min = 100000;
	for(int i = 1;i < n;i = i+2)
	{
		if(arr[i] > max)max = arr[i];
		if(arr[i-1] < min)min = arr[i-1];
	}
	if(n%2 == 1)
	{
		if(arr[n-1] < min)min = arr[n-1];
		if(arr[n-1] > max)max = arr[n-1];
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	return 0;
}
