#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class point
{
    public:
    int number;
    int x_coordinate;
    int y_coordinate;
    bool color;
    int pairup;
    int slope;
    float slopea(point &alpha)
    {
        if(alpha.x_coordinate == x_coordinate)
        {
            if(alpha.y_coordinate > y_coordinate)
            {
                return -1000000;
            }
            else if(alpha.y_coordinate == y_coordinate)
            {
                return -1000001;
            }
            else
            {
                return 1000000;
            }
        }
        return ((alpha.y_coordinate - y_coordinate)/(alpha.x_coordinate - x_coordinate));
    }
    point()
    {
        int pairup = -1;
    }
};

bool lesser_by_slope(const point &po1,const point &po2)
{
    return po1.slope < po2.slope;
}

bool lesser_by_number(const point &po1,const point &po2)
{
    return po1.number < po2.number;
}

void pair_up(vector <point> &setpo,int start,int endg)
{
    point alpha;
    if(start == endg)
    {

        return;
    }
    else
    {
        int min_x = setpo[start].x_coordinate;
        int k=start;
        int n;
        int i = start;
        std::vector<point>::iterator j = setpo.begin()+ start;
        for(i = start; i< endg;i++)
        {
            if(min_x > setpo[i].x_coordinate)
            {
                j = setpo.begin() + i;
                k =i;
                min_x = setpo[i].x_coordinate;
            }
        }
        alpha = setpo[k];
//            cout<<k<<"l\t"<<setpo[k].x_coordinate<<setpo[k].y_coordinate<<endl;
        for(i = start;i < endg;i++)
        {
            setpo[i].slope=setpo[i].slopea(alpha);
        }
        n =1;
        std::sort(setpo.begin()+start,setpo.begin() +endg,lesser_by_slope);
        for(i = (start+endg)/2 -1; n != 0 && i < endg ;i++)
        {
            n = 0;
            //cout<<i<<"\t"<<setpo[i].x_coordinate<<setpo[i].y_coordinate<<endl;
            if(setpo[start].color == setpo[i].color)
            {
                n =1;
            }
            else
            {
                for(int l = start + 1; l < i; l++)
                {
                    if(setpo[l].color == setpo[start].color)
                    {
                        n++;
                    }
                    else
                    {
                        n--;
                    }
                }
            }
        }
        if(n!=0)
        {
            for(i = start+1; n != 0 && i < (endg+start)/2 -1;i++)
            {
                n = 0;
            //cout<<i<<"\t"<<setpo[i].x_coordinate<<setpo[i].y_coordinate<<endl;
                if(setpo[start].color == setpo[i].color)
                {
                    n =1;
                }
                else
                {
                    for(int l = start + 1; l < i; l++)
                    {
                        if(setpo[l].color == setpo[start].color)
                        {
                            n++;
                        }
                        else
                        {
                            n--;
                        }
                    }
                }
            }
        }
        i--;
        setpo[start].pairup = setpo[i].number;
        //cout<<"k"<<start<<" "<<i<<endl;
        setpo[i].pairup = setpo[start].number;
        pair_up(setpo,start+1,i);
        pair_up(setpo,i + 1,endg);
    }
}

int main()
{
    int value;
    cin>>value;
    vector <point> poin_set;
    point * po;
    value = value /2;
    for(int i = 0; i< value; i++)
    {
        po = new point;
        cin>>po->x_coordinate>>po->y_coordinate;
        po->color = 0;
        po->number = i;
        poin_set.push_back(*po);
    }
    for(int i = value; i< 2 * value; i++)
    {
        po = new point;
        cin>>po->x_coordinate>>po->y_coordinate;
        po->color = 1;
        po->number = i;
        poin_set.push_back(*po);
    }
    pair_up(poin_set,0,poin_set.size());
    std::sort(poin_set.begin(),poin_set.end(),lesser_by_number);

    for(int i = 0; i < value ; i++)
    {
        cout<<poin_set[i].number<<"  "<<poin_set[i].pairup - value<<endl;
    }
}
