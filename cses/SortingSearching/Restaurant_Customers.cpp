#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0,j=0;
    int cnt = 1,maxi=1;
    while(i<n && j<n){
        if(a[i]<b[j]){
            cnt++;
            maxi = max(i-j+1,maxi);
            i++;
        }
        else{
            cnt--;
            j++;
        } 
        

    }
    cout<<maxi<<endl;
    return 0;
}