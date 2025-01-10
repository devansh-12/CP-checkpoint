// #include<bits/stdc++.h>
// using namespace std;

// bool reOrder(vector<int> &arr,vector<int> &hash,vector<int> &position,int i,int n,vector<int> &res){
//     if(i==n){
//         return true;
//     }
//     for(int j=0;j<n;j++){

//         if(hash[j-arr[i]+100]==-1 && position[j]==-1){
//             hash[j-arr[i]+100]=1;
//             res[j] = arr[i];
//             position[j]=arr[i];
//             if(reOrder(arr,hash,position,i+1,n,res)){
//                 //cout<<j;
//                 return true;
//             }
//             res[j] = -1;
//             hash[j-arr[i]+100]=-1;
//             position[j]=-1;
//         }
//     }
//     return false;

// }

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> arr(n);
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }
//         vector<int> hash(200,-1);
//         vector<int> res(n, -1);
//         vector<int> position(100,-1);
//         reOrder(arr,hash,position,0,arr.size(),res);
//         for(int i=0;i<n;i++){
//             cout<<res[i]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

bool reOrder(vector<int> &arr,vector<int> &hash,vector<int> &position,int i,int n,vector<int> &res){
    if(i==n){
        return true;
    }
    for(int j=0;j<n;j++){

        if(hash[j-arr[i]+100]==-1 && position[j]==-1){
            hash[j-arr[i]+100]=1;
            res[j] = arr[i];
            position[j]=arr[i];
            if(reOrder(arr,hash,position,i+1,n,res)){
                //cout<<j;
                return true;
            }
            res[j] = -1;
            hash[j-arr[i]+100]=-1;
            position[j]=-1;
        }
    }
    return false;

}

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
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}