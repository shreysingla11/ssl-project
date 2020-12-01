#include<iostream>
#include<string>
using namespace std;

string entry;
int sizer;
bool same_block = false;
bool breaker = true;


int same_block_checker(int index, int l)
{
    int k = (2*l - 1);
    while( k <= (3*l - 1) )
    {
        int position = 0;
        //cout<<k;
        for(position = 0; (position < l) && (index + position + k < sizer)  ; position++)
        {
            //cout<<"Hi";
            //cout<<index+position+k;
            if( entry[index + position] != entry[index + k + position])
            {
                //cout<<position;
                breaker = false;
                break;
            }

            if(position == l-1)
            {
                return k + index;
            }
        }
        if(breaker == false)
        {
            k = k + position + 1;
        }
    }

    return -1;

}

int main()
{

    cin >> entry;
    //entry = 123213231213123132312132123;
    sizer = entry.length();

    int i=1;

    for(int l = 1; l< 1 + ((sizer + 4)/8) ; l = l*2 )
    {
        for(i=0 ; i< sizer/l ; i++ )
        {
            if(same_block_checker(i*l,l) > 0)
            {

                int first_start = i*l;
                int second_start = same_block_checker(i*l , l);


                //cout << same_block_checker(1,2) <<endl;
                //Check while decreasing counter before the blocks
                int indexer = 1;
                while( (second_start - indexer) >= (first_start + l))
                {
                    if(entry[first_start - indexer] != entry[second_start -indexer ] )
                    {
                        break;
                    }

                    indexer++;
                }
                indexer--;
                if( (first_start + l) == (second_start - indexer))
                {
                    cout<< l + indexer << " " << first_start - indexer<<endl;
                    return 0;
                }

                indexer = 1;
                //Check while increasing counter after the blocks
                while( second_start > first_start + l + indexer - 1)
                {
                    if(entry[ first_start + l + indexer - 1 ] != entry[ second_start + indexer + l - 1] )
                    {
                        break;
                    }

                    indexer++;
                }
                indexer--;
                if( (first_start + l + indexer - 1) == (second_start - 1))
                {
                    cout<< l + indexer << " " << first_start<<endl;
                    return 0;
                }
            }
        }
    }
cout<<"0"<<" "<<"0";
return 0;
}
