#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int main()
{

int n;
scanf("%d",&n);

vector<vector<int> > main(n);
vector<vector<int> > pred(n);
vector<int> t(n);
queue<int> go;
queue<int> dont;
vector<int> count(n,0);
vector<int> notcount(n,0);
vector<bool> already(n,false);

// indiv data
for (int i = 0;i<n;i++)
{

int temp2;

scanf("%d" , &temp2);
t[i] = temp2;

int nfrnd;
scanf("%d" , &nfrnd );

// definetly going
if(t[i]==0)
{
go.push(i);
already[i]=true;

}
// frnd input;
 if(t[i]>nfrnd)
 {
  dont.push(i);
  already[i] = true;
 }

int xx;
 while(nfrnd--)
 {
    scanf("%d",&xx);
    main[i].push_back(xx);
    pred[xx].push_back(i);
 }


 // definetly not



}
// for loop ends

int going=0;
int not_going = 0;


while(!go.empty())
{
int temp = go.front();
go.pop();
going++;
int sizofpred = pred[temp].size();
for(int i = 0 ; i<sizofpred;i++)
    {

        count[pred[temp][i]]++;
        if( already[pred[temp][i]]==true)
        {


        }

        else
    {
        if(t[pred[temp][i]]<=count[pred[temp][i]])
            {

                go.push(pred[temp][i]);
                already[pred[temp][i]]=true;
            }
        }
    }
}
// while of going
while(!dont.empty())
{
int temp = dont.front();
dont.pop();
not_going++;
int sizofpred = pred[temp].size();
for( int i = 0; i <sizofpred;i++)
    {
    bool check = true;
           notcount[pred[temp][i]]++;
        if( already[pred[temp][i]] == true){check = false;

        }
        if(check)
        {

        if(t[pred[temp][i]]> main[pred[temp][i]].size() - notcount[pred[temp][i]])
        {
            dont.push(pred[temp][i]);
            already[pred[temp][i]]=true;
        }
        }
    }

}

printf("%d %d\n" ,going , main.size() - not_going);
return 0;

}
