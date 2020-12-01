#include <iostream>
#include <string>

using namespace std;

void search2nd(string &s,int &l,int &i1,int &i2,int &n)
{
    //block is of length l

    //check the second occurence till 3n-2 places to right of block formed from s[o] to s[l-1]
    //if present return the id of begining of the second occurence as well as of first occurence
    //if not present check occurence of block formed from s[l] to s[2l-1]
    int i=0;
    while(i<((n/l)*l))//check various boxes
    {
        //check second occurence of block from s[i] to s[i+l-1]
        int k=i+l;
        while((k<=(i+(3*l)-2))&&(k<n))//limit the starting position of the second occurence to be checked
        {
            int m=i;//position through the block assigned with the starting
            while((s[m]==s[k])&&(m<(i+l)))
            {
                m++;
                k++;
            }
            if (m==i)//doesn't match at first position itself
            {
                k++;
            }
            if (m==(i+l-1))//complete block matched second occurrence begins at position (k-l) with the block begining at position i
            {
                i1=i;
                i2=k-l;
                return;
            }
            //else s[m]!=s[k]
        }//no second occurence of the block

        i=i+l;//check for other block
    }//all blocks have been checked
    return;
}//end of search2nd()

void detect(string &s,int &l,int &ls,int &p,int &n)
{
    while(true)
    {
    int i1,i2;
    i1=0;//position of begining of block
    i2=0;//position of begining of its second occurence
    search2nd(s, l, i1, i2, n);
    if(i2!=0)//second occurence of a block of length l begining at i1 found at begining position i2
    {
        //try to extend the substring on both sides of the occurrence of the block
        int p1,p2;

        p1=i1-1;
        p2=i2-1;
        while((p2>(i1+l-1))&&(s[p1]==s[p2]))//check square on the left side
        {
            p1--;
            p2--;
        }
        if(p2==(i1+l-1))
        {
            //square found on extending the left side
            ls=p2-p1;
            p=p1+1;
            return;
        }

        else//try on the right side
        {
        int p11,p22;
        p11=i1+l;
        p22=i2+l;
        while((p11<i2)&&(s[p11]==s[p22]))//check square on the right side
        {
            p11++;
            p22++;
        }
        if(p11==i2)
        {
            //square found on extending the right side
            ls=p11-p1-1;
            p=p1+1;
            return;
        }

        else//no square present
        {
            if((2*l)>=(n/4))
            {
                return;
            }

            l=2*l;
        }

        }
    }
    else
    {
        if((2*l)>=(n/4))
        {
            return;
        }

        l=2*l;
    }

    }
}

int main()
{
    string s;
    cin>>s;//input the string
    int n=s.length();//length of the string
    int l=1;
    int ls=0;
    int p=0;
    detect(s, l, ls, p, n);
    cout<<(ls+1)<<" "<<(p+1);//output length of shortest square and its position
    return 0;
}
