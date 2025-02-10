#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> arr(3);
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(arr.begin(),arr.end());
        if(arr[0]==arr[1] && arr[1]==arr[2]){
            cout<<0<<endl;continue;
        }
        else if(arr[0]==arr[1] && arr[1]+1==arr[2]){
            cout<<0<<endl;continue;
        }
        else if(arr[0]==arr[1]){
            arr[0]++;
            arr[1]++;
            arr[2]--;
        }
        else if(arr[1]==arr[2] && arr[1]-1==arr[0]){
            cout<<0<<endl;
            continue;
        }
        else if(arr[1]==arr[2]){
            arr[0]++;
            arr[1]--;
            arr[2]--;
        }
        else{
            arr[0]++;arr[2]--;
        }
        cout<<abs(arr[0]-arr[1])+abs(arr[0]-arr[2])+abs(arr[2]-arr[1])<<endl;
    }
    return 0;
}