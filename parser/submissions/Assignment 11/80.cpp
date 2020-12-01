#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdio>
using namespace std;
int main()
{
    long long pow_2[45],val[26],temp,powsum[5];
    int a[26][5],carry;
    char ch[26],c;

    unordered_map<long long,char> mymap;

    int i,j,k,l,s;

    temp=1;

    for(i=0; i<45; i++)
    {
        pow_2[i]=temp;
        temp=temp*2;
       // cout<<pow_2[i]<<" "<<i<<endl;

    }

    c='a';

    for(i=0; i<26; i++)
    {
        ch[i]=c;
        c=c+1;

    }

    a[0][0]=0;
    a[0][1]=0;
    a[0][2]=0;
    a[0][3]=0;
    a[0][4]=0;

    for(i=1; i<26; i++)
    {
        carry=1;
        for(j=0; j<5; j++)
        {
            if(a[i-1][j]==0)
            {
                if(carry==0)
                {
                    a[i][j]=0;
                }
                else
                {
                    a[i][j]=1;
                    carry=0;
                }
            }
            else
            {
                if(carry==1)
                {
                    a[i][j]=0;
                    carry=1;
                }
                else
                {
                    a[i][j]=1;
                }
            }
        }
    }

    long long sum=0;

    for(i=0; i<5; i++)
    {
        sum=0;
        for(j=0; j<9; j++)
        {
            sum=sum+pow_2[j+9*i];
        }
        powsum[i]=sum;
        //cout<<sum<<endl;
    }

    c='a';

    for(i=0; i<26; i++)
    {
        sum=0;
        for(j=0; j<5; j++)
        {
            if(a[i][j]==1)
            {
                sum=sum+powsum[j];
            }
        }
        val[i]=sum;
        //      cout<<sum<<endl;
    }

    long long err;

    for(s=0; s<26; s++)
    {
        err=0;
        for(i=0; i<45; i++)
        {
            for(j=i+1; j<45; j++)
            {
                for(k=j+1; k<45; k++)
                {
                    for(l=k+1; l<45; l++)
                    {
                    err=0;
                        if(a[s][i/9]==0)
                        {
                            err=err+pow_2[i];
                        }
                        else
                        {
                            err=err-pow_2[i];
                        }
                        if(a[s][j/9]==0)
                        {
                            err=err+pow_2[j];
                        }
                        else
                        {
                            err=err-pow_2[j];
                        }
                        if(a[s][k/9]==0)
                        {
                            err=err+pow_2[k];
                        }
                        else
                        {
                            err=err-pow_2[k];
                        }
                        if(a[s][l/9]==0)
                        {
                            err=err+pow_2[l];
                        }
                        else
                        {
                            err=err-pow_2[l];
                        }

                        mymap[val[s]+err]=ch[s];


                    }
                }
            }
        }
    }

    for(s=0; s<26; s++)
    {
        err=0;
        for(i=0; i<45; i++)
        {
            for(j=i+1; j<45; j++)
            {
                for(k=j+1; k<45; k++)
                {
                err=0;


                    if(a[s][i/9]==0)
                    {
                        err=err+pow_2[i];
                    }
                    else
                    {
                        err=err-pow_2[i];
                    }
                    if(a[s][j/9]==0)
                    {
                        err=err+pow_2[j];
                    }
                    else
                    {
                        err=err-pow_2[j];
                    }
                    if(a[s][k/9]==0)
                    {
                        err=err+pow_2[k];
                    }
                    else
                    {
                        err=err-pow_2[k];
                    }

                    mymap[val[s]+err]=ch[s];



                }
            }
        }
    }

int m;

    for(s=0; s<26; s++)
    {

        for(i=0; i<45; i++)
        {
            for(j=i+1; j<45; j++)
            {
            err=0;


                if(a[s][i/9]==0)
                {
                    err=err+pow_2[i];
                }
                else
                {
                    err=err-pow_2[i];
                }
               // cout<<err<<" here"<<endl;
                if(a[s][j/9]==0)
                {
                    err=err+pow_2[j];
                }
                else
                {
                    err=err-pow_2[j];
                }


                mymap[val[s]+err]=ch[s];




            }
        }
    }



    for(s=0; s<26; s++)
    {
        err=0;
        for(i=0; i<45; i++)
        {
             err=0;
            if(a[s][i/9]==0)
            {
                err=err+pow_2[i];
            }
            else
            {
                err=err-pow_2[i];
            }



            mymap[val[s]+err]=ch[s];


        }
    }

    for(s=0; s<26; s++)
    {

        mymap[val[s]]=ch[s];

    }
    //cout<<"?";

    long long in;
    unordered_map<long long ,char>::iterator it,it1;
    it1=mymap.end();
    int t;
    cin>>t;
    for(i=0; i<t; i++)
    {
        scanf("%lld",&in);
        it=mymap.find(in);
        if(it==it1)
        {
       // cout<<"?";
       printf("?");
        }
        else
        {
           //cout<<it->second;
           printf("%c",it->second);
        }
    }
cout<<endl;

    return 0;
}
