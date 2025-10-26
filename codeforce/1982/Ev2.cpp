#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define debug if(de) cout
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool de = true;
const ll M = 1e9 + 7;
const ll inv2 = 500000004;

struct mydata {
    ll val;
    ll pref;
    ll suff;
    ll len;
};

mydata combine(mydata x, mydata y) {
    mydata pr;
    pr.len = x.len + y.len;
    pr.pref = x.pref;
    pr.suff = y.suff;
    ll n = x.suff + y.pref;
    ll add = (n * (n + 1) % M) * inv2 % M;

    if (x.pref == x.len) {
        pr.pref = x.pref + y.pref;
        add = 0;
    }
    if (y.suff == y.len) {
        pr.suff = x.suff + y.suff;
        add = 0;
    }
    pr.val = (x.val + y.val + add) % M;
    return pr;
}

mydata get(ll n, ll k, ll q) {
    
    mydata pr;
    pr.len = n;
    // if (n < (1 << k) - 1) {
    //     cout<<"here"<<endl;
    //     pr.val = 0;
    //     pr.pref = 0;
    //     pr.suff = 0;
    //     return pr;
    // }
    if (k == 0 || n == 0) {
        pr.val = 0;
        pr.pref = 1;
        pr.suff = 1;
        cout << n _ k _ q << endl;
        cout<<pr.val _ pr.pref _ pr.suff _ pr.len<<endl;
        return pr;
    }
   
    if (n >= q) pr = combine(get(q - 1, k, q / 2), get(n - q, k - 1, q / 2));
    else pr = get(n, k, q / 2);
    cout << n _ k _ q << endl;
    cout<<pr.val _ pr.pref _ pr.suff _ pr.len<<endl;
    return pr;
}

void solve() {
    ll n, m, i, k, s = 0, q = 1;
    cin >> n >> k;
    q = 1;
    while (n / q > 1) {
        q *= 2;
    }
    mydata pr;
    pr = get(n, k, q);
    s = pr.val;
    k = pr.pref;
    s = (s + (k * (k + 1) % M) * inv2 % M) % M;
    if (pr.pref != n) {
        k = pr.suff;
        s = (s + (k * (k + 1) % M) * inv2 % M) % M;
    }
    cout << s << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}