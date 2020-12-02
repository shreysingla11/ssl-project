#include<cstdio>
#include<vector>

using namespace std;


int Nred(vector<vector<int> > red,vector<vector<int> > blue,int i,int j)
{
    int rx=red[i][0],ry=red[i][1],bx=blue[j][0],by=blue[j][1],k=0,num=0;

    while(k<red.size())
    {
        if(red[k][1]*(bx-rx)+red[k][0]*(ry-by)+(by*rx-bx*ry)>0)
        {
            num++;
        }
        k++;
    }
    return num;
}

int Nblue(vector<vector<int> > red,vector<vector<int> > blue,int i,int j)
{
    int rx=red[i][0],ry=red[i][1],bx=blue[j][0],by=blue[j][1],k=0,num=0;

    while(k<red.size())
    {
        if(blue[k][1]*(bx-rx)+blue[k][0]*(ry-by)+(by*rx-bx*ry)>0)
        {
            num++;
        }
        k++;
    }
    return num;
}

void points(vector<vector<int> > red,vector<vector<int> > blue)
{
    if(red.size()==0 || blue.size()==0){}
    else
    {
        int i=0,j=0,rx=red[0][0],ry=red[0][1],bx,by,p,q;
        vector<vector<int> >red_left;
        vector<vector<int> >red_right;
        vector<vector<int> >blue_left;
        vector<vector<int> >blue_right;
        vector<int> v(3);
        while(j<blue.size())
        {
            if(Nred(red,blue,i,j)==Nblue(red,blue,i,j))break;
            else j++;
        }
        bx=blue[j][0];
        by=blue[j][1];
        printf("%d %d\n",red[0][2],blue[j][2]);
        i=0;j=0;
        while(i<red.size())
        {
            p=red[i][1]*(bx-rx)+red[i][0]*(ry-by)+(by*rx-bx*ry);
            if(p<0)
            {
                v[0]=red[i][0];
                v[1]=red[i][1];
                v[2]=red[i][2];
                red_left.push_back(v);
            }
            else if(p>0)
            {
                v[0]=red[i][0];
                v[1]=red[i][1];
                v[2]=red[i][2];
                red_right.push_back(v);
            }
            i++;
        }
        while(j<blue.size())
        {
            q=blue[j][1]*(bx-rx)+blue[j][0]*(ry-by)+(by*rx-bx*ry);
            if(q<0)
            {
                v[0]=blue[j][0];
                v[1]=blue[j][1];
                v[2]=blue[j][2];
                blue_left.push_back(v);
            }
            else if(q>0)
            {
                v[0]=blue[j][0];
                v[1]=blue[j][1];
                v[2]=blue[j][2];
                blue_right.push_back(v);
            }
            j++;
        }
        points(red_left,blue_left);
        points(red_right,blue_right);
    }

}

int main()
{
    vector<vector<int> > red;
    vector<vector<int> > blue;
    vector<int> v(3);
    int a,n,i,x,y;
    scanf("%d",&a);
    n=a/2;
    i=0;
    while(i<n)
    {
        scanf("%d%d",&x,&y);
        v[0]=x;
        v[1]=y;
        v[2]=i;
        red.push_back(v);
        i++;
    }
    while(i<2*n)
    {
        scanf("%d%d",&x,&y);
        v[0]=x;
        v[1]=y;
        v[2]=i-n;
        blue.push_back(v);
        i++;
    }
    points(red,blue);
}
