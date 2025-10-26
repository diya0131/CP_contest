#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

vector < vector < ll > > tree;


void build(vector < ll >& a, ll v, ll tl, ll tr) {
    vector < ll > pr(3);
    pr[1] = 0;
    pr[2] = 0;
    if (tl == tr) {
        pr[0] = a[tl];
        tree[v] = pr;
    } else {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        pr[0] = min(tree[2 * v][0], tree[2 * v + 1][0]);
        tree[v] = pr;
    }
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val, ll all) {
    vector< ll> pr(3);
    pr[2] = 0;
    if (l > r) return;
    all += tree[v][1];
    // cout<<"modify" _ v _ l _ r _ val _ all<<endl;
    if (tl == l && tr == r) {
        tree[v][1] += val;
        tree[v][0] += all + val - tree[v][2];
        tree[v][2] = all + val;
    } else {
        ll tm = (tl + tr) / 2;
        modify(2 * v, tl, tm, l, min(tm, r), val, all);
        modify(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val, all);
        // pr[0] = min(tree[2 * v][0], tree[2 * v + 1][0]);
        // pr[1] = tree[v][1];
        // pr[2] = all - pr[2];
        // tree[v] = pr;
    }

}

ll get(ll v, ll tl, ll tr, ll l, ll r, ll all) {
    if (l > r) return INT_MAX;
    // cout<<"get" _ v _ l _ r <<endl;
    // cout<<"get: "<<v<<endl;
    all += tree[v][1];
    vector < ll > pr(3);
    if (tl == l && tr == r) {
        return tree[v][0] + all - tree[v][2];
    } else {
        ll tm = (tl + tr) / 2;
        ll mi = min(get(2 * v, tl, tm, l, min(tm, r), all), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, all));
        cout << "get: " << v _ l _ r _ mi << endl;

        return mi;
    }
}

int main() {
    vector < ll > pr(3);
    freopen("input.txt", "r", stdin);
    ll n, i, j, k, s, m, l, r, x;
    char ch;
    cin >> n;
    pr[2] = 0;
    for (i = 0;i < 8 * n;i++) {
        tree.pb(pr);
    }
    vector < ll > a;
    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    for (i = 0;i < n;i++) {
        a.pb(a[i]);
    }

    build(a, 1, 0, 2 * n - 1);
    cin >> m;

    i = 0;
    vector < ll > qp;
    while (true) {
        i++;
        cin >> x;
        qp.pb(x);

        if (scanf("%c", &ch) == EOF) {
            // cout << "asking: " << qp.size() _ qp[0] _ qp[1] << endl;
            if (qp.size() == 2) {
                if (qp[0] < qp[1]) {
                    cout << get(1, 0, 2 * n - 1, qp[0], qp[1], 0) << endl;
                } else {
                    cout << get(1, 0, 2 * n - 1, qp[0], n + qp[1], 0) << endl;
                }

            } else {
                if (qp[0] <= qp[1]) {
                    modify(1, 0, 2 * n - 1, qp[0], qp[1], qp[2], 0);
                    modify(1, 0, 2 * n - 1, n + qp[0], n + qp[1], qp[2], 0);
                    // modify(1, 0, 2 * n - 1, qp[0], qp[1], qp[2]);
                } else {

                    modify(1, 0, 2 * n - 1, qp[0], n + qp[1], qp[2], 0);
                    modify(1, 0, 2 * n - 1, 0, qp[1], qp[2], 0);
                    modify(1, 0, 2 * n - 1, n + qp[0], 2 * n - 1, qp[2], 0);

                }

            }
            qp.clear();
            return 0;
        }
        if (ch == '\n') {
            //  cout << "asking: " << qp.size() _ qp[0] _ qp[1] << endl;
            if (qp.size() == 2) {
                if (qp[0] < qp[1]) {
                    cout << get(1, 0, 2 * n - 1, qp[0], qp[1], 0) << endl;
                } else {
                    cout << get(1, 0, 2 * n - 1, qp[0], n + qp[1], 0) << endl;
                }

            } else {
                if (qp[0] <= qp[1]) {
                    modify(1, 0, 2 * n - 1, qp[0], qp[1], qp[2], 0);
                    modify(1, 0, 2 * n - 1, n + qp[0], n + qp[1], qp[2], 0);
                    // modify(1, 0, 2 * n - 1, qp[0], qp[1], qp[2]);
                } else {
                    modify(1, 0, 2 * n - 1, qp[0], n + qp[1], qp[2], 0);
                    modify(1, 0, 2 * n - 1, 0, qp[1], qp[2], 0);
                    modify(1, 0, 2 * n - 1, n + qp[0], 2 * n - 1, qp[2], 0);
                }

            }
            qp.clear();
        }

    }
}