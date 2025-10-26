#include<bits/stdc++.h>
#include<chrono>
#include <random>

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
    string s, r;
    ll i, j, a=0, b=0, n;
    cin>>n>>s>>r;
    for(i=0;i<n;i++){
        if(s[i]=='0') a++;
        else b++;
    }
    for(i=0;i<n-1;i++){
        // cout<<i _ a _ b<<endl;
        if(a==0 || b==0) {
            
            cout<<"NO\n";
            return;
        }
        if(r[i]=='0') b--;
        else a--;
    }
    cout<<"YES\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}