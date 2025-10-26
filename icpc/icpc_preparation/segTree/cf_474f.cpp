#include<bits/stdc++.h>
#define ll long long
#define ALL(a) a.begin(), a.end()
#define pb push_back
#define _ <<" "<<

using namespace std;

struct myNode{
    ll gcd=0;
    ll cnt=0;
    // bool vis=false;
};

vector < myNode > tree;

myNode combine( myNode x, myNode y){
    myNode nd;
    // if(x.vis) return y;
    // if(y.vis) return x;

    nd.gcd=gcd(x.gcd, y.gcd);
    nd.cnt =0;
    if(nd.gcd==x.gcd) nd.cnt+=x.cnt;
    if(nd.gcd==y.gcd) nd.cnt+=y.cnt;
    return nd;
}

void build(vector < ll >& a, ll v, ll tl, ll tr){
    // cout<<v _ tl _ tr<<endl;
    myNode nd;
    if(tl==tr){
        nd.cnt=1;
        nd.gcd=a[tl];
        tree[v]=nd;
    }
    else{
        ll tm = (tl+tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        nd = combine(tree[2*v], tree[2*v+1]);
        tree[v]=nd;
    }
}

myNode get(ll v, ll tl, ll tr, ll l, ll r){
    myNode nd;
    // nd.vis = -1;
    if(l>r) return nd;
    if(tl == l && tr == r){
        nd = tree[v];
        // tree[v].vis = 1;
        return nd;
    }
    ll tm = (tl+tr)/2;
    nd=combine(get(2*v, tl , tm, l, min(r, tm)), get(2*v+1, tm+1, tr, max(l, tm+1), r));
    
    return nd;
}

int main(){
    ll n, i, j, k, s, t, l, r, m;
    myNode nd;
    // nd.vis = 0;
    vector < ll > a;
    cin>>n;
    for(i=0;i<4*n;i++) tree.pb(nd);
    for(i=0;i<n;i++){
        cin>>k;
        a.pb(k);
    }
    build(a, 1, 0, n-1);
    // for(i=0;i<4*n;i++){
    //     cout<<i _ tree[i].gcd _ tree[i].cnt _ tree[i].vis<<endl;
    // }

    cin>>m;
    for(i=0;i<m;i++){
        cin>>l>>r;
        nd = get(1, 0, n-1, l-1, r-1);
        // cout<<nd.cnt<<endl;
        cout<< ( r - l + 1 ) - nd.cnt <<endl;
    }
}