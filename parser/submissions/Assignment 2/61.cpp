#include<iostream>

using namespace std;


struct point
{
    int x;
    int y;
    int index;
};

int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    return (val > 0)? 1: -1;
}

void recursive(point coordinates[],int number)
{bool checker = false;
    int clock_index[] = {0};
    int anticlock_index[] = {0};
    int clock_red;
    int clock_blue;
    int anticlock_red;
    int anticlock_blue;
    int anticlock_total=0;
    int clock_total=0;
    if(number == 2)
    {
        cout<<coordinates[0].index<<" "<<coordinates[1].index<<endl;
        return;
    }
    for(int i=1; i<number; i++)
    {
        int clock_index[] = {0};
        int anticlock_index[] = {0};
        int clock_red=0;
        int clock_blue=0;
        int anticlock_red=0;
        int anticlock_blue=0;
        int anticlock_total=0;
        int clock_total=0;
        for(int j=1; j!=i && j <number ; j++)
        {
            if(orientation(coordinates[0],coordinates[i],coordinates[j]) > 0)
            {
                clock_index[clock_total] = j;
                clock_total++;
                if(j<=number/2) clock_red++;
                else clock_blue++;
            }
            else
            {
                anticlock_index[anticlock_total] = j;
                anticlock_total++;
                if(j<=number/2) anticlock_red++;
                else anticlock_blue++;
            }
        }
        if(anticlock_red == anticlock_blue)
        {
            point next_array[anticlock_total];
            for(int k=0; k<anticlock_total; k++)
            {
                next_array[k] = coordinates[anticlock_index[k]];

            }
            point remaining_array[number - anticlock_total];
            int counter = 0;
            for(int p=0; p < number ; p++)
            {
                for(int q=0; q<clock_total; q++)
                {
                    if(p != clock_index[q])
                    {
                        checker = true;
                        break;
                    }
                }
                if(checker == true){
            remaining_array[counter] = coordinates[p];
                        counter++;
                        checker = false;}
            }
            recursive(next_array,anticlock_total);
            recursive(remaining_array,number - anticlock_total);
            return ;
        }

        if(clock_red == clock_blue)
        {
            point next_array[clock_total];
            for(int k=0; k<clock_total; k++)
            {
                next_array[k] = coordinates[clock_index[k]];
            }
            point remaining_array[number - clock_total];
            int counter = 0;
            for(int p=0; p < number ; p++)
            {
                for(int q=0; q<clock_total; q++)
                {
                    if(p != clock_index[q])
                    {
                        checker = true;
                        break;
                    }

                }

                if(checker == true){
             remaining_array[counter] = coordinates[p];
                        counter++;
                        checker  = false;
            }
            }
            recursive(next_array,clock_total);
            recursive(remaining_array,number - clock_total);
            return ;
        }

    }
}


int main()
{
    int number;
    cin>>number;
    point coordinates[number];
    for(int i=0; i<number; i++)
    {
        cin>>coordinates[i].x>>coordinates[i].y;

    }
    for(int i=0; i<number/2; i++)
    {
        coordinates[i].index = i;
    }
    for(int i=number/2; i<number; i++)
    {
        coordinates[i].index = (number/2) - i;
    }
    recursive(coordinates,number);
}
