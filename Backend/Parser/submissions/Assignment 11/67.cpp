#include<iostream>
using namespace std;
#include<unordered_map>
#include<cmath>
#include<vector>
#include<cstdio>

void print(vector<int> a)
{
    for(int i=0; i<a.size();i++)
    {
        cout<<a[i];
    }
    cout<<endl;
}

long long int binarytodecimal(vector<int> a)
{
    long long int b=0;
    for(int i=0;i<45;i++)
    {
        b+= a[44-i]*pow(2,i);
    }
    return b;
}

int main()
{
    unordered_map <long long int,char> finalmap;
//    unordered_map a;
    for(int s=0; s<26; s++)
    {
        vector<int> fivebit;
        int rem=4;
        vector<int> longbinary;
        fivebit.resize(5,0);
        longbinary.resize(45);
        int scopy=s;
        while(scopy!=0)
        {
            fivebit[rem]=scopy%2;
            scopy=scopy/2;
            rem--;
        }
        for(int m=0; m<5;m++)
        {
            for(int n=0; n<9;n++)
            {
                longbinary[m*9 +n]= fivebit[m];
            }
        }
        /*for(int i=0; i<46; i++)
        {
            if(i==45)
            {
                longbinary[i]= 1- longbinary[i];
                finalmap[binarytodecimal(longbinary)]=char(s+97);
                //cout<<binarytodecimal(longbinary)<<endl;
                longbinary[i]= 1- longbinary[i];
                break;
            }
            if(longbinary[i]==0)
            {
                longbinary[i]= 1- longbinary[i];
            }
            else
            {

            }
            for(int j=i+1; j<46; j++)
            {
                if(j==45)
                {
                    longbinary[j]= 1- longbinary[j];
                    finalmap[binarytodecimal(longbinary)]=char(s+97);
                    //cout<<binarytodecimal(longbinary)<<endl;
                    longbinary[j]= 1- longbinary[j];
                    break;
                }
                longbinary[j]= 1- longbinary[j];
                for(int k=j+1;k<46;k++)
                {
                    if(k==45)
                    {
                        longbinary[k]= 1- longbinary[k];
                        finalmap[binarytodecimal(longbinary)]=char(s+97);
                        //cout<<binarytodecimal(longbinary)<<endl;
                        longbinary[k]= 1- longbinary[k];
                        break;
                    }
                    longbinary[k]= 1- longbinary[k];
                    for(int l=k+1; l<46;l++)
                    {
                        if(l==45)
                        {
                            longbinary[l]= 1- longbinary[l];
                            finalmap[binarytodecimal(longbinary)]=char(s+97);
                            //cout<<binarytodecimal(longbinary)<<endl;
                            longbinary[l]= 1- longbinary[l];
                            break;
                        }
                        longbinary[l]= 1- longbinary[l];
                        finalmap[binarytodecimal(longbinary)]=char(s+97);
                        //cout<<binarytodecimal(longbinary)<<endl;
                        longbinary[l]= 1- longbinary[l];
                    }
                    longbinary[k]= 1- longbinary[k];
                }
                longbinary[j]= 1- longbinary[j];
            }
            longbinary[i]= 1- longbinary[i];
        }*/

            long long int b=binarytodecimal(longbinary);
			finalmap[b]=(char(s+97));
			for (int j=0;j<45;++j)
			{
				long long int value1=b^((long long int)1<<j);
				finalmap[value1]=(char(s+97));
				int k=j+1;
				while(k<45)
				{
                    long long int value2=b^((long long int)1<<j)^((long long int)1<<k);
					finalmap[value2]=(char(s+97));
					int l=k+1;
					while(l<45)
					{
                        long long int value3=b^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l);
						finalmap[value3]=(char(s+97));

						for(int m = l+1; m<45; ++m){
							long long int value4=b^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l)^((long long int)1<<m);
							finalmap[value4]=(char(s+97));
							// if()
						}
                        l++;
					}

                    k++;
				}

			}

    }
    int n;
    scanf("%d",&n);
    long long int x;
    unordered_map<long long int,char>::iterator iter;
    for(int i=0; i<n;i++)
    {
        //cin>>x;
        scanf("%lld",&x);
        iter=finalmap.find(x);
        if(iter==finalmap.end())
        {
            printf("?");
            //cout<<"?";
        }
        else printf("%c",iter->second);
    }
    return 0;
}
