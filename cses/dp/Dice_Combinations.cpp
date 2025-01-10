#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long mod = 1e9+7;

vector<vector<ll>> mulMat(const vector<vector<ll>> &a,const vector<vector<ll>> &b){
    int R1 = a.size(); // R1
    int C1 = a[0].size(); // C1
    int R2 = b.size(); // R2
    int C2 = b[0].size(); // C2
    vector<vector<ll>> result(R1,vector<ll>(C2,0));
    for(int i=0;i<R1;i++){
        for(int j=0;j<C2;j++){
            for(int k=0;k<R2;k++){

                result[i][j] = (result[i][j]+((a[i][k]*b[k][j])%mod))%mod ;
            }
        }
    }
    return result;
}

vector<vector<ll>> matExpo(vector<vector<ll>> &M,int n){
    if (n == 0) {
        vector<vector<ll>> identity(6,vector<ll>(6,0));
        for (int i = 0; i < 6; i++) {
            identity[i][i] = 1;
        }
            return identity; 
    }

    if(n==1){
        return M;
    }

    if(n%2==0){
        vector<vector<ll>> half = matExpo(M,n/2);
        return  mulMat(half,half);
    }
    return mulMat(M,matExpo(M,n-1));

}
// long long calcNumDie(long long n,vector<int> &dp){
//     if(n==0){
//         return 1;
//     }
//     if(dp[n]!=-1){return dp[n];}
//     long long res = 0;
//     for(int i=1;i<=6;i++){
//         if(n-i>=0){
//         res = (res + calcNumDie(n-i,dp))%mod;
//         }
//     }
//     return dp[n]=res;
// }

int main(){
    int n;
    cin>>n;
    // vector<int> dp(n+1,0);
    // dp[0]=1;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=6;j++){
    //         if(i-j>=0){
    //             dp[i] = (dp[i] + dp[i-j])%mod;
    //         }
    //     }
    // }
    // cout<<dp[n]<<endl;
    //cout<<calcNumDie(n,dp)<<endl;
    vector<vector<ll>> initial = {{16},{8},{4},{2},{1},{1}};
    vector<vector<ll>> M={
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0}
    };
    long long ans ;
    if(n<=5){
        ans = initial[5-n][0];
    }
    else{
    vector<vector<ll>> res = mulMat(matExpo(M,n-5),initial);
    ans = res[0][0];
    }
    cout<<ans<<endl;
    return 0;
}

