#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int ind =-1,numOnes = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1 && ind == -1){
            ind = i;
        }
        if(a[i]==1){numOnes++;}
    }

    if(numOnes==0){
        cout<<0<<endl;
        return 0;
    }
    if(numOnes==1){
        cout<<1<<endl;
        return 0;
    }
    int numZero = 0;
    long long res =1;
    for(int i=ind;i<n;i++){
        if(a[i]==1){
            res *= (numZero+1);
            numZero = 0;

        }
        else{
            numZero++;
        }
    }
    cout<<res<<endl;
    return 0;
}