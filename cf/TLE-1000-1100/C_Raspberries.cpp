#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k==4){
            int evenCnt = 0;int flag=0,f2=0;
            for(int i=0;i<n;i++){
                if(arr[i]%4==0){flag =1;break;}
                if(arr[i]%4==3){f2 =1;}
            if(arr[i]%2==0){evenCnt++;}

            }
            if(flag){
                cout<<0<<endl;
            }
            else if(f2){
            cout<<min(1,max(0, 2 - evenCnt))<<endl;
            }
            else{
            cout<<max(0, 2 - evenCnt)<<endl;
            }
            continue;
        }
        int mini = k;
        for(int i=0;i<n;i++){
            if(arr[i]%k==0){mini=0;break;}
            mini = min(k-(arr[i]%k),mini);
        }
        cout<<mini<<endl;
    }
    return 0;
}