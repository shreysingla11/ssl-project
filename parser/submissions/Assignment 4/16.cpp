#include<iostream>
#include<list>
#include<vector>

using namespace std;

class counter
{
    list<int > webpage;
    vector<int> count1,count2;
    list<list<int> >  lol;
    vector<list <list <int > > :: iterator > nt,pt;
    vector<list<int> :: iterator> itr1,itr2;
    int maxvalue,minvalue;

public:


    counter(int n)
    {


        maxvalue=0;
        minvalue=-1;
        count1.resize(n,0);
        count2.resize(n,0);
        list<int> l;
        list<int> :: iterator tep=l.begin();
        int z=n;
        lol.push_back(l);
        pt.push_back(lol.begin());
        nt.push_back(lol.begin());
        nt.push_back(lol.begin());
        while(n>0)
        {

            (*pt[0]).push_back(z-n);
            itr1.push_back(--((*pt[0]).end()));
            n--;

        }



    }



    void increment(int i)
    {
        if(count1[i]<0)
        {



            if(count1[i]==minvalue&&(*nt[minvalue]).size()==1)
            {
                if(minvalue!=-1){minvalue++;}
            }
            (*nt[-count1[i]]).erase(itr1[i]);
            count1[i]++;


            if(count1[i]==0)
            {
                (*pt[0]).push_back(i);
                itr1[i]=--((*pt[0]).end());

            }
            else
            {

                (*nt[count1[i]]).push_back(i);
                itr1[i]=--((*nt[count1[i]]).end());

            }
            return;

        }
        else
        {
            if(count1[i]==maxvalue)
            {

                (*pt[count1[i]]).erase(itr1[i]);
                count1[i]++;
                maxvalue++;
                list<int > temp;
                temp.push_back(i);
                lol.push_back(temp);
                pt[count1[i]]=--(lol.end());
                itr1[i]=--((*pt[count1[i]]).end());

            }
            else
            {
                (*pt[count1[i]]).erase(itr1[i]);
                count1[i]++;
                (*pt[count1[i]]).push_back(i);
                itr1[i]=--((*pt[count1[i]]).end());

            }



        }



        return ;
    }


    void decrement(int i)
    {


        if(count1[i]>=0)
        {

            if(count1[i]==maxvalue&&(*pt[maxvalue]).size()==1)
            {

                maxvalue--;
            }
               (*pt[count1[i]]).erase(itr1[i]);
            count1[i]--;

            if(count1[i]==-1)
            {
                (*nt[1]).push_back(i);
                itr1[i]=--((*nt[1]).end());

            }
            else
            {

                (*pt[count1[i]]).push_back(i);
                itr1[i]=--((*pt[count1[i]]).end());

            }

            return;




        }

        else
        {

            if(count1[i]==minvalue)
            {


                (*nt[count1[i]]).erase(itr1[i]);
                count1[i]--;
                minvalue--;
                list<int > temp;
                temp.push_back(i);
                lol.push_front(temp);
                nt[-count1[i]]=(lol.begin());
                itr1[i]=--((*nt[-count1[i]]).end());

            }
            else
            {
                (*nt[count1[i]]).erase(itr1[i]);
                count1[i]--;
                (*nt[count1[i]]).push_back(i);
                itr1[i]=--((*nt[count1[i]]).end());

            }



        }


        return ;
    }


    int count(int i)
    {


    return count1[i];

    }

    void reset(int i)
    {
        if(count1[i]<0)
        {
            (*nt[-count1[i]]).erase(itr1[i]);
            count1[i]=0;
            (*pt[0]).push_back(i);
            itr1[i]=--((*pt[0]).end());
        }
        else
        {
            (*pt[count1[i]]).erase(itr1[i]);
            count1[i]=0;
            (*pt[0]).push_back(i);
            itr1[i]=--((*pt[0]).end());



        }

    return ;
    }


    int numMax()
    {
        return maxvalue;

    }

    int findMax()
    {


        return (*pt[maxvalue]).size();
    }

    void printMax()
    {
        int j=0;
        list<int> :: iterator q;
        q=(*pt[maxvalue]).begin();
        while(j<(*pt[maxvalue]).size())
        {
            cout<<*q<<endl;
            q++;
            j++;

        }



    return ;
    }



};
