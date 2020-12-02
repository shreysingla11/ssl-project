#include<iostream>
using namespace std;


class boolfunc{
   public:
   boolfunc();
~boolfunc();
boolfunc( boolfunc const &);
void operator+=(boolfunc const &);
void operator*=(boolfunc const &);
void operator~();
bool operator==(boolfunc const &);
}
