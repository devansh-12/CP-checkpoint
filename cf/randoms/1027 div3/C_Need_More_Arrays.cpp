#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int i=1,l=0,len=1;
        while(i<n){
            if(arr[i]>arr[l]+1){
                len++;
                l=i;
            }
            i++;
        }
        cout<<len<<endl;


    }
    return 0;
}