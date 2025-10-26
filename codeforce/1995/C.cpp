#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

void solve() {
    ll n, m, i, j, x, y, k, pre, precnt, res = 0, q, p;
    cin >> n >> m;
    map < ll, ll > mp;
    map < ll, ll >::iterator it;
    ll a[n];
    for (i = 0;i < n;i++) {
        cin >> a[i];
       
    }
    for (i = 0;i < n;i++) {
        cin >> k;
       mp[a[i]]=k;
    }
    pre = (*mp.begin()).ff;
    precnt = (*mp.begin()).ss;
    it = next(mp.begin());
    res=pre*min(m/pre, precnt);
    for (;it != mp.end();it++) {
        res=max(res, (*it).ff * min((*it).ss, m/(*it).ff));
        if ((*it).ff == pre + 1) {
            if ((*it).ss * (*it).ff + pre * precnt <= m) {
                res = max(res, (*it).ss * (*it).ff + pre * precnt);
            } else {
                p = min((m / pre), precnt);
                k = pre * p ;
                q= min(((m-k)/(*it).ff), (*it).ss);
                k+=q*(*it).ff;
                res = max(res, k + min(m - k, min((*it).ss-q, p)));
            }
        }
        pre = (*it).ff;
        precnt = (*it).ss;
        test<<i _ res<<endl;
    }
    cout<<res<<endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}