#include<bits/stdc++.h>
#include<chrono>
#include <random>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

vector< vector < ll > > mp;

map < ll, ll > posmp;

bool go(map<ll,vector<ll>>&a, map<ll,vector<ll>>&b, vector< ll >&p, vector< ll >&d, ll pos, bool dir, ll k){
    ll t, to, idx;
    test<<pos _ dir<<endl;
    ll ppos = pos;
    bool pdir = dir, res;
    
    while(1){
        idx = posmp[pos];
        if(mp[idx][dir]!=-1){
            if(mp[idx][dir]<2){
                res =  mp[idx][dir];
                break;
            } else {
                res = 0;
                break;
            }
        }  else {
            mp[idx][dir]=2;
        }

        
        if(dir){
            t = (pos + d[idx])%k;
            if(upper_bound(ALL(b[t]), -pos)==b[t].end()){
                res = 1;
                break;
            } else {
                to = -*upper_bound(ALL(b[t]), -pos);
            }
        } else {
            t = (pos - d[idx]%k + k)%k;
            test<<"t" _ t<<endl;
            if(upper_bound(ALL(a[t]), pos)==a[t].end()){
                res = 1;
                break;
            } else {
                to = *upper_bound(ALL(a[t]), pos);
            }
        }
        test<<to<<endl;
        pos = to;
        dir = !dir;
    }

    pos = ppos;
    dir = pdir;
    while(1){
        idx = posmp[pos];
        if(mp[idx][dir]!=-1){
            if(mp[idx][dir]<2) break;
        }  
        mp[idx][dir]=res;

        ll idx = posmp[pos];
        if(dir){
            t = (pos + d[idx])%k;
            if(upper_bound(ALL(b[t]), -pos)==b[t].end()){
                break;
            } else {
                to = -*upper_bound(ALL(b[t]), -pos);
            }
        } else {
            t = (pos - d[idx]%k + k)%k;
            if(upper_bound(ALL(a[t]), pos)==a[t].end()){
                break;
            } else {
                to = *upper_bound(ALL(a[t]), pos);
            }
        }
        pos = to;
        dir = !dir;
        
    }
    return res;
}

void solve() {
    mp.clear();
    posmp.clear();
    ll n, k, s, t, to, i, j, q, pos;
    cin>>n>>k;
    mp.resize(n, vector < ll >(2, -1));
    vector< ll > p(n), d(n);
    map<ll, vector< ll > > a, b;
    for(i=0;i<n;i++) cin>>p[i];
    for(i=0;i<n;i++){
        posmp[p[i]]=i;
        cin>>d[i];
        t = (p[i]%k - d[i]%k + k) % k;
        a[t].pb(p[i]);
        t = (p[i]%k + d[i]%k + k) % k;
        b[t].push_back(-p[i]);
    }
    for(auto it=b.begin();it!=b.end();it++){
        ll sz = it->ss.size();
        for(i=0;i<sz/2;i++){
            swap(it->ss[i], it->ss[sz-1-i]);
        }
    }
    
    pair < ll, bool > pr;
    
    cin>>q;
    while(q--){
        cin>>pos;
        pos = pos;
        t = pos%k;
       
        if(lower_bound(ALL(a[t]), pos)==a[t].end()){
            cout<<"YES\n";
        } else {
            to = *lower_bound(ALL(a[t]), pos);
            if(go(a, b, p, d, to, 1, k)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        
    }
}

int main() {
    // BOOST
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}