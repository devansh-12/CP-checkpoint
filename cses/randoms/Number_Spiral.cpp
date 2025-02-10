#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(x<=y){
            if(y%2==0){
                cout<<(y*y)-(y-1) - (y-x)<<endl;
            }
            else{
                cout<<y*y-(y-1) + (y-x)<<endl;
            }
        }
        else{
            if(x%2==0){
                cout<<x*x-(x-1) + (x-y)<<endl;
            }
            else{
                cout<<x*x-(x-1) - (x-y)<<endl;
            }
        }
    }
    return 0;
}