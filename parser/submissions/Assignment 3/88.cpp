# include <iostream>
# include <fstream>
# include <vector>
using namespace std;
void compute(int * first,int *second,int s_indx,int& L,int& pos,int n,int m)
{
    int i=s_indx+1,j=1;
    L=1;
    pos=s_indx;
    bool found=false;//to remove partially correct
    while(i<n && j<m)
    {
        if(i==n-1&&j==m-1) //final case
        {
            if(first[i]==second[j]) //substring found
            {
                //cout<<"found match"<<endl;
                if(pos==-1)
                {
                    pos=i;
                    L=1;
                }
                else
                {
                    i++;
                    j++;
                    L++;
                }
                found=true;
                break;
            }
            else
            {
                pos=-1;//no such substring exist
                i++;
                j++;
                found=false;
                L=0;
                break;
            }

        }
        else if(i<n-1 && j==m-1)
        {
            if(first[i]==second[j]) //found some soln
            {
                if(pos==-1)
                {
                    pos=i;
                    L=1;
                }
                else
                {
                    i++;
                    j++;
                    L++;
                }
                found=true;
                break;
            }
            else
            {
                L++;
                i++;//check for further values
            }

        }
        else if(i<n-1 && j<m-1)
        {
            if(first[i]==second[j])
            {
                //found a match
                if(pos==-1)
                {
                    pos=i;
                    L=1;
                    i++;
                    j++;
                }
                else
                {
                    i++;
                    j++;
                    L++;
                }

            }
            else
            {
                if(pos!=-1)
                {
                    L++;
                }

                i++;//search for further values
            }

        }
        else
        {
            pos=-1;
            break;
        }


    }
    //cout<<"done for indices"<<s_indx<<endl;
    return;
}

int main()
{
    int n,m;
    //ifstream fin("0.in");
    cin>>n>>m;
    //first take input
    int *first=new int[n];
    int *second=new int[m];

    for(int i=0; i<n; i++)
    {
        cin>>first[i];

    }
    for (int i=0; i<m; i++)
    {
        cin>>second[i];
    }
    //input taken now write the function;
    //find the indices of first element and do it
    std::vector<int> findices;
    for(int i=0; i<n; i++)
    {
        if(first[i]==second[0])
        {
            findices.push_back(i);
        }
    }
    //cout<<"found indices"<<endl;
//now check it for all values in f indices
    int L1=1,pos1=-1,L2=1,pos2=-1;
    int len=findices.size();
    bool strt=false;
    for(int i=len-1; i>=0; i--)
    {
        compute(first,second,findices[i],L2,pos2,n,m);
        //cout<<L2<<" "<<pos2<<endl;

        if(L2>1)
        {
            if(!strt)
            {
                if(pos2!=-1){
                L1=L2;
                pos1=pos2;
                strt=true;
                }
              //  cout<<"started"<<L1<<pos1<<endl;
            }
            else
            {
                if(pos2!=-1){
                if(L2<L1)
                {
                    L1=L2;
                    pos1=pos2;

                }
                }
            }
        }
    }
    cout<<L1<<" "<<pos1+1<<endl;



    return 0;
}
