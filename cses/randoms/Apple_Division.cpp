#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long sum1=a[n-1],sum2=0;
    for(int i=n-2;i>=0;i--){
        if(sum1>sum2){
            sum2+=a[i];
        }
        else{
            sum1+=a[i];
        }
    }
    cout<<abs(sum1-sum2)<<endl;
    return 0;
}