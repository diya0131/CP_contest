#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

const bool TEST = 0;

void solve() {
    ll n, k, mn=LLONG_MAX, t;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>t;
        mn=min(mn, t);
    }
    if(n==1) {
        if(k<mn){
            cout<<"NO\n";
        } else cout<<"YES\n";
        return;
    }
   
    if(k<((n-2)*2+1)*mn){
        cout<<"NO\n";
    } else cout<<"YES\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}