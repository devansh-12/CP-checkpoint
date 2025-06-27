#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    for(long long i=1;i<=k;i++){
        long long ans = (i*i)*(i*i-1)/2;
        ans -= (i-1)*(i-2)*4;
        cout<<ans<<endl ;
    }
    
    return 0;
}