#include <iostream>

#include<vector>
#include<algorithm>
#include<cstdio>
#include<unordered_map>

using namespace std;

int get_input_bits(int input)
{
   int input_bits=0;
   int temp=1;
   for(;input>=1;input/=2)
   {
     int temp2=input%2;
     input_bits = temp*temp2 + input_bits;
     temp=temp*10;
    }

    return input_bits;
}

long long int get_big_integer(int k)
{
  long long int n=0;

  int temp=get_input_bits(k);

  int A[5];
  //int p=10;

  for(int i=4;i>=0;i--)
  {
    A[i]=temp%10;
    temp=temp/10;
  }

  for(int i=0;i<5;i++)
  {
        if(A[i]==1)
        {
            long long int temp1=511;
            int temp2=512;
            for(int j=0;j<4-i;j++)
            {
              temp1=temp1*temp2;
            }
            n=n+temp1;
        }
        else continue;
  }

  return n;

}

struct func
{

    long long operator()(long long const i) const
    {
      long long int key=0;
      long long int temp=i;
      int errors=0;
      int loop=0;

      while(temp>0)
      {
        int temp2=temp%512;
        int temp3=get_input_bits(temp2);
        int temp4=temp3;
        //int errors=0;
        int no_of_1s=0;

        for(int j=0;j<9;j++)
        {
           if(temp4%10==1) no_of_1s++;
           temp4/=10;
        }

        if(no_of_1s>=5)
        {
          errors=errors+9-no_of_1s;
          long long int temp5=511;
          int temp6=512;
          for(int j=0;j<loop;j++)
            {
              temp5=temp5*temp6;
            }
          key=key+temp5;
        }

        else
        {
          errors=errors+no_of_1s;
        }

        if(errors>=5)
        {
          return -1;
        }

        temp=temp/512;
      }

      return key;

    }

};


int main(){

func f;

int i=27;
//long long int j=get_input_bits(i);

//cout<<j;

unordered_map<long long int,char,func> codes;

for(int i=0;i<26;i++)
{
  long long int temp = get_big_integer(i);
  codes.insert(pair<long long int,char>(temp,(char)(i+97)));
  //cout<<endl<<temp<<"   "<<(char)(i+97);
}

int n;
cin>>n;
for(int j=0;j<n;j++)
{
  long long int temp;
  cin >> temp;
  long long int temp2;
  temp2=f(temp);

  if(codes.count(temp2)>0)
  {
     cout<<codes[temp2];
  }

  else
  {
     cout<<"?";
  }
}

return 0;
}
