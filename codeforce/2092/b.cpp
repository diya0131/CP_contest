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
    int n, i, j, s=0, k, t=0;
    cin>>n;
    string a, b;
    cin>>a>>b;
    for(i=0;i<n;i++){
        if(i%2==0){
            s+=(a[i]=='0');
            t+=(b[i]=='0');
        } else {
            t+=(a[i]=='0');
            s+=(b[i]=='0');
        }
    }
    if(s>=(n+1)/2 && t>=(n/2)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}