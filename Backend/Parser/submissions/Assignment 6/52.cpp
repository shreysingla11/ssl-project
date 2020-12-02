#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;
string a;
int n;
int equals(int index,int l){
	int lower=index+2*l-1;
	int upper=index+3*l-1;
	int c=0,ind=0;
	int j=0;
    if(upper>n)
    return 0;
	for(ind=lower;ind<=upper&&ind<n;)
	{
        if(a[index]==a[ind])
        {
            for(j=0;j<l;j++)
            {
                if(a[index+j]!=a[ind+j])
                {
                    break;
                }
			}
			            if(j==l)
            {
                return ind;
            }
        }
        else
        {

            ind++;
        }
	}

		return 0;
    }




int main()
{
	cin>>a;
	vector<string> b;
	int l;
	n=a.length();
	int aa=0;
	int mins=n;int minsw=0;
	int i=0,k=0;
	for(l=1;l<=(n+4)/8+1;l*=2)
	{
		for(i=0;i<n/l-1;i++){
            k=equals(i*l,l);
            if(k>0){
                int firstlow=i*l;
                int secondlow=k;
                int d=firstlow,b=secondlow;
                int x,y,z,f,g;
                while(a[d]==a[b]&&b>=firstlow+l){
                    x=d;y=b;
                    if(d!=0){
                        d--;b--;
                            }
                    else{

                            x=0;y=b;
                            break;

                        }
                }
                d=firstlow+l;b=secondlow+l;
                z=d-1;f=b-1;
                while(a[d]==a[b] && d<secondlow)
                {   z=d;
                    f=b;
                    if(b!=n-1){
                    d++;b++;
                    }
                    else{
                    z=d;f=b;
                    break;
                    }

                }
                int q,w;

                if(z==y-1){
                q=z-x+1;
                w=x;
                aa=1;
                if(mins>q){
                mins=q;
                minsw=w;}
                }
                }
		}

	}
	if(aa==0){
	cout<<0<<" "<<0<<endl;}
	else
	cout<<mins<<" "<<minsw<<endl;
	return 0;
}
