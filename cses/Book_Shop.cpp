#include<bits/stdc++.h>
using namespace std;

int shopBooks(vector<int>&prices,vector<int>&pages,int ind){
    int n = prices.size();
    
}

int main(){
    int n , w;
    cin>>n>>w;
    vector<int>prices(n),pages(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    shopBooks(prices,pages,n)
}