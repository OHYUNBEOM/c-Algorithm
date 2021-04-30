#include<iostream>
#include<math.h>
using namespace std;
double Fix(double x0, double es, int imax, double ea);
double g(double x);
double Fix(double x0, double es, int imax, double ea)
{
	double xr = x0, xrold;
	int iter = 0;
	while (1)
	{
		xrold = xr;
		cout << iter << "번 반복\t" << xr << "\t\t" << ea << endl;
		xr = g(xrold);
		iter += 1;
		if (xr != 0)
		{
			ea = fabs((xr - xrold) / xr) * 100;
		}
		if (ea < es || imax <= iter)
		{
			break;
		}
	}
	return xr;
}
double g(double x)
{
	return sqrt((1.7 * x + 2.5) / 0.9);
}
void main()
{
	cout << "\t\tx0" << "\t\tea" << endl;
	cout << endl << "고정점 반복법으로 구한 해: " << Fix(5, 0.01, 100, 100) << endl << endl;
}