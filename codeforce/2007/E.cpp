#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 1;

ll timer, all, w;
vector < set < ll > > adj;
vector < ll > t;

pair < ll, ll > dfs(ll k) {
    ll s, x, y;
    pair < ll, ll > road;
    set< ll >::iterator it;
    if (adj[k].size() == 0) {
        return { 0, 0 };
    }
    it = adj[k].begin();
    cin >> x >> y;
    t[x - 1] = y;
    all += y;
    test << k _ ": ";
    if (t[k] == -1) {

        cout << w - all << " ";

    } else cout << t[k] << " ";
    test << endl;
    road = dfs(*it);
    it++;
    for (;it != adj[k].end();it++) {
        cin >> x >> y;
        all += y;
        t[x - 1] = y;
        if (t[*it] == -1) {
            road.ss++;
        } else road.ff += t[*it];
        test << k _ ": ";
        if (road.ss) {
            cout << w - all + road.ff << " ";
        } else {
            cout << road.ff << " ";
        }
        test << endl;
        road = dfs(*it);
    }
    if (t[k] == -1) {
        road.ss++;
    } else {
        road.ff += t[k];
    }
    return road;
}


void solve() {
    ll n, i, j, m, k, s;
    cin >> n >> w;
    adj.clear();
    adj.resize(n);
    t.assign(n, -1);
    for (i = 1;i < n;i++) {
        cin >> k;
        // adj[i].insert(k-1);
        adj[k - 1].insert(i);
    }
    timer = 1;
    all = 0;
    dfs(0);
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}