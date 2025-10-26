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
    string s, t;
    cin>>s>>t;
    for(i=0;i<n;i++){
        if(s[i]=='0' && t[i]=='1'){
            cout<<"NO\n";
            return;
        }
        if(s[i]=='1'){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}