#include<bits/stdc++.h>
using namespace std;

const int Mod = 1e9+7;
long long powFunc(long long  base, long long pow){
    if(pow==0){
        return 1;
    }
    if(pow==1){
        return base%Mod;
    }
    long long  base_by_2 = powFunc(base,pow/2);
    if(pow%2==1){
        return ((base_by_2*base_by_2)%Mod*base)%Mod;
    }
    return (base_by_2*base_by_2)%Mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        long long m,n;
        cin>>m>>n;
        cout<<powFunc(m,n)<<endl;
    }
    return 0;
}