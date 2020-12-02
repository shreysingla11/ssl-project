#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str[100], w[50];
    int l=1;
    cin >> str;
    int start, fin;
    start= 2*l - 1;
    fin = 4*l - 2;
    int i,j,k,flag,pos;
    k=0;
    flag=0;
    int n=strlen(str);
    while (l<((n+1)/2))
    {
        start= 2*l - 1;
        fin = 4*l - 2;
        for (j=start;j<=fin;j++)
        {
            for (i=0;i<n-j;i++)
            {
                if (str[i]==str[i+j])
                {
                    w[k]=str[i];
                    w[k+1]='\0';
                    if (k==0)
                    {
                        pos=i;
                    }
                    k++;
                    if (k==j)
                    {
                        flag=1;
                        break;
                    }
                }
                if (str[i]!=str[i+j])
                {
                    k=0;
                    pos=0;
                    flag=0;
                    w[k]='\0';
                }
            }
            if (flag==1)
            {
                break;
            }
        }
        if (flag==1)
        {
            break;
        }
        l=l*2;
    }
    cout << strlen(w) << " " << pos;
    return 0;
}
