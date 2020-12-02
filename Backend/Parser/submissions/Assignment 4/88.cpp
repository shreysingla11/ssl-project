#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)


using namespace std;


class counter{
//public:


class list_obj{
public:
int size1;
int count;
int index;
list <list_obj>::iterator m_it;
list <list<list_obj> >::iterator list_it;
};


int n1;
list <list_obj>::iterator m_zero;
/**m_zero  contains the index of zero count**/
vector <list<list_obj>::iterator > it2m;
/**it2m stores the [0 n-1] ojects**/
list <list_obj> m_list;
/**m_list is the main list containing counts**/
list <list<list_obj> > sc;
/**sc is the list of lists of elements with same counts**/

public:
counter(int n){
    n1=n;
list_obj curr;
curr.count=0;
curr.size1=n;
/**curr.list_it is yet to be initialised**/
m_list.push_back(curr);
list<list_obj> zc;
/**zerocount numbers list**/

/**initializing m_zero for use in reset()**/
m_zero=m_list.begin();

/**initialising zc**/
list_obj zero;
zero.m_it=m_list.begin();
sc.push_back(zc);
for(int i=0;i<n;i++){
zero.index=i;
zero.count=0;
//zc.push_back(zero);
(*sc.begin()).push_back(zero);
it2m.push_back(--((*sc.begin()).end()));
}
//sc.push_back(zc);
(*m_list.begin()).list_it=sc.begin();
/**curr.list_it is initialised**/


/**testing**/

/**testing done**/
}

void increment(int i){

list_obj currm,currs,nexm,temp;
list <list_obj>::iterator cmit,csit,nmit;
list <list_obj> nwli;
list <list <list_obj> >::iterator proc;
csit=it2m[i];
currs=*csit;
cmit=currs.m_it;
currm=*cmit;
nmit=cmit;
nmit++;
nexm=*nmit;
/**if nmit is not end() this is fine
and so we use this only in case 2**/


/**CASE 1 AND 3**/
if(nmit==m_list.end()||(nexm.count>currm.count+1)){

    /**create in sc**/
    sc.push_back(nwli);
    /**insert in m_list**/
    /**link m_list to this new list**/
    temp.index=-1;
    temp.size1=1;
    temp.count=currm.count+1;
    temp.list_it=sc.end();
    temp.list_it--;
    temp.m_it=m_list.end();/**not required just for error checking**/
    if(nmit==m_list.end())m_list.push_back(temp);
    else{if(nexm.count>currm.count+1)m_list.insert(nmit,temp);
    }
}


/**CODE COMMON FOR ALL THE CASES**/
    /** insert in new list along with link to m_list **/
    temp.index=i;
    temp.count=currs.count+1;
    //temp.list_it=nwli.end();/**not required just for error checking**/
    nmit=cmit;
    nmit++;
    temp.m_it=nmit;
    proc=sc.end();
    proc--;
    //if(!(nmit==m_list.end()||(nexm.count>currm.count+1)))
    if((nexm.count==currm.count+1))
    /**if the list already exists then insert in the existing list**/
    {
        proc=nexm.list_it;
        /**increasing the size of list**/
        (*nmit).size1++;
    }

    (*proc).push_back(temp);

    /**delete from old list*/
    (*currm.list_it).erase(csit);
    (*cmit).size1--;
    if(currm.count!=0)if((*cmit).size1==0)m_list.erase(cmit);
    /**link vector to new positoin**/
    it2m[i]=(*proc).end();
    it2m[i]--;

}


void decrement(int i){

list_obj currm,currs,nexm,temp;
list <list_obj>::iterator cmit,csit,nmit;
list <list_obj> nwli;
list <list <list_obj> >::iterator proc;
csit=it2m[i];
currs=*csit;
cmit=currs.m_it;
currm=*cmit;
nmit=cmit;
nmit--;
nexm=*nmit;
/**if nmit is not end() this is fine
and so we use this only in case 2**/


/**CASE 1 AND 3**/
if(nmit==--m_list.begin()||(nexm.count<currm.count-1)){

    /**create in sc**/
    sc.push_back(nwli);
    /**insert in m_list**/
    /**link m_list to this new list**/
    temp.index=-1;
    temp.size1++;
    temp.count=currm.count-1;
    //cout<<temp.count<<"te "<<temp.size1<<endl;

    temp.list_it=sc.end();
    temp.list_it--;
    temp.m_it=m_list.end();/**not required just for error checking**/
    if(nmit==--m_list.begin())m_list.push_front(temp);
    else{if(nexm.count<currm.count-1)m_list.insert(cmit,temp);
    }
}


/**CODE COMMON FOR ALL THE CASES**/
    /** insert in new list along with link to m_list **/
    temp.index=i;
    temp.count=currs.count-1;
    //temp.list_it=nwli.end();/**not required just for error checking**/
    nmit=cmit;
    nmit--;
    temp.m_it=nmit;
    proc=sc.end();
    proc--;
    /**if the list already exists then insert in the existing list**/
    if(!(nmit==--m_list.begin()||(nexm.count<currm.count-1)))
    if(nexm.count==currm.count-1)
    {
        (*nmit).size1++;
        proc=nexm.list_it;
        //cout<<nexm.count<<"ne "<<nexm.size1<<endl;

    }
    (*proc).push_back(temp);

    /**delete from old list*/
    (*currm.list_it).erase(csit);
    (*cmit).size1--;
    if(currm.count!=0)if((*cmit).size1==0)m_list.erase(cmit);

    /**link vector to new positoin**/
    it2m[i]=(*proc).end();
    it2m[i]--;
}


int count(int i){
list_obj currs;
list <list_obj>::iterator csit;
csit=it2m[i];
currs=*csit;
    return currs.count;
}

int findMax(){
//int ans=m_list.back().count;
    list_obj pr_list=m_list.back();
            //cout<<"yo "<<pr_list.size1<<endl;
    /**correction for not deleting the m_zero**/
    if(pr_list.size1==0){
        pr_list=*(--(--m_list.end()));
        //pr_list=*(com.list_it);
        }

return pr_list.count;
}

int numMax(){

list_obj pr_list=m_list.back();
            //cout<<"yo "<<pr_list.size1<<endl;
    /**correction for not deleting the m_zero**/
    if(pr_list.size1==0){
            //cout<<"yo "<<pr_list.size1<<endl;
        pr_list=*(--(--m_list.end()));
        //pr_list=*(com.list_it);
        }

return pr_list.size1;
}

void printMax(){
    list <list_obj> pr_list=(*m_list.back().list_it);

    /**correction for not deleting the m_zero**/
    if(pr_list.size()==0){
        list_obj com=*(--(--m_list.end()));
        pr_list=*(com.list_it);}

list< list_obj>::iterator it=pr_list.begin();
while(it!=pr_list.end()){
    cout<<(*it).index<<" ";
    it++;
}
cout<<endl;

}

void reset(int i){


    list_obj currm,currs,nexm,temp;
    list <list_obj>::iterator cmit,csit,nmit;

csit=it2m[i];
currs=*csit;
cmit=currs.m_it;
currm=*cmit;
nmit=cmit;
nmit--;
nexm=*nmit;

    temp.index=i;
    temp.count=0;
    temp.m_it=m_zero;
    (*(*m_zero).list_it).push_back(temp);

    /**delete from old list*/
    (*currm.list_it).erase(csit);
    if(currm.count!=0)if((*cmit).size1==0)m_list.erase(cmit);
    /**link vector to new position**/
    it2m[i]=(*(*m_zero).list_it).end();
    it2m[i]--;

}

};
