#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const int mod = 1e9+7;

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

vector<vector<ll>> matrixExpo(vector<vector<ll>> mat,ll n){
    if(n==0){
        return {{1,0},{0,1}};
    }
    if(n==1){
        return mat;
    }

    if(n%2==0){
        vector<vector<ll>> half = matrixExpo(mat,n/2);
        return mulMat(half,half);
    }
    return mulMat(mat,matrixExpo(mat,n-1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin>>n;

    vector<vector<ll>> fibMatrix = {
        {1, 1},
        {1, 0}
    };
    vector<vector<ll>> baseSeq ={{1},{0}};
    if(n==0 || n==1){cout<<n<<endl;return 0;}
    vector<vector<ll>> result = mulMat(matrixExpo(fibMatrix,n-1),baseSeq);
    cout<<result[0][0]<<endl;
    return 0;
}