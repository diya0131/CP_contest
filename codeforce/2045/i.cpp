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

ll n;
vector < ll > bt;

void add(ll k){
    while(k<=n){
        bt[k]++;
        k+=(-k) & k;
    }
}

ll get(ll k){
    ll s=0;
    while(k>0){
        s+=bt[k];
        k-=(-k) & k;
    }
    return s;
}

void solve() {
    ll i, j, k, s, m, c=0, res=0, u;
    cin>>n>>m;
    vector < bool > is(m, false);
    map < ll, ll > mp;
    bt.assign(n+1, 0);
    for(i=1;i<=n;i++){
        cin>>k;
        if(is[k]){
            u = (i - mp[k] - 1) - (get(i-1) - get(mp[k]));
            res+=u;
            add(mp[k]);
        } else {
            is[k]=1;
            c++;
            u = (i - 1) - get(i-1);
            res+=u;
        }
        mp[k]=i;
        // cout<<i _ res<<endl;
    }
    // cout<<res _ c _ m-c<<endl;
    res+=c * (m-c);
    res+=(c-1)*c/2;
    cout<<res<<endl;
}

int main() {
    // BOOST
    solve();
}