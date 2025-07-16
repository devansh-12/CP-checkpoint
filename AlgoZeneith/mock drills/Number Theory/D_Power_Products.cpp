#include<bits/stdc++.h>
using namespace std;


const long long N = 1e5;
vector<long long> prime(N+1,true),hp(N+1,0),lp(N+1,0);

void seive(){
    prime[0]=prime[1]=false;
    for(long long i=2;i<=N;i++){
        if(prime[i]==true){
            lp[i]=hp[i]=i;
            for(long long j=i;j<=N;j+=i){
                prime[j] = false;
                if(lp[j]==0){
                    lp[j]=i;
                }
                hp[j]=i;
            }
        }
    }
}

vector<pair<long long,long long>> factorize(long long val,long long k){
    
    vector<pair<long long,long long>> factors;
    while(val>1){
        long long pf = hp[val];
        long long pow=0;
        while(val % pf ==0){
            val/=pf;
            pow++;
        }

        if(pow % k != 0){
            factors.push_back({pf,pow%k});
        }
        
    }
    return factors;
}



int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }

    long long res=0;

    seive();
    map<vector<pair<long long,long long>>,long long> m1;
    for(long long i=0;i<n;i++){
        vector<pair<long long,long long>> factors = factorize(arr[i],k);
        vector<pair<long long,long long>> comp ;
        for(auto p:factors){
            long long s,f;
            f=p.first;
            s=p.second;
            comp.push_back({f,(k-s)%k});
        }
        if(m1.find(comp)!=m1.end()){
            res += m1[comp];
        }
        m1[factors]++;

    }
    cout<<res<<endl;

    return 0;
}