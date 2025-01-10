#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct P{
    int x , y;

    void read(){
        cin>>x>>y;
    }

    P operator-(const P &b) const{
        return P{x-b.x,y-b.y};
    }
    P operator+(const P &b) const{
        return P{x+b.x,y+b.y};
    }

    long long operator *(const P &b) const{
        return (long long ) x *b.y - (long long)y* b.x;
    }
    long long crossProduct(const P &b,const P &c) const {
        return (b - *this) * (c - *this);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        P p1,p2,p3,p4 ; 
        p1.read();
        p2.read();
        p3.read();
        p4.read();

        if((p1.crossProduct(p2,p4)==0 && p1.crossProduct(p2,p3)==0) ||
         (p3.crossProduct(p4,p2)==0 && p3.crossProduct(p4,p1)==0)){
            if(max(p1.x,p2.x) >= min(p3.x,p4.x) && min(p1.x,p2.x) <= max(p3.x,p4.x) &&
   max(p1.y,p2.y) >= min(p3.y,p4.y) && min(p1.y,p2.y) <= max(p3.y,p4.y)){
                cout<<"YES"<<"\n";
                continue;
            }
            else 
            {
                cout<<"NO"<<"\n";
                continue;
            }
            
        }
        int flag=0;
        for(int i=0;i<2;i++){
            
        ll sign1 = p1.crossProduct(p2,p4);
        ll sign2 = p1.crossProduct(p2,p3);
        if((sign1>0 && sign2 >0) || (sign1<0 && sign2<0) ){
            cout<<"NO"<<"\n";  
            flag=1;     
            break; 
            }
        
        swap(p1,p3);
        swap(p2,p4);
        }
        if(flag==0)
        cout<<"YES"<<endl;
        
    }
    return 0;
}