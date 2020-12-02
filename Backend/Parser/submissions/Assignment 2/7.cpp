#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void f(vector<vector<int> > &A);

int check_line(vector<vector<int> > &A,int i,int k)
{
    int n=A.size(),points=0;
    vector<vector<int> > I,J;
    for(int j=1; j<n; j++)
    {

        if(j==i)
        {
            continue;
        }
        else
        {
            if(((A[j][1]-A[k][1])*(A[i][0]-A[k][0])-(A[i][1]-A[k][1])*(A[j][0]-A[k][0]))>0)

            {
                I.push_back(A[j]);
                if(j<(n/2))
                {
                    points++;
                }
                else
                {
                    points--;
                }

            }
            else
            {
                J.push_back(A[j]);
            }


        }
    }

    if(points==0)
    {
        f(I);
        f(J);
        return 1;
    }
    else
    {

        return 0;

    }

};


void f(vector<vector<int> > &A)
{
    int n=A.size();

    if(n!=0)
    {
        for(int k=0; k<(n/2); k++)
        {
            for(int i=(n/2); i<n; i++)
            {
                if(check_line(A,i,k)==1)
                {
                    cout<<A[0][2]<<" "<<A[i][2]<<endl;
                    return;
                }


            }
        }

    }
    else
    {
        return;
    }
};




int main()
{

    int n;
    cin>>n;

    vector<vector<int> > A;
    for(int i=0; i<n; i++)
    {
        vector<int> M;
        int x,y;
        cin>>x>>y;
        M.push_back(x);
        M.push_back(y);
        if(i<n/2)
        {
            M.push_back(i);
        }
        else
        {
            M.push_back(i-(n/2));
        }
        A.push_back(M);
    }
    f(A);

    return 0;
}
