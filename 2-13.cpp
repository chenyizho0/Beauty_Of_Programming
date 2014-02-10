/*************************************************************************
    > File Name: 2-13.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月11日 星期二 01时08分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[100];

int countRes(int a,int b)
{
	if(a==0||b==0)return 0;
	if(a<0&&b<0)return 1;
	if(a<0&&b>0)return -1;
	if(a>0&&b<0)return -1;
	if(a>0&&b>0)return 1;
}

int main()
{
	int n;
	cout << "please input element number ";
	cin >> n;
	cout << "please input elements " << endl;
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	int res = 1;
	int minPos,minNeg;
	minPos = 1000000;
	minNeg = -1000000;
	int numberOfZero = 0;
	int numberOfNeg = 0;
	for(int i = 0;i < n;i++)
	{
		res = countRes(res,arr[i]);
		if(arr[i] < 0 && arr[i]>minNeg)
		{
			minNeg = arr[i];
		}
		if(arr[i] > 0 && arr[i] < minPos)
		{
			minPos = arr[i];
		}
		if(arr[i] == 0)
		{
			numberOfZero++;
		}
		if(arr[i] < 0)
		{
			numberOfNeg++;
		}
	}
	if(res > 0)
	{
		cout << "except number " << minPos << endl;
	}
	else if(res < 0)
	{
		cout << "except number " << minNeg << endl;
	}
	else
	{
		if(numberOfZero > 1)
		{
			cout << "the mutiple result must be 0" << endl;
		}
		else
		{
			if(numberOfNeg%2 == 0)
			{
				cout << "except number " << 0 << endl;
			}
			else
			{
				cout << "the mutiple result must be 0" << endl;
			}
		}
	}
	return 0;

}
