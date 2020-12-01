#include<iostream>
#include<string>
using namespace std;
string toBinary(long long int n);

int main()
{
	int n,s0,s1,error=0,fin=0;
	string s,f="",final;
	long long int a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		s=toBinary(a);
		//cout<<s.size()<<endl;
		//cout<<s<<endl;
        f="";fin=0;error=0;

		for(int j=0;j<5;j++)
		{
            s0=0;s1=0;
			for(int i=j*9;i<9*j+9;i++)
			{

				if(s[i]=='0')
				{
					s0++;
				}
				else{
					s1++;
				}
			}
			//cout<<"out of loop"<<endl;
			if(s0>=5){
				f=f+"0";
				error=error+s1;
			}
			else{
				f=f+"1";
				error=error+s0;
			}
			//cout<<s0<<" "<<s1<<endl;
		}
        //cout<<error<<endl;
		//cout<<"out of loop 2"<<endl;
		if(error<=4){
		//cout<<"inside if"<<endl;
		//cout<<f<<endl;
		for(int i=4;i>=0;i--)
		{
            if(f[i]=='1')
            {
            fin=fin+1;
            }
            fin=fin*2;
		}
		fin=fin/2;
		fin+=97;
		//cout<<fin<<endl;
		cout<<char(fin);
		}
		else{
		cout<<'?';}

	}
}

string toBinary(long long int n)
{
    std::string r;
    while(n!=0) {r=r+(n%2==0 ?"0":"1"); n/=2;}
    //cout<<"first "<<r<<endl;
    for(int i=r.size();i<=44;i++)
    {
    	r=r+"0";
    }
    //cout<<"second "<<r<<endl;
    return r;
}
