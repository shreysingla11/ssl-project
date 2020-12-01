#include <iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<limits>

using namespace std;


int main()
{
    int inf = numeric_limits<int>::max();
    int n,temp;
    scanf("%d",&n);

    vector<vector<int> > c(n);
    queue<int> vertiq;
    queue<int> goodnessq;
    vector<vector<int> > Label(2*n+1);
    vector<vector<int> > inq(n);
    int vert,good;



    for(int i=0;i<n;i++)
    {

        c[i].resize(n);
        for(int j = 0; j<n;j++)
        {
            scanf("%d",&temp);
            c[i][j] = temp;
        }
    }
    //cout<<"notreached queue"<<endl;
    vector<int> tempvect;
    vector<int> tempvect2;
    tempvect.push_back(0);
    tempvect2.push_back(1);
    for(int i=1;i<n+1;i++)
    {
        tempvect.push_back(-1);

    }
    for(int i=1;i<2*n+1;i++)
    {
        tempvect2.push_back(0);
    }
    Label[n] = (tempvect);
    inq[0] = tempvect2;

    tempvect.clear();

    tempvect2[0]=0;
    for(int j =1;j<n;j++)
    {
        inq[j] = tempvect2;

    }
    //cout<<"not clear queue"<<endl;
    for(int j =0;j<n+1;j++)
    {
        tempvect.push_back(-1);
    }
    for(int i =0;i<n;i++)
    {
        Label[i] = (tempvect);

    }
    for(int i =n+1;i<=2*n;i++)
    {
        Label[i] = (tempvect);

    }


    vertiq.push(0);
    goodnessq.push(n);

    //cout<<"reached queue"<<endl;

    while(!vertiq.empty())
    {
        vert = vertiq.front();
        good = goodnessq.front();
        vertiq.pop();
        goodnessq.pop();
        inq[vert][good] = 0;
        for(int i =0 ;i<n;i++)
        {
            if(c[vert][i]<0)
            {

                if((Label[good+1][i])!=-1)
                {
                    //cout<<i<<" <0 "<<good+1<<endl;
                    if((Label[good][vert]-c[vert][i]<Label[good+1][i]))
                    {
                        //cout<<i<<" <0 "<<good+1<<endl;
                        Label[good+1][i] = Label[good][vert]-c[vert][i];
                        if(inq[i][good+1]==0)
                        {
                            vertiq.push(i);
                            goodnessq.push(good+1);
                            inq[i][good+1]==1;
                            //cout<<i<<" <0 "<<good+1<<endl;
                        }

                    }
                }
                ////////////////////////////
            }
            if(c[vert][i]>0)
            {
                //cout<<i<<" >0 "<<good+1<<endl;
                if((Label[good-1][i])!=-1)
                {
                    if((Label[good][vert]+c[vert][i]<Label[good-1][i]))
                    {
                        //cout<<i<<" >0 "<<good+1<<endl;
                        Label[good-1][i] = Label[good][vert]-c[vert][i];
                        if(inq[i][good-1]==0)
                        {
                            vertiq.push(i);
                            goodnessq.push(good-1);
                            inq[i][good-1]==1;
                            //cout<<i<<" >0 "<<good-1<<endl;
                        }

                    }
                }

                ////////////////////////////////

            }




        }

    }


    for(int i = 0;i<n;i++)
    {
        int m =1000000000;
        for(int j =n;j<=2*n;j++)
        {
            //cout<<Label[j][i]<<endl;
            if(m>Label[j][i]&&(Label[j][i]!=-1)){m=Label[j][i];}

        }
        if(m==1000000000){cout<<"infinity"<<endl;}
        else {printf("%d \n",m);}

    }


    return 0;

}
