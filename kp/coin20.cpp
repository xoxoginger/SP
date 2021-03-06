/*  AJV2020   */
#include "mlisp.h"
double count__change(double amount);
double cc(double amount, double kinds__of__coins);
double first__denomination(double kinds__of__coins);
double group = 8;
double variant = 29;
//________________ 
double count__change(double amount){
return cc(amount, 5);
}
double cc(double amount, double kinds__of__coins){
return ((amount == 0) ? 1 : (amount < 0) ? 0 : (kinds__of__coins == 0) ? 0 : ((cc(amount, (kinds__of__coins-1)) + cc((amount-first__denomination(kinds__of__coins)), kinds__of__coins))));
}
double first__denomination(double kinds__of__coins){
return ((kinds__of__coins == 1) ? 1 : (kinds__of__coins == 2) ? 5 : (kinds__of__coins == 3) ? 10 : (kinds__of__coins == 4) ? 15 : (kinds__of__coins == 5) ? 20 : (0));
}
int main(){
 display(count__change(100)); newline();
 display(count__change(remainder(((100 * group) + variant), 137))); newline();
std::cin.get();
 return 0;
}

