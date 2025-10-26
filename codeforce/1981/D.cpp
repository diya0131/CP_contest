#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff firts
#define ss second
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, m, x, y, s=0, i;
    cin>>n;
    for(i=1;i<n;i++){
        if(i%2){
            if(n<=(i*(i+1)/2+1)) break;
        }
        else{
            if(n<=(i*i/2+2)) break;
        }
    }
    m=i;
    if(m%2){
        cout<<m<<" ";
        for(i=1;i<=m;i++){
            cout<<i<<" "<<i<<" ";
        }
        
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}