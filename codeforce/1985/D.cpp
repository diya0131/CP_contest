#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;


void solve(){
    ll n, i, j, m;
    cin>>n>>m;
    ll l=n-1, r=0, d=0, u=m-1;
    char ch;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>ch;
            if(ch=='#'){
                l=min(l, i);
                r=max(r, i);
                d=max(d, j);
                u=min(u, j);
            }
        }
    }
    cout<<(l+r)/2+1<<" "<<(d+u)/2+1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}