//                 lexer.h 2020
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  AJV		     *
//*             (c)  2020                    *
//********************************************
class tLexer :public tBaseLexer {
public:
    // персональный код разработчика
    std::string Authentication()const {
        return "AJV"
            + std::string("2020");
    }
    //конструктор
    tLexer() :tBaseLexer() {
        //создать автоматы:

        //  ноль Azero
        //addstr(Azero, 0, "+-", 2);
        //addstr(Azero, 0, "0", 1);
        //addstr(Azero, 2, "0", 1);
        //Azero.final(1);

        //  целое Aint
        addstr(Aint, 0, "+-", 2);
        addrange(Aint, 2, '0', '9', 1);
        addrange(Aint, 0, '0', '9', 1);
        addrange(Aint, 1, '0', '9', 1);
        Aint.final(1);

        //________________________________________

        // вещественное
            //addrange(Adec,0,'0','9',1);
            //addstr  (Adec,1,".",   2);
            //addrange(Adec,2,'0','9',2);
          //Adec.final(2);
        //________________________________________

        // вещественное с е≈
          addstr(Adec, 0, "-+", 1);
          addrange(Adec, 1, '1', '9', 2);
          addstr(Adec, 1, "0", 4);
          addrange(Adec, 2, '0', '9', 2);
          addstr(Adec, 2, ".", 3);
          addstr(Adec, 4, ".", 3);
          addrange(Adec, 3, '0', '9', 5);
          addrange(Adec, 5, '0', '9', 5);
          addstr(Adec, 3, "eE", 6);
          addstr(Adec, 5, "eE", 6);
          addstr(Adec, 6, "-+", 7);
          addrange(Adec, 7, '0', '9', 8);
          addrange(Adec, 8, '0', '9', 8);
          Adec.final(8);

          // идентификатор
            addrange(Aid, 0, 'A', 'Z', 1);
            addrange(Aid, 0, 'a', 'z', 1);
            addstr(Aid, 0, "!", 2);
            addstr(Aid, 0, "?", 6); //


            addrange(Aid, 1, 'A', 'Z', 1);
            addrange(Aid, 1, 'a', 'z', 1);
            addrange(Aid, 1, '0', '9', 1);
            addstr(Aid, 1, "-", 1);
            addstr(Aid, 1, "!", 3);
            addstr(Aid, 1, "?", 4);
            addstr(Aid, 1, "-", 5);

            addstr(Aid, 3, "?", 3);
            addstr(Aid, 3, "!", 1);
            addstr(Aid, 3, "?", 1);

            addstr(Aid, 4, "?", 4);
            addrange(Aid, 4, 'A', 'Z', 1);
            addrange(Aid, 4, 'a', 'z', 1);
            addrange(Aid, 4, '0', '9', 1);
            addstr(Aid, 4, "-", 1);
            addstr(Aid, 4, "!", 1);

            addstr(Aid, 5, "-", 5);
            addstr(Aid, 5, "?", 5);
            addstr(Aid, 5, "!", 1);
            addrange(Aid, 5, 'A', 'Z', 1);
            addrange(Aid, 5, 'a', 'z', 1);
            addrange(Aid, 5, '0', '9', 1);

            addstr(Aid, 6, "?", 6);
            addstr(Aid, 6, "-", 1);
            addstr(Aid, 6, "!", 1);
            addrange(Aid, 6, 'A', 'Z', 1);
            addrange(Aid, 6, 'a', 'z', 1);
            addrange(Aid, 6, '0', '9', 1);


            Aid.final(1);
            Aid.final(2);
            Aid.final(3);
            Aid.final(5);
            //________________________________________

            // идентификатор предиката

        addstr(Aidq, 0, "!", 4);
        addstr(Aidq, 0, "?", 1);
        addstr(Aidq, 0, "-", 3);
        addrange(Aidq, 0, 'a', 'z', 2);
        addrange(Aidq, 0, 'A', 'Z', 2);

        addstr(Aidq, 1, "?", 1);
        addrange(Aidq, 1, 'a', 'z', 4);
        addrange(Aidq, 1, 'A', 'Z', 4);
        addrange(Aidq, 1, '0', '9', 4);
        addstr(Aidq, 1, "-", 2);
        addstr(Aidq, 1, "!", 2);

        addstr(Aidq, 2, "-", 2);
        addrange(Aidq, 2, 'a', 'z', 2);
        addrange(Aidq, 2, 'A', 'Z', 2);
        addrange(Aidq, 2, '0', '9', 2);
        addstr(Aidq, 2, "?", 1);
        addstr(Aidq, 2, "!", 5);

        addstr(Aidq, 3, "-", 3);
        addrange(Aidq, 3, 'a', 'z', 4);
        addrange(Aidq, 3, 'A', 'Z', 4);
        addrange(Aidq, 3, '0', '9', 4);
        addstr(Aidq, 3, "!", 5);
        addstr(Aidq, 3, "?", 2);
        addrange(Aidq, 3, 'a', 'z', 2);
        addrange(Aidq, 3, 'A', 'Z', 2);
        addrange(Aidq, 3, '0', '9', 2);

        addstr(Aidq, 4, "!", 4);
        addstr(Aidq, 4, "?", 1);
        addstr(Aidq, 4, "-", 3);
        addrange(Aidq, 4, 'a', 'z', 5);
        addrange(Aidq, 4, 'A', 'Z', 5);
        addrange(Aidq, 4, '0', '9', 5);

        addrange(Aidq, 5, 'a', 'z', 1);
        addrange(Aidq, 5, 'A', 'Z', 1);
        addrange(Aidq, 5, '0', '9', 1);
        addstr(Aidq, 5, "-", 1);
        addstr(Aidq, 5, "?", 1);

        Aidq.final(1);

        //___________________________________________________________________________
        //тупые варианты

        /*addstr(Aidq, 0, "!", 4);
        addstr(Aidq, 0, "?", 1);
        addstr(Aidq, 0, "-", 3);
        addrange(Aidq, 0, 'a', 'z', 2);
        addrange(Aidq, 0, 'A', 'Z', 2);

        addstr(Aidq, 1, "?", 1);
        addstr(Aidq, 1, "?", 2);
        addstr(Aidq, 1, "-", 2);
        addrange(Aidq, 1, 'a', 'z', 2);
        addrange(Aidq, 1, 'A', 'Z', 2);
        addrange(Aidq, 1, '0', '9', 2);
        addstr(Aidq, 1, "!", 4);

        addstr(Aidq, 2, "?", 2);
        addstr(Aidq, 2, "-", 2);
        addrange(Aidq, 2, 'a', 'z', 2);
        addrange(Aidq, 2, 'A', 'Z', 2);
        addrange(Aidq, 2, '0', '9', 2);
        addstr(Aidq, 2, "?", 1);
        addstr(Aidq, 2, "!", 1);

        addstr(Aidq, 3, "!", 5);
        addstr(Aidq, 3, "-", 3);
        addstr(Aidq, 3, "?", 2);
        //addstr(Aidq, 3, "!", 2);
        addrange(Aidq, 3, 'a', 'z', 2);
        addrange(Aidq, 3, 'A', 'Z', 2);
        addrange(Aidq, 3, '0', '9', 2);
        addrange(Aidq, 3, 'a', 'z', 1);
        addrange(Aidq, 3, 'A', 'Z', 1);
        addrange(Aidq, 3, '0', '9', 1);
        addstr(Aidq, 3, "?", 1);

        addstr(Aidq, 4, "!", 4);
        addrange(Aidq, 4, 'a', 'z', 1);
        addrange(Aidq, 4, 'A', 'Z', 1);
        addrange(Aidq, 4, '0', '9', 1);
        addrange(Aidq, 4, 'a', 'z', 2);
        addrange(Aidq, 4, 'A', 'Z', 2);
        addrange(Aidq, 4, '0', '9', 2);
        addstr(Aidq, 4, "-", 2);
        addstr(Aidq, 4, "?", 2);
        addstr(Aidq, 4, "-", 3);

        addrange(Aidq, 5, 'a', 'z', 1);
        addrange(Aidq, 5, 'A', 'Z', 1);
        addrange(Aidq, 5, '0', '9', 1);
        addstr(Aidq, 5, "?", 1);
        addstr(Aidq, 5, "-", 1);

        Aidq.final(1);*/

        /*addstr(Aidq, 6, "!", 2);

        addstr(Aidq, 0, "!", 6);
        addstr(Aidq, 0, "?", 1);
        addstr(Aidq, 0, "-", 3);
        addrange(Aidq, 0, 'a', 'z', 2);
        addrange(Aidq, 0, 'A', 'Z', 2);

        addstr(Aidq, 3, "-", 3);
        addrange(Aidq, 2, 'a', 'z', 2);
        addrange(Aidq, 2, 'A', 'Z', 2);
        addrange(Aidq, 2, '0', '9', 2);
        addstr(Aidq, 2, "-", 2);
        addstr(Aidq, 6, "!", 6);
        addstr(Aidq, 1, "?", 1);

        addstr(Aidq, 1, "-", 5);
        addstr(Aidq, 1, "!", 4);
        addrange(Aidq, 1, 'a', 'z', 2);
        addrange(Aidq, 1, 'A', 'Z', 2);
        addrange(Aidq, 1, '0', '9', 2);
        addstr(Aidq, 1, "-", 2);
        addstr(Aidq, 1, "!", 2);
        addstr(Aidq, 1, "!", 6); //


        addstr(Aidq, 2, "?", 1);


        addstr(Aidq, 3, "!", 1);
        addstr(Aidq, 3, "?", 1);
        addrange(Aidq, 3, 'a', 'z', 2);
        addrange(Aidq, 3, 'A', 'Z', 2);
        addrange(Aidq, 3, '0', '9', 2);
        addstr(Aidq, 3, "!", 2);

        addstr(Aidq, 4, "?", 1);
        addstr(Aidq, 4, "!", 4);
        addrange(Aidq, 4, 'a', 'z', 2);
        addrange(Aidq, 4, 'A', 'Z', 2);
        addrange(Aidq, 4, '0', '9', 2);

        addstr(Aidq, 5, "?", 1);
        addstr(Aidq, 5, "!", 2);

        addstr(Aidq, 6, "?", 1);
        addstr(Aidq, 6, "-", 3);
        addrange(Aidq, 6, 'a', 'z', 7);
        addrange(Aidq, 6, 'A', 'Z', 7);
        addrange(Aidq, 6, '0', '9', 7);

        addstr(Aidq, 7, "?", 1);


        Aidq.final(1);
        */
    }
};
#endif

