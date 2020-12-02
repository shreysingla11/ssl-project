#include<cstdio>
#include<vector>

using namespace std;


class points
{
public:
int x;
int y;
int index;


};
    vector<points> redl;
    vector<points> bluel;
    vector<points> redr;
    vector<points> bluer;
bool equalto(vector<points> red,vector<points> blue, points redm,points bluem)
    {
    int countlr=0;
    int countlb=0;
    bluer.clear();
    redr.clear();
    redl.clear();
    bluel.clear();
    for(int i = 0;i<blue.size();i++ )

    {   if(blue[i].y==bluem.y&&blue[i].x==bluem.x){continue;}
       if((blue[i].y-bluem.y)*(redm.x-bluem.x)- (redm.y-bluem.y)*(blue[i].x-bluem.x)<0)
            {
                countlb++;
                bluel.push_back(blue[i]);
            }
        else bluer.push_back(blue[i]);



    }
      for(int i = 0;i<red.size();i++ )



    {   if(red[i].y==redm.y&&red[i].x==redm.x){continue;}
       if((red[i].y-bluem.y)*(redm.x-bluem.x)- (redm.y-bluem.y)*(red[i].x-bluem.x)<0)
            {
                countlr++;
                redl.push_back(red[i]);
            }
        else redr.push_back(red[i]);
    }




    if(countlb==countlr){ return true;}
    else
    {
    bluer.clear();
    redr.clear();
    redl.clear();
    bluel.clear();

    return false;

    }




    }
void pairing( vector<points> &red, vector<points> &blue)
{
    if(red.empty())return;
    if(red.size()==1){printf("%d %d\n",red[0].index,blue[0].index);return;}

    for( int i = 0;i<blue.size();i++)
    {
        if(equalto(red,blue,red[0],blue[i]))
        {
        printf("%d %d\n",red[0].index,blue[i].index);
        pairing(redl,bluel);
        pairing(redr,bluer);
        break;
        }

    }
    return;




}

int main()
{
int n;
scanf("%d",&n);
vector<points> red;
vector<points> blue;
for(int i = 0 ;i<n/2;i++)
    {


        points temp;
        scanf("%d %d",&temp.x,&temp.y);
        temp.index = i;
        red.push_back(temp);


    }
for(int i = 0 ;i<n/2;i++)
    {


        points temp;
        scanf("%d %d",&temp.x,&temp.y);
        temp.index = i;
        blue.push_back(temp);


    }
pairing(red,blue);
return 0;
}
