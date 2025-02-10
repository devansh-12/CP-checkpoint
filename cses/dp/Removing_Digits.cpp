#include<bits/stdc++.h>
using namespace std ;

// dp - space optimized 
// int main(){
//     int n;
//     cin>>n;
//     if(n<=9){
//         cout<<1<<endl;
//         return 0;
//     }
//     vector<int> prev(10,1),curr(10);
    
//     // 10-19-> 1 , 31-39->3
//     for(int i=1;i<=n/10;i++){
//         for(int j=0;j<10;j++){
//             int num = (10*i)+j;
//             int temp=num,cnt = INT_MAX;
//             while(temp){
//                 int rem = temp %10;
//                 if(rem==0){

//                 }
//                 else if((num-rem)>=i*10){
//                     cnt = min(cnt,curr[(num-rem)%10]+1);
//                 }
//                 else{
//                     cnt = min(cnt,prev[(num-rem)%10]+1);
//                 }
//                 temp/=10;
//             }
//             curr[num%10] = cnt;
//         }
//         prev=curr;
//     }
//     cout<<curr[n%10]<<endl;
//     return 0;
// }

int main(){
    int n;
    cin>>n;
    int temp=n,cnt=0;
    int maxi = INT_MIN;
    while(n){
    int temp = n,maxi = INT_MIN;
    while(temp){
        int rem = temp%10;
        maxi = max(maxi,rem);
        temp/=10;
    }
    n-=maxi;
    cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}