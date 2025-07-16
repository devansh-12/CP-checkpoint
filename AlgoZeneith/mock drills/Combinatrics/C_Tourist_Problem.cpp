#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b ){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    ll sum1 = 0,sum2=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        sum1+=a[i];
    }

    sort(a.begin(),a.end());
    vector<ll> prefixSum(n+1,0);
    
    for(int i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1]+a[i-1];
    }

    for(int i=1;i<n;i++){
        sum2 += (a[i]*1LL*i - prefixSum[i]);
    }

    sum1+=sum2*2;
    ll g= gcd(sum1,n);
    cout<<sum1/g<<" "<<n/g<<endl;
    return 0;
}