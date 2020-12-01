#include<iostream>
#include<cstdio>
#include<string>
#include<unordered_map>
#include<bitset>
#include<vector>
using namespace std;
int main()
{
    vector<string> alpha(26), bits(26);
    int i, j, k, l, m;
    long long int n;
    for(i=0; i<26; i++)
    {
        alpha[i]=bitset<5> (i).to_string();
    }
    for(i=0;i<26;i++)
    {
        for(j=0;j<5;j++)
        {
            for(k=0;k<9;k++)
            {
                bits[i]+=alpha[i][j];
            }
        }
    }
    unordered_map <string, char> mymap;
    vector<string> temp;
    string temp2, temp3, temp4, temp5;
    string temp6;
    char t='a';
    for(i=0;i<26;i++)
    {
        mymap[bits[i]]=t+i;
        for(j=0;j<45;j++)
        {
            temp.push_back(bits[i]);
            temp2=*(--temp.end());
            if(temp2[j]=='1') temp2[j]='0';
            else temp2[j]='1';
            mymap[temp2]=t+i;
            for(k=j+1;k<45;k++)
            {
                temp.push_back(temp2);
                temp3=*(--temp.end());
                if(temp3[k]=='1') temp3[k]='0';
                else temp3[k]='1';
                mymap[temp3]=t+i;
                //if(i==2&&j==3&&k==20) cout<<temp3<<endl;
                for(l=k+1;l<45;l++)
                {
                    temp.push_back(temp3);
                    temp4=*(--temp.end());
                    if(temp4[l]=='1') temp4[l]='0';
                    else temp4[l]='1';
                    mymap[temp4]=t+i;
                    for(m=l+1;m<45;m++)
                    {
                        temp.push_back(temp4);
                        temp5=*(--temp.end());
                        if(temp5[m]=='1') temp5[m]='0';
                        else temp5[m]='1';
                        mymap[temp5]=t+i;
                    }
                }
            }
        }
    }
    //cout<<"Hello"<<endl;
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
    scanf("%lld",&n);
    temp6=bitset<45> (n).to_string();
    t=mymap[temp6];
    //cout<<sizeof(t)<<endl;
    if(t<='z'&&t>='a')   printf("%c",t);
    else printf("?");
    }
    return 0;
}
