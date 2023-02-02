#include <iostream>
using namespace std;

double power(double x, int n)
{ 
double p = 1.0;
int c = 0;
while (c < n)
{
p = p * x;
c = c + 1;
}
return p;
}

int factorial(int n)
{
int f = 1;
int c = n;
while (c > 1)
{
f = f * c;
c = c - 1;
}
return f;
}

void testPower(double x, int maxPower)
{
cout.setf(ios::fixed);
for (int n = 1; n <= maxPower; ++n)
{
cout.precision(4);
cout << x << " ^ ";
cout.width(2);
cout << n << " = ";
cout.precision(15);
cout << power(x, n) << endl;
}
cout << endl;
}
void testFactorial(int maxN)
{
for (int n = 0; n <= maxN; ++n)
{
cout.width(2);
cout << n << "! = ";
cout << factorial(n) << endl;
}
cout << endl;
}

double myImprovedCos(double x, int noOfTerms)
{
int maxN = 2 * noOfTerms - 2;
double sum = 1.0;
double term = 1.0;
int n = 2;
while (n <= maxN)
{
term = -term * (x*x) / (n * (n-1));
sum = sum + term;
n = n + 2;
}
return sum;
}

double myCos(double x, int noOfTerms)
{
int maxN = 2 * noOfTerms - 2;
double sum = 1.0;
int sign = -1;
int n = 2;
while (n <= maxN)
{
double p = power(x, n);
double f = factorial(n);
sum = sum + sign * p /f;
sign = sign * -1;
n = n + 2;
}
return sum;
}

void testMyCos(double x, int maxNoOfTerms)
{
cout << "Entering testMyCos() ..." << endl;
cout.setf(ios::fixed);
for (int n = 1; n <= maxNoOfTerms; ++n)
{
cout << "Number of terms = ";
cout.width(4);
cout << n;
cout.precision(4);
cout << " => cos(" << x << ") = ";
cout.precision(20);
cout << myCos(x, n) << endl;
}
cout << "testMyCos() completed." << endl
<< endl;
}

int main()
{
double radiian;
cout << "Angle in radian => ";
cin >> radiian;
int maxNoOfTerms;
cout << "Max number of terms => ";
cin >> maxNoOfTerms;
cout << endl;
testMyCos(radiian, maxNoOfTerms);
}