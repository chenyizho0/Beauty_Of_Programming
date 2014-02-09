/*************************************************************************
    > File Name: 2-10-maxmin2.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月10日 星期一 03时15分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[100];

int main()
{
	int n;
	cout << "please input number " ;
	cin >> n;
	cout << "please input the elements " << endl;
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	int max = -100000,min = 100000;
	for(int i = 1;i < n;i=i+2)
	{
		if(arr[i-1] < arr[i])
		{
			if(max < arr[i])max = arr[i];
			if(min > arr[i-1])min = arr[i-1];
		}
		else
		{
			if(max < arr[i-1])max = arr[i-1];
			if(min > arr[i])min = arr[i];
		}
	}
	if(n%2 == 1)
	{
		if(max < arr[n-1])max = arr[n-1];
		if(min > arr[n-1])min = arr[n-1];
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
	return 0;

}

