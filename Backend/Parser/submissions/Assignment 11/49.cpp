#include <iostream>

using namespace std;

int main() {
    int T;
	long long int number;
	int ans;
	char ansC;
    int remainder;
    int ik1=0,ik2=9,ik3=18,ik4=27,ik5=36,ik6=45;
    int er1,er2,er3,er4,er5;
    int val1,val2,val3,val4,val5;
    int binNum[45]={0};
    int ss,ss1;

    cin>>T;
    while(T--){

        ss = 0;
        cin >> number;

        while(ss<45) {

            if(number <= 1) {
                binNum[ss] = number;ss++;
                break;
            }

            remainder = number%2;
            binNum[ss] = remainder;ss++;
            number = number / 2;

        }
        if(ss==45){cout<<"?";continue;}
        /*ss1 = ss;
        while(ss1<45){binNum[ss1]=0;ss1++;}*/

        er1=0;er2=0;er3=0;er4=0;er5=0;

        for (int ik = 0 ; ik < 45 ; ik++){
        if(ik<ss){
            if(ik<ik2 && binNum[ik]==0){er1++;}
            if(ik>=ik2 && ik<ik3 && binNum[ik]==0){er2++;}
            if(ik>=ik3 && ik<ik4 && binNum[ik]==0){er3++;}
            if(ik>=ik4 && ik<ik5 && binNum[ik]==0){er4++;}
            if(ik>=ik5 && binNum[ik]==0){er5++;}
        }else{
            if(ss<ik2){er2=9;er3=9;er4=9;er5=9;er1+=ik2-ss+1;}
            if(ss>=ik2 && ss<ik3){er3=9;er4=9;er5=9;er2+=ik3-ss+1;}
            if(ss>=ik3 && ss<ik4){er4=9;er5=9;er3+=ik4-ss+1;}
            if(ss>=ik4 && ss<ik5){er5=9;er4+=ik5-ss+1;}
            if(ss>=ik5){er5+=ik6-ss+1;}
        }/*
            if(binNum[ik+ik1]==0){er1++;}
            if(binNum[ik+ik2]==0){er2++;}
            if(binNum[ik+ik3]==0){er3++;}
            if(binNum[ik+ik4]==0){er4++;}
            if(binNum[ik+ik5]==0){er5++;}*/
        }
        if(er1>4){val1=0;er1=9-er1;}
        else{val1=1;}
        if(er2>4){val2=0;er2=9-er2;}
        else{val2=1;}
        if(er3>4){val3=0;er3=9-er3;}
        else{val3=1;}
        if(er4>4){val4=0;er4=9-er4;}
        else{val4=1;}
        if(er5>4){val5=0;er5=9-er5;}
        else{val5=1;}

        if(er1+er2+er3+er4+er5>4 || ss==45){cout<<"?";}
        else{
            ans = (val1*1) + (val2*2) + (val3*4) + (val4*8) + (val5*16);
            ans += 97;
            ansC = ans;
            if(ans < 97 || ans > 122){cout<< "?";}
            else{cout<<ansC;}
        }
    }
	return 0;

}
