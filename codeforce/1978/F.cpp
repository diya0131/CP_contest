#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define _ <<" "<<

using namespace std;

const ll N = 1e6 + 1;


struct dsu {
    ll parent;
    ll rank;
};

vector < ll > divs[N];
map< ll, ll > primes;
set< ll >::iterator it;
vector< dsu > comps;
ll s;

ll find(ll x) {
    if (comps[x].parent == x) return x;
    comps[x].parent = find(comps[x].parent);
    return comps[x].parent;
}

void Union(ll x, ll y){
    ll left = find(x);
    ll right = find(y);
    if(left==right){
        return;
    }
    s--;
    if(comps[left].rank < comps[right].rank){
        comps[left].parent = right;
        return;
    }
    if(comps[left].rank > comps[right].rank){
        comps[right].parent = left;
        return;
    }
    
    comps[left].parent = right;
    comps[right].rank++;
    return;
    
}


void solve() {
    primes.clear();
    comps.clear();
    ll n, i, j, k, t, i1;
    cin >> n >> k;
    k = min(n, k);
    bool vis[2 * n], can;
    vector< ll > a(n);
    s = 2 * n - 1;
    // cout<<s<<endl;
    for (i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i] == 1) {
            s += n - 2;
        }
        vis[i] = true;
        vis[n + i] = true;
    }
    if (a[0] == 1) s++;
    dsu ds;
    ds.rank = 1;
    comps.pb(ds);
    for (i = 1;i < 2 * n;i++) {
        ds.parent = i;
        comps.pb(ds);
    }
    // cout<<s<<endl;
    for (i = 1;i < 2 * n;i++) {

        i1 = i % n;
        can = false;
        for (j = 0;j < divs[a[i1]].size();j++) {
            if ( primes.find(divs[a[i1]][j])!=primes.end() && primes[divs[a[i1]][j]] >= i - k){
                Union(i, primes[divs[a[i1]][j]]);
            }
            primes[divs[a[i1]][j]]=i;
        }
       
    }
    
    cout << s << endl;
}

int main() {
    ll k;
    for (ll i = 2;i < N;i++) {
        if (divs[i].size() == 0) {
            k = i;
            while (k < N) {
                divs[k].pb(i);
                k += i;
            }
        }
    }
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}