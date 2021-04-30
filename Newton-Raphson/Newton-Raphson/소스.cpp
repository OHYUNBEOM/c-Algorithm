#include<iostream>
using namespace std;
double fx(double);
double fx_1(double);
double NewtonRaphson(double xi, double es, int imax, double ea);
double fx(double x)
{
	return(-0.9 * x * x) + (1.7 * x) + 2.5;
}
double fx_1(double x)
{
	return (-1.8 * x) + 1.7;
}
double NewtonRaphson(double xi, double es, int imax, double ea)
{
	double xi_1 = xi;
	int iter = 0;
	while (1)
	{
		xi_1 = xi;
		xi = xi_1 - fx(xi) / fx_1(xi);
		cout << iter << "번 반복\t" << xi << "\t" << ea;
		iter += 1;
		if (xi != 0)
		{
			ea = fabs((xi - xi_1) / xi) * 100;
		}
		if (ea < es || imax <= iter)
		{
			break;
		}
		cout << endl;
	}
	return xi;
}
void main()
{
	cout << "반복\t\t" << "xi\t" << "ea" << endl;
	cout << "\n\n" << "Newton Raphson법으로 구한 해 : " << NewtonRaphson(5, 0.01, 100, 100) << "\n" << endl;
}