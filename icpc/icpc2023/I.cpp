#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

const bool TEST = 0;
ll cnt, v;
vector < vector< pair < ll, ll > > > adj;

pair < ll, bool > dfs(pair < ll, ll > k, ll p){
    ll mx=0, mn=1;
    pair < ll, bool > pr;
    if(k.ff!=0 && adj[k.ff].size()==1) mx=0;
    for(auto to: adj[k.ff]){
        if(to.ff!=p){
            pr=dfs(to, k.ff);
            if(pr.ss) mn=min(mn, pr.ff);
            else mx=max(mx, pr.ff);
        }
    }
    test<<k.ff _ k.ss _ mn _ mx <<endl;
    if(mn<=0 && mx+mn<=0) {
        return {mn+k.ss, 1};
    }
    
    if(mx+k.ss>v){
        cnt++;
        test<<"++" _ k.ss - v <<endl;
        return {k.ss-v, 1};
    }
    return {mx+k.ss, 0};
}

int main() {
    ll n, i, j, k, s, c, l, r, m, t;
    pair < ll, bool > pr;
    cin>>n>>c;    
    adj.resize(n);
    for(i=1;i<n;i++){
        cin>>k>>t;
        k--;
        adj[i].pb({k, t});
        adj[k].pb({i, t});
    }
    l=0;r=1e10;
    // l=0;r=30;

    while(l<r){
        m=(l+r)/2;
        v=m;
        cnt=0;
        pr=dfs({0, 1}, -1);
        if(!pr.ss) cnt++;
        test<<"--------" _ m _ cnt _ k<<endl;
        if(cnt>c){
            l=m+1;
        } else {
            r=m;
        }
    }
    cout<<l<<endl;
}