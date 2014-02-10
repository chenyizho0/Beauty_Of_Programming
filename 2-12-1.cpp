/*************************************************************************
    > File Name: 2-12-1.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月11日 星期二 00时11分52秒
 ************************************************************************/
#include<algorithm>
#include<iostream>
using namespace std;

int arr[100];
int sum;
int n;

bool binary_search(int num,int start,int end)
{
	if(end < start)return false;
	if(arr[(start+end)/2] == num)
	{
		if(sum - num != num)
		{
			cout << sum-num << " " << num << endl;
			return true;
		}
		else
		{
			if((start+end)/2-1>=0&&arr[(start+end)/2-1]==num)
			{
				cout << sum - num << " " << num << endl;
				return true;
			}
			else if((start+end)/2+1<n&&arr[(start+end)/2+1]==num)
			{
				cout << sum - num << " " << num << endl;
				return true;
			}
			else 
				return false;
		}
	}
	else if(arr[(start+end)/2] < num)
	{
		return binary_search(num,(start+end)/2+1,end);
	}
	else
	{
		return binary_search(num,start,(start+end)/2-1);
	}
}

int main()
{
	cout << "please input the element number " ;
	cin >> n;
	cout << "please input the elements" << endl;
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	cout << "please input the sum ";
	cin >> sum;
	for(int i = 0;i < n;i++)
	{
		bool isFound = binary_search(sum-arr[i],0,n-1);
		//if(isFound)break;
	}
}
