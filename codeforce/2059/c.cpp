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
    ll n, i, j, k, t, c;
    cin>>n;
    vector a(n, vector< ll > (n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector< ll> b(n);
    for(i=0;i<n;i++){
        c=0;
        for(j=n-1;j>=0;j--){
            if(a[i][j]==1) c++;
            else break;
        }
        b[i]=c;
    }
    sort(ALL(b));
    c=0;
    for(i=0;i<n;i++){
        
        if(c<=b[i]) c++;
    }
    cout<<c<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}