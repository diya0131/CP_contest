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

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

struct model {
    string a = "";
    string b = "";
    int cnt = 0;
};

vector<model> tree;
string s, t;

model combine(model x, model y) {
    model ret;
    ret.a = x.a + y.a;
    ret.b = x.b + y.b;
    ret.cnt = x.cnt + y.cnt;
    int n = x.a.size();
    int m = y.a.size();

    for (int i = max(0, n - 3); i < min(n+m-2, n+3); i++) {
        if (ret.a[i] == '0' && ret.a[i + 2] == '0') {
            ret.b[i + 1] = '1';
        }
    }
    for (int i = max(0, n - 3); i < min(n+m-2, n+3); i++) {
        if (ret.b[i] == '1' && ret.b[i + 2] == '1' && ret.a[i + 1] == '0') {
            ret.a[i + 1] = '1';
            ret.cnt++;
        }
    }
    return ret;
}

model result(model x, model y) {
    model ret;
    if (x.a.size() >= 6) {
        x.a = x.a.substr(0, 3) + x.a.substr(x.a.size() - 3, 3);
        x.b = x.b.substr(0, 3) + x.b.substr(x.b.size() - 3, 3);
    }
    if (y.a.size() >= 6) {
        y.a = y.a.substr(0, 3) + y.a.substr(y.a.size() - 3, 3);
        y.b = y.b.substr(0, 3) + y.b.substr(y.b.size() - 3, 3);
    }
    ret.a = x.a + y.a;
    ret.b = x.b + y.b;
    ret.cnt = x.cnt + y.cnt;

    // cout << "a_size: " << ret.a.size() - 2 << endl;
    
    for (int i = max((ll)0, (ll)x.a.size()-3); i <= min(ret.a.size()-2, x.a.size()+3); i++) {
        if (ret.a[i] == '0' && ret.a[i + 2] == '0') {
            ret.b[i + 1] = '1';
        }
    }
    for (int i = max((ll)0, (ll)x.a.size()-3); i <= min(ret.a.size()-2, x.a.size()+3); i++) {
        if (ret.b[i] == '1' && ret.b[i + 2] == '1' && ret.a[i + 1] == '0') {
            ret.a[i + 1] = '1';
            ret.cnt++;
        }
    }
    
    
    return ret;
}

model make(int idx) {
    model ret;
    ret.a = s[idx];
    ret.b = t[idx];
    if (s[idx] == '1') {
        ret.cnt = 1;
    }
    return ret;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = make(tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
}

void modelPrint(model x) {
    cout << "\"" << x.a << "\", \"" << x.b << "\"," _ x.cnt << endl;
}

void print() {
    for (int i = 0; i < tree.size(); i++) {
        modelPrint(tree[i]);
    }
}

model get(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return model();
    }
    // cout << tl _ tr _ tree[v].cnt << endl;
    if (tl == l && tr == r) {
        // modelPrint(tree[v]);
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return result(get(2 * v, tl, tm, l, min(tm, r)), get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

void Solve() {
    int n;
    cin >> n;
    cin >> s >> t;
    tree.resize(4 * n);
    build(1, 0, n - 1);
    // print(); 
    int q;
    cin >> q;
    int l, r;
    while (q--) {
        cin >> l >> r;
        l--; r--;
        cout << get(1, 0, n - 1, l, r).cnt << endl;
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        Solve();
    }
}