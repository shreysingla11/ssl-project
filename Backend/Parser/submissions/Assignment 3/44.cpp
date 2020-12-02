#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<int> a(n);
    vector<int> b(m);
    //vector<vector<int> > please(n, vector<int>(m));
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int j=0; j<m; j++)
    {
        cin>>b[j];}
    if(m>n){cout<<"infinity"<<endl;return 0;}
    int c1,c2;
    int maxer;
    int start;
    int ender;
    int lengther;
    maxer=-1;
    vector<bool> test(m);

    for(c1=0;c1<m;c1++){
    for(c2=maxer;c2<n;c2++){
    if(b[c1]==a[c2]){
    if(c1==0){start=c2;}
    if(c1==(m-1)){ender=c2;}
    test[c1]='true';maxer=c2+1;break;}
    }
    }
    if(!test[m-1]){cout<<"infinity"<<endl;return 0;}
    start++;
    ender++;
    lengther=ender-start+1;
    cout<<lengther<<" "<<start<<endl;
    return 0;
    }


