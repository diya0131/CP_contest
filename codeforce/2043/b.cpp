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
    ll n, d, s, i;
    cin>>n>>d;
    cout<<1<<" ";
    if(d%3==0 || n>=3) cout<<3<<" ";
    if(d%5==0) cout<<5<<" ";
    if(d%7==0 || n>=3) cout<<7<<" ";
    if(n>=6 || d%9==0 || ( d%3==0 && n>=3)) cout<<9<<" ";
    cout<<endl;

    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}