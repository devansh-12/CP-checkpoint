#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool kamHogaKya(ll n,ll x,ll y,ll time){
    int numCopies;
    if(time-min(x,y)<0){
        return false;
    }
    time -= min(x,y);
    numCopies=1;
    numCopies+=time/x;
    numCopies+=time/y;
    if(numCopies>=n){
        return true;
    }
    return false;

}

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    ll low = 1,high = min(x,y)*(ll)n;
    while(low<=high){
        ll mid = (low+high)/2;
        if(kamHogaKya(n,x,y,mid)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<low<<endl;
    return 0;
}