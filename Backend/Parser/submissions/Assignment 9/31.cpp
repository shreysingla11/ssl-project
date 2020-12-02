#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class boolfunc{
    private:
        //root value/variable is stored
        int index,no_of_terms; //the root value index
        boolfunc* left;
        boolfunc* right;
        bool left_node,right_node;
        //int no_of_terms; //the no of terms obtained in the sum of product expression including that variable
        //vector<int> variables[no_of_terms]; //stores the no_of_variables and then variables in each term after it
        //pointers to the subtrees are stored here
    public:
        //operations on the trees are stored here
        boolfunc(); //- constructor that does nothing
        //~boolfunc(); //- destructor that should free all allocated memory
        boolfunc( boolfunc const &); //- copy constructor
        void operator+=(boolfunc const &); //- or operator
        void operator*=(boolfunc const &); //- and operator
        void operator~(); //- not operation
        bool operator==(boolfunc const &); //- check for equality.
        void read(); //- reading the input in lexicographic order for a given no of terms
        void print(); //- printing the same way input is given
        void subst(int i, bool v); //-modifies the function by setting x_i to v creating a new function

        //my own functions
        void read(vector<int> variables[],int count_temp);
        string print(int temp);
};

boolfunc::boolfunc(){
    //constructor that does nothing
}
void boolfunc::read(){
    cout<<"This is the read() \n";
    cin>>no_of_terms;
    //assuming that in the input the variables are given in lexicographic order initially in the input
    vector<int> variables[no_of_terms];
    int temp1,temp2,max_index=0;
    for(int i=0;i<no_of_terms;i++){
        cin>>temp1;
        variables[i].push_back(temp1);
        for(int j=1;j<=temp1;j++){
            cin>>temp2;
            variables[i].push_back(temp2);
        }
        if(max_index<variables[i].back()){
            max_index=variables[i].back();
        }
        else if(max_index<(-1*variables[i].back())){
            max_index=(-1*variables[i].back());
        }
    }
    index=max_index;
    int left_count=0,right_count=0;
    for(int i=0;i<no_of_terms;i++){
        if(variables[i].back()==max_index){
            variables[i].pop_back();
            variables[i][0]--;
            variables[i].push_back(1);
            right_count++;
        }
        else if(variables[i].back()==(-1*max_index)){
            variables[i].pop_back();
            variables[i][0]--;
            variables[i].push_back(-1);
            left_count++;
        }
        else{
            variables[i].push_back(0);
            left_count++;
            right_count++;
        }
    }
    for(int i=0;i<no_of_terms;i++){
        for(int j=1;j<=(variables[i][0]+1);j++){
            cout<<variables[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    vector<int> variables_left[left_count];
    vector<int> variables_right[right_count];
    int i,j;
    for(i=0,j=0;i<no_of_terms;i++){
        if(variables[i].back()==1){
            if(variables[i].size()==2){
                //cout<<"This is read(0)\n";
                break;
            }
            else{
                variables_right[j]=variables[i];
                variables_right[j].pop_back();
                j++;
            }
        }
        else if(variables[i].back()==0){
            variables_right[j]=variables[i];
            variables_right[j].pop_back();
            j++;
        }
    }
    if(i!=no_of_terms){
        cout<<"This is read(0)\n";
        //cout<<"hi\n";
        right_node=true;
        //cout<<"hi2\n";
        right=NULL;
        //cout<<"hi3\n";
    }
    else{
        right=new boolfunc;
        right->read(variables_right,right_count);
    }
    //cout<<"hi4\n";
    for(i=0,j=0;i<no_of_terms;i++){
        if(variables[i].back()==-1){
            if(variables[i].size()==2){
                break;
            }
            else{
                variables_left[j]=variables[i];
                variables_left[j].pop_back();
                j++;
            }
        }
        else if(variables[i].back()==0){
            variables_left[j]=variables[i];
            variables_left[j].pop_back();
            j++;
        }
    }
    //cout<<"hi5\n";
    if(i!=no_of_terms){
        //cout<<"hi6\n";
        cout<<"This is read(0)\n";
        left_node=true;
        left=NULL;
    }
    else{
        left=new boolfunc;
        left->read(variables_left,left_count);
    }
    cout<<"This is read(0) exit\n";
}

void boolfunc::read(vector<int> variables[],int count_temp){
    //cout<<"This is read("<<count_temp<<")\n";
    no_of_terms=count_temp;
    int temp1,temp2,max_index=0;
    for(int i=0;i<no_of_terms;i++){
        if(max_index<variables[i].back()){
            max_index=variables[i].back();
        }
        else if(max_index<(-1*variables[i].back())){
            max_index=(-1*variables[i].back());
        }
    }
    //cout<<"This is read("<<count_temp<<")\n";
    index=max_index;
    int left_count=0,right_count=0;
    for(int i=0;i<no_of_terms;i++){
        if(variables[i].back()==max_index){
            variables[i].pop_back();
            variables[i][0]--;
            variables[i].push_back(1);
            right_count++;
        }
        else if(variables[i].back()==(-1*max_index)){
            variables[i].pop_back();
            variables[i][0]--;
            variables[i].push_back(-1);
            left_count++;
        }
        else{
            variables[i].push_back(0);
            left_count++;
            right_count++;
        }
    }
    for(int i=0;i<no_of_terms;i++){
        for(int j=1;j<=(variables[i][0]+1);j++){
            cout<<variables[i][j]<<" ";
        }
        cout<<"\n";
    }
    //cout<<"\n";
    //cout<<"This is read("<<count_temp<<")\n";
    vector<int> variables_left[left_count];
    vector<int> variables_right[right_count];
    int i,j;
    for(i=0,j=0;i<no_of_terms;i++){
        if(variables[i].back()==1){
            if(variables[i].size()==2){
                break;
            }
            else{
                variables_right[j]=variables[i];
                variables_right[j].pop_back();
                j++;
            }
        }
        else if(variables[i].back()==0){
            variables_right[j]=variables[i];
            variables_right[j].pop_back();
            j++;
        }
    }
    if(i!=no_of_terms){
        cout<<"This is read("<<count_temp<<")\n";
        right_node=true;
        right=NULL;
    }
    else{
        right=new boolfunc;
        right->read(variables_right,right_count);
    }
    //cout<<"This is read("<<count_temp<<")\n";
    for(i=0,j=0;i<no_of_terms;i++){
        if(variables[i].back()==-1){
            if(variables[i].size()==2){
                break;
            }
            else{
                variables_left[j]=variables[i];
                variables_left[j].pop_back();
                j++;
            }
        }
        else if(variables[i].back()==0){
            variables_left[j]=variables[i];
            variables_left[j].pop_back();
            j++;
        }
    }
    if(i!=no_of_terms){
        cout<<"This is read("<<count_temp<<")\n";
        left_node=true;
        left=NULL;
    }
    else{
        left=new boolfunc;
        left->read(variables_left,left_count);
    }
    cout<<"This is read() exit\n";
}

void boolfunc::print(){
    cout<<"This is print()\n";
    string left_exp,right_exp;
    std::stringstream ss;
    ss << index;
    std::string str_pos = ss.str();
    ss << (-1*index);
    std::string str_neg = ss.str();
    if(left!=NULL){
        left_exp=left->print(1);
        for(string::iterator it=left_exp.begin();it!=left_exp.end();it++){
            if(*it=='+'){
                left_exp.insert(it,str_neg.begin(),str_neg.end());
                it++;
            }
        }
    }
    else{
        if(left_node){
            left_exp = str_neg;
        }
    }
    if(right!=NULL){
        right_exp=right->print(1);
        for(string::iterator it=right_exp.begin();it!=right_exp.end();it++){
            if(*it=='+'){
                right_exp.insert(it,str_pos.begin(),str_pos.end());
                it++;
            }
        }
    }
    else{
        if(right_node){
            right_exp = str_pos;
        }
    }
    left_exp += '+';
    left_exp += right_exp;
    cout<<left_exp;
}

string boolfunc::print(int temp){
    cout<<"This is print("<<temp<<")\n";
    temp++;
    char index_pos,index_neg;
    std::stringstream ss;
    ss << index;
    std::string str_pos = ss.str();
    ss << (-1*index);
    std::string str_neg = ss.str();
    string left_exp,right_exp;
    if(left!=NULL){
        left_exp=left->print(temp);
        for(string::iterator it=left_exp.begin();it!=left_exp.end();it++){
            if(*it=='+'){
                left_exp.insert(it,str_neg.begin(),str_neg.end());
                it++;
            }
        }
    }
    else{
        if(left_node){
            left_exp = str_neg;
        }
    }
    if(right!=NULL){
        right_exp=right->print(temp);
        for(string::iterator it=right_exp.begin();it<=right_exp.end();it++){
            if(*it=='+'){
                right_exp.insert(it,str_pos.begin(),str_pos.end());
                it++;
            }
        }
    }
    else{
        if(right_node){
            right_exp = str_pos;
        }
    }
    left_exp += '+';
    left_exp += right_exp;
    return left_exp;
}

//int main(){
  //  boolfunc a;
    //a.read();
    //a.print();
    //return 1;
//}
