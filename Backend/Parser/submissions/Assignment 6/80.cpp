
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main()
{
string seq;
cin>>seq;
int l=0,shortest_i=0,length=0;
for(l=1;l<seq.size();l*=2)
{int i=1,k=0,j=0,block,start1=0,start2=0,end1=0,end2=0,counter=0;
int n = seq.size()/(l);
bool blockmatch=false,biggerblockmatch=false;
    for(block=1;block<n-l;block+=l)
    {    counter=0;
        for(i=block,j=block+2*l;(j<block+4*l)&&(i<block+l);i++,j++)
        {        counter++;
            if(seq[i-1]!=seq[j-1]){j=j;
                                    k=j;
                                    i=block-1;}
        }
        if((i==block+l)&&(j<block+4*l)){blockmatch=true;break;}
    }

if(blockmatch){ start1=i-1,end1=i-1+l,start2=k;

for(i=0;i<seq.size();i++)
{
if(seq[end1+i+1-1]==seq[start2+l-1+i+1-1]){k=i;break;}
}
int end2=start2+l-1+k+1-1;
for(i=0;;i++)
{
if(seq[start1-(i+1)-1]!=seq[start2-(i+1)-1]){if((start2-i-1)==end1){biggerblockmatch=true;break;}
                                                start1=start1-i;
                                                start2=start2-i;
                                                break;}
}
}

if(biggerblockmatch){
                    shortest_i=start1-i-1;
                    length=(end1+i)-start1+i+1;
                    break;}
}


cout<<length<<" "<<shortest_i<<endl;
return 0;
}
