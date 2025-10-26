#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, m;
    cin>>n;
    vector < int > a;
    while(n>0){
        a.pb(n%2);
        n/=2;
    }
    bool p = 1, q = 1;
    a.pb(1);
    for(int i=a.size()-2;i>=0;i--){
        if(a[i]==1) {
            if(p){
                a[i]=0;
                
            }
            else{
                a[i+1]=1;
                a[i]=0;
                p=1;
            }
            q=1;
        }
        else{
            if(q){
                a[i+1]=-1;
                q=0;
            }
            p=0;
        }
    }
    if(p){
        a[0]=-1;
    }

    for(int i=0;i<a.size()-1;i++){
        if(a[i]==1 && a[i+1]==-1){
            a[i]=-1;
            a[i+1]=0;
        }
        else{
            if(a[i]==-1 && a[i+1]==1){
                a[i]=1;
                a[i+1]=0;
            }
        }
    }
    if(a[a.size()-1]==0){
        cout<<a.size()-1<<endl;
        for(int i=0;i<a.size()-1;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}