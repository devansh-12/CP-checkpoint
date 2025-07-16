#include<bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> lp,hp;
map<int,int> primes;
const int mod = 1e9+7;

void precompute(int N){
    isPrime.resize(N+1,true);
    hp.resize(N+1,1);
    lp.resize(N+1,1);
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i<=N;i++){

        if(isPrime[i]){
            lp[i]=hp[i]=i;

            for(int j=2*i;j<=N;j+=i){
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==1){
                    lp[j]=i;
                }
            }
        }
    }

}

void addPrimes(int num){

    while(num>1){
        int pf = hp[num];
        primes[pf]++;
        num/=pf;
    }

}

int main(){
    int n;
    cin>>n;

    precompute(n);
    long long res = 1;
    for(int i=2;i<=n;i++){
        addPrimes(i);
    }

    for(auto [f,s]:primes){
        res = (res * (s+1))%mod;
    }
    cout<<res<<endl;
    return 0;
}