#include <iostream>
#include "mlisp.h"

double odd__bits(double n);
double even__bits(double n);
double bit__count(double n);
void report__results(double n);
double dd = 16;
double mm = 12;
double yyyy = 1997;

double odd__bits(double n)
{
	return (n == 0 ? 0
		: myremainder(n, 2) == 0 ?
		odd__bits(quotient(n, 2))
		: even__bits(quotient(n, 2)));
}

double even__bits(double n)
{
	return (n == 0 ? 1
		: myremainder(n, 2) == 0 ?
		even__bits(quotient(n, 2))
		: true ? odd__bits(quotient(n, 2))
		: _infinity);
}

double bit__count(double n)
{
	return (n == 0 ? 0 : (myremainder(n, 2) + bit__count(quotient(n, 2))));
}

void report__results(double n)
{
	display("Happy birthday to you!\n\t");
	display(n);
	newline();
	display("\teven?\t");
	display(even__bits(n) == 1 ? "yes" : "no");
	newline();
	display("\todd?\t");
	display(odd__bits(n) == 1 ? "yes" : "no");
	newline();
	display("bit__count = ");
	display(bit__count(n));
	//return 0;
}

int main() {
	report__results(dd * 1000000 +
		mm * 10000 +
		yyyy);
	newline();
	std::cin.get();
	return 0;
}