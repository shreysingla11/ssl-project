

class boolfunc{
public:
boolfunc *l,*r;int n;
boolfunc(){}                                                 //constructor that does nothing
~boolfunc(){}                                                //destructor that should free all allocated memory
boolfunc( boolfunc const &){}                                //copy constructor
void operator+=(boolfunc const &b){}                          //or operator
void operator*=(boolfunc const &){}                          //and operator
void operator~(){}                                           //not operation
bool operator==(boolfunc const &b){if(n==b.n && l==b.l && r==b.r){return true;}
                                   else{return false;}
                                   }                          //check for equality.
void read(){int v,s,i,j,k;cin>>v;
 for(i=0;i<v;i++){cin>>s;for(j=0;j<s,j++){cin>>j;
  if(j>0){boolfunc b;}            }}                                                //reads the function in sum of products form and constructs it binary tree representation.}
void print(){}                                               //prints out the function in the same format as the input.
void subst(int i, bool v){}                                  //modifies the function by setting the value of x_i to v. This will be a new function independent of x_i.
}};

