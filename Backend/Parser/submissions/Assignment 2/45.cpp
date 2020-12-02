#include<iostream>
#include<vector>

using namespace std;

class point
{
    public:
        int x,y,paired,lr;
};

void recursive(vector<point> &red,vector<point> &blue,vector<int> rednum,vector<int> bluenum)
{
    int n=rednum.size();
    if(n==0)
    {
        return;
    }
    else if(n==1)
    {

        red[rednum[0]].paired = bluenum[0];
    }
    else if(n==2)
    {

        double slope;
        if((red[rednum[0]].x-blue[bluenum[0]].x)==0)
        {
            if(((red[rednum[1]].x)-(red[rednum[0]].x))*((blue[bluenum[1]].x)-(blue[bluenum[0]].x))>0)
            {
                red[rednum[0]].paired = bluenum[0];
                red[rednum[1]].paired = bluenum[1];
            }
            else
            {
                red[rednum[0]].paired = bluenum[1];
                red[rednum[1]].paired = bluenum[0];
            }
        }
        else
        {
            slope = (red[rednum[0]].y-blue[bluenum[0]].y)/(red[rednum[0]].x-blue[bluenum[0]].x);
            int intercept = (red[rednum[0]].y)-((red[rednum[0]].x)*slope);
            int blu1=(blue[bluenum[1]].y-(slope*(blue[bluenum[1]].x))-intercept);
            int red1=(red[rednum[1]].y-(slope*(red[rednum[1]].x))-intercept);
            if(blu1*red1>0)
            {
                red[rednum[0]].paired = bluenum[0];
                red[rednum[1]].paired = bluenum[1];
            }
            else
            {
                red[rednum[0]].paired = bluenum[1];
                red[rednum[1]].paired = bluenum[0];
            }
        }

    }
    else
    {
//        Dividing into halves
        int i;
        for(i=0;i<n;i++)
        {
//          assuming line red[rednured[rednum[0]]-blue[bluenum[i]]m[0]] - blue[bluenum[i]]


            red[rednum[0]].lr=2;blue[bluenum[i]].lr=2;

            double slope;
            //slope == 0
            if((red[rednum[0]].x-blue[bluenum[i]].x)==0)
            {
                int leftblue=0,leftred=0;
                for(int j=0;j<n;j++)
                {
                    if(j==i){continue;}
                    else
                    {
                        if((blue[bluenum[j]].y-blue[bluenum[i]].x)>0)
                        {
                            blue[bluenum[j]].lr = 0;
                            leftblue++;
                        }
                        else
                        {
                            blue[bluenum[j]].lr = 1;
                        }
                    }
                }
                for(int j=1;j<n;j++)
                {

                    if((blue[bluenum[j]].y-blue[bluenum[i]].x)>0)
                    {
                        red[rednum[j]].lr = 0;
                        leftred++;
                    }
                    else
                    {
                        red[rednum[j]].lr = 1;
                    }

                }

                if(leftblue==leftred){break;}
            }
            else
            {
                slope = (red[rednum[0]].y-blue[bluenum[i]].y)/(red[rednum[0]].x-blue[bluenum[i]].x);
                int intercept = (red[rednum[0]].y)-((red[rednum[0]].x)*slope);
                int leftblue = 0,leftred = 0;

                for(int j=0;j<n;j++)
                {
                    if(j==i){continue;}
                    else
                    {
                        if((blue[bluenum[j]].y-(slope*(blue[bluenum[j]].x))-intercept)>0)
                        {
                            blue[bluenum[j]].lr = 0;
                            leftblue++;
                        }
                        else
                        {
                            blue[bluenum[j]].lr = 1;
                        }
                    }
                }
                for(int j=1;j<n;j++)
                {

                    if((red[rednum[j]].y-(slope*(red[rednum[j]].x))-intercept)>0)
                    {
                        red[rednum[j]].lr = 0;
                        leftred++;
                    }
                    else
                    {
                        red[rednum[j]].lr = 1;
                    }

                }

                if(leftblue==leftred){break;}

            }
        }


        red[rednum[0]].paired = bluenum[i];

        vector<int> nextrednumL;vector<int> nextbluenumL;vector<int> nextrednumR;vector<int> nextbluenumR;

        for(int j=0;j<n;j++)
        {
            if((red[rednum[j]].lr)==0){nextrednumL.push_back(rednum[j]);}
            else if((red[rednum[j]].lr)==1){nextrednumR.push_back(rednum[j]);}
            else{}

            if((blue[bluenum[j]].lr)==0){nextbluenumL.push_back(bluenum[j]);}
            else if((blue[bluenum[j]].lr)==1){nextbluenumR.push_back(bluenum[j]);}
            else{}
        }
//      Divided
        recursive(red,blue,nextrednumL,nextbluenumL);
        recursive(red,blue,nextrednumR,nextbluenumR);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    n=n/2;
    vector<point> red;vector<point> blue;
    vector<int> rednum;vector<int> bluenum;
    point p;
    for(int i=0;i<n;i++)
    {
        int X,Y;
        cin>>X;
        cin>>Y;
        p.x=X;
        p.y=Y;
        red.push_back(p);
        rednum.push_back(i);

    }
    for(int i=0;i<n;i++)
    {
        int X,Y;
        cin>>X;
        cin>>Y;
        p.x=X;
        p.y=Y;
        blue.push_back(p);
        bluenum.push_back(i);
    }
    recursive(red,blue,rednum,bluenum);
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<red[i].paired<<endl;
    }
    return 0;
}
