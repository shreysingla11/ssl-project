
class distinct{


 struct interval
    {
    int start;
    int end;

    };


    struct segment{
    interval inter;
    vector<int> v;
    };




vector<segment> seg_tree;

public:
distinct(vector<int> input)
    {
    vector<int> array;
    vector<int> l;
    array=input;

        int n=array.size();
        int height=0;

    l.resize(n,0);
    for(int i=0;i<n;i++)
        {
        int j=i-1;
        for(;j>=0;j--)
            {
            if(array[j]==array[i])
                {
                l[i]=j;
                break;
                }
            }
        if(j<0)
            l[i]=-1;
        }

    int temp=n;
    while(temp>0)
        {
        temp/=2;
        height++;
        }
    seg_tree.resize(n);

    for(int i=0;i<n;i++)
        {
        seg_tree[i].v.resize(n,0);
        }
    int k_max=1;

    for(int i=1;i<=height;i++)
        {

            for(int k=0;k<k_max;k++)
                {
                    int star=((n/k_max)*(k))+((n/k_max)/2);
                    int en=(n/k_max)*(k+1);
                    seg_tree[k_max+k-1].inter.start=star;
                    seg_tree[k_max+k-1].inter.end=en;
                }
        k_max*=2;
        }

    seg_tree[n-1].inter.start=0;
    seg_tree[n-1].inter.end=1;

    for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
            {
            if(j==0)
                {
                if(l[j]>=seg_tree[i].inter.start&&l[j]<seg_tree[i].inter.end)
                seg_tree[i].v[0]=1;
                else
                seg_tree[i].v[0]=0;
                }
            else
                {
                if(l[j]>=seg_tree[i].inter.start&&l[j]<seg_tree[i].inter.end)
                    {
                    seg_tree[i].v[j]=seg_tree[i].v[j-1]+1;

                    }
                else
                    {
                    seg_tree[i].v[j]=seg_tree[i].v[j-1];
                    }
                }
            }
        }

    }
int num_distinct(int a,int b)
{
    int root=0;
    int curr=root;
    int count=0;
    while(true)
        {
        if(a==seg_tree[curr].inter.start)
            {
            count+=seg_tree[curr].v[b];
            break;
            }
        else if(a>seg_tree[curr].inter.start)
            {
                curr=2*curr+2;
            }
        else if(a<seg_tree[curr].inter.start)
            {
                count+=seg_tree[curr].v[b];
                curr=2*curr+1;
            }
        }

    return b-a+1-count;
}
};


