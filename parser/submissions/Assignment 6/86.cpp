# include <iostream>
# include <string>
using namespace std;
bool  check(string str, int l,int &s_len,int &l_index) //this function will do everything
{
    //cout<<"6"<<endl;
    s_len=0;
    l_index=0;
    //cout<<"l is"<<l<<endl;
    int len=str.length();
    int num_blocks=len/l;
    len=len-len%l;
    bool foundmatch;
    for(int i=0; i<num_blocks-1; i++) //i represents the block we are considering right now
    {
        //cout<<"14"<<endl;
        foundmatch=false;
        //for compare each block with the next occurrence for it.
        int sindex=l*i;
        //start withis block and go from sindex + 2l-1 to sindex + 3l-2
        int max_dist=2*l-1;
        int k;
        for(; max_dist<=3*l-2;)//change maxdist accordingly
        {
            //now check the blocks
           // cout<<max_dist<<"this is max_dist"<<endl;
            //cout<<"23"<<endl;
            bool misd_block=false;

            for( k= sindex; k<sindex+l; k++)
            {
                if(str[k]!=str[k+max_dist])
                {
                    //mismatch found
                    //cout<<"mismatchfound;";
                    //cout<<str.substr(sindex,max_dist)<<"!="<<str.substr(sindex+max_dist,max_dist)<<endl;
                    misd_block=true;
                    break;
                }

            }

            if(misd_block)
            {
                //mismatch found;
                //start from ahead of this.
                //cout<<str.substr(sindex,max_dist)<<"!="<<str.substr(sindex+max_dist,max_dist)<<endl;

                if(max_dist==k-sindex+max_dist){
                max_dist++;
                }
                else{
                max_dist=k-sindex+max_dist;
                }


                //cout<<max_dist<<endl;


            }
            else
            {
                //found a match for block;
                //cout<<str.substr(sindex,max_dist)<<"!="<<str.substr(sindex+max_dist,max_dist)<<endl;
                foundmatch=true;
                break;

            }

        }

        if(foundmatch)
        {
            //cout<<"foundmatch"<<endl;//if found a match
            //go ahead and find the max length
            //now find the index where it all starts.
            int len_w=l;
            int s_w=sindex-1;
            int s_next=s_w+max_dist;
            int e_w=sindex+l;
            int e_next=e_w+ max_dist;
            while(s_w>=0 && str[s_w]==str[s_next] && (s_next>=sindex+l) )
            {
                len_w++;
                s_w--;
                s_next--;
            }
            //s_w is the sstart of the the ww
            s_w++;
            s_next++;




            if(s_next==sindex+l-1) //last indices should match
            {
                //found a square
                if(len>=2*l-1)
                {
                    //tis is the string
                    l_index=s_w;
                    s_len=len_w;

                    break;
                }
                else
                {
                    // not of appropriate length
                    //go for next block
                }


            }
            else //bboth have different end
            {
                //now match the right end;
                while(e_next<len && str[e_w]==str[e_next] && (e_w<sindex+max_dist))
                {
                    len_w++;
                    e_w++;
                    e_next++;

                }
                e_next--;
                e_w--;

                if(e_w==sindex+max_dist-1)
                {
                    //right end matched;
                    if(len>2*l-1)
                    {

                        l_index=s_w;
                        s_len=len_w;
                        break;
                    }
                    else
                    {
                        //insuffcinet length
                    }

                }
                else{
                    //mismatch continue
                }


            }



        }
        else
        {
           //continue do nothing
        }

    }

    return foundmatch;


}
int main()
{
    string input;//take the input
    cin>>input;
    //cout<<150<<endl;
    int s_len=0,l_index=0,l=1;
    bool result=false;
    while(l<=input.length()-1 && (!result))
    {
        //cout<<155<<endl;
        result=check(input,l,s_len,l_index);
        if(!result)
        {
            l=l*2;
        }
    }
    cout<<s_len<<" "<<l_index<<endl;

    /* code */
    return 0;
}
