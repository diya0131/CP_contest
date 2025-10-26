#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define _ <<' '<<
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define debug(n) cout << #n << " = " << n << endl;
#define int ll

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

vector<int> L, R;

class LazySegmentTree {
public:
    vector<int> tree, lazy, res;
    string str;
    int n;
    LazySegmentTree(string& s) {
        str = s;
        n = s.size();
    }
    int combine(int x, int y) {
        return x + y;
    }
    void build(char ch) {
        res.clear();
        lazy = tree = vector<int>(4 * n, -1);
        build(1, 0, n - 1, ch);
    }
    void build(int v, int tl, int tr, char ch) {
        if (tl == tr) {
            tree[v] = (str[tl] == ch);
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, ch);
        build(2 * v + 1, tm + 1, tr, ch);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
    void push(int v, int tl, int tr) {
        if (lazy[v] == -1) {
            return;
        }
        if (tl == tr) {
            if (lazy[v]) {
                res.push_back(tl);
            }
            return;
        }
        int tm = (tl + tr) / 2;
        lazy[2 * v] = lazy[v];
        lazy[2 * v + 1] = lazy[v];
        tree[2 * v] = (tm - tl + 1) * lazy[v];
        tree[2 * v + 1] = (tr - tm) * lazy[v];
        lazy[v] = -1;
    }
    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }
    void update(int v, int tl, int tr, int l, int r, int val) {
        if (l > r || l > tr || r < tl) {
            return;
        }
        if (tl == l && tr == r) {
            lazy[v] = val;
            tree[v] = (tr - tl + 1) * val;
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(tm, r), val);
        update(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, val);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (tl == l && tr == r) {
            return tree[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return combine(
            get(2 * v, tl, tm, l, min(tm, r)),
            get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r)
        );
    }
    void dfs() {
        dfs(1, 0, n - 1);
    }
    void dfs(int v, int tl, int tr) {
        push(v, tl, tr);
        if (tl == tr) {
            return;
        }
        int tm = (tl + tr) / 2;
        dfs(2 * v, tl, tm);
        dfs(2 * v + 1, tm + 1, tr);
    }
    void print() {
        for (int i = 0; i < 4 * n; i++) {
            cout << tree[i] << " \n"[i == (4 * n - 1)];
        }
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string t(n, 'a');
    vector<int> l(q), r(q), k(q);
    L = R = vector<int> (q);
    LazySegmentTree lst(s);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> k[i];
        l[i]--; r[i]--;
        L[i] = l[i];
        R[i] = r[i];
    }
    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;
        lst.build(ch);
        // cout << ch << ": ";
        // lst.print();
        // if (lst.tree[1] == 0) {
        //     continue;
        // }
        for (int j = 0; j < q; j++) {
            int cnt = lst.get(l[j], r[j]);
            if (!cnt) continue;
            if (k[j] == 1) {
                lst.update(l[j] , L[j]-1, 0);
                lst.update(L[j], L[j] + cnt - 1, 1);
                lst.update(L[j] + cnt, r[j], 0);
                L[j] += cnt;
            } else {
                lst.update(R[j]+1 , r[j], 0);
                lst.update(R[j] - cnt + 1, R[j], 1);
                lst.update(l[j], R[j] - cnt, 0);
                R[j] -= cnt;
            }
        }
        lst.dfs();
        for (int j : lst.res) {
            t[j] = ch;
        }
    }
    // for (int i = 0; i < q; i++) {
    //     cout << L[i] _ R[i] << endl;
    // }
    cout << t << endl;
}