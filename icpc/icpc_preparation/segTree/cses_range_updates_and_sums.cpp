#include<bits/stdc++.h>
#define ALL(a) a.begin(), a.end()
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

const ll N = 2e5 + 5;

ll st[4 * N] = { 0 }, base[4 * N] = { 0 }, add[4 * N] = { 0 };

void build(vector < ll >& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void push(ll v, ll len) {
    ll right = len / 2;
    ll left = len - right;
    if (base[v] != 0) {
        st[2 * v] = left * base[v];
        st[2 * v + 1] = right * base[v];
        base[2 * v] = base[v];
        base[2 * v + 1] = base[v];
        add[2 * v] = 0;
        add[2 * v + 1] = 0;
    }
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    st[2 * v] += add[v] * left;
    st[2 * v + 1] += add[v] * right;
    add[v] = 0;
    base[v] = 0;
}



void updateAdd(ll v, ll tl, ll tr, ll l, ll r, ll k) {
    // cout<<"updateAdd" _ v _ tl _ tr _ "|" _ l _ r<<endl;
    if (l > r) return;
    if (tl == l && tr == r) {
        // cout<<"updateAdd=" _ v _ tl _ tr<<endl;
        st[v] += (tr - tl + 1) * k;
        add[v] += k;
        return;
    }
    ll tm = (tl + tr) / 2;
    push(v, tr - tl + 1);
    // cout<<"called "<<tl _ tm _ tr _ "|" _ l _ min(r, tm) _ "|" _ max(l, tm+1) _ r<<endl;
    updateAdd(2 * v, tl, tm, l, min(r, tm), k);
    updateAdd(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, k);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void updateBase(ll v, ll tl, ll tr, ll l, ll r, ll k) {
    if (l > r) return;
    if (tl == l && tr == r) {
        st[v] = (tr - tl + 1) * k;
        base[v] = k;
        add[v] = 0;
        return;
    }
    ll tm = (tl + tr) / 2;
    push(v, tr - tl + 1);
    updateBase(2 * v, tl, tm, l, min(r, tm), k);
    updateBase(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, k);
    st[v] = st[2 * v] + st[2 * v + 1];
}

ll get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return st[v];
    ll tm = (tl + tr) / 2;
    push(v, tr-tl+1);
    return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void printT(ll n) {
    cout << endl;
    for (int i = 1;i < 14;i++) {
        cout << i _ st[i] _ add[i] _ base[i] << endl;
    }
}

int main() {
    ll n, i, j, k, s, q, l, r;
    vector < ll > a;
    // freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb(k);
    }
    build(a, 1, 0, n - 1);

    while (q--) {
        cin >> j;

        switch (j) {
        case 1:
            cin >> l >> r >> k;
            // cout<<"add" _ l-1 _ r-1 _ k<<endl;
            updateAdd(1, 0, n - 1, l - 1, r - 1, k);
            break;

        case 2:
            cin >> l >> r >> k;
            // cout<<"base" _ l-1 _ r-1 _ k<<endl;
            updateBase(1, 0, n - 1, l - 1, r - 1, k);
            break;
        case 3:
            cin >> l >> r;
            // cout<<"see" _ l-1 _ r-1 <<endl;
            cout << get(1, 0, n - 1, l - 1, r - 1) << endl;
            break;
        }
        // printT(n);
    }
}