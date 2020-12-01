#include <iostream>
#include <map>
#include<iomanip>


using namespace std;

int main()
{
    int nLanes,width,t1,t2;
    double shipSpeed,ferrySpeed;
    cin>>nLanes>>width>>shipSpeed>>ferrySpeed>>t1>>t2;
    //shipSpeed+=0.0;
    //ferrySpeed+=0.0;
    multimap<double,bool> forbade;
    for(int i=0;i<nLanes;i++)
    {
        char east;
        int mi;
        cin>>east>>mi;
        for(int j=0;j<mi;j++)
        {
            int li,pi,posiT1;
            double tStart,tCross;
            cin>>li>>pi;
            if(east=='W')
            {
                //posiT1=pi;
                tStart=(pi/shipSpeed)-((i+1)*width/ferrySpeed);
                tCross=((pi+li)/shipSpeed)-(i*width/ferrySpeed);
                if(tCross>=t1 && tStart<=t2)
                {
                    if(tStart<t1){tStart=t1;}
                    if(tCross>t2){tCross=t2;}
                    forbade.insert(pair<double,bool>(tStart,0));
                    forbade.insert(pair<double,bool>(tCross,1));
                }

            }
            else
            {
                //posiT1=pi+shipSpeed*(t1);
                tStart=-(pi/shipSpeed)-((i+1)*width/ferrySpeed);
                tCross=((-pi+li)/shipSpeed)-(i*width/ferrySpeed);
                if(tCross>=t1 && tStart<=t2)
                {
                    if(tStart<t1){tStart=t1;}
                    if(tCross>t2){tCross=t2;}
                    forbade.insert(pair<double,bool>(tStart,0));
                    forbade.insert(pair<double,bool>(tCross,1));
                }

            }



        }
        int open=0;
        multimap<double,bool>::iterator nextitr=forbade.begin();
        double maxD=nextitr->first-t1;
        multimap<double,bool>::iterator enditr = forbade.end();
        if(nextitr==enditr){maxD=t2-t1;}
        for(multimap<double,bool>::iterator itr=forbade.begin();itr!=enditr;itr++)
        {
            if(itr->second == 0){open++;}
            else
            {
                open--;
                if(open==0)
                {
                    nextitr=itr;
                    ++nextitr;
                    if(nextitr!=enditr){
                        if((nextitr->first)-(itr->first)>maxD){maxD=((nextitr->first)-(itr->first));}
                    }
                    else
                    {
                        if((t2-(itr->first))>maxD){maxD=(t2-(itr->first));}
                    }

                }
            }
        }
       cout << fixed;
        cout << setprecision(8);
        cout<<maxD<<endl;
    }

    return 0;
}
