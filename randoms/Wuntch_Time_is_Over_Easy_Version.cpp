#include<bits/stdc++.h>
using namespace std;

const int sz = 1e6;
int main(){
    int t;
    cin>>t;
    vector<int> divisors(sz+1,0);
    vector<bool> primes(sz+1,true);
    vector<long long>prefix(sz+1);
    primes[0]=primes[1]=false;
    divisors[0]=0;
    for(int i=2;i<=sz;i++){
        if(primes[i]){
        for(int j=2*i;j<=sz;j+=i){
            primes[j]=false;
        }
        }
    }
    for(int i=1;i<=sz;i++){

        for(int j=i;j<=sz;j+=i){
            divisors[j]++;
        }
    }
    prefix[0]=prefix[1]=0;
    for(int i=2;i<=sz;i++){
        prefix[i]= prefix[i-1];
        if(primes[divisors[i]]){
            prefix[i]+=1;
        }
    }
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<" ";
    }
    return 0;
}