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
    ll n, i, j,k;
    cin>>n;
    ll p[n];
    for(i=0; i<n; i++) cin>>p[i];
    for(i=0;i<n;i++){
        if(p[i]!=i+1){
            if(p[i]!=i+2 || p[i+1]!=i+1){
                cout<<"NO\n";
                return;
            }
            i++;
        }
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