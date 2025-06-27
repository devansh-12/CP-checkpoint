#include<bits/stdc++.h>
using namespace std;


const int sz = 1e6;
vector<int> primes(sz+1,0);

void seives(map<int,vector<int>> & mapOfPos){
    primes[0]=primes[1];
    for(int i=2;i<=sz;i++){
        if(primes[i]==0){
            primes[i]++;
            for(int j=2*i;j<=sz;j+=i){
                primes[j]++;
            }
        }
    }

    for(int i=0;i<=sz;i++){
        if(primes[i] <= 10)
        mapOfPos[primes[i]].push_back(i);
    }
}

int main(){
    int t;
    cin>>t;
    map<int,vector<int>> mapOfPos;
    seives(mapOfPos);
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        int i,j;
        i = lower_bound(mapOfPos[n].begin(),mapOfPos[n].end(),a)-mapOfPos[n].begin();
        j = upper_bound(mapOfPos[n].begin(),mapOfPos[n].end(),b)-mapOfPos[n].begin();

        cout<<j-i<<endl;
    }

    return 0;
}