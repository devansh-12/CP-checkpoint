#include<bits/stdc++.h>
#include<cmath>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long sr = static_cast<long long>(sqrtl(n));
        long long sr1 = static_cast<long long>(sqrtl(n + sr));
        cout<<n+sr1<<endl;
    }
    return 0;
}
