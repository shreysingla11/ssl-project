#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct level
{
    vector<int> array_1;
    vector<int> array_2;
};

struct pairs
{
    int value;
    int position;
};

bool l_checker(pairs a, pairs b)
{
    if(a.value > b.value)
    {
        return false;
    }
    else if(b.value > a.value)
    {
        return true;
    }
    else
    {
        if(a.position > b.position)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

class distinct
{
int sizer;
public:
    vector<int> second_first;
    vector<int> l;
    vector<level> series;
    distinct(vector<int> init)
    {
        sizer = init.size();
        vector<pairs> temp;
        temp.resize(sizer);
        l.resize(sizer);
        series.resize(sizer);
        for(int i=0; i<sizer; i++)
        {
            pairs temp_pair;
            temp_pair.position = i;
            temp_pair.value = init[i];
            temp[i]=temp_pair;
        }
        //cout<<"Yo1"<<endl;
        sort(temp.begin(),temp.end(),l_checker);
        //for(int i=0; i<init.size();i++)
        //{
        //   cout<<temp[i].value<<" "<<temp[i].position<<" ";
        //}
        //cout<<endl;
        //cout<<"Yo2"<<endl;
        //cout<<temp.size()<<endl;
        //l[0]=-1;
        int temp_2 = -1;
        for(int i = 0; i< sizer; i++)
        {
            second_first.push_back(temp_2);
            if(l[i] > 0) temp_2 = i;
        }


        l[temp[0].position]=-1;
        for(int i=1; i<sizer; i++)
        {
            //cout<<"Yo2"<<endl;
            if( temp[i-1].value == temp[i].value )
            {
                l[temp[i].position] = temp[i-1].position;
            }
            else
            {
                l[temp[i].position] = -1;
            }
            //cout<<"Yo1"<<endl;
        }
        //---------------------- l  formed -------------------

        int log_n = log2(sizer);
        int counter=0;
        //(series[0]).array_1.resize(sizer);
        /*
        for(int i=0; i<sizer; i++)
        {
            if( l[i] >= (sizer/2) ) counter++;
            (series[0]).array_1[i] = counter;
            //cout<<counter<<endl;
        }*/
        for(int i=0; i<log_n;i++)
        {
            int largest_left = -1;
            int largest_right = -1;
            vector<int> counter(sizer,0);
            vector<int> temp_1;
            for(int j=0; j<sizer; j++)
            {
                int k = ( ( l[j] * (pow(2,i)) ) / sizer );
                if( l[j] > (  (k * sizer ) / pow(2,i)  + sizer/pow(2,i+1) ) &&  l[j] < (  ( (k+1) * sizer ) / pow(2,i) ) )
                {
                    counter[k]++;
                }
                ((series[i]).array_1).push_back(counter[k]);

                if( l[j] >= ( (k * sizer)/pow(2,i) + sizer/pow(2,i+1) ) &&  l[j] < ( ( (k+1) * sizer ) / pow(2,i) ) )
                {
                    ((series[i]).array_2).push_back(largest_left);
                    largest_right = j;
                }
                else
                {
                    ((series[i]).array_2).push_back(largest_right);
                    largest_left = j;
                }

            }

        }


    }


    int num_distinct(int i, int j)
    {
        int ori_j = j;
        int result = 0, interval = 0;
        int log_n = log2(sizer);
        j = second_first[j];

        if(j<0) return 0;

        for (int it = 0; it < log_n; it++)
        {
            if(i < ( (interval * sizer) / pow(2,it - 1) + sizer/pow(2,it) ))
            {
                result = result + (series[it]).array_1[j];
                if( l[j] > ( (interval * sizer) / pow(2,it - 1) + sizer/pow(2,it) ) )
                {
                    j = (series[it]).array_2[j];
                    if(j<0) return (ori_j - i + 1 - result );
                }
            }
            else if(i > ( (interval * sizer) / pow(2,it - 1) + sizer/pow(2,it) ))
            {
                interval = ( interval * sizer / pow(2,it -1) ) + sizer / pow(2,it);
                //if( l[j] < ( (interval * sizer) / pow(2,it - 1) + sizer/pow(2,it) ) )
                //    j = (series[it]).array_2[j];
            }
            else
            {
                return (ori_j - i + 1 - result );
            }
        }
    return (ori_j - i + 1 - result );
    }
};


