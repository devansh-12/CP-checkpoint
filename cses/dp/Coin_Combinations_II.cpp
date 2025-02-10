#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  //vector<vector<int>> dp(n+1,vector<int>(x,0)) ;
  vector<int> curState(x+1,0);
  vector<int> prevState(x+1,0);
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }

  for(int i=n-1;i>=0;i--){
      curState[0]=1;
      for(int j=1;j<=x;j++){
          int pick=0,skip=prevState[j];
          if(j-arr[i]>=0){
              pick = curState[j-arr[i]];
          }
          curState[j]= (pick + skip)%mod;
      }
      prevState=curState;
  }
  cout<<curState[x]<<endl;
  
  
  
  return 0;
}