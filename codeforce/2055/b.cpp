#include<bits/stdc++.h>
#include<random>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const bool TEST = 0;

void solve() {
    ll n, i, s=-1, k=-1;
    cin>>n;
    vector < ll > a(n), b(n);
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    for(i=0;i<n;i++){
        // cout<<k _ s _ a[i] _ b[i]<<endl;
        if(a[i]>=b[i]) {
            if(s==-1) s= a[i]-b[i];
            else s = min(a[i]-b[i], s);
        }
        else {
            if(k==-1) k = b[i]-a[i];
            else{
                cout<<"NO\n";
                return;
            }
        }
    }
    if(s>=k) cout<<"YES\n";
    else cout<<"NO\n";
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}