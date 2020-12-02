#include <iostream>
#include <string>
#include <unordered_map>
#include <bitset>
#include <utility>
#include <cstdio>
//#include <stdlib>
using namespace std;
/*struct func
{
	long long operator()(long long const i) const
	{

	}
};*/

int main()
{
    long long int powerarray[45];
    powerarray[44] = 1;
    for(int i = 43; i>=0; i--)
    {
        powerarray[i] = 2*powerarray[i+1];
        //cout<<powerarray[i]<<endl;
    }
    char ch = 'a';
    int mine = 0;
    unordered_map<long long int,char> me;
    for(;ch!='{';mine++,ch = ch+1)
    {
        bitset<5> binform(mine);
        string temp = binform.to_string();
        string myfinal;
        for(int i = 0; i<45; i++)
        {
            myfinal+=temp[i/9];
        }
        //cout<<temp<<endl<<myfinal<<endl;
        temp = myfinal;
        //cout<<temp<<endl;

    long long int original = 0;
        for(int q = 0; q<45; q++)
        {
            original+=powerarray[q]*(temp[q]-'0');
        }
        me[original] = ch;
        for(int i = 0; i<45; i++)
        {
            if(temp[i] == '0')
            {
                temp[i] = '1';
                original+=powerarray[i];
            }
            else
            {
                temp[i] = '0';
                original-=powerarray[i];
            }
            for(int j = i+1; j<45; j++)
            {
                if(temp[j] == '0')
                {
                    temp[j] = '1';
                    original+=powerarray[j];
                }
                else
                {
                    temp[j] = '0';
                    original-=powerarray[j];
                }
                for(int k = j+1; k<45; k++)
                {
                    if(temp[k] == '0')
                    {
                        temp[k] = '1';
                        original+=powerarray[k];
                    }
                    else
                    {
                        temp[k] = '0';
                        original-=powerarray[k];
                    }
                    for(int l = k+1; l<45; l++)
                    {
                        if(temp[l] == '0')
                        {
                            temp[l] = '1';
                            original+=powerarray[l];
                        }
                        else
                        {
                            temp[l] = '0';
                            original-=powerarray[l];
                        }
                        me[original] = ch;
                        //me.insert(make_pair<unsigned long long int,char>(original,ch));
                        if(temp[l] == '0')
                        {
                            temp[l] = '1';
                            original+=powerarray[l];
                        }
                        else
                        {
                            temp[l] = '0';
                            original-=powerarray[l];
                        }
                    }
                    me[original] = ch;
                    //me.insert(make_pair<unsigned long long int,char>(original,ch;))
                    if(temp[k] == '0')
                    {
                        temp[k] = '1';
                        original+=powerarray[k];
                    }
                    else
                    {
                        temp[k] = '0';
                        original-=powerarray[k];
                    }
                }
                me[original] = ch;
                //me.insert(make_pair<unsigned long long int,char>(original,ch;))
                if(temp[j] == '0')
                {
                    temp[j] = '1';
                    original+=powerarray[j];
                }
                else
                {
                    temp[j] = '0';
                    original-=powerarray[j];
                }
            }
            me[original] = ch;
            /*for(int qw = 0;qw<45;qw++)
            {
                cout<<temp[qw];
            }
            cout<<"  "<<original<<endl;*/
            //me.insert(make_pair<unsigned long long int,char>(original,ch;))
            if(temp[i] == '0')
            {
                temp[i] = '1';
                original+=powerarray[i];
            }
            else
            {
                temp[i] = '0';
                original-=powerarray[i];
            }
        }
    }


    /*for(auto& b: me)
    cout<<b.first<<": "<<b.second<<endl;
*/


    int n;
    cin>>n;
    long long int query;
    unordered_map<long long int,char>::iterator got;
    unordered_map<long long int,char>::const_iterator endite;
    for(int i = 0;i<n;i++)
    {
        cin>>query;
        got = me.find(query);
        if(got == endite )
        {
            //cout<<"?"<<endl;
            printf("?");

        }
        else
        {
            printf("%c",got->second);
            //cout<<got->second<<endl;
        }
    }
    return 0;
}
