#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Point
{
public:
    int x;
    int y;
    int ind;
    int col;//equals to 1 if col is red else is equal to zer0
};


class line_seg
{
public:
    Point* R;
    Point* B;

};



int line_equation(Point* R,Point*B,Point* p)
{
    int x1=R->x;
    int x2=B->x;
    int y1=R->y;
    int y2=B->y;
    int x=p->x;
    int y=p->y;
    int ans=(x2-x1)*(y-y1)-(y2-y1)*(x-x1);
    return ans;
};
class data
{
public:
    vector <Point*> r_points;
    vector <Point*> b_points;
    int n;

    data()
    {
        cin>>n;///taking 2n as input
        n=n/2;
        r_points.resize(n);
//    cout<<"size "<<r_points.size();

        for(int i=0; i<n; i++)
        {
            r_points[i]=new Point;
            r_points[i]->ind=i;
            r_points[i]->col=1;
            cin>>(r_points[i]->x)>>(r_points[i]->y);
        };
//take all the red ponits and store in r_ponits
//cout<<"here"<<endl;

        b_points.resize(n);
        for(int i=0; i<n; i++)
        {
            b_points[i]=new Point;
            b_points[i]->ind=i;
            b_points[i]->col=0;
            cin>>b_points[i]->x>>b_points[i]->y;
        };

    }


};
void assign_seg(vector <Point*>r_points,vector <Point*>b_points,vector <line_seg*> &lin_seg)
{//cout<<"here"<<endl;
    int    siz=r_points.size();
    //cout<<siz<<"size"<<endl;
    if(siz==0){
    return;
    }
    if(siz==1){
    //cout<<"infienthu"<<endl;
    line_seg* l=new line_seg;
    l->R=r_points[0];
    l->B=b_points[0];
    lin_seg.push_back(l);

    return;
    }
    else{
    bool assined=false;
    vector <Point*>l_r_points;
    vector <Point*>l_b_points;
    vector <Point*>r_r_points;
    vector <Point*>r_b_points;
    for(int i=0; i<siz; i++)
    {
        for(int j=0; j<siz; j++)
        {
            //line_seg* ll=new line_seg;
            //ll->R=r_points[i];
            //ll->B=b_points[j];
            int r_count=0;
            int b_count=0;
            l_r_points.clear();

            l_b_points.clear();
            r_r_points.clear();
            r_b_points.clear();
            for(int k=0; k<siz; k++)
            {if(k!=i){
                if(line_equation( r_points[i],b_points[j],r_points[k])<0)
                {
                    r_count++;
                    l_r_points.push_back(r_points[k]);
                }
                else
                {
                    r_r_points.push_back(r_points[k]);
                }
                }
            };
            for(int k=0; k<siz; k++)
            {if(k!=j){
                if(line_equation( r_points[i],b_points[j],b_points[k])<0)
                {
                    b_count++;
                    l_b_points.push_back(b_points[k]);
                }
                else
                {
                    r_b_points.push_back(b_points[k]);
                }
                }
            };

            if(r_count==b_count)
            {
            //cout<<i<<" "<<j<<endl;
//cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
                line_seg* l=new line_seg;
    l->R=r_points[i];
    l->B=b_points[j];
    lin_seg.push_back(l);
                assined=true;

                break;
            }

        }
        if(assined)
        {

            break;
        }
    }
    if(l_r_points.size()==l_b_points.size()&&r_r_points.size()==r_b_points.size()){
//cout<<"enthu"<<endl;
    assign_seg(l_r_points,l_b_points,lin_seg);

    assign_seg(r_r_points,r_b_points,lin_seg);
}

    return;
    }
}
int main()
{
    data D;
    vector <line_seg*> lin_seg;
    //cout<<"here"<<endl;
    assign_seg(D.r_points,D.b_points,lin_seg);
    //assign_seg(r_points,b_points);
    //cout<<lin_seg.size()<<endl;
    for(int i=0; i<D.n; i++)
    {//cout<<"here2"<<endl;
        cout<<(lin_seg[i]->R)->ind<<" "<<(lin_seg[i]->B)->ind<<endl;
    };
    return 0;
}

















