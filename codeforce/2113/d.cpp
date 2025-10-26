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
    ll n, i, j, k, s, t, mn=LLONG_MAX;
    cin>>n;
    vector<ll >a(n), b(n);

    set < ll > x, y;
    set < ll >::iterator it;
    for(i=0;i<n;i++) {
        cin>>a[i];
        x.insert(a[i]);
    }
    for(i=0;i<n;i++) {
        cin>>b[i];
        mn = min(b[i], mn);
        b[i]= mn;
    }
    // for(i=0;i<n;i++) cout<<b[i]<<" ";
    if(*x.begin() > b[0]) {
        cout<<n<<endl;
        return;
    }
    
    for(i=n-1;i>0;i--){
        x.erase(a[i]);
        y.insert(a[i]);
    
        if(*x.begin()<*prev(y.end())){
            if(x.size()==1) mn = *prev(y.end());
            else mn = min(*next(x.begin()), *prev(y.end()));
        } else mn = *x.begin();

        if(b[n-i]<mn){
            cout<<i<<endl;
            return;
        }
    }
    cout<<0<<endl;
    return;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}