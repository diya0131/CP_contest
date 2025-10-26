#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    ll n, i, j, k, s, mx, mn, lmn, lmx, rmn, rmx, mmn, mmx;
    cin>>n;
    vector< ll > a(n);
    vector < pair < ll, ll > > b(n);
    for(i=0;i<n;i++){
        cin>>a[i];
        b[i]={a[i], i};
    }
    sort(ALL(b));
    lmn=0;
    rmn=n-1;
    while(lmn<rmn){
        
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}