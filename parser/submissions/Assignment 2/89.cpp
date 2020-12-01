# include <iostream>
# include <vector>
using namespace std;

void midline (int &cnt, vector<int>& redx, vector<int>& bluex, vector<int>& redy,
vector<int>& bluey, vector<char>& dirred, vector<char>& dirblue,
vector<int>& solred, int n, char dir)
{
    if(cnt>=n){return;}

    int t=0;
    while(dirred[t]!=dir&&dirred[t]==-1&&t<n)   {
        t++;
    }
    if(t>2) {return;}
    int x1=redx[t],y1=redy[t],x2,y2;
    bool check=false;
    int i=0,j=0,a,b,c;
    int countred=0,countblue=0;
    while(!check&&i<n)    {
        if(dirblue[i]==dir) {
            x2=bluex[i],y2=bluey[i];
            a=y2-y1;
            b=x1-x2;
            c=(-1*y1*b)+(-1*x1*a);
            j=0;
            countred=0,countblue=0;
            while(j<n)  {
                if(a*redx[j]+b*redy[j]+c>0)
                    {countred++;
                    dirred[j]=1;}
                else {dirred[j]=0;}
                if(a*bluex[j]+b*bluey[j]+c>0)
                    {countblue++;
                    dirblue[j]=1;}
                else {dirblue[j]=0;}
                j++;
            }

            if (countred==countblue)
                {check=true;}
            else
                {check=false;}
            i++;
        }
        else    {
            i++;
        }
    }
    if(check=false) {return;}
    if(dirblue[i-1]==-1){return;}

    solred[t]=i-1;
    dirred[t]=-1;dirblue[i-1]=-1;
    cnt++;

    midline( cnt, redx, bluex, redy, bluey, dirred, dirblue, solred, n, 1);
    midline( cnt, redx, bluex, redy, bluey, dirred, dirblue, solred, n, 0);
    return;
}

int main() {
    int n;
    cin>>n;
    n=n/2;
    vector<int> redx(n);
    vector<int> bluex(n);
    vector<int> redy(n);
    vector<int> bluey(n);
    vector<char> dirred(n,1);
    vector<char> dirblue(n,1);
    vector<int> solred(n,1);
    int cnt=0;
    int i=0;
    while(i<n)  {
        cin>>redx[i];
        cin>>redy[i];
        i++;
    }
    i=0;
    while(i<n)  {
        cin>>bluex[i];
        cin>>bluey[i];
        i++;
    }

    midline( cnt, redx, bluex, redy, bluey, dirred, dirblue, solred, n, 1);

    i=0;
    while(i<n)  {
        cout<<i<<" "<<solred[i]<<endl;
        i++;
    }
    return 0;
}
