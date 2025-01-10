#include<bits/stdc++.h>
using namespace std;

int main(){
   
    int n;
    cin>>n;
    vector<int> arr(n-1);
    for(int i=0;i<n-1;i++){
        int x;
        cin>>arr[i];
    }
    long long sum1 = accumulate(arr.begin(),arr.end(),0LL);
    long long sum2 = n*1LL *(n+1)/2;
    cout<<(sum2-sum1)<<endl;

    return 0;
}