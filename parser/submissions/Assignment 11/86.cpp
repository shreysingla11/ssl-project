
#include<iostream>
#include<cstdio>
#include<map>
#include<unordered_map>
#include<bitset>
//#include<string>
using namespace std;

int main()
    {
     int n;
     cin>>n;
     //string bin;
     bitset<45> f;
     bitset<5> fin;
     int count;
     int count1,count2;
     char out;
     long int val;
     long long int test;
     for (int con=0;con<n;con++)
        {
         long long int test;
         //test=con;
         scanf("%lld",&test);
         //string bin;
         count=0;
         f=bitset<45>(test);
         //cout<<f.to_ullong();
         count1=0;count2=0;
         for(int i=0;i<9;i++)
            {
             if(f[i]==0){count1++;}
             if(f[i]==1){count2++;}
            }
         if(count1>count2){fin[0]=0;count=count+count2;}
         else{fin[0]=1;count=count+count1;}
         if (count>4){printf("%c",'?');}
         else
            {
             count1=0;count2=0;
             for(int i=9;i<18;i++)
                {
                 if(f[i]==0){count1++;}
                 if(f[i]==1){count2++;}
                }
             if(count1>count2){fin[2]=0;count=count+count2;}
             else{fin[1]=1;count=count+count1;}
             if (count>4){printf("%c",'?');}
             else
                {
                 count1=0;count2=0;
                 for(int i=18;i<27;i++)
                    {
                     if(f[i]==0){count1++;}
                     if(f[i]==1){count2++;}
                    }
                 if(count1>count2){fin[3]=0;count=count+count2;}
                 else{fin[3]=1;count=count+count1;}
                 if (count>4){printf("%c",'?');}
                 else
                    {
                     count1=0;count2=0;
                     for(int i=27;i<36;i++)
                        {
                         if(f[i]==0){count1++;}
                         if(f[i]==1){count2++;}
                        }
                     if(count1>count2){fin[4]=0;count=count+count2;}
                     else{fin[4]=1;count=count+count1;}
                     if (count>4){printf("%c",'?');}
                     else
                        {
                         count1=0;count2=0;
                         for(int i=36;i<45;i++)
                            {
                             if(f[i]==0){count1++;}
                             if(f[i]==1){count2++;}
                            }
                         if(count1>count2){fin[5]=0;count=count+count2;}
                         else{fin[5]=1;count=count+count1;}
                         if (count>4){printf("%c",'?');}
                         else
                            {
                             val=fin.to_ulong();
                             if(val>25){printf("%c",'?');}
                             else{out=char(val+97);printf("%c",out);}
                            }
                        }
                    }
                }
            }
        }
    }
