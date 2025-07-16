#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<bool> prime(N+1,true);
void seives(){
    prime[0]=prime[1]=false;
    for(int i=2;i<=N;i++){
        if(prime[i]){
            for(int j=2*i;j<=N;j+=i){
                prime[j]=false;
            }

        }
        
    }
}

int main(){
    int n;
    cin>>n;
    seives();
    long long x;
    for(int i=0;i<n;i++){
        cin>>x;
        long long sq = sqrt(x);
        if(sq*sq==x && prime[sq])
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}