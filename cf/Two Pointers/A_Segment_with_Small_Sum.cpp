#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,s,sum=0;
    cin>>n>>s;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,len=0;
    for(int i=0;i<n;i++){
        
        while(sum+arr[i]>s){
            sum-=arr[l];
            l++;
            
        }
        len = max(len,i-l+1);
        sum += arr[i];
    }
    cout<<len<<endl;
}