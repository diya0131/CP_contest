#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define test if(te) cout

using namespace std;

const bool te = 0;

vector < pair < ll, ll > > arr;
bool comp(ll& x, ll& y) {
    pair < ll, ll > a = arr[x];
    pair < ll, ll > b = arr[y];
    if ((a.ff + a.ss) * b.ff * b.ss == (b.ff + b.ss) * a.ff * a.ss) {
        return min(a.ff, a.ss) < min(b.ff, b.ss);
    } else return (a.ff + a.ss) * b.ff * b.ss > (b.ff + b.ss) * a.ff * a.ss;
}
bool compmi(ll& x, ll& y) {
    pair < ll, ll > a = arr[x];
    pair < ll, ll > b = arr[y];
    return  min(a.ff, a.ss) < min(b.ff, b.ss);
}

void solve() {
    ll n, i, j, k, x, y, all = 0, t, add = INT_MAX, ct;
    cin >> n >> k;
    arr.resize(n);
    vector < ll > val(n), mi(n);
    vector < bool > vis(n, 0);
    pair < ll, ll > pr;
    for (i = 0;i < n;i++) {
        cin >> x >> y;
        all += x + y;
        arr[i] = { x, y };
        val[i] = i;
        mi[i] = i;
    }
    if (all < k) {
        cout << -1 << endl;
        return;
    }
    sort(ALL(val), comp);
    sort(ALL(mi), compmi);
    for (i = 0;i < n;i++) {
        test << arr[val[i]].ff _ arr[val[i]].ss << endl;
    }
    for (i = 0;i < n;i++) {
        test << arr[mi[i]].ff _ arr[mi[i]].ss << endl;
    }
    ll s = 0, c = 0;
    for (i = 0;i < n;i++) {
        pr = arr[val[i]];
        if (s + pr.ff + pr.ss <= k) {
            vis[val[i]] = 1;
            c += pr.ff * pr.ss;
            s += pr.ff + pr.ss;
        }
    }
    if (s == k) {
        cout << c << endl;
        return;
    }
    for (i = 0;i < n;i++) {
        if (!vis[mi[i]]) {
            pr = arr[mi[i]];
            t = 0;
            ct = 0;
            while (s + t < k) {
                if (pr.ff < pr.ss) {
                    ct += pr.ff;
                    pr.ss--;
                } else {
                    ct += pr.ss;
                    pr.ff--;
                }
                // test<<pr.ff _ pr.ss _ s _ c<<endl; 
                t++;
            }
            add = min(add, ct);
        }
    }
    test << "res: ";

    cout << c + add << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cout<<"test "<<t<<endl;
        solve();}
}