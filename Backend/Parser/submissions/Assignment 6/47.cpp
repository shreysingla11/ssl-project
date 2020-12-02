#include<iostream>
#include<string>
using namespace std;





int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int stop0=0;
    for(int l=1;(l<=((n+2)/4))&&(stop0==0);l=l*2)
    {
        int stop1=0;
        //cout<<"l: "<<l<<endl;
        for(int block=0;(block<(n/l)-1)&&(stop1==0);)//Not considering last block
        {
            //cout<<"block: "<<block<<endl;
            int foundblock=0,j,i;
            for(int searching=(block+2)*l-1;(searching<((block+4)*l-1))&&(searching<n);)
            {
                //cout<<"searching: "<<searching<<endl;
                for(j=searching,i=block*l;(j<searching+l)&&(j<n);)
                {
                    //cout<<"i: "<<i<<" j: "<<j<<endl;
                    if(s[i]==s[j])
                    {
                        if(i==(block+1)*l-1)
                        {
                            foundblock=1;
                            //cout<<"Found here "<<s[i]<<s[j]<<endl;
                            //cout<<"j: "<<j<<" search: "<<searching<<" l: "<<l<<endl;
                            //cout<<"block: "<<block<<endl;
                            break;
                        }
                        else
                        {
                            i++;
                            j++;
                        }
                    }
                    else
                    {
                        j++;
                        i=block*l;
                    }
                }
                if(foundblock==1){break;}//check again
                else{searching=j;}
            }
            if(foundblock==1)
            {
                //cout<<"Hi "<<l<<endl;
                int leftStart=block*l;
                int leftEnd=leftStart+l-1;
                int rightEnd=j;
                int rightStart=j-l+1;
                int p=leftStart-1;
                int r=leftEnd+1;
                int q=rightStart-1;
                int t=rightEnd+1;
                while((p>=0)&&(q!=leftEnd))
                {
                    if(s[p]==s[q])
                    {
                        p--;
                        q--;
                    }
                    else{break;}
                }
                int gotill=q-leftEnd;
                p++;q++;
                if(gotill==0){
                    //cout<<"found1"<<endl;
                    stop1=1;stop0=1;
                    cout<<"ans: "<<q-p<<" "<<p<<endl;return 0;
                }
                while((r!=q)&&(t<n))
                {
                    if(s[r]==s[t])
                    {
                        r++;
                        t++;
                    }
                    else{break;}
                }
                if(r==q){
                    //cout<<"found3 "<<" s[p] "<<s[p]<<" s[q] "<<s[q]<<" s[r] "<<s[r-1]<<" s[t] "<<s[t-1]<<endl;stop1=1;stop0=1;
                    cout<<"ans: "<<q-p<<" "<<p<<endl;return 0;
                }
                else{block++;}
            }
            else
            {
                block++;
            }
        }

    }
    cout<<0<<" "<<0<<endl;

    return 0;
}
