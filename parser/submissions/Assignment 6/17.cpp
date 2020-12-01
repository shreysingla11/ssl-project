#include <iostream>
using namespace std;



int main(){
    string s;
    cin >> s;
    
    int l=1;
    int len=s.length();
    bool found = false;
    int ans1=0,ans2=0;
    while(l<=len){
        

        int start=0;//block starts here
        while(start<len){
            //check 2nd occurence of the block starting at start
            int index1=start,index2=start+l;
            int matched=0;
            int max2=min(4*l -2 + start,len-1);
            while(index2 <= max2 && !found){

//            	cout << "max2 " << max2<<"   l     =         "<<l << endl;
//            	cout << "checking " << index1 << " , " << index2 << endl;

                if(s[index1] == s[index2]){
                    matched++;


                    if(matched == l){
                        //extend strings to find square
                        int s1=index1-l+1,s2=index2-l+1,e1=index1,e2=index2;
                        
/*
                        cout << endl;
                        for(int i=s1;i<=e1;i++)
                        	cout << s[i];
                        cout << endl << endl;
                        for(int i=s2;i<=e2;i++)
                        	cout << s[i];
                        cout << endl;
*/

                        while(s1 != 1 && s[s1-1] == s[s2-1] && s2-e1>1){
                            //cout << "w4"<<endl;
                            s1 --;
                            s2 --;
                        }
                        
                        if(s2 - e1 == 1){
                            found = true;
                            if(ans1 == 0 || ans1>e1-s1+1){


                                ans1 = e1-s1+1;
                                ans2 = s1;

  //                          	cout << "yolo " << ans1 << "  " << ans2 << endl;
                            }
                        }
                        else{
                            while((e2 +1 != len) && s[e1+1] == s[e2+1] && s2 - e1 > 1){
                                
                                //    cout << "w5"<<endl;
                                e1 ++;
                                e2 ++;
                            }
                            if(s2 - e1 == 1){
                                found = true;
                                if(ans1 == 0 || ans1>e1-s1+1){
                                    ans1 = e1-s1+1;
                                    ans2 = s1;

    //                        	cout << ans1 << "  " << ans2 << endl;
                                }
                            }
                        }
                        
                        
                        
                        
                        //finding second occurence
      //                  cout <<"second \n";
                        matched = 0;
                        index2++;
                    }

                    index1 ++;
                	index2 ++;
                    
                }
                else{
                    index1 = start;
                    index2 ++;
                    matched = 0;
                }



            }
            start += l;
        }
        l <<= 1;
    }
    
    cout << ans1 <<" "<< ans2 << endl;
    
}