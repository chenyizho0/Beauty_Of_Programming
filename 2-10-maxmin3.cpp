/*************************************************************************
    > File Name: 2-10-maxmin3.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月10日 星期一 03时24分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Pair
{
public:
	int max;
	int min;
	Pair(int aa,int bb)
	{
		max = aa;
		min = bb;
	}
	Pair()
	{
		max = 0;
		min = 0;
	}
};

int arr[100];

Pair searchMaxMin(int start,int end)
{
	Pair p;
	if(start >= end-1)
	{
		if(arr[start] > arr[end])
		{
			p.max = arr[start];
			p.min = arr[end];
		}
		else
		{
			p.max = arr[end];
			p.min = arr[start];
		}
	}
	else
	{
		Pair p1 = searchMaxMin(start,(start+end)/2);
		Pair p2 = searchMaxMin((start+end)/2+1,end);
		if(p1.min < p2.min)p.min = p1.min;
		else p.min = p2.min;
		if(p1.max > p2.max)p.max = p1.max;
		else p.max = p2.max;
	}
	return p;
}

int main()
{
	int n;
	cout << "please input number n " ;
	cin >> n;
	cout << "please input elements " << endl;
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	Pair p = searchMaxMin(0,n-1);
	cout << "max = " << p.max << endl;
	cout << "min = " << p.min << endl;
}
