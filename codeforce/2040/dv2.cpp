#include<bits/stdc++.h>
#include<chrono>
#include <random>
#include<unordered_set>

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

const ll N = 4e5 + 5;
unordered_set<ll> primes;
ll n;

vector < vector < ll > > adj;
vector < ll > par;
vector < pair < ll, ll > > cnt;
unordered_set < ll > st;
unordered_set < ll >::iterator it;
vector< ll > res;

void dfs(ll k, ll p) {
    par[k] = p;
    for (ll to : adj[k]) {
        if (p != to) dfs(to, k);
    }
}

bool find(ll k, ll p) {
    ll t = res[k], pri, pr;

    for (ll to : adj[k]) {
        if (to != p) {
            bool bl = false;
            for (it = st.begin();it != st.end();it++) {
                pr = *it;
                if (primes.count(abs(pr - t)) == 0) {
                    res[to] = pr;
                    st.erase(it);
                    bl = true;
                    break;
                }
            }
            if (!bl) return false;
            bl = find(to, k);
            if (!bl) return false;
        }
    }
    
    return true;
}

void solve() {
    ll i, j, k, t, u, v, p;
    bool bl, can, did;
    pair < ll, ll > pr;
    cin >> n;
    res.clear();
    res.assign(n, -1);
    adj.clear();
    adj.resize(n);
    for (i = 1;i < n;i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cnt.clear();
    cnt.resize(n);
    par.clear();
    par.resize(n);
    for (i = 0;i < n;i++) {
        cnt[i] = { adj[i].size(), i };
    }
    dfs(0, -1);

    for (int i1 = 0;i1 < 2;i1++) {
        st.clear();
        for (i = 1;i <= 2 * n;i++) st.insert(i);
        res[0] = *st.begin();
        st.erase(st.begin());
        can = find(0, -1);
        if (can) {
            for (i = 0;i < n;i++) {
                cout << res[i] << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    BOOST

    ll j;
    vector < bool > is(N, 1);
    for (int i = 2;i < N;i++) {
        if (is[i]) {
            primes.insert(i);
            j = 2 * i;
            while (j < N) {
                is[j] = 0;
                j += i;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}