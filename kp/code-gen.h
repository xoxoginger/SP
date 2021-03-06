//                 code-gen.h 2014
#ifndef CODE_GEN_H
#define CODE_GEN_H
#include <string>
#include "base-compiler.h"
using namespace std;
class tCG:public tBC{
public:
//конструктор
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
 int p02() { //   PROG -> CALCS
	 S1->obj = "int main(){\n" + S1->obj + "std::cin.get();\n return 0;\n}\n";
	 return 0;
 }
 int p03() { //   PROG -> DEFS
	 S1->obj += "int main(){\n"
		 " display(\"No calculations!\");newline();\n"
		 "std::cin.get();\nreturn 0;\n}\n";
	 return 0;
 }
 int p04() { //   PROG -> DEFS CALCS
	 S1->obj += "int main(){\n" + S2->obj + "std::cin.get();\n return 0;\n}\n";
	 return 0;
 }
 int p05() { //      E -> $id
	 S1->obj = decor(S1->name);
	 return 0;
 }
 int p06() { //      E -> $int
	 S1->obj = decor(S1->name);
	 return 0;
 }
 int p07() { //      E -> $dec
	 S1->obj = decor(S1->name);
	 return 0;
 }
 int p08() { //      E -> ADD
	 return 0;
 }
 int p09() { //      E -> SUB
	 return 0;
 }
 int p10() { //      E -> DIV
	 return 0;
 }
 int p11() { //      E -> MUL
	 return 0;
 }
 int p12() { //      E -> COND
	 return 0;
 }
 int p13() { //      E -> EASYLET
	 return 0;
 }
 int p14() { //      E -> CPROC
	 return 0;
 }
 int p15() { //    ADD -> HADD E )
	 S1->obj += " + " + S2->obj + ")";
	 return 0;
 }
 int p16() { //   HADD -> ( +
	 S1->obj = "(";
	 S1->count = 0;
	 return 0;
 }
 int p17() { //   HADD -> HADD E
	 if (S1->count != 0)
	 {
		 S1->obj += " + ";
	 }
	 S1->obj += S2->obj;
	 S1->count++;
	 return 0;
 }
 int p18() { //    SUB -> ( - E E ) //DO
	 //S1->obj = "(";
	 //S1->count = 0;
	 //if (S1->count != 0)
	 //{
	 //S1->obj += "-";
	 //}
	// S1->obj += S4->obj;
	 //S1->count++;
	 S1->obj = "(" + S3->obj + "-" + S4->obj + ")";
	 return 0;
 }
 int p19() { //    DIV -> ( / E ) //DO +
	 S1->obj = "(1 / (double)" + S3->obj + " )";
	 return 0;
 }
 int p20() { //    MUL -> HMUL E )
	 S1->obj += " * " + S2->obj + ")";
	 return 0;
 }
 int p21() { //   HMUL -> ( *
	 S1->obj = "(";
	 S1->count = 0;
	 return 0;
 }
 int p22() { //   HMUL -> HMUL E
	 if (S1->count != 0)
	 {
		 S1->obj += " * ";
	 }
	 S1->obj += S2->obj;
	 S1->count++;
	 return 0;
 }
 int p23() { //   COND -> HCOND ELSE )
	 S1->obj += S2->obj + ")";
	 //S1->obj = S1->obj + S2->obj + ")";
	 return 0;
 }
 int p24() { //  HCOND -> ( cond
	 S1->obj = "(";
	 return 0;
 }
 int p25() { //  HCOND -> HCOND CLAUS
	 //if (S1->count)S1->obj += "):";
	 S1->obj += S2->obj;
	 //++S1->count;
	 return 0;
 }
 int p26() { //  CLAUS -> ( BOOL E )
	 //if(S1->count == 1)
		//S1->obj += S4->obj;
	 S1->obj = "" + S2->obj + " ? " + S3->obj + " : " ;
	 //S1->count = 1;
	 return 0;
 }

 /*int tCG::p25()
{ //   COND -> HCOND ELSE )
	S1->obj += S2->obj + ")";
	return 0;
}
int tCG::p26()
{ //  HCOND -> ( cond
	S1->obj = "(";
	return 0;
}
int tCG::p27()
{ //  HCOND -> HCOND CLAUS
	S1->obj += S2->obj;
	return 0;
}
int tCG::p28()
{ //  CLAUS -> ( BOOL E )
	S1->obj = "" + S2->obj + " ? " + S3->obj + " : ";
	return 0;
}

___________________________________________________________________________________

int tCG::p25()
{ //   COND -> HCOND ELSE ) = (k ? a : (k ? b : (k ? c : d))) при последов.
	// (a ? (b ? (d ? e : c) : c) : c) вложенный конд +
	S1->obj = S1->obj + S2->obj + ")"; // закрывает конд
	// else в скобки,весбь конд в скобки
	return 0;
}
int tCG::p26()
{                  //  HCOND -> ( cond
	S1->obj = "("; // открывает конд
	// S1->count = 0;
	return 0;
}
int tCG::p27()
{ //  HCOND -> HCOND CLAUS
	//if (S1->count)S1->obj += "):";
	S1->obj += S2->obj + "("; //() ? () : (
	++S1->count;
	return 0;
}
int tCG::p28()
{ //  CLAUS -> ( BOOL E )
	S1->count = 0;
	S1->obj = "" + S2->obj + " ? " + S3->obj + " : ";
	return 0;
}*/
 int p27() { //   ELSE -> ( else E ) //DO XZZZZZZZ
	 S1->obj += "(" + S3->obj + ")";
	 return 0;
 }
 int p28() { //EASYLET -> HEASYL E )
	 if (S1->count != 0)
		 S1->obj += S2->obj + ";\n";
	 S1->obj += S2->obj;
	 ++(S1->count);
	 return 0;
 }
 int p29() { // HEASYL -> ( let ( )
	 return 0;
 }
 int p30() { // HEASYL -> HEASYL INTER
	 S1->obj += S2->obj + ", ";
	 return 0;
 }
 int p31() { //    STR -> $str
	 S1->obj = decor(S1->name);
	 return 0;
 }
 int p32() { //    STR -> SIF //DO +
	 return 0;
 }
 int p33() { //    SIF -> ( if BOOL STR STR ) //DO +
	 S1->obj = S3->obj + " ? " + S4->obj + " : " + S5->obj; //+ " : ";
	 return 0;
 }
 int p34() { //  CPROC -> HCPROC )
	 S1->obj = S1->obj + ")";
	 return 0;
 }
 int p35() { // HCPROC -> ( $id
	 S1->count = 0;
	 S1->obj = decor(S2->name) + "(";
	 return 0;
 }
 int p36() { // HCPROC -> HCPROC E
	 if (S1->count != 0)
	 {
		 S1->obj += ", ";
	 }
	 S1->obj += S2->obj;
	 S1->count++;
	 return 0;
 }
 int p37() { //   BOOL -> $bool
	 if (S1->name == "#t")
	 {
		 S1->obj = "true";
	 }
	 else if (S1->name == "#f")
	 {
		 S1->obj = "false";
	 }
	 return 0;
 }
 int p38() { //   BOOL -> $idq
	 S1->obj = decor(S1->name);
	 return 0;
 }
 int p39() { //   BOOL -> REL
	 S1->obj = "(" + S1->obj + ")";
	 return 0;
 }
 int p40() { //   BOOL -> CPRED
	 S1->obj = S1->obj;
	 return 0;
 }
 int p41() { //  CPRED -> HCPRED )
	 S1->obj = S1->obj + ")";
	 return 0;
 }
 int p42() { // HCPRED -> ( $idq
	 S1->count = 0;
	 S1->obj = decor(S2->name) + "(";
	 return 0;
 }
 int p43() { // HCPRED -> HCPRED ARG
	 if (S1->count != 0)
	 {
		 S1->obj += ", ";
	 }
	 S1->obj += S2->obj;
	 S1->count++;
	 return 0;
 }
 int p44() { //    ARG -> E
	 return 0;
 }
 int p45() { //    ARG -> BOOL
	 return 0;
 }
 int p46() { //    REL -> ( = E E 
	 S1->obj = S3->obj + " == " + S4->obj;
	 return 0;
 }
 int p47() { //    REL -> ( < E E )
	 S1->obj = S3->obj + " < " + S4->obj;
	 return 0;
 }
 int p48() { //    SET -> HSET E )
	 S1->obj += S2->obj;
	 return 0;
 }
 int p49() { //   HSET -> ( set! $id
	 S1->obj = S3->name + " = ";
	 S1->name = S3->name;
	 return 0;
 }
 int p50() { //DISPSET -> ( display E )
	 S1->obj = "display(" + S3->obj + ")";
	 return 0;
 }
 int p51() { //DISPSET -> ( display BOOL )
	 S1->obj = "display(" + S3->obj + ")";
	 return 0;
 }
 int p52() { //DISPSET -> ( display STR )
	 S1->obj = "display(" + S3->obj + ")";
	 return 0;
 }
 int p53() { //DISPSET -> ( newline )
	 S1->obj = "newline()";
	 return 0;
 }
 int p54() { //DISPSET -> SET
	 return 0;
 }
 int p55() { //  INTER -> DISPSET
	 return 0;
 }
 int p56() { //  INTER -> E
	 return 0;
 }
 int p57() { //  CALCS -> CALC
	 return 0;
 }
 int p58() { //  CALCS -> CALCS CALC
	 S1->obj += S2->obj;
	 return 0;
 }
 int p59() { //   CALC -> E
	 S1->obj = " display(" + S1->obj + "); newline();\n";
	 return 0;
 }
 int p60() { //   CALC -> BOOL
	 S1->obj = " display(" + S1->obj + "); newline();\n";
	 return 0;
 }
 int p61() { //   CALC -> STR
	 S1->obj = " display(" + S1->obj + "); newline();\n";
	 return 0;
 }
 int p62() { //   CALC -> DISPSET
	 S1->obj += ";\n";
	 return 0;
 }
 int p63() { //   DEFS -> DEF
	 return 0;
 }
 int p64() { //   DEFS -> DEFS DEF
	 S1->obj += S2->obj;
	 return 0;
 }
 int p65() { //    DEF -> PRED
	 return 0;
 }
 int p66() { //    DEF -> VAR
	 return 0;
 }
 int p67() { //    DEF -> PROC
	 return 0;
 }
 int p68() { //   PRED -> HPRED BOOL )
	 S1->obj += "return " + S2->obj + ";\n}\n";
	 return 0;
 }
 int p69() { //  HPRED -> PDPAR )
	 S1->obj += ")";
	 declarations += S1->obj + ";\n";
	 S1->obj += "{\n";
	 return 0;
 }
 int p70() { //  PDPAR -> ( define ( $idq
	 S1->obj = "bool " + decor(S4->name) + "(";
	 S1->count = 0;
	 return 0;
 }
 int p71() { //  PDPAR -> PDPAR $idq
	 if (S1->count != 0)
	 {
		 S1->obj += ", ";
	 }
	 S1->obj += "bool " + decor(S2->name);
	 S1->count++;
	 return 0;
 }
 int p72() { //  PDPAR -> PDPAR $id
	 if (S1->count)
		 S1->obj += ", ";
	 S1->obj += "double " + decor(S2->name);
	 ++(S1->count);
	 return 0;
 }
 int p73() { //    VAR -> VARDCL E )
	 S1->obj += " = " + S2->obj + ";\n";
	 declarations += S1->obj;
	 S1->obj = "";
	 return 0;
 }
 int p74() { // VARDCL -> ( define $id
	 S1->obj = "double " + decor(S3->name);
	 return 0;
 }
 int p75() { //   PROC -> HPROC BLOCK )
	 if (S1->count == 0)
	 {
		 S1->obj += "{\n";
	 }
	 S1->obj = S1->obj + S2->obj + "\n}\n";
	 return 0;
 }
 int p76() { //   PROC -> HPROC E )
	 if (S1->count == 0)
	 {
		 S1->obj += "{\n";
	 }
	 S1->obj += "return " + S2->obj + ";\n}\n";
	 return 0;
 }
 int p77() { //  HPROC -> PCPAR )
	 S1->obj += ")";
	 S1->count = 0;
	 declarations += S1->obj + ";\n";
	 return 0;
 }
 int p78() { //  HPROC -> HPROC INTER
	 if (S1->count == 0)
	 {
		 S1->obj += "{\n";
	 }
	 S1->obj += S2->obj + ";\n";
	 S1->count++;
	 return 0;
 }
 int p79() { //  PCPAR -> ( define ( $id
	 S1->obj = "double " + decor(S4->name) + "(";
	 S1->count = 0;
	 return 0;
 }
 int p80() { //  PCPAR -> PCPAR $id
	 if (S1->count)
		 S1->obj += ", ";
	 S1->obj += "double " + decor(S2->name);
	 ++(S1->count);
	 return 0;
 }
 int p81() { //  BLOCK -> HBLOCK E )
	 S1->obj = "{\n" + S1->obj + "return " + S2->obj + ";\n}\n";
	 return 0;
 }
 int p82() { // HBLOCK -> BLVAR )
	 return 0;
 }
 int p83() { // HBLOCK -> HBLOCK INTER
	 S1->obj += S2->obj + ";\n";
	 return 0;
 }
 int p84() { //  BLVAR -> ( let ( LOCDEF
	 S1->obj = S4->obj;
	 return 0;
 }
 int p85() { //  BLVAR -> BLVAR LOCDEF
	 S1->obj += S2->obj + "\n";
	 return 0;
 }
 int p86() { // LOCDEF -> ( $id E )
	 S1->obj = "double " + decor(S2->name) + " = " + S3->obj + ";\n";
	 return 0;
 }
 //_____________________
 int p87() { return 0; } int p88() { return 0; }
 int p89() { return 0; } int p90() { return 0; }
 int p91() { return 0; } int p92() { return 0; }
 int p93() { return 0; } int p94() { return 0; }
 int p95() { return 0; } int p96() { return 0; }
 int p97() { return 0; } int p98() { return 0; }
 int p99() { return 0; } int p100() { return 0; }
 int p101() { return 0; } int p102() { return 0; }
 int p103() { return 0; } int p104() { return 0; }
 int p105() { return 0; } int p106() { return 0; }
 int p107() { return 0; } int p108() { return 0; }
 int p109() { return 0; } int p110() { return 0; }

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
// заменить '-','!','?'
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

