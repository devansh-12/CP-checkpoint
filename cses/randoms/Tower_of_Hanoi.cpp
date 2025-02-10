
#include<bits/stdc++.h>
using namespace std;

void towerofHanoi(int n,int start,int end){
    // 6 - start - end 
    if(n==0){
        
        return ;
    }
    
    towerofHanoi(n-1,start,6-start-end);
    cout<<start<<" "<<end<<endl;
    towerofHanoi(n-1,6-start-end,end);
}
int numSteps(int n,int start,int end,int &cnt){
    // 6 - start - end 
    if(n==0){
        return cnt;
    }
    
    numSteps(n-1,start,6-start-end,cnt);
    cnt++;
    numSteps(n-1,6-start-end,end,cnt);
    return cnt;
}

int main(){
    int n;
    cin>>n;
    int cnt=0;
    cout<<numSteps(n,1,3,cnt)<<endl;
    towerofHanoi(n,1,3);
    return 0;
}