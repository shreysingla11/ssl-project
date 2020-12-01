#include<iostream>
using namespace std;
#include<set>
#include<map>
#include<vector>
struct btree{
	int value;
	btree * left;
	btree * right;
};
class boolfunc{
	//int no;
	//vector<bool> leaf;
	int value;
	boolfunc * left;
	boolfunc * right;
	vector<int> v;
public:
	boolfunc(){
		value=0;
		left=NULL;
		right=NULL;
	}
	~boolfunc(){
//		leaf.clear();
	}
	boolfunc( boolfunc const &a){
		value=a.value;
		cout<<"incopy"<<endl;
		if(a.left!=NULL){
            left=new boolfunc;
			*(left)=*(a.left);
			}
		else
			left=NULL;
		if(a.right!=NULL){
            right=new boolfunc;
			*(right)=*(a.right);
			}
		else
			right=NULL;
	}
	boolfunc operator+(boolfunc const &a){
		boolfunc news;
		if (value==0)
		{
			news=a;
		}
		else if(a.value==0){
			news=*this;
		}
		else if(a.value==-1||value == -1){
			news.value=-1;
			news.left=NULL;
			news.right=NULL;
		}
		else{
			if(a.value>value){
				news.value=value;
				*(news.left)= *(left)+a;
				*(news.right)=*(right)+a;
			}
			else if(a.value<value){
				news.value=a.value;
				*(news.left)=*(a.left)+ *(this);
				*(news.right)=*(a.right) + *(this);
			}
			else{
				news.value=a.value;
				*(news.left)=*(a.left) + *(left);
				*(news.right)=*(a.right) + *(right);
			}
		}
		return news;
	}
	void operator+=(boolfunc const &a){
		*this = *this + a;
	}
	boolfunc operator*(boolfunc const &a){
		boolfunc news;
		if (value==0||a.value==0)
		{
			news.value=0;
			news.left=NULL;
			news.right=NULL;
		}
		else if(a.value==-1){
			news=*this;
		}
		else if(value=-1){
			news=a;
		}
		else{
			if(a.value>value){
				news.value=value;
				*(news.left)= *(left) * a;
				*(news.right)=*(right) *a;
			}
			else if(a.value<value){
				news.value=a.value;
				*(news.left)=*(a.left) * *(this);
				*(news.right)=*(a.right) * *(this);
			}
			else{
				news.value=a.value;
				*(news.left)=*(a.left) * *(left);
				*(news.right)=*(a.right) * *(right);
			}
		}
		return news;
	}
	void operator*=(boolfunc const &a){
		*this = *this * a;
	}
	void operator=(boolfunc const &a){
        value=a.value;
		if(a.left!=NULL)
			*(left)=*(a.left);
		else
			left=NULL;
		if(a.right!=NULL)
			*(right)=*(a.right);
		else
			right=NULL;
	}
	void operator~(){
		if(value==0){
			value=-1;
		}
		else if(value==-1){
			value=0;
		}
		else{
			~*(left);
			~*(right);
		}
	}
	bool operator==(boolfunc const &a){
		if(a.value==value && *(left)==*(a.left) && *(right)==*(a.right))
			return true;
		else
			return false;
	}
	void read(){
		int s;
		cin>>s;
		while(s--){
			int no;
			cin>>no;
			boolfunc news;
			while(no--){
				int nos;
				cin>>nos;boolfunc news1;
				news1.left=new boolfunc;
				news1.right=new boolfunc;
				news1.left->value=0;
				news1.right->value=-1;
				if(nos<0){
					news1.value=-nos;
					~news1;
				}
				else{
					news1.value=nos;
				}
				news*=news1;
			}
			*this+=news;
		}
	}
	int falses(){
		if(value==-1){
			return 1;
		}
		else if(value==0)
			return 0;
		else
			return left->falses()+right->falses();
	}
	int trues(){
		if(value==0){
			return 1;
		}
		else if(value==1)
			return 0;
		else
			return left->trues()+right->trues();
	}
//	void print1(){
//        if(value==-1){
//            cout<<v.size()<<endl;
//            for()
//        }
//        else if(value!=0){
//
//        }
//	}
	void print_recurrence()
    {
        if(value==-1)
        {
            cout<<v.size()<<"dvdfv"<<endl;
            for(int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            v.pop_back();
            cout<<endl;
        }
        else if(value!=0)
        {
            v.push_back(-value);
            left->print_recurrence();
            v.pop_back();
            v.push_back(value);
            right->print_recurrence();
            v.pop_back();
        }
    }
    void print()
    {
        cout<<trues()<<endl;
        print_recurrence();
    }
	void subst(int i, bool v){

	}
};
//int main(int argc, char const *argv[])
//{
//	boolfunc b;
//	boolfunc c=boolfunc(b);
//    c.read();
//    c.print();
//	return 0;
//}
