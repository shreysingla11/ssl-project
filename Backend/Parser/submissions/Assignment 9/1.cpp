#include <iostream>
#include <vector>
using namespace std;
class boolfunc
{
   public:

      boolfunc() ;                                               // constructor that does nothing
      ~boolfunc() ;                                                    //destructor that should free all allocated memory
      boolfunc (boolfunc const &) ;                                    //copy constructor
     void operator+=(boolfunc const &) ;                               //- or operator
     void operator*=(boolfunc const &);                                  //- and operator
     void operator~();                                                   //- not operation
     bool operator==(boolfunc const &);                              //check for equality.
    void read();
};

// Member functions definitions
void boolfunc::read(void)
{
int a,i,j;
    cin>>a;
    vector <vector <int> > b;



    for(i=0;i<a;i++)
    {
    int c;
    cin>>c;
    vector <int>  d;
    for(j=0;j<c;j++)
    {
    int e;
    cin>>e;
    d.push_back(e);
    }
    b.push_back(d);
    }


}





