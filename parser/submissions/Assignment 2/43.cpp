#include <iostream>
#include <vector>
using namespace std;

int number_of_points(vector<vector<int> > &red, vector<vector<int> > &blue, int i, int j, int sign, vector<vector<int> > &red_l, vector<vector<int> > &blue_l, int n)
{
    i=red[i][2];
    int res, nbl=0, nrl=0, nbr=0, nrr=0;
    cout << "a" << endl;
    int x1=red[i][0], y1=red[i][1];
    cout << endl;
    int x2=blue[j][0], y2=blue[j][1];
    cout << "a" << endl;

    cout << "a" << endl;
    int eq1,eq2;
    for (int a=0;a<n;a++)
    {
        eq1=red[a][1]-y1 - (y2-y1)*(red[a][0]-x1)/(x2-x1);
        if ((eq1*sign<0)&&(red[a][2]!=j))
        {
            red_l[nrl][0]=red[a][0];
            red_l[nrl][1]=red[a][1];
            red_l[nrl][2]=red[a][2];
            nrl++;
        }
        eq2=blue[i][1]-y1 - (y2-y1)*(blue[i][0]-x1)/(x2-x1);
        if (eq2*sign<0)
        {
            blue_l[nbl][0]=blue[i][0];
            blue_l[nbl][1]=blue[i][1];
            blue_l[nbl][2]=blue[i][2];
            nbl++;
        }
    }
    if (nrl==nbl)
    {
        if (nrl==0)
            {res=2;}
        else res=1;
    }
    else
        res=0;
    return res;
}

int f (vector<vector<int> > &red, vector<vector<int> > &blue, vector<vector<int> > &answer , int n)
{
    int res, nl, nr, a, i,  j, flag;
    vector<vector<int> > red_r, blue_r, red_l, blue_l;
    nl=nr=0;
    // For storing return value of number_of_points()
    cout << n << endl;
    int nresl, nresr;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            flag=0;
            // For increasing j, when jth element of blue is already paired with a red point in answer
            if (!answer.empty())
            {
                for (a=0;a<answer.size();a++)
                {
                    if (blue_l[j][2]==answer[1][a])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if (flag==1)
            {
                continue;
            }
            //
            // For comparing number of points
            nresl=number_of_points(red, blue, i, j, 1, red_l, blue_l,n);
            nresr=number_of_points(red, blue, i, j, -1, red_r, blue_r,n);
            if ((nresl||nresr)==0)
                continue;
            else if ((nresl==2)&&(nresr==2))
            {
                int k=answer.size();
                answer[k][0]=red[i][2];
                answer[k][1]=blue[j][2];
                return 1;
            }
            else
            {
                int k=answer.size();
                answer[k][0]=red[i][2];
                answer[k][1]=blue[j][2];
            }

            //

            // For recursion
            res=f(red_l, blue_l, answer,n)&&f(red_r, blue_r, answer,n);
            if (res==0)
            {
                continue;
            }
            else if (res==1)
            {

                return 1;
            }
            //

        }

    }
    return 0;
}

int main()
{
    vector<vector <int> > red, blue, answer;
    vector<int> v;
    int n,x,y;
    cin >> n;
    // Input red
    for (int i=0;i<n/2;i++)
    {
        cin >> x;
        v.push_back(x);
        cin >> y;
        v.push_back(y);
        v[2]=i;
        red.push_back(v);
    }

    // Input Blue
    for (int j=0;j<n/2;j++)
    {
        cin >> x;
        v.push_back(x);
        cin >> y;
        v.push_back(y);
        v[2]=j;
        red.push_back(v);
    }

    int res=f(red, blue, answer, n/2);
    if (res==0)
    {
        cout << "No such pairings found" << endl;
    }
    else
    {
        for (int k=0;k<n/2;k++)
        {
            cout << endl;
            for (int l=0;l<=1;l++)
            {
                cout << answer[k][l] << "          ";
            }
        }
    }
    return 0;
}
