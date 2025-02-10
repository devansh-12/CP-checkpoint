#include<bits/stdc++.h>
using namespace std;

const int sz = 1e7;
int divisors[sz+1];


int main(){
    for(int i=1;i<=sz;i++){
    divisors[i]=1;
    }

    for(int i=2;i<=sz;i++){

            for(int j=i;j<=sz;j+=i){
                divisors[j]++;
            }
        
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<divisors[n]<<endl;
    }

    return 0;
}