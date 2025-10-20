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
    int n, m, i, j, s, t;
    cin>>n>>m;
    vector< int > a(n), b(m);
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<m;i++) cin>>b[i];
    sort(ALL(b));
    t = min(a[0], b[0] - a[0]);
    for(i=1;i<n;i++){
        
        
        j = lower_bound(ALL(b), a[i]+t) - b.begin();
        // cout<<j _ a[i]+t<<endl;
        if(j==m) {
            if(t <= a[i]) t = a[i];
            else {
                cout<<"NO\n";
                return;
            }
            continue;
        }
        if(t <= a[i] && a[i]<b[j] - a[i]) t= a[i];
        else t = b[j] - a[i];

        // cout<<i _ t _ j _ b[j]<<endl;
    }
    cout<<"YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}