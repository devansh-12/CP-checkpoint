#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        ll v1X,v1Y,v2X,v2Y;
        v1X = (ll)x2-x1;
        v1Y = (ll)y2-y1;
        v2X = (ll)x3-x1;
        v2Y = (ll)y3-y1;
        ll crossProduct = v1X*v2Y - v1Y*v2X;
        if(crossProduct==0){
            cout<<"TOUCH"<<"\n";
        }
        else if(crossProduct>0){
            cout<<"LEFT"<<"\n";
        }
        else{
            cout<<"RIGHT"<<"\n";
        }
        
    }
    return 0;
}