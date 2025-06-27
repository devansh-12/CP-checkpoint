#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n,ans=0;
    int k;
    cin>>n>>k;
    vector<long long> a(k);
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    for(int i=1;i<(1LL<<k);i++){
        long long prod =1;
        int setbits = 0;
        for(int j=0;j<k;j++){
            if((1<<j) & i){
                if(prod > n/a[j]){
                   prod = -1;
                   
                   break;
                }
                setbits++;
                prod*=a[j];
            }
        }
        if(prod!=-1){
            if(setbits%2==0){
                ans -= n/prod;
            }
            else{
                ans += n/prod;
            } 
        }
    }
    cout<<ans<<endl;
    return 0;
}