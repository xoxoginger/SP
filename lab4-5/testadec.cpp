//               testadec.cpp
/*#include <iostream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main()
{
  tFSM Adec;
///////////////////////
//удалить этот код и заменить своим
  addrange(Adec,0,'1','9',1);
  addrange(Adec,1,'0','9',1);
  addstr(Adec,1,".",2);
  addrange(Adec,2,'0','9',2);
 Adec.final(2);
///////////////////////
  cout << "Number of states = " << Adec.size()
       << "\n";

  while(true)
 {
  char input[81];
  cout << ">";
  cin.getline(input,81);
  if(!*input) break;
  int res = Adec.apply(input);
  cout << setw(res?res+1:0) << "^"
       << endl;
 }
 return 0;
}*/

//               cppid.cpp
#include <iostream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main()
{
    tFSM fsm;
    ///////////////////////
    //  Постоить автомат
    addstr(fsm, 0, "-+", 1);
    addrange(fsm, 1, '1', '9', 2);
    addstr(fsm, 1, "0", 4);
    addrange(fsm, 2, '0', '9', 2);
    addstr(fsm, 2, ".", 3);
    addstr(fsm, 4, ".", 3);
    addrange(fsm, 3, '0', '9', 5);
    addrange(fsm, 5, '0', '9', 5);
    addstr(fsm, 3, "eE", 6);
    addstr(fsm, 5, "eE", 6);
    addstr(fsm, 6, "-+", 7);
    addrange(fsm, 7, '0', '9', 8);
    addrange(fsm, 8, '0', '9', 8);
    fsm.final(8);
    ///////////////////////

    cout << "Number of states = " << fsm.size()
        << "\n";

    while (true)
    {
        char input[81];
        cout << ">";
        cin.getline(input, 81);
        if (!*input) break;
        int res = fsm.apply(input);
        cout << setw(res ? res + 1 : 0) << "^"
            << endl;
    }
    return 0;
}
