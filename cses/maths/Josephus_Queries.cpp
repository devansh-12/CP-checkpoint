#include<bits/stdc++.h>
using namespace std;

long long josephus(int n,int k){
    if(n==1){
        return 1;
    }
    if(k<=(n+1)/2){
        if(2*k>n)
        return (2*k)%n;
        return 2*k;
    }
    long long temp = josephus(n/2,k-(n+1)/2);
    if(n%2==1){
        return 2*temp+1;
    }
    return 2*temp-1;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<josephus(n,k)<<endl;
    }
    return 0;
}