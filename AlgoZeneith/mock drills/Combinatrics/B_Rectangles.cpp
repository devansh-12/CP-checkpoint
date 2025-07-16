#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binExp(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll half = binExp(a,b/2);
    half = half * half ;
    if(b%2==1)return a * half;
    return half;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    ll res =0;
    for(int i=0;i<n;i++){
        int numOnes=0,numZeroes=0;
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                numOnes++;
            }
            else{
                numZeroes++;
            }
        }
        res += binExp(2,numOnes)-1;
        res += binExp(2,numZeroes)-1;
    }

    for(int i=0;i<m;i++){
        int numOnes=0,numZeroes=0;
        for(int j=0;j<n;j++){
            if(a[j][i]==1){
                numOnes++;
            }
            else{
                numZeroes++;
            }
        }
        res += binExp(2,numOnes)-1;
        res += binExp(2,numZeroes)-1;
    }

    res -= n*m;
    cout<<res<<endl;

    return 0;
}