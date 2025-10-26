#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;
const ll M = 1e9 + 7;

vector < vector < ll > > st;

void build(vector < ll >& vec, ll v, ll tl, ll tr){
    if(tl==tr){
        st[v].pb(vec[tl]);
        return;
    }
    ll tm = (tl+tr)/2;
    build(vec, 2*v, tl, tm);
    build(vec, 2*v+1, tm+1, tr);
    merge(ALL(st[2*v]), ALL(st[2*v+1]), back_inserter(st[v]));
}

void solve() {
    ll n, k, i, j, x = 0, y = 0, m, pr, sf, l, r;
    cin>>n>>m;
    st.clear();
    st.resize(4*n);
    vector < ll > tmp(n, n), pref(n, 0), suff(n, 0), tmx(n, 0);
    for(i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        tmp[x]=y;
        pref[x]=1;
        suff[y]=1;
        tmx[y]=x;
    }
    priority_queue < ll , vector < ll > , greater< ll > > b;
    priority_queue < ll > bx;
    for(i=0;i<n;i++){

        if(tmp[i]!=n) b.push(tmp[i]);
        while(!b.empty() && b.top()<i){
            b.pop();
        }
        if(!b.empty()){
            tmp[i]=b.top();
        }
    }
    
    for(i=n-1;i>=0;i--){
        if(tmx[i]!=n) bx.push(tmx[i]);
        while(!bx.empty() && bx.top()>i){
            bx.pop();
        }
        if(!bx.empty()){
            tmx[i]=bx.top();
        }
    }
    build(tmp, 1, 0, n-1);
    for(i=0;i<n;i++){
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<n;i++){
        cout<<tmx[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<=n;i++){
        l = tmx[i];
        r = tmp[i];
        cout<<l _ r <<endl;
        // k = get(1, 0, n-1, )
    }
    
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}