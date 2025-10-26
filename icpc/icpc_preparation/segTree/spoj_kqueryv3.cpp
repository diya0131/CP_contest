//https://www.spoj.com/problems/KQUERY/

#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define debug(a) cout << #a << " = " << a << endl;
#define _ <<" "<<



using namespace std;

vector < ll > tree;
vector < pair < ll, ll > > a;

void update(ll v, ll tl, ll tr, ll pos) {
    // cout<<v _ pos<<endl;
    ll tm = (tl + tr) / 2;
    if (tl == tr) {
        tree[v] = 1;
    } else {
        if(pos<=tm) update(2*v, tl, tm, pos);
        else update(2*v+1, tm+1, tr, pos);
        tree[v]=tree[2*v]+tree[2*v+1];
    }

}

ll get(ll v, ll tl, ll tr, ll l, ll r, ll k) {
    if(v==-1) return 0;
    // cout<<v<<" - "<<k<<endl;
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return tree[v];
    } else {
        ll tm = (tl + tr) / 2;
        ll res = get(2 * v, tl, tm, l, min(r, tm), k) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, k);
        return res;
    }
}

int main() {
    cin.tie(0);cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, i, j, k, s, t, m, rma, x, y;
    cin >> n;
    
    vector < ll >::iterator it;
    for (i = 0; i < 4 * n; i++) {
        tree.pb(0);
    }
    rma = 1 << (ll)ceil(log2(n));
    rma=n;
    for (i = 0;i < n;i++) {
        cin >> k;
        a.pb({k, i});
    }
    sort(ALL(a), greater<>());
    
    cin >> m;
    vector < ll > q[m];
    ll res[m];
    for( i=0; i<m; i++ ) {
        cin>>x>>y>>k;
        q[i]={k, i, x-1, y-1};
    }
    sort(q, q+m, greater<>());
    j=0;
    for(i=0;i<m;i++){
        while(j<n && a[j].ff > q[i][0] ){
            update(1, 0, rma-1, a[j].ss);
            j++;
        }
        res[q[i][1]]=get(1, 0, rma-1, q[i][2], q[i][3], q[i][0]);
    }
    for(i=0;i<m;i++){
        cout<<res[i]<<endl;
    }


}