/*#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
*/
class counter{
    typedef list<int>::iterator pos;
    typedef list<list<int> >::iterator iter;
    struct a{
        int count;
        iter it1;
        pos it2;
    };
    list < list<int> > LoL;
    vector <a> val;
    iter zero;
    public:
        counter(int n){
            a temp;
            temp.count=0;
            list<int>tmp;
            for (int i=0; i<n; i++)
                tmp.push_back(i);

            LoL.push_back(tmp);
            pos prev = (LoL.begin())->begin();
            for (int i=0; i<n; i++){
                temp.it1 = LoL.begin();
                temp.it2 = prev;
                prev++;
                val.push_back(temp);
            }
            zero = LoL.begin();
        }

        void increment (int i){
            iter in_main = val[i].it1;
            val[i].count++;
            //pos in_list = val[i].it2;
            iter checklast = LoL.end();
            checklast--;
            if (in_main == checklast){
                if (in_main->size() ==1){}
                else {list<int>tmp;
                tmp.push_back(i);
                LoL.push_back(tmp);
                in_main++;
                (val[i].it1)->erase(val[i].it2);
                if ((val[i].it1)->empty() && val[i].it1 !=zero)
                    LoL.erase(val[i].it1);

                val[i].it1=in_main;
                val[i].it2 = (val[i].it1)->begin();
                }
            }
            else{
                if (val[(++in_main)->front()].count == val[i].count || in_main == zero){
                    (val[i].it1)->erase(val[i].it2);
                    if ((val[i].it1)->size()==0 && val[i].it1 != zero)
                        LoL.erase(val[i].it1);

                    val[i].it1=in_main;
                    (val[i].it1)->push_back(i);
                    pos temp1 = (val[i].it1)->end();
                    temp1--;
                    val[i].it2 = temp1;
                }
                else{

                    if ( (val[i].it1)->size() == 1){}
                    else{
                    list<int>tmp;
                    tmp.push_back(i);
                    (val[i].it1)->erase(val[i].it2);
                    if ((val[i].it1)->empty() && val[i].it1 !=zero)
                        LoL.erase(val[i].it1);

                    LoL.insert(in_main, tmp);
                    in_main--;
                    val[i].it1 = in_main;
                    val[i].it2 = (in_main)->begin();
                    }
                }

            }
        }

        void decrement(int i){
            iter in_main = val[i].it1;
            val[i].count--;
            //pos in_list = val[i].it2;
            iter checkbeg = LoL.begin();

            if (in_main == checkbeg){
                if(in_main->size()==1){}
                else{list<int>tmp;
                tmp.push_back(i);
                LoL.push_front(tmp);

                in_main--;
                (val[i].it1)->erase(val[i].it2);
                if ((val[i].it1)->empty() && val[i].it1 !=zero)
                    LoL.erase(val[i].it1);
                val[i].it1=in_main;
                val[i].it2 = (val[i].it1)->begin();
                }
            }

            else{
                if (val[(--in_main)->front()].count == val[i].count || in_main==zero){
                    (val[i].it1)->erase(val[i].it2);
                    if ((val[i].it1)->size()==0 && val[i].it1 !=zero)
                        LoL.erase(val[i].it1);

                    val[i].it1=in_main;
                    (val[i].it1)->push_back(i);
                    pos temp1 = (val[i].it1)->end();
                    temp1--;
                    val[i].it2 = temp1;
            }
            else{
                    if ((val[i].it1)->size()==1){}
                    else{
                    list<int>tmp;
                    tmp.push_back(i);
                    (val[i].it1)->erase(val[i].it2);
                    if ((val[i].it1)->empty())
                        LoL.erase(val[i].it1);

                    in_main++;
                    LoL.insert(in_main, tmp);
                    in_main--;
                    val[i].it1 = in_main;
                    val[i].it2 = (in_main)->begin();
                    }
            }
        }
    }

    void reset(int i){
        iter in_main = val[i].it1;
        val[i].count=0;
        (val[i].it1)->erase(val[i].it2);
        if ((val[i].it1)->empty() && (val[i].it1 !=zero))
            LoL.erase(val[i].it1);

        zero->push_back(i);
        pos temp = zero->end();
        temp--;
        val[i].it1 = zero;
        val[i].it2 = temp;
    }

      int count(int i){
            return (val[i].count);
        }

        int findMax(){
            iter tempit = LoL.end();
            --tempit;
            if (tempit == zero && zero->size()==0) tempit--;
            int c = val[(*tempit).front()].count;
            return c;
        }

        int numMax(){
            iter tempit = LoL.end();
            tempit--;
            if (tempit == zero && zero->size()==0) tempit--;
            return ( (*tempit).size());
        }


        void printMax(){
            iter tempit = LoL.end();
            --tempit;
            if (tempit ==zero && zero->size()==0) tempit--;
            pos temp = (*tempit).begin();
            pos endo = (*tempit).end();
            for (pos i= temp; i!=endo; ++i){
                int d = *i;
                cout<<d<<" ";
            }
            cout<<endl;
        }

};



