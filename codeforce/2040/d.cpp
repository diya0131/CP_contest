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

const ll N = 4e5 + 5;
vector < ll > primes;
ll n;

vector < vector < ll > > adj;
vector < ll > par;
vector < pair < ll, ll > > cnt;

void dfs(ll k, ll p) {
    par[k] = p;
    for (ll to : adj[k]) {
        if (p != to) dfs(to, k);
    }
}

void solve() {
    ll i, j, k, t, u, v, p;
    bool bl, can, did;
    pair < ll, ll > pr;
    cin >> n;
    vector< ll > res(n, -1);
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
    set < pair < ll, ll > > st;
    set < pair < ll, ll > >::iterator it;
    for (int i1 = 0;i1 < 100;i1++) {
        for (i = 1;i <= 2 * n;i++) st.insert({ rng(), i });
        sort(ALL(cnt));
        did = true;
        for (i = n - 1;i >= 0;i--) {
            k = cnt[i].second;
            if (res[k] == -1) {
                if (par[k] != -1 && res[par[k]] != -1) {
                    t = res[par[k]];
                    bl = false;
                    for (it = st.begin();it != st.end();it++) {
                        pr = *it;
                        p = *lower_bound(ALL(primes), abs(pr.ss - t));
                        if (p != abs(pr.ss - t)) {
                            res[k] = pr.ss;
                            st.erase(it);
                            bl = true;
                            break;
                        }
                    }
                    if (!bl) {
                        did = false;
                        break;
                    }
                } else {
                    it = st.begin();
                    res[k] = it->ss;
                    st.erase(it);
                }
            }
            t = res[k];
            can = true;
            for (ll to : adj[k]) {
                if (res[to] == -1) {
                    bl = false;
                    for (it = st.begin();it != st.end();it++) {
                        pr = *it;
                        p = *lower_bound(ALL(primes), abs(pr.ss - t));
                        if (p != abs(pr.ss - t)) {
                            res[to] = pr.ss;
                            st.erase(it);
                            bl = true;
                            break;
                        }
                    }
                    if (!bl) {
                        can = false;
                        break;
                    }
                }
            }
            if (!can) {
                did = false;
                break;
            }
        }
        if (did) {
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
    // BOOST

    ll j;
    vector < bool > is(N, 1);
    for (int i = 2;i < N;i++) {
        if (is[i]) {
            primes.push_back(i);
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