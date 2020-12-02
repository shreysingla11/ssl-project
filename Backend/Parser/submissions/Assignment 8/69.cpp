#include <iostream>
#include<vector>
using namespace std;
std::vector<double> merge(std::vector<double> left, std::vector<double> right);
std::vector<double> mergeSort(std::vector<double> vec);
void print(vector<double> v);

void sort(std::vector<double>& vec) { // using reference here std::vector<double>& - to be able to change vector inside function
    vec = mergeSort(vec);
//    for (unsigned int i = 0; i < vec.size(); i++){
//        std::cout << vec[i] << " ";
//    }
}

std::vector<double> merge(std::vector<double> left, std::vector<double> right) {
    std::vector<double> ret(left.size() + right.size(), -1); // construct vector with left.size() + right.size() elements assigned to -1
    int left_position = 0;
    int right_position = 0;
    int ret_position = 0;
    while (left_position < left.size() && right_position < right.size()) {
        double left_value = left[left_position];
        double right_value = right[right_position];
        if (left_value < right_value) {
            ret[ret_position++] =  left_value;
            left_position++;
        } else {
            ret[ret_position++] = right_value;
            right_position++;
        }
    }
    while (left_position < left.size()) {
        ret[ret_position++] = left[left_position++];
    }
    while (right_position < right.size()) {
        ret[ret_position++] = right[right_position++];
    }
    return ret;
}

std::vector<double> mergeSort(std::vector<double> vec){
    if (vec.size() < 2){
        return vec;
    }
    int middle = vec.size() / 2;
    std::vector<double> left(vec.begin(), vec.begin() + middle);
    std::vector<double> right(vec.begin() + middle, vec.end());

    left = mergeSort(left);
    right = mergeSort(right);
    std::vector<double> ret = merge(left, right);
    return ret;
}
void print(vector<double> v)
{
	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}
int main()
{
vector<double> position,length,endp;


double nolanes=0,width=0,vs=0,vf=0,t1=0,t2=0;
double len=0,pos=0;
int i=0,y=0;
char x;
cin>>nolanes;
cin>>width;
cin>>vs;
cin>>vf;
cin>>t1;
cin>>t2;
for (i = 0; i < nolanes; i++)
{
cin>>x;
cin>>y;
for(int j=0;j<y;j++){
cin>>len;
length.push_back(len);
cin>>pos;
if(x=='E'){pos=-pos;}
pos/=vs;
len/=vs;
position.push_back(pos+(width/vf));
endp.push_back((pos+len));
}
}
sort(position);
sort(endp);
int p=0,q=0,counter=0;
double curr=0,maximum=0,startmax=0;
while(true)
{

if(endp[p]<position[q])
                {counter--;
                 if(counter==0){if(endp[p+1]<position[q])
                                                {curr=endp[p+1]-endp[p];}
                                else {curr=position[q]-endp[p];}
                                if(maximum<curr){maximum=curr;
                                                startmax=endp[p];}}
                                        p++;}
else {counter++;
        if(counter==0){if(endp[q+1]<position[p])
                                                {curr=endp[q+1]-position[q];}
                                else {curr=position[p]-position[q];}
                                if(maximum<curr){maximum=curr;
                                startmax=position[q];}}
                                q++;}

//check this
if((p>=endp.size())||(q>=position.size())){break;}

}
if(t1>startmax){startmax=t1;}
if(t2<maximum+startmax){maximum=t2-startmax;}
cout<<maximum<<endl;
    return 0;
}
