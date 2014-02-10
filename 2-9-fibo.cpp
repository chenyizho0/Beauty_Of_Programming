/*************************************************************************
    > File Name: 2-9-fibo.cpp
    > Author: laixukai
    > Mail: laixukai@126.com 
    > Created Time: 2014年02月10日 星期一 03时58分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Matrix
{
public:
	int a11;
	int a12;
	int a21;
	int a22;
	Matrix(int b11,int b12,int b21,int b22)
	{
		a11 = b11;
		a12 = b12;
		a21 = b21;
		a22 = b22;
	}
};

Matrix M = Matrix(1,1,1,0);

Matrix Mutip(Matrix a,Matrix m)
{
   return Matrix(a.a11*m.a11+a.a12*m.a21,a.a11*m.a12+a.a12*m.a22,a.a21*m.a11+a.a22*m.a21,a.a21*m.a12+a.a22*m.a22);
}

Matrix count(int n)
{
	if(n == 1)
	{
		return M;
	}
	else
	{
			Matrix m = count(n/2);
			Matrix ans = Mutip(m,m);
			if(n%2 == 0)
			{
				return ans;
			}
			else
			{
				return Mutip(ans,M);
			}
	}
}

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		Matrix m = count(n);
		cout << m.a21 << endl;
	}




}
