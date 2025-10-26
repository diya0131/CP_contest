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

vector < vector < char > > a;
vector < vector < vector< vector < ll > > > > dp;

ll n, m;

queue < vector < ll > > q;

void calc(ll x, ll y, ll u, ll v, ll c, ll val, ll xc, ll xval) {
    if(a[u][v]=='#') return;
    test<<"calc" _ x _ y _ u _ v _ "|" _ c _ val _ xc _ xval<<endl;
    if (u >= 0 && v >= 0 && u <= n && v <= m && val<4) {
        ll i, j;
        vector < ll > tmp(4);
        tmp[0] = u;
        tmp[1]=v;
        tmp[2]=c;
        tmp[3]=val;
        if(dp[u][v][c][val] > dp[x][y][xc][xval] + 1){
            dp[u][v][c][val] = dp[x][y][xc][xval] + 1;
            test<<"gone\n";
            q.push(tmp);
        }
    }
    test<<"calc end\n";
}

void go(ll x, ll y, ll dir, ll val) {
    if(a[x][y]=='#') return;
    ll u, v, i, j, c;
    u = x - 1;
    v = y;
    c = 2;
    calc(x, y, u, v, c, (c == dir ? val + 1 : 1), dir, val);
    u = x + 1;
    v = y;
    c = 0;
    calc(x, y, u, v, c, (c == dir ? val + 1 : 1), dir, val);
    u = x;
    v = y - 1;
    c = 1;
    calc(x, y, u, v, c, (c == dir ? val + 1 : 1), dir, val);
    u = x;
    v = y + 1;
    c = 3;
    calc(x, y, u, v, c, (c == dir ? val + 1 : 1), dir, val);
    test<<"end\n";
}

void dfs(ll x, ll y) {
    vector < ll > tmp;
    ll i, j;
    tmp.resize(4);
    tmp[0] = x;
    tmp[1] = y;
    tmp[3] = 3;
    for (i = 0;i < 4;i++) {
        dp[x][y][i][3] = 0;
        tmp[2] = i;
        q.push(tmp);
    }
    test<<q.size() _ "sz"<<endl;
    pair < ll, ll > pr;
    vector is(n, vector(m, vector(4, vector(4, false))));
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        test<<"hm - " _ tmp.size()<<endl;
        if (is[tmp[0]][tmp[1]][tmp[2]][tmp[3]]) continue;
        test<<"queue" _ tmp[0] _ tmp[1] _ tmp[2] _ tmp[3]<<endl;
        is[tmp[0]][tmp[1]][tmp[2]][tmp[3]] = 1;
        test<<tmp[0] _  tmp[1] _  tmp[2] _  tmp[3]<<endl;
        go(tmp[0], tmp[1], tmp[2], tmp[3]);
        test<<"q end\n";
    }
}

void solve() {
    ll i, j, k, res = LLONG_MAX;
    cin >> n >> m;
    a.resize(n, vector < char >(m));
    pair < ll, ll > st, end;
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') st = { i, j };
            if (a[i][j] == 'T') end = { i, j };
        }
    }
    dp.assign(n, vector(m, vector(4, vector(4, LLONG_MAX))));

    test<<"here\n";
    test<<st.ff _ st.ss<<endl;
    dfs(st.ff, st.ss);

    for(i=0;i<4;i++){
        for(j=1;j<=3;j++){
            res = min(res, dp[end.ff][end.ss][i][j]);
        }
    }
    if(res == LLONG_MAX) cout<<-1<<endl;
    else cout<<res<<endl;
}

int main() {
    solve();
}