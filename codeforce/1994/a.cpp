#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

void solve(){
    ll n, m, i, j;
    
    cin>>n;
    ll a[n];
    map < ll, ll > mp;
    for(i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if((*it).ss%2){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}