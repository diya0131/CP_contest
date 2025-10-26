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
    ll w, h, a, b, x1, y1, x2, y2;
    cin>>w>>h>>a>>b>>x1>>y1>>x2>>y2;
    if(x1==x2){
        if( abs(y1-y2)%b==0) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    if(y1==y2){
        if( abs(x1-x2)%a==0) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    if(abs(x1-x2)%a==0 || abs(y1-y2)%b==0) cout<<"YES\n";
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