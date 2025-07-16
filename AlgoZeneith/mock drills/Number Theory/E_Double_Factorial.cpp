#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;

    if(n%2==1){
        cout<<0<<endl;
        return 0;
    }

    long long num = 10;
    long long res = 0;
    while(num <= n){
        res += n/num;
        num*=5;

    }
    cout<<res<<endl;
    return 0;
}