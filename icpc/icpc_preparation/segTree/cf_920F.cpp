#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const ll N = 3e5 + 5, N1 = 1e6 + 1;

vector < ll* > st[4 * N];
vector < ll* >::iterator it;
ll sum[4 * N];
bool marked[4 * N];
ll non[4 * N];

ll val[N1];

vector < ll > a;

void build(vector < ll >& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        marked[v] = 0;
        if (a[tl] > 2) {
            st[v].pb(&a[tl]);
            sum[v] = a[tl];
            non[v] = 0;
        } else {
            sum[v] = 0;
            non[v] = a[tl];
        }
        return;
    }
    ll tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    for (int i = 0;i < st[2 * v].size();i++) st[v].pb(st[2 * v][i]);
    for (int i = 0;i < st[2 * v + 1].size();i++) st[v].pb(st[2 * v + 1][i]);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    non[v] = non[2 * v] + non[2 * v + 1];
}

void push(ll v) {
    if (marked[v]) {
        marked[2 * v] = 1;
        marked[2 * v + 1] = 1;
        ll t = 2 * v;
        ll su = 0;
        for (it = st[t].begin(); it != st[t].end();) {
            if (**it < 3) {
                non[t] += **it;
                st[t].erase(it);
            } else {
                su += **it;
                it++;
            }
        }
        sum[t] = su;
        t = 2 * v + 1;
        su = 0;
        for (it = st[t].begin(); it != st[t].end();) {
            if (**it < 3) {
                non[t] += **it;
                st[t].erase(it);
            } else {
                su += **it;
                it++;
            }
        }
        sum[t] = su;
        marked[v] = 0;
    }
}

void update(ll v, ll tl, ll tr, ll l, ll r) {
    ll k, su;
    if (l > r) return;
    if (tl == l && tr == r) {
        marked[v] = 1;
        su = 0;
        for (it = st[v].begin(); it != st[v].end();) {
            k = val[**it];
            if (k < 3) {
                if(**it>2) non[v] += k;
                **it = 0;
                st[v].erase(it);
            } else {
                su += k;
                **it = k;
                it++;
            }
        }
        sum[v] = su;
        return;
    }
    ll tm = (tl + tr) / 2;
    push(v);
    update(2 * v, tl, tm, l, min(r, tm));
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    non[v] = non[2 * v] + non[2 * v + 1];
}

ll get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return sum[v] + non[v];
    }
    ll tm = (tl + tr) / 2;
    push(v);
    return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void printT(ll n) {
    for (int i = 0;i < 13;i++) {
        cout << "index " << i _ sum[i] _ non[i] << endl;
        for (int j = 0;j < st[i].size();j++) cout << *st[i][j] << " ";
        cout << endl;
    }
    cout << "print \n";
    for (int i = 0;i < n;i++) {

        cout << a[i] << " ";

    }
    cout << endl;
}

int main() {
    ll n, m, i, j, k, s, l, r;

    for (i = 1;i <= N1;i++) {
        j = i;
        while (j <= N1) {
            val[j]++;
            j += i;
        }
    }

    cin >> n >> m;

    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    build(a, 1, 0, n - 1);

    while (m--) {
        cin >> j >> l >> r;

        l--;
        r--;
        // cout << "query: " << j _ l _ r << endl;
        if (j == 1) {
            update(1, 0, n - 1, l, r);
        } else {
            cout << get(1, 0, n - 1, l, r) << endl;
        }
        // printT(n);
    }
}