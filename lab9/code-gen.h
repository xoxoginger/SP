//                 code-gen.h 2014
#ifndef CODE_GEN_H
#define CODE_GEN_H
#include <string>
#include "base-compiler.h"
using namespace std;

class tCG:public tBC{
public:
//êîíñòğóêòîğ
 tCG(const char* gramma_name) :tBC(gramma_name){}
private:
 std::string declarations;
 std::string decor(const std::string& id);

protected:
 void init(){declarations.clear();}

 int p01() { // S -> PROG
     string header = "/*  " + lex.Authentication() + "   */\n";
     header += "#include \"mlisp.h\"\n";
     header += declarations;
     header += "//________________ \n";
     S1->obj = header + S1->obj;
     return 0;
 }
 int p02() { //  PROG -> CALCS
     S1->obj = "int main(){\n" + S1->obj
         + " std::cin.get();\n return 0;\n}\n";
     return 0;
 }
 int p03() { //  PROG -> DEFS
     S1->obj += "int main(){\n"
         " display(\"No calculations!\");newline();\n"
         " std::cin.get();\n return 0;\n}\n";
     return 0;
 }
 int p04() { //  PROG -> DEFS CALCS
     S1->obj += "int main(){\n" + S2->obj + "std::cin.get();\n return 0;\n}\n";
     return 0;
 }
 int p05() { // CALCS -> CALC
     return 0;
 }
 int p06() { // CALCS -> CALCS CALC
     S1->obj += S2->obj;
     return 0;
 }
 int p07() { //  CALC -> E
     S1->obj = " display(" + S1->obj + "); newline();\n";
     return 0;
 }
 int p08() { //     E -> $id
     S1->obj = decor(S1->name);
     return 0;
 }
 int p09() { //     E -> $int
     S1->obj = decor(S1->name);
     return 0;
 }
 int p10() { //     E -> CPROC
     return 0;
 }
 int p11() { //     E -> MUL
     S1->obj = "( " + S1->obj + " )";
     return 0;
 }
 int p12() { // CPROC -> HCPROC )
     S1->obj = S1->obj + ")";
     return 0;
 }
 int p13() { //HCPROC -> ( $id
     S1->count = 0;
     S1->obj = decor(S2->name) + "(";
     return 0;
 }
 int p14() { //HCPROC -> HCPROC E
     if (S1->count != 0)
     {
         S1->obj += ", ";
     }
     S1->obj += S2->obj;
     S1->count++;
     return 0;
 }
 int p15() { //   MUL -> HMUL E )
     if (S1->count == 0) //îäèí îïåğàíä
         S1->obj = S2->obj;
     else            //áîëåå îäíîãî îïåğàíäà
         S1->obj += S2->obj;
     S1->count = 0;
     return 0;
 }
 int p16() { //  HMUL -> ( *
     S1->obj = "(";
     return 0;
 }
 int p17() { //  HMUL -> HMUL E
     S1->obj += S2->obj + " * ";
     ++S1->count;
     return 0;
 }
 int p18() { //   SET -> HSET E )
     S1->obj += S2->obj;
     return 0;
 }
 int p19() { //   hSET -> ( set! $id
     S1->obj = S3->name + " = ";
     S1->name = S3->name;
     return 0;
 }
 int p20() { //   DEF -> PROC
     return 0;
 }
 int p21() { //  DEFS -> DEF
     return 0;
 }
 int p22() { //  DEFS -> DEFS DEF
     S1->obj += S2->obj;
     return 0;
 }

 int p23() { //  PROC -> HPROC E )
     S1->obj += "return " + S2->obj + ";\n}\n";
     /*if (S2->obj[S2->obj.size()-1] == ';') {
        S2->obj = S2->obj.substr(0,S2->obj.size()-1);
    }
    else if (S2->obj[S2->obj.size()-1] == '\n' && S2->obj[S2->obj.size()-2] == ';') {
        S2->obj = S2->obj.substr(0,S2->obj.size()-2);
    }
    else if (S2->obj[S2->obj.size()-1] == ' ' && S2->obj[S2->obj.size()-2] == ';') {
        S2->obj = S2->obj.substr(0,S2->obj.size()-2);
    }

    S1->obj = S1->obj + "\treturn " + S2->obj + ";\n}\n";
    return 0;*/
     return 0;
 }
 int p24() { // HPROC -> PCPAR ) //ÅÑÒÒÜ ÄĞÓÃÀß
     S1->obj += ")";
     declarations += S1->obj + ";\n"; //!!!
     S1->obj += "{\n";
     return 0;
 }
 int p25() { // HPROC -> HPROC SET
     S1->obj += S2->obj + ";\n";
     return 0;
 }
 int p26() { // PCPAR -> ( define ( $id //åñòü åùå
     S1->obj = "double " + decor(S4->name) + "(";
     S1->count = 0;
     S1->name = S4->name;
     return 0;
 }
 int p27() { // PCPAR -> PCPAR $id
     if (S1->count)S1->obj += ", ";// íå ïåğâûé ïàğàìåòğ
     S1->obj += "double " + decor(S2->name);
     ++(S1->count);
     return 0;
 }
 //_____________________
 int p28() { return 0; } int p29() { return 0; }
 int p30() { return 0; } int p31() { return 0; }
 int p32() { return 0; } int p33() { return 0; }
 int p34() { return 0; } int p35() { return 0; }
 int p36() { return 0; } int p37() { return 0; }
 int p38() { return 0; } int p39() { return 0; }
 int p40() { return 0; } int p41() { return 0; }
 int p42() { return 0; } int p43() { return 0; }
 int p44() { return 0; } int p45() { return 0; }
 int p46() { return 0; } int p47() { return 0; }
 int p48() { return 0; } int p49() { return 0; }
 int p50() { return 0; } int p51() { return 0; }
 int p52() { return 0; } int p53() { return 0; }
 int p54() { return 0; } int p55() { return 0; }
 int p56() { return 0; } int p57() { return 0; }
 int p58() { return 0; } int p59() { return 0; }
 int p60() { return 0; } int p61() { return 0; }
 int p62() { return 0; } int p63() { return 0; }
 int p64() { return 0; } int p65() { return 0; }
 int p66() { return 0; } int p67() { return 0; }
 int p68() { return 0; } int p69() { return 0; }
 int p70() { return 0; } int p71() { return 0; }
 int p72() { return 0; } int p73() { return 0; }
 int p74() { return 0; } int p75() { return 0; }
 int p76() { return 0; } int p77() { return 0; }
 int p78() { return 0; } int p79() { return 0; }
 int p80() { return 0; } int p81() { return 0; }
 int p82() { return 0; } int p83() { return 0; }
 int p84() { return 0; } int p85() { return 0; }
 int p86() { return 0; } int p87() { return 0; }
 int p88() { return 0; } int p89() { return 0; }
 int p90() { return 0; } int p91() { return 0; }
 int p92() { return 0; } int p93() { return 0; }
 int p94() { return 0; } int p95() { return 0; }
 int p96() { return 0; } int p97() { return 0; }
 int p98() { return 0; } int p99() { return 0; }
 int p100() { return 0; } int p101() { return 0; }
 int p102() { return 0; } int p103() { return 0; }
 int p104() { return 0; } int p105() { return 0; }
 int p106() { return 0; } int p107() { return 0; }
 int p108() { return 0; } int p109() { return 0; }
 int p110() { return 0; }


};
 std::string tCG::decor(const std::string& id){
  static const char* cpp_reserved[]={
   "try",
//????????????????????????
   "main"
  };
  static const size_t n =
              sizeof(cpp_reserved)/sizeof(char*);
  for(size_t i=0; i<n; ++i)
  if( id == cpp_reserved[i])
     return "__"+
            lex.Authentication()+
            "__"+id;
// çàìåíèòü '-','!','?'
 std::string tmp;
 for(size_t i=0; i<id.size(); ++i){
  switch(id[i]){
    case '?': tmp+="_Q"; break;
    case '!': tmp+="_E"; break;
    case '-': tmp+="__"; break;
    default : tmp+=id[i];
  }
 }
 return tmp;
 }
#endif

