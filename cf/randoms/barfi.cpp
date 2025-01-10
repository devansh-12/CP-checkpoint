#include <bits/stdc++.h>
  using namespace std;
  
  int splitAmongPeople(int minWeight,vector<int> &arr){
    int curWeight=0;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
      //curWeight+arr[i];
      curWeight+=arr[i];
      if(curWeight>minWeight){
        cnt++;
        curWeight=0;
      }
      
    }
    return cnt;
  }
  int main() {

    vector<int> v1;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
      int x;
      cin>>x;
      v1.push_back(x);
    }
    
    int low=*min_element(v1.begin(),v1.end()),high=accumulate(v1.begin(),v1.end(),0);
    int ans=-1;
    while(low<=high){
      int mid = (low+high)>>1;
      if(splitAmongPeople(mid,v1)>n){
        low=mid+1;
      }
      else if(splitAmongPeople(mid,v1)<n){
        high=mid-1;
      }
      else{
        ans=mid;
        low=mid+1;
      }
    }
    cout<<low<<endl;
    
    return 0;

  }
