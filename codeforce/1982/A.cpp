#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve(){
    int n, m, x, y;
    cin>>n>>m;
    cin>>x>>y;
    if(n==x && m==y)cout<<"YES\n";
    else{
        if((n<=m && y<=x) || (m<=n && x<=y)) cout<<"NO\n";
        else cout<<"YES\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}