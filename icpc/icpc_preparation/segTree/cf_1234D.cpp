#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

const ll N = 1e5 + 5;

using namespace std;

int st[4 * N];

void build(string& s, ll v, ll tl, ll tr) {
    if (tl == tr) {
        st[v] = 1 << (s[tl] - 'a');
        return;
    }
    ll tm = (tl + tr) / 2;
    build(s, 2 * v, tl, tm);
    build(s, 2 * v + 1, tm + 1, tr);

    st[v] = st[2 * v] | st[2 * v + 1];

}

int get(ll v, ll tl, ll tr, ll l, ll r) {

    if (l > r) return 0;
    if (tl == l && tr == r) {
        return st[v];
    }
    ll tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, min(r, tm)) | get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
}

void update(ll v, ll tl, ll tr, ll pos, ll val) {
    if (tl == tr) {
        st[v] = (1 << val);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2 * v, tl, tm, pos, val);
    else update(2 * v + 1, tm + 1, tr, pos, val);

    st[v] = st[2 * v] | st[2 * v + 1];

}

int main() {
    string str;
    char ch;
    cin >> str;
    int a;
    int x, y, s;
    int m, n = str.size();
    build(str, 1, 0, n - 1);
    cin >> m;
    while (m--) {
        cin >> x;
        if (x == 2) {
            cin >> x >> y;
            a = get(1, 0, n - 1, x - 1, y - 1);
            s = 0;
            while(a>0){
                if(a%2) s++;
                a/=2;
            }
            cout << s << endl;
        } else {
            cin >> x >> ch;
            update(1, 0, n - 1, x - 1, ch - 'a');
        }
    }
}