#include <iostream>
#include <vector>

using namespace std;

//int n;

double side(int ax, int ay, int bx, int by, int cx, int cy){
    double m1,val;
    if((bx-ax)==0){val=cx-bx+0.0;return val;}
    else{
        m1=(by-ay)*1.0/(bx-ax);
        val=(m1*cx)-cy+ay-(m1*ax)+0.0;
        return val;
    }
};

void findline(vector<int> rx,vector<int> ry,vector<int> bx,vector<int> by,vector<int> ri,vector<int> bi,int n){
    if(n==1){cout<<ri[0]<<" "<<bi[0]<<endl;return;}
    int rp=0,rn=0,bp=0,bn=0,rc,bc,i,j;
    vector<int> vecrpx,vecrnx,vecbpx,vecbnx,vecrpy,vecrny,vecbpy,vecbny,vecrpi,vecrni,vecbpi,vecbni;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(rc=0;(rc<n && rc!=i);rc++){
                if(side(rx[i],ry[i],bx[j],by[j],rx[rc],ry[rc])>0){
                    rp++;
                    vecrpx.push_back(rx[rc]);
                    vecrpx[rp-1]=rx[rc];
                    vecrpy.push_back(ry[rc]);
                    vecrpy[rp-1]=ry[rc];
                    vecrpi.push_back(ri[rc]);
                    vecrpi[rp-1]=ri[rc];
                }
                if(side(rx[i],ry[i],bx[j],by[j],rx[rc],ry[rc])<0){
                    rn++;
                    vecrpx.push_back(rx[rc]);
                    vecrpx[rn-1]=rx[rc];
                    vecrpy.push_back(ry[rc]);
                    vecrpy[rn-1]=ry[rc];
                    vecrpi.push_back(ri[rc]);
                    vecrpi[rn-1]=ri[rc];
                }
                if(side(rx[i],ry[i],bx[j],by[j],rx[rc],ry[rc])==0){cout<<"Some 3 points are linear1 "<<i<<" "<<j<<endl;return;}
            }
            for(bc=0;(bc<n && bc!=j);bc++){
                if(side(rx[i],ry[i],bx[j],by[j],bx[bc],by[bc])>0){
                    bp++;
                    vecbpx.push_back(bx[bc]);
                    vecbpx[bp-1]=bx[bc];
                    vecbpy.push_back(by[bc]);
                    vecbpy[bp-1]=by[bc];
                    vecbpi.push_back(bi[bc]);
                    vecbpi[bp-1]=bi[bc];
                }
                if(side(rx[i],ry[i],bx[j],by[j],bx[bc],by[bc])<0){
                    bn++;
                    vecbnx.push_back(bx[bc]);
                    vecbnx[bn-1]=bx[bc];
                    vecbny.push_back(by[bc]);
                    vecbny[bn-1]=by[bc];
                    vecbni.push_back(bi[bc]);
                    vecbni[bn-1]=bi[bc];
                }
                if(side(rx[i],ry[i],bx[j],by[j],bx[bc],by[bc])==0){cout<<"Some 3 points are linear "<<i<<" "<<j<<endl;return;}
            }
            if(rp==bp && (i!=0 || j!=0)){
                cout<<ri[i]<<" "<<bi[j]<<endl;
                if(rp>0){findline(vecrpx,vecrpy,vecbpx,vecbpy,vecrpi,vecbpi,rp);}
                if(rn>0){findline(vecrnx,vecrny,vecbnx,vecbny,vecrni,vecbni,rn);}
            }
            rp=0;rn=0;bp=0;bn=0;
            vecrpx.clear();vecrnx.clear();vecbpx.clear();vecbnx.clear();vecrpy.clear();vecrny.clear();vecbpy.clear();vecbny.clear();vecrpi.clear();vecrni.clear();vecbpi.clear();vecbni.clear();
        }
    }
};

bool ints(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy){
    double m1,m2,x,y,c1,c2;
    if((bx-ax) == 0 && (dx-cx) == 0){
        if(by>=ay){
            if((cy>=ay && cy<=by) || (dy>=ay && dy<=by)){return true;}
            else{return false;}
        }
        else{
            if((cy<=ay && cy>=by) || (dy<=ay && dy>=by)){return true;}
            else{return false;}
        }
    }
    if(bx-ax == 0){
        m2=(dy-cy)*1.0/(dx-cx);
        y=(m2*bx) - (m2*cx) + cy + 0.0;
        if((y>=ay && y<=by) || (y<=ay && y>=by)){return true;}
        else{return false;}
    }
    if(dx-cx == 0){
        m1=(by-ay)*1.0/(bx-ax);
        y=(m1*dx) - (m1*ax) + ay + 0.0;
        if((y>=cy && y<=dy) || (y<=cy && y>=dy)){return true;}
        else{return false;}
    }
    m1=(by-ay)*1.0/(bx-ax);
    m2=(dy-cy)*1.0/(dx-cx);
    if((m1-m2)==0){
        c1=ay-(m1*ax);
        c2=cy-(m2*cx);
        if(c1==c2){
            if(bx>=ax){
                if((cx>=ax && cx<=bx) || (dx>=ax && dx<=bx)){return true;}
                else{return false;}
            }
            else{
                if((cx<=ax && cx>=bx) || (dx<=ax && dx>=bx)){return true;}
                else{return false;}
            }
        }
        else{return false;}
    }
    else{
        x=((m1*ax)-(m2*cx)-ay+cy)*1.0/(m1-m2);
        if(x>=ax && x<=bx && x>=cx && x<=dx){return true;}
        else{return false;}
    }
};

int main(){
    int n2,n,r,i,j,rc,bc,temp;
    //int rp=0,rn=0,bp=0,bn=0;
    cout<<"give 2n : ";
    cin>>n2;
    n=n2/2;
    vector<int> redx(n),redy(n),blux(n),bluy(n),redi(n),blui(n),solr,solb;
    //vector<int> vecrpx,vecrnx,vecbpx,vecbnx,vecrpy,vecrny,vecbpy,vecbny,vecrpi,vecrni,vecbpi,vecbni;
    //cout << "vector size = " << redx.size() << endl;
    cout<<"give red points"<<endl;
    for(i=0;i<n;i++){
        cin>>redx[i]>>redy[i];
    }
    cout<<"give blue points"<<endl;
    for(i=0;i<n;i++){
        cin>>blux[i]>>bluy[i];
    }

    for(i=0;i<n;i++){
        solr.push_back(i);
        solb.push_back(i);
        for(j=0;j<i;j++){
            if(ints(redx[solr[j]],redy[solr[j]],blux[solb[j]],bluy[solb[j]],redx[solr[i]],redy[solr[i]],blux[solb[i]],bluy[solb[i]])==true){
                temp=solb[i];//cout<<"Hy"<<endl;
                solb[i]=solb[j];
                solb[j]=temp;
            }
        }
    }
//solution for the simple part
    cout<<"Solution Using simple method is : "<<endl;
    for(i=0;i<n;i++){
        cout<<solr[i]<<" "<<solb[i]<<endl;
    }
//continuing for the recursive part
    cout<<endl;
    for(i = 0; i < n; i++){
    	redi.push_back(i);
   	}
   	for(i = 0; i < n; i++){
    	blui.push_back(i);
   	}
   	cout<<"Solution using recursive method : "<<endl;
    findline(redx,redy,blux,bluy,redi,blui,n);
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            //vector<int> vecrpx,vecrnx,vecbpx,vecbnx,vecrpy,vecrny,vecbpy,vecbny,vecrpi,vecrni,vecbpi,vecbni;
            for(rc=0;(rc<n && rc!=i);rc++){
                if(side(redx[i],redy[i],blux[j],bluy[j],redx[rc],redy[rc])>0){
                    rp++;
                    vecrpx.push_back(redx[rc]);
                    vecrpy.push_back(redy[rc]);
                    vecrpi.push_back(rc);
                }
                if(side(redx[i],redy[i],blux[j],bluy[j],redx[rc],redy[rc])<0){
                    rn++;
                    vecrnx.push_back(redx[rc]);
                    vecrny.push_back(redy[rc]);
                    vecrni.push_back(rc);
                }
                if(side(redx[i],redy[i],blux[j],bluy[j],redx[rc],redy[rc])==0){cout<<"Some 3 points are linear1 "<<i<<" "<<j<<endl;return -1;}
            }
            for(bc=0;(bc<n && bc!=j);bc++){
                if(side(redx[i],redy[i],blux[j],bluy[j],blux[bc],bluy[bc])>0){
                    bp++;
                    vecbpx.push_back(blux[bc]);
                    vecbpy.push_back(bluy[bc]);
                    vecbpi.push_back(bc);
                }
                if(side(redx[i],redy[i],blux[j],bluy[j],blux[bc],bluy[bc])<0){
                    bn++;
                    vecbnx.push_back(blux[bc]);
                    vecbny.push_back(bluy[bc]);
                    vecbni.push_back(bc);
                }
                if(side(redx[i],redy[i],blux[j],bluy[j],blux[bc],bluy[bc])==0){cout<<"Some 3 points are linear "<<i<<" "<<j<<endl;return -1;}
            }
            if(rp==bp && (i!=0 || j!=0)){
                cout<<i<<" "<<j<<endl;
                findline(vecrpx,vecrpy,vecbpx,vecbpy,vecrpi,vecbpi);
                findline(vecrnx,vecrny,vecbnx,vecbny,vecrni,vecbni);
            }
            rp=0;rn=0;bp=0;bn=0;
            vecrpx.clear();vecrnx.clear();vecbpx.clear();vecbnx.clear();vecrpy.clear();vecrny.clear();vecbpy.clear();vecbny.clear();vecrpi.clear();vecrni.clear();vecbpi.clear();vecbni.clear();
        }
    }*/

    return 0;
}
