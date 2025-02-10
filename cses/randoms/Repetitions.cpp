#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    if(n==1){
    cout<<1<<endl;
    return 0;
    }
    int maxCnt=0;
    for(int i=0;i<n-1;i++){
        int cnt=1;
        while(i<n-1 && s[i]==s[i+1]){
            cnt++;
            i++;
        }
        maxCnt = max(maxCnt,cnt);
    }
    cout<<maxCnt<<endl;
    return 0;

}