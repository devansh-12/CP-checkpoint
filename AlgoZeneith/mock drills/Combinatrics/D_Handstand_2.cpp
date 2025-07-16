#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<vector<int>> digits(10,vector<int>(10,0));
    
    for(int i=1;i<=n;i++){
        int first, last = -1, temp;
        temp =i;
        while(temp > 0){
            int rem = temp%10;
            if(last == -1)last = rem;
            first = rem;
            temp /=10;
        }
        digits[first][last]++;
    }
    long long res = 0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            res += digits[i][j] * digits[j][i]; 
        }
    }

    cout<< res <<endl;
    return 0;
}