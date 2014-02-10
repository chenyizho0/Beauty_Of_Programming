/*************************************************************************
    > File Name: 2-12-2.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月11日 星期二 00时33分38秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int arr[100];

int main()
{
	int n;
	cout << "please input element number ";
	cin >> n;
	cout << "please input elements " << endl;
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	int sum;
	cout << "please input sum ";
	cin >> sum;
	int i = 0;
	int j = n-1;
	bool isFound = false;
	for(;;)
	{
		if(i >= j)
		{
			if(!isFound)cout << "not found" << endl;
			break;
		}
		else
		{
			if(arr[i]+arr[j] == sum)
			{
				isFound = true;
				cout << arr[i] << " " << arr[j] << endl;
				i++;
				j++;
			}
			else if(arr[i]+arr[j]< sum)
			{
				i++;
			}
			else
			{
				j++;
			}

		}
	}
	return 0;
}
