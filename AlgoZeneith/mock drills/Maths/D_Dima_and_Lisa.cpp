#include<bits/stdc++.h>
using namespace std;

const int sz = 300;
vector<bool> prime(sz+1,true);
vector<int> primes;

vector<vector<int>> precompute(){
    prime[0]=prime[1]=false;
    
    for(int i=2;i<=sz;i++){

        if(prime[i]){
            primes.push_back(i);
            for(int j=2*i;j<=sz;j+=i){
                prime[j]=false;
            }
        }
    }

    vector<vector<int>> res(sz+1,vector<int>());
    res[2].push_back(2);
    //primes ready 

    int n = primes.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(primes[i]+primes[j]>300){
                break;
            }

            if(res[primes[i]+primes[j]].empty())
            {
               res[primes[i]+primes[j]].push_back(primes[i]);
            res[primes[i]+primes[j]].push_back(primes[j]); 
            }
            
        }

    }
    return res;
}

// works in O(rt(n))
bool findPrime(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;

    auto res = precompute();
    for(int i=n;i >= max(n-300, 2);i--){
        if(findPrime(i)){
            int sum = n-i;
            int sz = res[sum].size();
            cout<<sz+1<<endl;
            cout<<i<<" ";
            for(int temp:res[sum]){
                cout<<temp<<" ";
            }
            cout<<endl;
            break;
        }
    }

    return 0;
}