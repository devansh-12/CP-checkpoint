#include<bits/stdc++.h>
using namespace std ;

vector<int> arr((int)1e6+1,0);

int main(){
    int n,maxi=1 ;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[x]++;
        maxi = max(maxi,x);
    }
    int i,j;


    for(i=maxi;i>=1;i--){
        int cnt = arr[i];

        for(j=2*i;j<=maxi;j+=i){
            if(cnt>=2){
                cout<<i<<endl;
                return 0;
            }
            else if(arr[j]!=0){
                cnt += arr[j];
            }
        }
        if(cnt>=2){
                cout<<i<<endl;
                return 0;
        }

    }
    return 0;
}