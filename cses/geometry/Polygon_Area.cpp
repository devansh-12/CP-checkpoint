#include<bits/stdc++.h>
using namespace std;

struct P{
    public:
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
    int n;
    cin>>n;
    vector<struct P> points(n);
    for(int i=0;i<n;i++){
        points[i].read();
    }
    struct P p;
    p.x=p.y=0;
    long long res = 0;
    for(int i=0;i<n;i++){

        struct P p1 = points[(i)%n];
        struct P p2 = points[(i+1)%n];

        res += p.crossProduct(p1,p2);
    }
    cout<<abs(res)<<endl;
}