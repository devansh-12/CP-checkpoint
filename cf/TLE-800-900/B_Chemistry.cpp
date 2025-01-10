#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(26,0);
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            arr[x-'a']++;
        }
        int disOddCnt =0 ;
        for(int i=0;i<26;i++){
            if(arr[i]%2!=0){
                disOddCnt++;
            }
        }

        if(disOddCnt-k<=1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}