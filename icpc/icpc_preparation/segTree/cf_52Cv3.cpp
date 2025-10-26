#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const int N = 2e5 + 5;

// vector < ll > tree, lazy;
ll tree[4 * N], lazy[4 * N];
vector < ll > a;

void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}

void push(ll v) {
    tree[2 * v] += lazy[v];
    tree[2 * v + 1] += lazy[v];
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    if (l > r) return;
    if (tl == l && tr == r) {
        lazy[v] += val;
        tree[v] += val;
    } else {
        ll tm = (tl + tr) / 2;
        push(v);
        modify(2 * v, tl, tm, l, min(tm, r), val);
        modify(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return INT_MAX;
    if (tl == l && tr == r) {
        return tree[v];
    }
    push(v);
    ll tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, min(tm, r)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

vector<int> split_muug(string& s) {
    int n = s.size();
    string tmp = "";
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            ret.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
    ret.push_back(stoi(tmp));
    return ret;
}

int main() {
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    ll n, i, j, k, s, m, l, r, x;
    string str;
    char ch;
    cin >> n;
    // tree.resize(4 * n, 0);
    // lazy.resize(4 * n, 0);
    
    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    for (i = 0;i < n;i++) {
        a.pb(a[i]);
    }

    build(1, 0, n - 1);
    (cin >> m).ignore();

    i = 0;
    vector < int > qp;
    bool can = false;

    while (m--) {
        // getline(cin, str);
        // qp = split_muug(str);
        qp.clear();
        do {
            cin >> x;
            qp.pb(x);
        } while (scanf("%c", &ch) != EOF && ch != '\n');
        if (qp.size() == 2) {
            if (qp[0] <= qp[1]) {
                cout << get(1, 0, n - 1, qp[0], qp[1]) << endl;
            } else {
                cout << min(get(1, 0, n - 1, 0, qp[1]), get(1, 0, n - 1, qp[0], n - 1)) << endl;
            }
        } else {
            if (qp[0] <= qp[1]) {
                modify(1, 0, n - 1, qp[0], qp[1], qp[2]);
            } else {
                modify(1, 0, n - 1, 0, qp[1], qp[2]);
                modify(1, 0, n - 1, qp[0], n - 1, qp[2]);
            }
        }
    }
}