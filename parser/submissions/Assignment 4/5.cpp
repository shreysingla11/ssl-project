#include <iostream>
#include <list>
#include <vector>

using namespace std;

class counter
{
    private:

      int n;
      list<int> temp2;
      list<list<int> > L;
      vector<int> v;
      vector< list<list<int> >::iterator> u;

    public:

      void increment(int i)
      {
        v[i]++;
        (*u[i]).remove(i);
        if(++u[i]==L.end())
        {
          --u[i];
          list<int> temp;
          temp.clear();
          temp.push_back(i);
          L.push_back(temp);
          if((*u[i]).empty()){u[i]=L.erase((u[i]));}
          else u[i]++;

        }

        else
        {
            --u[i];
          if(v[i]==v[*((++u[i])->begin())])
          {
            (u[i])->push_back(i);
            u[i]--;
            if((*u[i]).empty())u[i]=L.erase((u[i]));
            else u[i]++;

          }

          else
          { --u[i];
            list<int> temp2;
            temp2.push_back(i);
            if((*u[i]).empty())u[i]=L.erase((u[i]));
            L.insert(++u[i],temp2);
            u[i]--;
          }
        }

      }

      void decrement(int i)
      {
        v[i]--;

        (u[i])->remove(i);

        if(u[i]==L.begin())
        {
          list<int> temp;
          temp.clear();
          temp.push_back(i);
          L.push_front(temp);
          if((*u[i]).empty()){u[i]=L.erase((u[i]));}
          u[i]--;

        }

        else
        {
          u[i]--;

          if(v[i]==v[*((u[i])->begin())])
          {
             (u[i])->push_back(i);
            u[i]++;
            if((*u[i]).empty())u[i]=L.erase((u[i]));
            u[i]--;

          }

          else
          { ++u[i];
            list<int> temp2;
            temp2.push_back(i);
            L.insert(u[i],temp2);
            if((*u[i]).empty())u[i]=L.erase((u[i]));
            u[i]--;
          }
        }

      }

      void reset(int i)
      {
        v[i]=0;
        (*u[i]).remove(i);
        if((*u[i]).empty())u[i]=L.erase((u[i]));

        if(v[*((L.begin())->begin())]==0) {  (L.begin())->push_back(i);
                                          u[i]=L.begin();
                                        }
        else
        {
          list<int> temp3;
          temp3.clear();
          temp3.push_back(i);
          L.push_front(temp3);
          u[i]=L.begin();
        }

      }

      int findMax()
      {
        list<list<int> >::iterator r=L.end();
        r--;
        int temp5=v[*((r)->begin())];
        //cout<<"maximum count is : "<<v[*((r)->begin())]<<endl;
        return temp5;
      }

      int numMax()
      {
       list<list<int> >::iterator r=L.end();
        r--;
        int temp4=((r)->size());
        //cout<<"number of pages having maximum page count :"<<((r)->size())<<endl;
       return temp4;
      }

      void printMax()
      {
        list<list<int> >::iterator s=L.end();
        s--;

        for(list<int>::iterator t=(*s).begin();t!=(*s).end();t++)
        {

            cout<<(*t)<<"  ";

        }

        cout<<endl<<endl;
      }

      int count(int i)
      {
          int temp6=v[i];
          return temp6;
      }
    counter(int N)
    {
        n=N;
        temp2.clear();
        v.assign(n,0);
       for(int i=0;i<n;i++)
       {
         v[i]=2;
         temp2.push_back(i);
       }
       L.clear();
       L.push_front(temp2);

        for(int i=0;i<n;i++)
       {
         u.push_back(L.begin());
       }

    }

};
