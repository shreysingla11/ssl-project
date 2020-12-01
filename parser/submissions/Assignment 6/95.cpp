#include<cstdio>
#include<iostream>
#include<string>

using namespace std;



int main()
    {
     int t,k,temp;
     int mini,length;
     string a;
     cin>>a;
     bool check3=false;
     //cout<<a<<"\n";
     int n=a.length();
     /*int l=1;
     for(;l<=(n+2/4);l=l*2)
        {
         bool check2=false;
         for (int i=0;i<(n/l);i++)
            {
             bool check1=true;
             k=i*l;
             t=k+2*l-1;
             while (k<=i*l+l-1&&k<n&&t<n)
                {
                 if (a[k]==a[t]){k++;t++;}
                 if (a[k]!=a[t])
                    {
                     if(k==i*l)
                        {
                         if(t+1<=i*l+4*l-2){t++;}
                         else{check1=false;break;}

                        }
                     else{k=i*l;}
                    }
                }

            if (check1==true)
                {
                 int start=t-l;
                 k=i*l;
                 while(k>=0&&k<n&&start<n)
                    {
                     if(a[k]==a[start])
                        {
                         if (k>0)
                         {k--;
                         start--;
                         if (start==i*l+l)
                            {
                             mini=k;
                             length=l+(i*l-k);
                             check2=true;
                             break;
                            }
                        }
                         if (k==0)
                            {
                             mini=k;
                             temp=start;
                             k=i*l+l-1;
                             start=t-1;
                             while(start<n)
                                {
                                 if (a[k]!=a[start]){break;}
                                 if(a[k]==a[start])
                                    {
                                     k++;
                                     start++;
                                     if(temp==k+1)
                                        {
                                         length=(start-mini)/2;
                                         check2=true;
                                         break;
                                        }
                                    }
                                 }
                             if (check2==true){break;}
                            }
                        }
                    if (a[k]!=a[start])
                        {
                         if(k<i*l)
                            {
                             mini=k+1;
                             temp=start+1;
                             k=i*l+l-1;
                             start=t-1;
                             while(start<n)
                                {
                                 if (a[k]!=a[start]){break;}
                                 if(a[k]==a[start])
                                    {
                                     k++;
                                     start++;
                                     if(temp==k+1)
                                        {
                                         length=(start-mini)/2;
                                         check2=true;
                                         break;
                                        }
                                    }
                                 }
                             if (check2==true){break;}
                            }
                         if(k>i*l){break;}
                        }

                    }

                }
             if (check2==true){break;}
            }
         if (check2==true){check3=true;break;}
        }
    if (check3==true){cout<<mini<<" "<<length;}
    */
    cout<<0<<" "<<0;
    return 0;
    }
