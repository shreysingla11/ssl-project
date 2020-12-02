#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
struct matchedBlocks
{
    int first;
    int second;

};
int main()
{
    bool squareFound=false;
    string s;
    int l=1;
    double n;
    int numblocks,i,j,k,matching;
    bool matched;
    cin>>s;
    vector <matchedBlocks> *found;
    matchedBlocks *ithMatch;
    n = s.size()+0.0;
    for (; (l<((n+2)/4))&&(!squareFound); l*=2)
    {
        //n by l blocks
        //cout<<"l = "<<l<<endl;
        numblocks = ceil(n/l);
        for (i=1; (i<=numblocks)&&(!squareFound); i++) //iterate over each block
        {
            //cout<<"i = "<<i<<endl;
            if (i>2) delete found;
            found=new vector<matchedBlocks> ;
            matched = false;
            for(j=(i-1)*l,k=i*l; (k<=i*l+4*l-3);) 	//iterate within the blocks
            {
                //cout<<"j = "<<j<<" k = "<<k<<" i = "<<i<<endl;
                if(s[j]==s[k])
                {
                    if (j==l*i-1)
                    {
                        matched = true;
                        ithMatch = new matchedBlocks;
                        ithMatch->first = (i-1)*l;
                        ithMatch->second = k-l+1;
                        (*found).push_back(*ithMatch);	//identify j and k because occurence found
                        j=(i-1)*l;
                        k++;
                    }
                    else
                    {
                        j++;
                        k++;
                    }
                }
                else
                {
                    if (j==(i-1)*l) k++;
                    j=(i-1)*l;
                }
            }

            //got found.
            if ((*found).size())
            {
                int matchingK=((*found)[0]).second;
                int matchingI=((*found)[0]).first;
                int y = matchingK;
                int x = matchingI;
                for(; (y>=matchingI+l)&&(x>=0);)
                {
                    if (s[x]!=s[y]) break;
                    else
                    {
                        x--;
                        y--;
                    }
                }
                x++;
                y++;						//left extension
                int rightX = matchingI+l-1;
                int rightY = matchingK+l-1;
                for(; (rightX<y)&&(rightY<=n-1);)
                {
                    if (s[rightX]!=s[rightY]) break;
                    else
                    {
                        rightX++;
                        rightY++;
                    }
                }
                rightY--;
                rightX--;
                if (y==rightX+1)
                {
                    squareFound=true;
                    cout<<rightX-x+1 <<" "<<x<<endl;
                    //cout<<"l = "<<l<<" matchingI = "<<matchingI<<" matchingK = "<<matchingK<<endl;
                }
                if (squareFound==false && (*found).size()>1)
                {
                    int matchingK=((*found)[1]).second;
                    int matchingI=((*found)[1]).first;
                    int y = matchingK;
                    int x = matchingI;
                    for(; (y>=matchingI+l)&&(x>=0);)
                    {
                        if (s[x]!=s[y]) break;
                        else
                        {
                            x--;
                            y--;
                        }
                    }
                    x++;
                    y++;						//left extension
                    int rightX = matchingI+l-1;
                    int rightY = matchingK+l-1;
                    for(; (rightX<y)&&(rightY<=n-1);)
                    {
                        if (s[rightX]!=s[rightY]) break;
                        else
                        {
                            rightX++;
                            rightY++;
                        }
                    }
                    rightY--;
                    rightX--;
                    if (y==rightX+1)
                    {
                        squareFound=true;
                        cout<<rightX-x+1 <<" "<<x<<endl;
                        //cout<<"l = "<<l<<" matchingI = "<<matchingI<<" matchingK = "<<matchingK<<endl;
                    }
                }
            }

        }
    }
    if (!squareFound) cout<<"0 0"<<endl;
    return 0;
}
