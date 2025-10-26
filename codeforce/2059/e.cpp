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
    ll n, m, i, j, k, s, t, c;
    cin>>n>>m;
    vector< ll > a(2*n*m+1);
    for(i=0;i<n*m;i++){
        cin>>a[i];
    }
    a[n*m]=-1;
    for(i=n*m+1;i<=2*n*m;i++){
        cin>>a[i];
    }
    vector< ll > b(2*n*m+1, 0);
    b[0]=0;
    for(i=1;i<=2*n*m;i++){
        c = b[i-1];
        while(c>0 && a[c]!=a[i]) c = b[c-1];
        if(a[c]==a[i]) b[i]=c+1;
        else b[i]=0;
        cout<<i _ b[i] _ c _ a[i] _ a[c]<<endl;
    }
    
    cout<<n*m-b[2*n*m]<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}