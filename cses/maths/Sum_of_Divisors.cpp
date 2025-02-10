#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    int n1 = sqrt(n);
    ll sum=0;

    for(int i=1;i<=n;i++){
        sum += i*(n/i);
        sum %= mod;
    }

    cout<<sum<<endl;
    return 0;
}