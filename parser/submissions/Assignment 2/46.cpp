#include<iostream>
#include<stdio.h>
using namespace std;

bool is_intersecting(float s1, float s2){
if(s1 == s2)    return true;
else            return false;
}

float slope(int a, int b, int c, int d){
    return (d-b)/(c-a);
}

int main(){
int n,i = 0,j = 0;
scanf("%d\n",&n);
float s1, s2;
int l1[n/2][2];
int l2[n/2][2];

for(i = 0; i < n/2 ; i++){
    scanf("%d %d\n", &l1[i][0], &l1[i][1]);
}

for(j = 0 ; j < n/2 ; j++){
    scanf("%d %d\n", &l2[j][0], &l2[j][1]);
}

for(i = 0 ; i < n/2 ; i++){
    s1 = slope(l1[i][0], l1[i][1], l2[i][0], l2[i][1]);
    for(j = i+1 ; j < n/2 ; j++){
        s2 = slope(l1[i+1][0], l1[i+1][0], l2[j][0], l2[j][1]);
        if(is_intersecting(s1, s2)){
            continue;
        }
        else {
            break;
        }
    }

}

for(i = 0 ; i< n/2 ; i++){
    printf("%d %d \n", l1[i][0], l1[i][1]);
}


return 0;











}
