#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 0;

vector < vector < int > > adj;
vector < vector < int > > cap;
vector < int > par;

int n;

int bfs(int rt) {
    test << "bfs\n";
    queue < int > q;
    int k;
    q.push(rt);
    par.assign(n, -1);
    par[0] = -2;
    while (!q.empty()) {

        k = q.front();
        q.pop();
        test << k << endl;
        if (k == n - 1) {
            return 1;
        }
        for (int to : adj[k]) {
            test << to _ cap[k][to] << endl;
            if (par[to] == -1 && cap[k][to]) {
                par[to] = k;
                q.push(to);
            }
        }
    }
    return 0;
}

int maxflow() {

    int flow = 0;
    while (bfs(0) > 0) {
        flow++;
        int cur = n - 1;
        while (cur != 0) {
            cap[par[cur]][cur]--;
            cap[cur][par[cur]]++;
            cur = par[cur];
        }
    }
    return flow;
}

void findPath(){
    
}

int main() {
    int m, i, j, k, s, u, v;
    cin >> n >> m;
    adj.resize(n);
    cap.assign(n, vector < int >(n, 0));
    for (i = 0;i < m;i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
        cap[u][v] = 1;
        cap[v][u] = 1;
    }

    cout << maxflow() << endl;
    findPath(0);
}