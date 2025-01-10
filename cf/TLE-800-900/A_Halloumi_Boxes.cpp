#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        bool sorted =true;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                sorted = false;
                break;
            }
        }
        if(m==1 && sorted==false){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    
    return 0;
}