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
    ll n, m, l, i, j, s, u, v, p, res = 0, mx = 0, k, pow=1;
    cin >> n >> m >> l;
    vector < pair < ll, ll > > hurdle(n), up(m);
    for (i = 0;i < n;i++) {
        cin >> u >> v;
        hurdle[i] = { u, v };
    }
    for (i = 0;i < m;i++) {
        cin >> u >> v;
        up[i] = { u, v };
    }
    p = 1;
    i = 0;
    j = 0;
    multiset < ll > st;
    multiset < ll >::iterator it;
    while (p < l && (i < n)) {
        p = hurdle[i].ff;
        while (j < m && up[j].ff < p) {
            st.insert(up[j].ss);
            j++;
        }
        p = hurdle[i].ss + 1;
        mx = max(mx, hurdle[i].ss - hurdle[i].ff + 2);
        while(mx>pow){
            if(st.size()==0){
                // cout<<pow _ p <<st.size()<<endl;
                cout<<-1<<endl;
                return;
            }
            it = prev(st.end());
            pow+=*it;
            res++;
            st.erase(it);
        }
        i++;
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}