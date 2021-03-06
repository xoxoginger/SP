/*  AJV2020   */
#include "mlisp.h"
double a = 1;
double b = 4;
double fun(double x);
double golden__section__search(double a, double b);
double golden__start(double a, double b);
double set1(double a, double b, double xa, double xb, double ya, double yb);
double set2(double a, double b, double xa, double xb, double ya, double yb);
double mphi = (+0.5E+0 * (3-sqrt(5)));
double __AJV2020__try(double a, double b, double xa, double ya, double xb, double yb);
bool close__enough_Q(double x, double y);
double tolerance = +0.00001E+0;
double xmin = 0;
//________________ 
double fun(double x){
x = (x-(29 * (1 / (double)30 )));
return (((x-atan((2 * x)))-log((pi * x)))-6);
}
double golden__section__search(double a, double b){
{
double xmin = ((a < b) ? golden__start(a, b) : (golden__start(b, a)));
newline();
return xmin;
}

}
double golden__start(double a, double b){
{
double xa = (a + (mphi * (b-a)));
double xb = (b-(mphi * (b-a)));

return __AJV2020__try(a, b, xa, fun(xa), xb, fun(xb));
}

}
double set1(double a, double b, double xa, double xb, double ya, double yb){
b = xb;
xb = xa;
yb = ya;
xa = (a + (mphi * (b-a)));
return __AJV2020__try(a, b, xa, fun(xa), xb, yb);
}
double set2(double a, double b, double xa, double xb, double ya, double yb){
a = xa;
xa = xb;
ya = yb;
xb = (b-(mphi * (b-a)));
return __AJV2020__try(a, b, xa, ya, xb, fun(xb));
}
double __AJV2020__try(double a, double b, double xa, double ya, double xb, double yb){
return (close__enough_Q(a, b) ? ((a + b) * +0.5E+0) : (display("+"), ((ya < yb) ? set1(a, b, xa, xb, ya, yb) : (set2(a, b, xa, xb, ya, yb)))));
}
bool close__enough_Q(double x, double y){
return (abs((x-y)) < tolerance);
}
int main(){
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

