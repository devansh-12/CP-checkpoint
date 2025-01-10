#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
vector<int> dp(1e6+1,0);

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    dp[0]=1;
    for(int i=1;i<=x;i++){

        for(auto coin:coins){
            if(i-coin<0){
                continue;
            }
            dp[i]= ((dp[i]+0LL+dp[i-coin])%mod);
        }
    }
    cout<<dp[x];
    
    return 0;
}
