#include<bits/stdc++.h>
using namespace std;


int main(){
    int m,n;
    cin>>n>>m;

    vector<long long> a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(a.begin(),a.end());
    long long g=0;
    for(int i=1;i<n;i++){
        g = __gcd(g,a[i]-a[0]);
    }

    long long ans=0;
    for(int i=0;i<m;i++){
        ans = __gcd(g,a[0]+b[i]);
        cout<<ans<<" ";
    }

    return 0;
}