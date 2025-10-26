#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;
const ll INF = 1e18;

void solve() {
    ll n, i, j, k;
    cin>>n;
    string s;
    cin>>s;
    k=0;
    i=0;
    while(i<n && s[i]=='1') i++;
    
    if(i==n) k=2;
    else k=i-1;
    if(n==k*k){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
}