#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        x=sqrt(arr[i]);
        if(x*x!=arr[i]){
            cout<<-1<<endl;
            continue;
        }
        cout<<0<<" "<<x<<endl;
    }

    return 0;
}