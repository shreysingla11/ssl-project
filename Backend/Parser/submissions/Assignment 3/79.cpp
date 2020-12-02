#include<cstdio>

using namespace std;
int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    int *a = new int[n+1];
    int *b=new int[m+1];
    int *ans1=new int[n+1];
    int *ans2=new int[n+1];

    for(int i =1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i =1;i<=m;i++)
    {
        scanf("%d",&b[i]);
    }

    if(a[n]==b[m])ans2[n]=1;
    else ans2[n] = n+1;


    for(int i =n-1;i>=1;i--)
    {
    if(a[i]==b[m])ans2[i]=1;
    else ans2[i]=ans2[i+1]+1;


    }


  int infinityp=n;

    for(int j = m-1;j>=1;j--)
    {
    ans1[infinityp]=n+1;
    for(int i =infinityp-1;i>=1;i--)
    {

        if(b[j]==a[i]){ans1[i]=1+ans2[i+1];}
        else ans1[i]=ans1[i+1]+1;
        if(ans1[i]>n){infinityp = i;}


    }


    for(int k =1;k<=infinityp;k++)
    {ans2[k]=ans1[k];}
    }

    int index;
    int mi = n+1;
    for(int i = n;i>=1;i--)
    {
    if(mi>ans1[i]){index = i;mi = ans1[i];}
    }
    if(mi<n+1)printf("%d %d",mi,index);
    else printf("infinity");

return 0;


}
