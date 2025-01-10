#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long calculateExponent(long long base,long long  pow,long long modulo){
    if(pow==0){return 1;}
    if(pow==1){return base;}
    if(pow%2==1){
        return ((calculateExponent(base,pow/2,modulo)*calculateExponent(base,pow/2,modulo))%modulo * base) % modulo;
    }
    return (calculateExponent(base,pow/2,modulo)*calculateExponent(base,pow/2,modulo)) % modulo;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        long long r = calculateExponent(b,c,mod-1);
        cout<<calculateExponent(a,r,mod)<<endl;
    }

    return 0;
}