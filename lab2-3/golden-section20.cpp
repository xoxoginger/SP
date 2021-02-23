#include "mlisp.h"

double a = 1;
double b = 4;
double eps = 0.00001;
double mphi = 0;
double xmin = 0;

double fun(double x);
double golden__section__search(double a, double b);
double golden__start(double a, double b);
double __AJV__try(double a, double b, double xa, double ya, double xb, double yb);

/*(define a 1)(define b 4); 3.47372
(define(fun x)
(set!x(-x(/ 29 30)))
(-x(atan(*2 x)) (log(*pi x)) 6)
)*/

double fun(double x) {
    x = x - (double)29 / 30;
    return x - atan(2 * x) - log(pi * x) - 6;
}

double golden__section__search(double a, double b) {
    {
        double xmin = a < b ? golden__start(a, b) : golden__start(b, a);
        newline();
        return xmin;
    }
}

double golden__start(double a, double b) {
    mphi = 0.5 * (3 - sqrt(5));
    {
        double xa = a + mphi * (b - a);
        double xb = b - mphi * (b - a);
        return __AJV__try(a, b, xa, fun(xa), xb, fun(xb));
    }
}

double __AJV__try(double a, double b, double xa, double ya, double xb, double yb) {
    return (abs(a - b) < eps ? (a + b) * 0.5
        : (true ?
        (display("+"), ya < yb ?
            b = xb,
            xb = xa,
            yb = ya,
            xa = a + mphi * (b - a),
            __AJV__try(a, b, xa, fun(xa), xb, yb)
            : (a = xa,
                xa = xb,
                ya = yb,
                xb = b - mphi * (b - a),
                __AJV__try(a, b, xa, ya, xb, fun(xb))))
            : _infinity));
}

int main() {
    xmin = golden__section__search(a, b);
    display("interval=\t[");
    display(a);
    display(" , ");
    display(b);
    display("]\n");
    display("xmin=\t\t");
    display(xmin); newline();
    display("f(xmin)=\t");
    display(fun(xmin)); newline();
    std::cin.get();
    return 0;
}
