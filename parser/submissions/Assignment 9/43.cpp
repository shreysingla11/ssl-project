#include<iostream>
using namespace std;

class boolfunc{

int r;
boolfunc* leftfunc;
boolfunc* rightfunc;
public:

boolfunc() {
}
~boolfunc()
{
delete leftfunc;
delete rightfunc;
}
boolfunc( boolfunc const &temp)
{

		if(temp.leftfunc!=NULL)
		{
			leftfunc=new boolfunc(*(temp.leftfunc));
		}
		else{leftfunc=NULL;}
		if(temp,rightfunc!=NULL)
		{

			rightfunc=new boolfunc(*(temp.rightfunc));
		}
		else{rightfunc=NULL;}
     r=temp.r;

}
void operator+=(boolfunc const &temp)
{
  if(temp.r==0)
   {
    return;
   }
   if(temp.r==-1)
   {
   r=-1;
   delete leftfunc;
   delete rightfunc;
   leftfunc=NULL;
   rightfunc=NULL;
   return;
   }
   else if(r==-1)
   {
     return;
   }
   else if(r==0)
   {
     r=temp.r;
     leftfunc=new boolfunc(*(temp.leftfunc));
     rightfunc=new boolfunc(*(temp.rightfunc));
     return;
   }

   if(r==temp.r)
   {
      *(leftfunc)+=*(temp.leftfunc);
      *(rightfunc)+=*(temp.rightfunc);
   }
   else if(r<temp.r)
   {
     *(leftfunc)+=temp;
     *(rightfunc)+=temp;
   }
   else{
    boolfunc *atemp=new boolfunc(*this);
    r=temp.r;
    delete leftfunc;
    delete rightfunc;
    leftfunc=new boolfunc(*(temp.leftfunc));
    rightfunc=new boolfunc(*(temp.rightfunc));
    *(leftfunc)+=(*atemp);
    *(rightfunc)+=(*atemp);

   }
}

void operator*=(boolfunc const &temp)
{
 if(temp.r==-1)
   {
    return;
   }
   if(temp.r==0)
   {
   r=0;
   delete leftfunc;
   delete rightfunc;
   leftfunc=NULL;
   rightfunc=NULL;
   return;
   }
   else if(r==0)
   {
     return;
   }
   else if(r==-1)
   {
     r=temp.r;
     leftfunc=new boolfunc(*(temp.leftfunc));
     rightfunc=new boolfunc(*(temp.rightfunc));
     return;
   }

   if(r==temp.r)
   {
      *(leftfunc)*=*(temp.leftfunc);
      *(rightfunc)*=*(temp.leftfunc);
   }
   else if(r<temp.r)
   {
     *(leftfunc)*=temp;
     *(rightfunc)*=temp;
   }
   else{
    boolfunc *atemp=new boolfunc(*this);
    r=temp.r;
    delete leftfunc;
    delete rightfunc;
    leftfunc=new boolfunc(*(temp.leftfunc));
    rightfunc=new boolfunc(*(temp.rightfunc));
    *(leftfunc)*=(*atemp);
    *(rightfunc)*=(*atemp);

   }


}


void operator~()
{
 if(r==-1){r=0;return;}
 if(r==0){r=-1;return;}
  boolfunc* alt=new boolfunc(*(leftfunc));
 ~(*(rightfunc));
 ~(*(leftfunc));
 *(alt)*=(*leftfunc);
 *(this)+=*(alt);
  delete alt;
}
bool operator==(boolfunc const &temp)
{
 if(r==0){if(temp.r==0){return true;}
          else return false;}
 else if(r==-1){if(temp.r==-1){return true;}
       else return true;}

  if(r!=temp.r)return false;
  else{
    return ((*leftfunc)==(*rightfunc));
  }
}
void read()
{
int notr,noi;
boolfunc* ate=new boolfunc;
ate->r=0;ate->leftfunc=NULL;ate->rightfunc=NULL;
cin>>notr;
for(int i=0;i<notr;i++)
{
 cin>>noi;
 boolfunc* ate2=new boolfunc;
ate2->r=-1;ate2->leftfunc=NULL;ate2->rightfunc=NULL;
 for(int j=0;j<noi;i++)
 {
   boolfunc* ate1=new boolfunc;
   cin>>ate1->r;
   if(ate1->r>0){ate->leftfunc=new boolfunc();ate->leftfunc->r=0;ate->leftfunc->leftfunc=NULL;ate->leftfunc->rightfunc=NULL;
                ate->rightfunc=new boolfunc();ate->rightfunc->r=-1;ate->rightfunc->leftfunc=NULL;ate->rightfunc->rightfunc=NULL;
                }

    else{ate->leftfunc=new boolfunc();ate->leftfunc->r=-1;ate->leftfunc->leftfunc=NULL;ate->leftfunc->rightfunc=NULL;
        ate->rightfunc=new boolfunc();ate->rightfunc->r=0;ate->rightfunc->leftfunc=NULL;ate->rightfunc->rightfunc=NULL;
        }
        *(ate2)*=(*ate1);
        delete ate1;
 }
 *(ate)+=(*ate2);
 delete ate2;
}
r=ate->r;
leftfunc=ate->leftfunc;
rightfunc=ate->rightfunc;
}


void print();
void subst(int i, bool v);

};
