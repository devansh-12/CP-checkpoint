#include<bits/stdc++.h>
using namespace std;

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
        struct P a,b,c,d;
        int a1,b1,c1,d1;
        cin>>a1>>b1>>c1>>d1;
        a.x=-a1;a.y=0;
        b.x=0;b.y=b1;
        c.x=c1;c.y=0;
        d.x=0;d.y=-d1;

        if( pow(a.x-b.x,2)+pow(a.y-b.y,2) == pow(b.x-c.x,2)+pow(b.y-c.y,2) &&
            pow(a.x-b.x,2)+pow(a.y-b.y,2) == pow(c.x-d.x,2)+pow(c.y-d.y,2) &&
            pow(a.x-b.x,2)+pow(a.y-b.y,2) == pow(d.x-a.x,2)+pow(d.y-a.y,2) &&
            pow(a.x-c.x,2)+pow(a.y-c.y,2) == pow(b.x-d.x,2)+pow(b.y-d.y,2)     
        ){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}