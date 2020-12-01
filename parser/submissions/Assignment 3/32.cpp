#include <iostream>
#include <vector>

using namespace std;

int calLength(vector<int> &a, vector<int> &b,vector<vector<int> > &L ,int i,int j,int& n,int &m);

int main()
{
  int n,m;
  int m_val=2147483647;
  int m_index=0;
  //read of lengths of a and b
  cin>>n;
  cin>>m;

  vector<int> a(n,0);
  vector<int> b(m,0);


  vector<int> infi(m,2147483647);
  vector<vector <int> >  L(n,infi);
  //read of a and b

  for(int i=0;i<n;i++)
  {
    cin>>a[i];

  }
  for(int i=0;i<m;i++)
  {
    cin>>b[i];

  }
  cout<<"test1"<<endl;
  cout<<L[2][1]<<endl;
 //L[0][0]=calLength(a,b,L,0,0,n,m);
 for(int i=n-1;i>=0;)
    {
    for(int j=m-1;j>=
       if((i==(n-1))&&(j==(m-1)))
        {
            if(a[i]==b[j])
            {
                cout<<"test3"<<endl;
                L[i][j]=1;

                //return 1;

            }

            else ;

        }
        if((i<(n-1))&&(j==(m-1)))
        {
            if(a[i]==b[j])
            {
               cout<<"test4"<<endl;
                L[i][j]=1;

                //return 1;

            }
            else
            {
                L[i][j]=1+L[i+1][j];
                //L[i][j]=1+ calLength(a,b,L,i+1,j,n,m);
                //return L[i][j];

            }

        }
        //L[n,j] = infinity for all j < m.
        if((i==(n-1))&&(j<(m-1)))
        {
            L[n][j]=2147483647;

            //return L[i][j];
        }

        //L[i,j] = 1 + L[i+1,j+1] if a_i == b_j,)
        //otherwise it is 1 + L[i+1,j] for
        //all 1 <= i < n, 1 <= j < m.
        if((i<(n-1))&&(j<(m-1)))
        {
            if(a[i]==b[j])
            {
               cout<<"test2"<<endl;
                L[i][j]=1+ L[i+1][j+1];
                //return L[i][j];

            }
            else
            {
                L[i][j]=1+ L[i+1][j];
               // return L[i][j];
                //return 1+calLength(a,b,L,i+1,j,n,m);
            }
        }


    }
    }

  for(int i=0;i<n;m_index++)
  {
    //m_val=(L[i][0]<m_val)L[i][0]:
    if(L[i][0]<m_val)
    {
        m_val=L[i][0];
        m_index=i;

    }

  }

  cout<<m_val<<" "<<m_index<<endl;

  return 0;

}




/*int calLength(vector<int> &a, vector<int> &b,vector<vector<int> > &L ,int i,int j,int& n,int &m)
{
   aa
        if((i==(n-1))&&(j==(m-1)))
        {
            if(a[i]==b[j])
            {
                cout<<"test3"<<endl;
                L[i][j]=1;

                //return 1;
            }

            else ;

        }
        if((i<(n-1))&&(j==(m-1)))
        {
            if(a[i]==b[j])
            {
               cout<<"test4"<<endl;
                L[i][j]=1;

                //return 1;

            }
            else
            {

                L[i][j]=1+ calLength(a,b,L,i+1,j,n,m);
                //return L[i][j];

            }

        }
        //L[n,j] = infinity for all j < m.
        if((i==(n-1))&&(j<(m-1)))
        {
            L[n][j]=2147483647;

            //return L[i][j];
        }

        //L[i,j] = 1 + L[i+1,j+1] if a_i == b_j,)
        //otherwise it is 1 + L[i+1,j] for
        //all 1 <= i < n, 1 <= j < m.
        if((i<(n-1))&&(j<(m-1)))
        {
            if(a[i]==b[j])
            {
               cout<<"test2"<<endl;
                L[i][j]=1+ calLength(a,b,L,i+1,j+1,n,m);
                //return L[i][j];

            }
            else
            {
                L[i][j]=1+ calLength(a,b,L,i+1,j,n,m);
               // return L[i][j];
                //return 1+calLength(a,b,L,i+1,j,n,m);
            }
        }
    }
    */
