#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
# define fr(i,n) for(int i=0;i<n;i++)
# define fr1(i,n) for(int i=1;i<=n;i++)

using namespace std;


int main()
{

    /**METHOD 2**/
    /**INPUT AND INITIALIZATIONS**/
    int n,w_len,w_st,s,Right,Left;
    bool w_fo,bl_fo;
    /**INITIALIZATIONS**/

    string str;
     //cout<<"YO";
    getline(cin,str);
    n=str.length();
    /**n contains the total length of the string**/
for(int l=1;l<=(n+2)/4;l*=2)
    {
        /**l contains the present substring length**/
        for(int str_p1=0;str_p1<=(n-l);str_p1+=l)
        {
            /**st_p1 is the begin index of block1**/
            if(str_p1>=n)break;
            s=str_p1;
            /**s is used just for convenience**/
            for(int str_p2=(s+(2*l)-1);str_p2<=(s+(4*l)-2);){

            /**st_p2 is the begin index of block2**/
            if(str_p2>=n||str_p2<0)break;
            /**for checking corros elements in blocks**/
            bl_fo=true;
            for(int i=0;i<l;i++){
                /**i is corros relative index **/

                 if((str_p2+i>=n)||str[str_p1+i]!=str[str_p2+i]){
                 bl_fo=false;
                 str_p2+=i;
                 if(i==0)str_p2++;
                 break;
                }
                 }

                 if(bl_fo==false)continue;
                 if(bl_fo==true){
                 /**BLOCK IS FOUND**/
                 /**EXTEND ON BOTH SIDES**/
                    Right=l;
                    /**Right is the right side of block index**/
                    w_fo=true;
                    while((str_p1+Right)<str_p2){

                     if(((str_p2+Right)>=n)||str[str_p1+Right]!=str[str_p2+Right]){
                     //w_fo=false;
                     break;
                     }
                     Right++;
                     }
                     Left=1;
                     //cout<<"enthu"<<endl;
                     while((str_p2-Left)>(str_p1+Right-1)){

                     if(((str_p2-Left)<0)||str[str_p2-Left]!=str[str_p1-Left]){

                     w_fo=false;
                     break;
                     }
                     Left++;
                     }
                    if(w_fo==true){
                    w_len=Right-Left+1;

                    w_st=str_p1-Left+1;
                    cout<<w_len<<" "<<w_st<<endl;
                    return 0;
                    }
                }
        str_p2+=l;
            }
        }
    }
    cout<<"0 0"<<endl;

    return 0;
}

