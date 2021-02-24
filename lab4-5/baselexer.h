//                 baselexer.h 2020
#ifndef BASELEXER_H
#define BASELEXER_H
#include <iostream>
#include <fstream>
#include <string>
#include "fsm.h"
using namespace std;

class tBaseLexer{
 std::ifstream fsource;//поток
//               ввода из файла
 int         line;//счетчик строк
 char        buf[1000];//буфер строки
 static const size_t bufsize=1000;
 char*       start;//указатель начала
//                   лексемы в буфере
 char*       end;//указатель конца
//                 лексемы в буфере
 std::string lexeme;//лексема

public:
//конструктор
 //tBaseLexer();
//деструктор
 ~tBaseLexer() {}
//функции-члены
 /*bool Begin(const char* filename);//под-
//            готовка к работе с файлом*/
 void End(){fsource.close();}//завершение
//                        работы с файлом

// std::string GetToken();//извлекает из
//                 текста очередной токен
 std::string GetLexeme()const{return lexeme;}
 int GetLineCount()const{return line;}
 int GetStartPos()const{return start-buf;}
 int GetEndPos()const{return end-buf;}
 std::string GetLineText()const{
                     return std::string(buf);}
 tBaseLexer() :start(buf), end(buf),
     line(0) {
     *buf = 0;
     // строка
     const char SP = ' ';// пробел
     addstr(Astr, 0, "\"", 1);
     addstr(Astr, 1, "\"", 2);
     addrange(Astr, 1, SP, '!', 1);
     addrange(Astr, 1, '#', '[', 1);
     addrange(Astr, 1, ']', '~', 1);
     addrange(Astr, 1, '\x80', '\xff', 1);// русские буквы
     addstr(Astr, 1, "\\", 3);
     //  escape-последовательности:
     // \'  \"  \?  \\  \a  \b  \f  \n  \r  \t  \v
     addstr(Astr, 3, "\"\\?'abfnrtv", 1);
     Astr.final(2);
     //________________________________________

     // оператор
     addstr(Aoper, 0, "+-*/=", 1);
     addstr(Aoper, 0, "<>", 2);
     addstr(Aoper, 2, "=", 1);
     Aoper.final(1);
     Aoper.final(2);
     //________________________________________

     // булевские константы
     addstr(Abool, 0, "#", 1);
     addstr(Abool, 1, "tf", 2);
     Abool.final(2);
     //________________________________________
 }

 bool Begin(const char* filename) {
     line = 0;
     start = buf;
     end = buf;
     *buf = 0;
     lexeme = "";
     fsource.clear();
     fsource.open(filename);
     return bool(fsource);//false - ошибка открыти€
  //                  файла
 }
 
 string GetToken() {
     lexeme = "";
     // пропустить пробельные символы и комментарии
     for (;;) {
         if (*end == 0 || *end == ';') {
             fsource.getline(buf, bufsize);
             end = buf;
             ++line;
             if (!fsource) {
                 *end = 0;
                 start = end;
                 return "#";//конец файла
             }
             // skip Racket metadata
             if (*buf == '#' && !(*(buf + 1) == 't' || *(buf + 1) == 'f'))*buf = 0;
             continue;
         }
         if (!std::isspace(*end)) break;// не-
      //                    пробельный символ
         ++end;
     }//for...

     start = end;// начало лексемы
  // скобки
     if (*start == '(' || *start == ')') {
         lexeme = string(1, *start);//строка из
    //                   одного символа
         ++end;// продвинуть за скобку
         return lexeme;
     }
     // строка
     if (*start == '"') {
         int lstr = Astr.apply(start);
         if (lstr != 0) {
             end += lstr;
             lexeme = string(start, end);
             return "$str";
         }
         // ошибка в записи строки, lstr==0
         lexeme = string(start);
         end += lexeme.length();
         return "?";
     }
     // атом
     //         end продвигаетс€ за конец атома
     while (*(++end) != 0) {
         if (std::isspace(*end) ||
             *end == ';' ||
             *end == '"' ||
             *end == '(' ||
             *end == ')') break;
     }//while...
     lexeme = string(start, end);//строка из
  //            последовательности символов

  // автоматы распознают токен внутри атома
     int total = lexeme.length();
     const char* input = lexeme.c_str();
     if (Aid.apply(input) == total) return "$id";
     if (Adec.apply(input) == total) return "$dec";
     if (Aint.apply(input) == total) return "$int";
     if (Abool.apply(input) == total) return "$bool";
     if (Aidq.apply(input) == total) return "$idq";
     if (Aoper.apply(input) == total) return lexeme;
     return "?";// неизвестный токен
 }

protected:
//автоматы
    tFSM Azero;//0
    tFSM Aint; //целое
    tFSM Adec; //вещественное
    tFSM AdecE;//вещественное с е≈
    tFSM Aid;  //идентификатор
    tFSM Aidq; //идентификатор предиката
private:
    tFSM Aoper;//оператор
    tFSM Abool;//булевска€ константа
    tFSM Astr; //строка
};
#endif

