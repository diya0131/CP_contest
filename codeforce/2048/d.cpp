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
    ll n, m, i, j, k, t, res, c;
    cin >> n >> m;
    vector < ll > a(n);
    vector < ll > b(m);
    vector< ll > tmp;
    for (i = 0;i < n;i++) cin >> a[i];
    k = a[0];
    for (i = 0;i < m;i++) {
        cin >> b[i];
        if (b[i] > k) tmp.pb(b[i]);
    }
    sort(ALL(tmp));
    sort(ALL(a));
    ll sz = tmp.size();
    // cout<<"sz " _ sz<<endl;
    vector < ll > vc(sz);
    for (i = 0;i < sz;i++) {
        // cout<<tmp[i] _ t<<endl;
        // if()
        t = n - (lower_bound(ALL(a), tmp[i]) - a.begin())+1;
        vc[i] = t;
        // cout<<tmp[i] _ t _ "t"<<endl;

        // cout << i _ vc[i] << endl;
    }

    for(i=1;i<=m;i++){
        res=0;
        c=0;
        for(j=m%i;j<sz;j+=i){
            // cout<<j _ vc[j]<<endl;
            res+=vc[j];
            
            c++;
        }
        res+=(m/i - c);
        // cout<<"haha" _ m/k _ c<<endl;
        cout<<res<<" ";
    }
    cout<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}