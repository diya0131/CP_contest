#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

vector < ll > tree;

void build(vector < ll >& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

ll get(ll v, ll tl, ll tr, ll l, ll r){
    if(l>r) return 0;
    if(tl==l && tr == r){
        return tree[v];
    }
    else{
        ll tm = (tl+tr)/2;
        return get(2*v, tl, tm, l, min(r, tm))+get(2*v+1, tm+1, tr, max(l, tm+1), r);
    }
}

int main() {
    ll n, i, j, k, s, t, m, h, d, alld=0, l, r;
    cin >> n >> m;
    vector < ll > he, dis;
    for (i = 0;i < 4 * n;i++) tree.pb(0);
    for (i = 0;i < n;i++) {
        cin >> d;
        alld+=d;
        dis.pb(d);
    }
    for (i = 0;i < n;i++) {
        cin >> h ;
        he.pb(h);
    }
    build(dis, 1, 0, n - 1);
    // for(i=0;i<4*n;i++){
    //     cout<<i _ tree[i]<<endl;
    // }

    for(i=0;i<m;i++){
        cin>>l>>r;
        l--;
        r--;
        k = get(1, 0, n-1, l, r);
        // cout<<"sum: "<<k<<endl;
        if(l==0) k+=dis[n-1];
        else k+=dis[l-1];
        k=alld-k;
        k+=2*(he[(n+l-1)%n] + he[(r+1)%n]);
        cout<<k<<endl;
    }
}