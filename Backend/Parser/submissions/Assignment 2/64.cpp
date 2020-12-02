#include<iostream>

using namespace std;
int red[5000][2], blue[5000][2];
int o(int a[2], int b[2], int c[2])
{
    if( ((b[1]-a[1])*(c[0]-b[0])) > ((b[0]-a[0])*(c[1]-b[1])) )
        return 1;
    else return 2;
}

bool intersect(int p1[2], int p2[2])
{
    int o1 = o(red[p1[0]], blue[p1[1]], red[p2[0]]);
    int o2 = o(red[p1[0]], blue[p1[1]], blue[p2[1]]);
    int o3 = o(red[p2[0]], blue[p2[1]], red[p1[0]]);
    int o4 = o(red[p2[0]], blue[p2[1]], blue[p1[1]]);

    if (o1 != o2 && o3 != o4)
        return true;
    return false;
}

void pairing(int seq[], int pivot, int n)
{

    if(n==2)
    {
        if(seq[0]<seq[1])
        {
            int temp=seq[1];
            seq[1]=seq[0];
            seq[0]=temp;
        }
        return;
    }
    int random=0;
    bool found=false;
    int n_pivot;
    int count_r=0, count_b=0;
    int n_seq1[n],n_seq2[n],counter1=0,counter2=0;
    for(int i=1;i<n;i++)
    {
        cout<<"in"<<endl;
        count_r=0, count_b=0;
        n_pivot=seq[i];
        counter1=0;counter2=0;


            for(int j=1;j<n;j++)
        {
            if(seq[j]!=n_pivot)
            {
                cout<<"in loop"<<endl;
                int pivot_c[2], n_pivot_c[2],n_c[2];
                if(pivot>=0)
                {
                    pivot_c[0]=red[pivot][0];
                    pivot_c[1]=red[pivot][1];
                }
                else
                {
                    pivot_c[0]=blue[-pivot-1][0];
                    pivot_c[1]=blue[-pivot-1][1];
                }
                //cout<<pivot_c[0]<<endl;
                if(n_pivot>=0)
                {
                    n_pivot_c[0]=red[n_pivot][0];
                    n_pivot_c[1]=red[n_pivot][1];
                }
                else
                {
                    n_pivot_c[0]=blue[-n_pivot-1][0];
                    n_pivot_c[1]=blue[-n_pivot-1][1];
                }
               // cout<<n_pivot_c[0]<<endl;
                if(seq[j]>=0)
                {
                    n_c[0]=red[seq[j]][0];
                    n_c[1]=red[seq[j]][1];
                }
                else
                {
                    n_c[0]=blue[-seq[j]-1][0];
                    n_c[1]=blue[-seq[j]-1][1];
                }
               // cout<<n_c[0]<<endl;

                if(o(pivot_c, n_pivot_c, n_c) ==1 )
                {
                    n_seq1[counter1]=seq[j];
                    counter1++;
                    if(seq[j]>=0)
                        count_r++;
                    else count_b++;
                }
                else
                {
                    n_seq2[counter2]=seq[j];
                    counter2++;
                }
            }
        }
        if(count_b==count_r && count_r!=0 && count_r!=n/2)
        {
            cout<<"end loop if"<<endl;
            n_seq2[counter2]=seq[pivot];
            counter2++;
            n_seq2[counter2]=seq[n_pivot];
            counter2++;
            break;
        }
        if(count_b==count_r && count_r==0 && ((n_pivot>=0 && pivot<0)||(n_pivot<0 && pivot>=0)))
        {
            random=1;
            n_seq1[counter1]=seq[pivot];
            counter1++;
            n_seq1[counter1]=seq[n_pivot];
            counter1++;
            break;
        }
        cout<<"end loop"<<endl;
    }

  //  cout<<"counter1="<<counter1<<" counter2="<<counter2<<endl;
    pairing(n_seq1,n_seq1[0],counter1);
    pairing(n_seq2,n_seq2[0],counter2);
    for(int i=0;i<counter1;i++)
    {
        seq[i]=n_seq1[i];
    }
    for(int i=counter1+1;i<n;i++)
    {
        seq[i]=n_seq2[i-counter1];
    }
    for(int i=0;i<n;i++)
        cout<<seq[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int main_pair[n/2][2];
    int sequence[n];



    for(int i=0;i<n/2;i++)
        cin>>red[i][0]>>red[i][1];
    for(int i=0;i<n/2;i++)
        cin>>blue[i][0]>>blue[i][1];

    for(int i=0;i<n/2;i++)
    {
        sequence[i]=i;
        sequence[n/2+i]=-i-1;
    }

   // bool intersect(int p1[2], int p2[2], int red[][2], int blue[][2]);
    //pairing(sequence, 0, n);
    stop:
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            int a[2]={i,i};
            int b[2]={j,j};
            if(intersect(a,b))
            {
                int temp10=blue[j][0];
                blue[j][0]=blue[i][0];
                blue[i][0]=temp10;
                int temp11=blue[j][1];
                blue[j][1]=blue[i][1];
                blue[i][1]=temp11;
                goto stop;
            }
        }
    }

    for(int i=0;i < n;i++)
    {
        if(i%2==0)
            main_pair[i/2][0]=sequence[i];
        else main_pair[i/2][1]= -sequence[i]-1;

        //cout<<sequence[i]<<endl;
    }

    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n/2;j++)
        {
            if(main_pair[i][0]>main_pair[j][0])
            {
                int temp1=main_pair[i][0];
                main_pair[i][0]=main_pair[j][0];
                main_pair[j][0]=temp1;

                int temp2=main_pair[i][1];
                main_pair[i][1]=main_pair[j][1];
                main_pair[j][1]=temp2;
            }
        }
    }

    for(int i=0;i<n/2;i++)
    {
        cout<<red[i]<<" "<<blue[i]<<endl;
    }
    return 0;
}
