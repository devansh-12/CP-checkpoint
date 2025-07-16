#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
 
ll ncr(int n,int r){
    if(r<0 || r>n)return 0;
    if(r>n-r)r=n-r;
    ll res = 1;
    for(int i=1;i<=r;i++){
        res = res*(n-i+1)/i;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    cout<<ncr(n-1,11)<<endl;
    return 0;
}
