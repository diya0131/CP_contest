#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const ll N = 3e5 + 5, N1 = 1e6 + 1;

const ll N2 = 10;
ll st[4 * N][N2];

ll lazy[4 * N];
ll val[N1], cnt[N1];

vector < ll > a;

void build(vector < ll >& a, ll v, ll tl, ll tr) {
    ll k;
    if (tl == tr) {
        lazy[v] = 0;
        k = a[tl];
        for (int i = 0;i < N2;i++) {
            st[v][i] = k;
            k = val[k];
        }
        return;
    }
    ll tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    for (int i = 0;i < N2;i++) {
        st[v][i] = st[2 * v][i] + st[2 * v + 1][i];
    }
}

void push(ll v) {
    if (lazy[v] > 0) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        lazy[v]=min(N2, lazy[v]);
        if (st[2 * v][0] > st[2 * v][N2 - 1]) {
            // if(true){
            for (int i = 0;i + lazy[v] < N2;i++) {
                st[2 * v][i] = st[2 * v][i + lazy[v]];
            }
            for (int i = N2 - lazy[v];i < N2;i++) {
                st[2 * v][i] = st[2 * v][N2 - 1];
            }
        } 
        
        if (st[2 * v + 1][0] > st[2 * v + 1][N2 - 1]) {
            // if(true){
            for (int i = 0;i + lazy[v] < N2;i++) {
                st[2 * v + 1][i] = st[2 * v + 1][i + lazy[v]];
            }
            for (int i = N2 - lazy[v];i < N2;i++) {
                st[2 * v + 1][i] = st[2 * v + 1][N2 - 1];
            }
        } 
        
        lazy[v] = 0;
    }
}

bool update(ll v, ll tl, ll tr, ll l, ll r) {
    ll k, su;
    if (l > r) return false;
    if (tl == l && tr == r) {
        lazy[v]++;
        su = 0;
        if (st[v][0] > st[v][N2 - 1]) {
            for (int i = 0;i + 1 < N2;i++) {
                st[v][i] = st[v][i + 1];
            }
            return true;
        }
        return false;
    }
    ll tm = (tl + tr) / 2;
    push(v);
    bool u1, u2;
    u1 = update(2 * v, tl, tm, l, min(r, tm));
    u2 = update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    if (u1 || u2) {
        for (int i = 0;i < N2;i++) {
            st[v][i] = st[2 * v][i] + st[2 * v + 1][i];
        }
        return true;
    }
    return false;
}

ll get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return st[v][0];
    }
    ll tm = (tl + tr) / 2;
    push(v);
    return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

// void printT(ll n) {
//     for (int i = 0;i < 13;i++) {
//         cout << "index " << i _ st[i][0] _ lazy[i] << endl;
//     }
//     cout << "print \n";
//     for (int i = 0;i < n;i++) {

//         cout << a[i] << " ";

//     }
//     cout << endl;
// }

int main() {
    ll n, m, i, j, k, s, l, r;

    for (i = 1;i < N1;i++) {
        j = i;
        while (j < N1) {
            val[j]++;
            j += i;
        }
    }

    cin >> n >> m;
    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    int num=0;
    build(a, 1, 0, n - 1);
    while (m--) {
        cin >> j >> l >> r;
        l--;
        r--;
        if (j == 1) {
            update(1, 0, n - 1, l, r);
        } else {
            num++;
            cout << get(1, 0, n - 1, l, r) << endl;
        }
    }
}