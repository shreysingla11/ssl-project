#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<unordered_map>

using namespace std;

unordered_map<long long int, char> hash_table;
unordered_map<long long int, char>::iterator iterator_returned;
long long int arr[26];

//int toggle(int i)
//{
//    if(i==1)return 0;
//    if(j==0)return 1;
//}

void print(vector<int> a)
{
    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i];
    }
    cout<<endl;
}

long long int decimal(vector<int> a)
{
    long long int temp=0;
    for(int i=0; i<45; i++)
    {
        temp += a[44-i] * pow(2,i);
    }
    return temp;
}

int main()
{
    //unordered_map hash_table;
    int number;
    //cin>>number;
    //vector<vector<int> > large_binary_set;
    //int count=0;
    for(int letter=0; letter < 26; letter++)
    {
        vector<int> small_binary;
        small_binary.resize(5,0);
        vector<int> large_binary;
        large_binary.resize(45,0);
        int letter_copy = letter;


        //***********************
        int place = 4;

        while(letter_copy != 0)
        {
            small_binary[place] = (letter_copy)%2;
            letter_copy = letter_copy / 2;
            place--;
        }
        //5 Digit Binary Number Formed
        //*************************

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<9; j++)
            {
                large_binary[ (9*i) + j ]=small_binary[i];
            }
        }
        //45 bit Array done
        //arr[letter] = decimal(large_binary);
        //hash_table[entry] = (char(letter+97));
//}

    //int i =0;
    //while(i<26 )
        //for (int i = 0; i < 26; ++i)
		//{
            long long int p = decimal(large_binary);
			hash_table[p]=(char(letter+97));
			for (int j=0;j<45;++j)
			{
				long long int value1=p^((long long int)1<<j);
				hash_table[value1]=(char(letter+97));
				for (int k = j+1; k<45; ++k)
				{
					long long int value2=p^((long long int)1<<j)^((long long int)1<<k);
					hash_table[value2]=(char(letter+97));
					for(int l = k+1; l<45; ++l)
					{
						long long int value3=p^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l);
						hash_table[value3]=(char(letter+97));
						for(int m = l+1; m<45; ++m){
							long long int value4=p^((long long int)1<<j)^((long long int)1<<k)^((long long int)1<<l)^((long long int)1<<m);
							hash_table[value4]=(char(letter+97));
							// if()
						}
					}
				}
			}}
            //i++;
		//}

    /*
        for(int j=0; j<45; j++)
        {
            entry=entry^(1<<j);
            hash_table[entry]= (char(letter+97));


            for(int k=j+1; k<45; k++)
            {
                entry=entry^(1<<k);
                hash_table[entry]=(char(letter+97));


                for(int l=k+1; l<45; l++)
                {
                    entry=entry^(1<<l);
                    hash_table[entry]=(char(letter+97));


                    for(int m=l+1; m<45; m++)
                    {
                        entry=entry^(1<<m);
                        hash_table[entry]=(char(letter+97));
                    }

                }

            }


        }
    */

        /*

        long long int temporary = decimal(large_binary);
        //print(small_binary);
        for(int i=0; i< 46; i++)
        {
            if(i==45)
            {
                large_binary[i] = 1 - large_binary[i];
                temporary += large_binary[i] * pow(2,45-i);

                //reset
                count++;

                //print(large_binary);
                cout<<temporary<<endl;
                large_binary[i] = 1 - large_binary[i];
                break;
            }
            large_binary[i] = 1 - large_binary[i];
            temporary += large_binary[i] * pow(2,45-i);
            for(int j=i+1; j<46; j++)
            {
                if(j==45)
                {
                    large_binary[j] = 1 - large_binary[j];
                    //reset
                    long long int temporary = decimal(large_binary);
                    //print(large_binary);
                    count++;
                    cout<<temporary<<endl;
                    large_binary[j] = 1 - large_binary[j];
                    break;
                }
                large_binary[j] = 1 - large_binary[j];


                for(int k=j+1; k<46; k++)
                {
                    if(k==45)
                    {
                        large_binary[k] = 1 - large_binary[k];
                        //reset
                        long long int temporary = decimal(large_binary);
                        //print(large_binary);
                        count++;
                        cout<<temporary<<endl;
                        large_binary[k] = 1 - large_binary[k];
                        break;
                    }
                    large_binary[k] = 1 - large_binary[k];

                    for(int l=k+1; l<46; l++)
                    {
                        if(l==45)
                        {
                            large_binary[l] = 1 - large_binary[l];
                            //reset
                            count++;
                            long long int temporary = decimal(large_binary);
                            //print(large_binary);
                            cout<<temporary<<endl;
                            large_binary[l] = 1 - large_binary[l];
                            break;
                        }
                        large_binary[l] = 1 - large_binary[l];
                        long long int temporary = decimal(large_binary);
                        //print(large_binary);
                        count++;
                        cout<<temporary<<endl;
                        large_binary[l] = 1- large_binary[l];
                    }

                    large_binary[k] = 1 - large_binary[k];
                }

                large_binary[j] = 1 - large_binary[j];
            }

            large_binary[i] = 1 - large_binary[i];
        }
        //Made All Possible Combinations of the 45 bit Number
        */

        //large_binary_set.push_back(large_binary);

    //cout<<count;
    /*
    while(number > 0)
    {
        long long int query;

    }
    */
    long long int variable;
    //int number;
    scanf("%d",&number);

    while(number>0)
    {
        scanf("%lld",&variable);
        iterator_returned = hash_table.find(variable);
        if(iterator_returned == hash_table.end())
        {
            printf("?");
        }
        else printf("%c",iterator_returned->second);
        number--;
    }

    return 0;

}
