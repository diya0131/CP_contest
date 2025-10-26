#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const int N = 1e5;
vector < pair < int, int > > st[4 * N];
vector < pair < int, int > >::iterator it;
int add[4 * N], sum[4 * N];;
vector < int > a;
vector < int > b;
vector <int> lucky = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777 };

bool cmp(pair< int, int > x, int y) {
    return x.ff < y;
}

void build(vector < int >& a, int v, int tl, int tr) {
    if (tl == tr) {
        add[v] = 0;
        int k = a[tl];
        bool isl = true;
        while (k > 0) {
            if (k % 10 != 4 || k % 10 != 7) isl = false;
            k /= 10;
        }
        if (isl) sum[v] = 1;
        else sum[v] = 0;
        st[v].pb({ a[tl], 1 });
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    int i = 0, j = 0;
    while (i < st[2 * v].size() && j < st[2 * v + 1].size()) {
        if (st[2 * v][i].ff == st[2 * v + 1][j].ff) {
            st[v].pb({ st[2 * v][i].ff, st[2 * v][i].ss + st[2 * v + 1][j].ss });
            i++;
            j++;
        } else {
            if (st[2 * v][i].ff < st[2 * v + 1][j].ff) {
                st[v].pb(st[2 * v][i]);
                i++;
            } else {
                st[v].pb(st[2 * v + 1][j]);
                j++;
            }
        }
    }

    if (i == st[2 * v].size()) {
        while (j < st[2 * v + 1].size()) {
            st[v].pb(st[2 * v + 1][j]);
            j++;
        }
    }
    if (j == st[2 * v + 1].size()) {
        while (i < st[2 * v].size()) {
            st[v].pb(st[2 * v][i]);
            i++;
        }
    }
    sum[v] + sum[2 * v] + sum[2 * v + 1];
}


ll get(int v, int tl, int tr, int l, int r, int addi) {
    // cout<<"get:" _ v<<endl;
    if (l > r) return 0;
    addi += add[v];
    // cout << "add:" _ v _ add[v] _ addi << endl;
    int i = lucky.size() - 1, s = 0;
    if (tl == l && tr == r) {

        while (i >= 0 && lucky[i] - addi >= 0) {
            it = lower_bound(ALL(st[v]), lucky[i] - addi, cmp);
            if (it != st[v].end() && (*it).ff == lucky[i] - addi) {
                // cout << tl _ tr _ addi _ lucky[i] _(*it).ff _(*it).ss << endl;
                s += (*it).ss;
            }
            i--;
        }
        for (i = tl; i <= tr;i++) {
            cout << a[i] + addi << " - ";
        }
        cout << endl;
        for (i = tl; i <= tr;i++) {
            cout << b[i] << " * ";
        }
        cout << endl;

        return s;
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, min(r, tm), addi) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, addi);

}

void update(int v, int tl, int tr, int l, int r, int k) {
    if (l > r) return;
    if (tl == l && tr == r) {
        add[v] += k;
        // cout << "upd" _ v _ tl _ tr _ add[v] << endl;
    } else {
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), k);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, k);
    }
}

void printT(int n) {
    for (int i = 1;i < n;i++) {
        cout << i << "--------" << endl;
        for (int j = 0;j < st[i].size();j++) {
            cout << st[i][j].ff _ st[i][j].ss << endl;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, i, j, k, l, r, q;
    string s;
    cin >> n >> q;
    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    build(a, 1, 0, n - 1);
    b = a;
    // printT(4 * n);
    while (q--) {
        cin >> s >> l >> r;
        l--;
        r--;
        if (s[0] == 'c') {
            cout << "---------" << endl;
            cout << get(1, 0, n - 1, l, r, 0) << endl;
        } else {
            cin >> k;
            update(1, 0, n - 1, l, r, k);
            for (i = l;i <= r;i++) b[i] += k;
        }
    }

}