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
    ll n, i, s, t, k, a, b, c;
    cin>>n;
    cout<<1 _ "1"<<endl;
    cout.flush();
    cin>>a;
    cout<<1 _ "11"<<endl;
    cout.flush();
    cin>>b;
    cout<<1 _ "10"<<endl;
    cout.flush();
    cin>>c;
    k = a - b;
    if(c==k) cout<<0 _ n _ "0"<<endl;
    else cout<<0 _ n _ "1"<<endl;
    cout.flush();
    cin>>k;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}