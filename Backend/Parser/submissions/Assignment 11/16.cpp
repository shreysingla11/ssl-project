#include<iostream>
#include<bitset>
#include<string>
#include<cstdio>
#include<unordered_map>
using namespace std;

typedef unordered_map<long long int,char> decodemap;

string tobinary(long long int n)
{
    string r;
    while(n!=0)
    {
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    return r;
}
/*long long int tobinary(long long int n)
{//conversion of decimal to binary
    long long int r=0,t=1;
    while(n!=0)
    {
        if(n%2==0)
        {
            r=r+t*0;
        }
        else
        {
            r=r+t*1;
        }
//r=r+ t*(n%2==0 ?"0":"1");
        t=t*10;
        n=n/2;
    }
    return r;
}

long long int twop[45];
    twop[0]=1;
    for(int i=1; i<45; i++)
    {
        twop[i]=twop[i-1]*2;
        //cout<<twop[i]<<endl;
    }*/
long long int strtolli(string p)
{
    long long int i=0;
    for(int j=0;j<45;j++)
    {
        i=i*2+(p[j]-'0');
    }
}
int main()
{
    //int n;
    decodemap mymap;
    string s,temp;
    long long int ans;
    char alpha='a';
        //decodemap::hasher fn = mymap.hash_function();
    //cout<<fn(1231232);


    for(int i=0; i<26; i++)
    {
        bitset<5> a(i);
        s=a.to_string();
        //cout<<s[4]<<endl;
        string curr="";
           //long long int ans;
        //cout<<curr<<endl;
        for(int j=0; j<5; j++)
        {
            for(int k=0; k<9; k++)
            {
                curr+=s[j];
                //cout<<curr<<endl;
            }
        }
        ans=strtolli(curr);
        mymap[ans]=alpha;
        //cout<<curr<<endl;
        for(int l=0; l<45; l++)
        {
            for(int m=l+1; m<45; m++)
            {
                for(int n=m+1; n<45; n++)
                {
                    for(int p=n+1; p<45; p++)
                    {
                        temp=curr;
                        if(temp[p]=='0')
                        {
                            temp[p]='1';
                        }
                        else
                        {
                            temp[p]='0';
                        }

                        if(temp[n]=='0')
                        {
                            temp[n]='1';
                        }
                        else
                        {
                            temp[n]='0';
                        }
                        if(temp[m]=='0')
                        {
                            temp[m]='1';
                        }
                        else
                        {
                            temp[m]='0';
                        }
                        if(temp[l]=='0')
                        {
                            temp[l]='1';
                        }
                        else
                        {
                            temp[l]='0';
                        }
                        ans=strtolli(temp);
                        mymap[ans]=alpha;
                    }
                }
            }
        }
        for(int m=0; m<45; m++)
            {
                for(int n=m+1; n<45; n++)
                {
                    for(int p=n+1; p<45; p++)
                    {
                        temp=curr;
                        if(temp[p]=='0')
                        {
                            temp[p]='1';
                        }
                        else
                        {
                            temp[p]='0';
                        }

                        if(temp[n]=='0')
                        {
                            temp[n]='1';
                        }
                        else
                        {
                            temp[n]='0';
                        }
                        if(temp[m]=='0')
                        {
                            temp[m]='1';
                        }
                        else
                        {
                            temp[m]='0';
                        }
                        ans=strtolli(temp);
                        mymap[ans]=alpha;
                    }
                }
            }

        for(int n=0; n<45; n++)
                {
                    for(int p=n+1; p<45; p++)
                    {
                        temp=curr;
                        if(temp[p]=='0')
                        {
                            temp[p]='1';
                        }
                        else
                        {
                            temp[p]='0';
                        }

                        if(temp[n]=='0')
                        {
                            temp[n]='1';
                        }
                        else
                        {
                            temp[n]='0';
                        }
                        ans=strtolli(temp);
                        mymap[ans]=alpha;
                    }
                }
                for(int p=0; p<45; p++)
                    {
                        temp=curr;
                        if(temp[p]=='0')
                        {
                            temp[p]='1';
                        }
                        else
                        {
                            temp[p]='0';
                        }
                        ans=strtolli(temp);
                        mymap[ans]=alpha;
                        //cout<<mymap[ans]<<endl;
                    }
        alpha++;
    }

    int n;
    cin>>n;
    long long int inp;
    for(int i=0;i<n;i++){
     cin>>inp;
     unordered_map<long long int,char>:: iterator getit=mymap.find(inp);
     if(getit==mymap.end()){
        char q='?';
        printf("%c",q);
     //cout<<"?";
     }
     else{
        char an=getit->second;
        printf("%c",an);
     //cout<<getit->second;
     }
    }
    //cout<< tobinary(527);
    //long long int
    return 0;
}


/*void Convert(long long int val)
{
   long long int mask = 1 << (sizeof(int) * 8 - 1);

   for(int i = 0; i < sizeof(int) * 8; i++)
   {
      if( (val & mask) == 0 )
         cout << '0' ;
      else
         cout << '1' ;

      mask  >>= 1;
   }
   cout << endl ;
}

int main()
{
   //for(unsigned int i = 0; i < 128; i++)
      Convert(50002020202);
}*/
