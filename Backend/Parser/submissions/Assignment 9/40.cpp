#include <iostream>
using namespace std;

class boolfunc{
	public:
		bool x1;
		bool f1;
		bool f2;
		boolfunc(); //constructor
		~boolfunc();
		boolfunc( boolfunc const & str); //copy constructor
		void operator +=(boolfunc const & str){
			x1 = true;
			f1 = (!(x1)&&(f1))||((str.x1)&&(str.f2));
			f2 = (!(str.x1)&&(str.f1))||((x1)&&(f2));
			};
		void operator *=(boolfunc const & str){
			x1 = true;
			f1 = (!(x1)&&(f1))&&((str.x1)&&(str.f2));
			f2 = (!(str.x1)&&(str.f1))&&((x1)&&(f2));
			};
		void operator ~(){
			x1 = x1 || (!(f1)&&!(f2));
			f1 = !f1;
			f2 = !f2;
			
			
			};
		bool operator ==(boolfunc const &);
		void read();
		void print();
		void subst(int i, bool v);
	};
		
		
boolfunc :: boolfunc(){}
boolfunc :: ~boolfunc(){}
boolfunc :: boolfunc(boolfunc const & str){
	x1 = str.x1;
	f2 = str.f2;
	f1 = str.f1;
		}
	
	
	
	
