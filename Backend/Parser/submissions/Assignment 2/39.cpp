#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool is_inter(vector< vector<int> > &red,vector< vector<int> > &blue,vector<int> &pairing,int i,int j)
{
    if(blue[pairing[i]][0] == red[i][0])
    {
        if(blue[pairing[j]][0]==red[j][0])
        {
            return false;
        }
        else
        {
            float m2inf = ((blue[pairing[j]][1]-red[j][1])*(1.0))/(blue[pairing[j]][0]-red[j][0]);
            float c2inf = red[j][1]*1.0 - m2inf*red[j][0];
            float yintinf = m2inf*red[i][0]+c2inf;
            float ychecker1inf = (yintinf-red[i][1]*1.0)*(yintinf-blue[pairing[i]][1]);
            float ychecker2inf = (yintinf-red[j][1]*1.0)*(yintinf-blue[pairing[j]][1]);
            if(ychecker1inf<0&ychecker2inf<0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    if(blue[pairing[j]][0] == red[j][0])
    {

            float m1inf = ((blue[pairing[i]][1]-red[i][1])*(1.0))/(blue[pairing[i]][0]-red[i][0]);
            float c1inf = red[i][1]*1.0 - m1inf*red[i][0];
            float yintinf2 = m1inf*red[j][0]+c1inf;
            float ychecker1inf2 = (yintinf2-red[i][1]*1.0)*(yintinf2-blue[pairing[i]][1]);
            float ychecker2inf2 = (yintinf2-red[j][1]*1.0)*(yintinf2-blue[pairing[j]][1]);
            if(ychecker1inf2<0&ychecker2inf2<0)
            {
                return true;
            }
            else
            {
                return false;
            }

    }
    float m1 = ((blue[pairing[i]][1]-red[i][1])*(1.0))/(blue[pairing[i]][0]-red[i][0]);
    float m2 = ((blue[pairing[j]][1]-red[j][1])*(1.0))/(blue[pairing[j]][0]-red[j][0]);
    float c1 = red[i][1]*1.0 - m1*red[i][0];
    float c2 = red[j][1]*1.0 - m2*red[j][0];
    float xint = (c2-c1)/(m1-m2);
    float checker1 = (xint-red[i][0]*1.0)*(xint-blue[pairing[i]][0]);
    float checker2 = (xint-red[j][0]*1.0)*(xint-blue[pairing[j]][0]);
    if(checker1<0&checker2<0)
    {
        return true;
    }
    else
    {
        return false;
    }
    /*if((red[i][0]<xint&&xint<blue[pairing[i]][0])||(red[i][0]>xint&&xint>blue[pairing[i]][0]))
    {
        return true;
    }
    else
    {
        return false;
    }*/
}
int main()
{
    int n;
    cin>>n;
    n = n/2;
    vector< vector<int > > red(n,vector<int> (2));
    for(int i = 0; i<n; i++)
    {
        cin>>red[i][0];
        cin>>red[i][1];
    }
    vector< vector<int> > blue(n,vector<int> (2));
    for(int i = 0; i<n; i++)
    {
        cin>>blue[i][0];
        cin>>blue[i][1];
    }
    vector<int> pairing(n);
    for(int i = 0; i<n; i++)
    {
        pairing[i] = i;
    }
    for(int top = 1; top<n; top++)
    {
        for(int bot = 0; bot<top; bot++)
        {
            if(is_inter(red,blue,pairing,bot,top)==false)
            {

            }
            else
            {
                int temp = pairing[top];
                pairing[top] = pairing[bot];
                pairing[bot] = temp;
                top = bot-1;
                break;
            }
        }
    }
    for(int k = 0; k<n; k++)
    {
        cout<<k<<" "<<pairing[k]<<endl;
    }
    return 0;
}
