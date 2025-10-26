#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

struct node {
    ll prefix = 0;
    ll suffix = 0;
    ll len = 0;
    ll ans = 0;
};

ll n;
vector < node > tree;

node combine(node x, node y) {
    node nd;
    nd.prefix = max(x.prefix, x.len + y.prefix);
    nd.suffix = max(y.suffix, x.suffix + y.len);

    nd.len = y.len + x.len;
    nd.ans = max(x.suffix + y.prefix, max(x.ans, y.ans));
    return nd;
}

void build(vector < ll >& he, vector < ll >& dis, ll v, ll tl, ll tr) {
    node nd;
    if (tl == tr) {
        nd.ans = dis[tl] + 2 * he[tl] + 2 * he[(tl + 1) % (2 * n)];
        nd.len = dis[tl];
        // nd.suffix = max(2 * he[(tl + 1) % (2 * n)], 2 * he[tl] + dis[tl]);
        // nd.prefix = max(2 * he[(tl + 1) % (2 * n)] + dis[tl], 2 * he[tl]);
        nd.suffix = 2 * he[tl] + dis[tl];
        nd.prefix = 2 * he[(tl + 1) % (2 * n)] + dis[tl];
        tree[v] = nd;
    } else {
        ll tm = (tl + tr) / 2;
        build(he, dis, 2 * v, tl, tm);
        build(he, dis, 2 * v + 1, tm + 1, tr);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
}

node get(ll v, ll tl, ll tr, ll l, ll r) {
    node nd;
    nd.ans = 0;
    nd.len = 0;
    nd.prefix = 0;
    nd.suffix = 0;
    if (l > r) return nd;
    if (tl == l && tr == r) {
        // cout << "return: " << tree[v].ans _ tl _ tr << endl;
        return tree[v];
    } else {
        ll tm = (tl + tr) / 2;
        nd = combine(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
        // cout << l _ r _ tl _ tr _ nd.ans _ nd.len _ nd.prefix _ nd.suffix << endl;
        return nd;
    }
}

int main() {
    ll i, j, k, s, t, m, h, d, l, r, io;
    cin >> n >> m;
    node nd;
    tree.clear();
    vector < ll > he, dis;
    for (i = 0;i < 8 * n;i++) tree.pb(nd);
    for (i = 0;i < n;i++) {
        cin >> d;
        dis.pb(d);
    }
    for (i = 0;i < n;i++) {
        cin >> h;
        he.pb(h);
    }
    for (i = 0;i < n;i++) {
        dis.pb(dis[i]);
    }
    for (i = 0;i < n;i++) {
        he.pb(he[i]);
    }
    // for(i=0;i<he.size();i++){
    //     cout<<he[i]<<" ";
    // }
    // cout<<endl;
    // for(i=0;i<dis.size();i++){
    //     cout<<dis[i]<<" ";
    // }
    // cout<<endl;
    build(he, dis, 1, 0, 2 * n - 1);
    // for (i = 0;i < 8 * n;i++) {
    //     cout << i _ tree[i].ans _ tree[i].len _ tree[i].prefix _ tree[i].suffix << endl;
    // }

    for (i = 0;i < m;i++) {
        cin >> l >> r;
        l--;
        r--;
        if(l>r){
           k = get(1, 0, 2*n-1, r+1, l-2).ans;
        }
        else k = get(1, 0, 2 * n - 1, r + 1, n + l - 2).ans;
        // cout<<"sum: "<<k<<endl;
        // if (l == 0) k += dis[n - 1];
        // else k += dis[l - 1];
        // k = alld - k;
        // k += 2 * (he[(n + l - 1) % 2*n] + he[(r + 1) % 2*n]);
        cout << k << endl;
    }
}