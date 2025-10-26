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
    ll n, i, k, t=0, c=0;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]=='p') t++;
    for(i=1;i<n-1;i++){
        if(s[i]=='s') c++;
        if(s[i]=='p') t++;
    }
    if(s[n-1]=='s') c++;
    if(c>0 && t>0) cout<<"NO\n";
    else cout<<"YES\n";

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}