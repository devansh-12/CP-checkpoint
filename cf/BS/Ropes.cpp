#include<bits/stdc++.h>
using namespace std;

int numRopes(vector<int> &arr,double cut){
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i]/cut;
    }
    return sum;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double low=0.0,high = *max_element(arr.begin(),arr.end());
    cout<<fixed<<setprecision(8);

    while(high-low > 1e-8){
        double mid = (low+high)/2.00;
        if(numRopes(arr,mid)==k){
            low=mid;
        }
        else if(numRopes(arr,mid)<k){
            high = mid;
        }
        else{
            low=mid;
        }
    }
    cout<<low<<endl;
    return 0;
}