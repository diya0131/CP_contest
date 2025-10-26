#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<
#define test if(te) cout

using namespace std;

const bool te = 0;

const ll N = 1e5;
const ll INF = 1e9;
ll n;
vector<vector<ll>> cap;
vector<vector<ll>> adj;
vector < ll > primes;

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({ s, INF });

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({ next, new_flow });
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t) {
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void sieve() {
    vector < bool > is(N, 1);
    primes.resize(9592);
    int k = 0, j;
    for (int i = 2;i < N;i++) {
        if (is[i]) {
            primes[k++] = i;
            j = 2 * i;
            while (j < N) {
                is[j] = 0;
                j += i;
            }
        }
    }
}


int main() {
    ll n1, m, i, j, k, s, u, v, t, p, cnt, ndcnt, x, y;
    sieve();
    cin >> n1 >> m;
    vector < ll > a(n1);
    vector < map < ll, pair < ll, ll > > > nd(n1);
    vector < pair < ll, ll > > b(m);
    ndcnt = 1;//0 - for start
    for (i = 0;i < n1;i++) {
        cin >> a[i];
        t = a[i];
        for (j = 0;j < primes.size() && t>1;j++) {
            cnt = 0;
            while (t % primes[j] == 0) {
                t /= primes[j];
                cnt++;
            }
            if (cnt > 0) {
                nd[i][primes[j]] = { ndcnt++, cnt };
                test<<"nah";
            }
        }
        if (t > 1) {
            nd[i][t] = { ndcnt++, 1 };
        }
    }
    ndcnt++;//for end ( sink )

    cap.assign(ndcnt, vector < ll >(ndcnt, 0));
    adj.resize(ndcnt);
    for (i = 0;i < n1;i++) {
        test<<"sz; " _ nd[i].size()<<endl;
        for (auto it = nd[i].begin(); it != nd[i].end();it++) {
            k = (*it).ss.ff;
            cnt = (*it).ss.ss;
            test<<"hey" _ k _ cnt<<endl;
            if (i % 2) {
                adj[k].pb(ndcnt - 1);
                cap[k][ndcnt - 1] = cnt;
            } else {
                adj[0].pb(k);
                cap[0][k] = cnt;
            }
        }
    }
    

    for (i = 0;i < m;i++) {
        cin >> u >> v;
        u--;
        v--;
        if (u % 2) swap(u, v);
        x = a[u];
        y = a[v];
        for (j = 0;j < primes.size();j++) {
            p = primes[j];
            if (x % p == 0 && y % p == 0) {
                test << "added" _ u _ v << endl;
                // adj[0].pb(nd[u][p].ff);
                // cap[0][nd[u][p].ff] = nd[u][p].ss;

                adj[nd[u][p].ff].pb(nd[v][p].ff);
                adj[nd[v][p].ff].pb(nd[u][p].ff);
                cap[nd[u][p].ff][nd[v][p].ff] = INF;

                // adj[nd[v][p].ff].pb(ndcnt - 1);
                // cap[nd[v][p].ff][ndcnt - 1] = nd[v][p].ss;
            }
            while (x % p == 0) x /= p;
            while (y % p == 0) y /= p;
        }
        if (x > 1 && x == y) {
            p = x;
            adj[0].pb(nd[u][p].ff);
            cap[0][nd[u][p].ff] = nd[u][p].ss;

            adj[nd[u][p].ff].pb(nd[v][p].ff);
            adj[nd[v][p].ff].pb(nd[u][p].ff);
            cap[nd[u][p].ff][nd[v][p].ff] = INF;

            adj[nd[v][p].ff].pb(ndcnt - 1);
            cap[nd[v][p].ff][ndcnt - 1] = nd[v][p].ss;
        }

    }
    test << "here\n";
    test << ndcnt << endl;
    for (i = 0;i < ndcnt;i++) {
        test << "nd" _ i << endl;
        for (ll to : adj[i]) {
            test << to _ cap[i][to] << endl;
        }
    }
    n = ndcnt;
    ll res = maxflow(0, ndcnt - 1);



    cout << res << endl;

}