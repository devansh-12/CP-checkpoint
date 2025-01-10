#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool blowingJob(vector<int> &t,vector<int> &z,vector<int> &y,ll time ,int m){
    
    int n = t.size();
    ll balloonsFilled=0;
    for(int i=0;i<n;i++){
        int temp = ((t[i]*z[i])+y[i]);
        balloonsFilled += (time/temp)*z[i];
        balloonsFilled +=  min((int)((time%temp)/t[i]),z[i]);
    }
    if(balloonsFilled>=m){
        return true;
    }
    return false;
}

void genSeq(vector<int> &t,vector<int> &z,vector<int> &y,ll time ,int m){
    cout<<time<<endl;
    int n = t.size();
    for(int i=0;i<n;i++){
        if(m<=0){
            cout<<0<<" ";
            continue;
        }
        ll balloonsFilled=0;
        int temp = ((t[i]*z[i])+y[i]);
        balloonsFilled += (time/temp)*z[i];
        balloonsFilled +=  min((int)((time%temp)/t[i]),z[i]);
        if(m-balloonsFilled<0){
            cout<<m<<" ";
            m=0;
            continue;
        }
        m-=balloonsFilled;
        cout<<balloonsFilled<<" ";
    }

}
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> t(n),z(n),y(n);
    for(int i=0;i<n;i++){
        cin>>t[i]>>z[i]>>y[i];
    }

    if (m == 0) { 
    cout << 0 << endl;
    for (int i = 0; i < n; i++) cout << "0 ";
    return 0; 
}


    ll low=1,high=3*1e6;
    while(low<=high){
        ll mid = low+high>>1;
        if(blowingJob(t,z,y,mid,m)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    genSeq(t,z,y,low,m);

    return 0;
}