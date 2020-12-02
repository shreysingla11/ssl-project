#include<iostream>
using namespace std;

class boolfunc{
int reg;
boolfunc* leftfunc;
boolfunc* rightfunc;
boolfunc(){
	reg=1;
}
~boolfunc(){} 
boolfunc(boolfunc const &arg){
		if(arg.leftfunc!=NULL){
			leftfunc=new boolfunc(*(arg.leftfunc))
		}
		else{
			leftfunc=NULL;
		}
		if(arg,rightfunc!=NULL){
			rightfunc=new boolfunc(*(arg.rightfunc))
		}
		else{
			rightfunc=NULL;
		}
		reg=arg.reg;
}
void operator+=(boolfunc const &arg){
  if(reg<arg.reg){leftfunc=new boolfunc(*(arg.leftfunc)+ *(leftfunc)) }
  else{rightfunc=new boolfunc(*(arg.rightfunc)+ *(rightfunc))}
}
void operator*=(boolfunc const &arg){
  if(reg<arg.reg){leftfunc=new boolfunc(*(arg.leftfunc)* *(leftfunc)) }
  else{rightfunc=new boolfunc(*(arg.rightfunc)* *(rightfunc))}
}
bool operator==(boolfunc const &){
}
};
