#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 ;
vector<bool> prime(N+1,true);
vector<int> primes;
void seives(){
    prime[0]=prime[1]=false;
    for(int i=2;i<=N;i++){
        if(prime[i]){
            primes.push_back(i);
            for(int j=i*2;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    seives();
    vector<int> res;

    for(int num:primes){
        int i=1;
        while((int)pow(num,i) <= n){
            res.push_back(pow(num,i));
            i++;
        }
    }
    cout<<res.size()<<endl;
    for(int num:res){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}