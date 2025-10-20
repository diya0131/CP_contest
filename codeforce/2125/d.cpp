#include<bits/stdc++.h>
#include<random>
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
const ll M = 998244353;

ll inv(ll x){
    ll q = x, res = 1, t = M-2;
    while(t){
        if(t%2) res = (res * q)%M;
        q = (q*q)%M;
        t/=2;
    }
    return res;
}


void solve() {
    ll n, m, i, j, s, t, l, r, p, q, idx, x;
    float x1;
    cin>>n>>m;

    vector< pair < ll, ll > > a(n), b(n), pr(n);

    for(i=0;i<n;i++){
        cin>>l>>r>>p>>q;
        l--; r--;
        a[i] = {l, i};
        b[i] = {l, r};
        pr[i] = {p, q};
    }
    sort(ALL(a));
    vector<ll>dp(m+1, 0), dpn(m+1, 1);
    vector<float>dp1(m+1, 0), dp1n(m+1, 1);
    dp[m]=1;
    dp1[m]=1;

    l = m;

    for(i=n-1;i>=0;i--){
        idx = a[i].ss;
        while(b[idx].ff < l){
            dpn[l-1] = dpn[l];
            dp1n[l-1] = dp1n[l];
            l--;
        }
        dpn[b[idx].ff] = dpn[b[idx].ff] * (pr[idx].ss-pr[idx].ff)%M * inv(pr[idx].ss)%M;
        dp1n[b[idx].ff] = dp1n[b[idx].ff] * (pr[idx].ss-pr[idx].ff) / (pr[idx].ss);
    }
    
    for(i=n-1;i>=0;i--){
        idx = a[i].ss;
        
        x = (((dpn[b[idx].ff] * inv(dpn[b[idx].ss+1]))% M * inv(pr[idx].ss-pr[idx].ff)) % M * pr[idx].ss) % M;
        x1 = dp1n[b[idx].ff] / dp1n[b[idx].ss+1] / (pr[idx].ss-pr[idx].ff) * (pr[idx].ss);
        // cout<<dp1n[b[idx].ff] _ dp1n[b[idx].ss+1] _ (pr[idx].ss-pr[idx].ff) / (pr[idx].ss) _ x1<<endl;
        dp[b[idx].ff] = (dp[b[idx].ff] + ((pr[idx].ff * dp[b[idx].ss+1])%M * inv(pr[idx].ss) % M * x) % M) % M;
        dp1[b[idx].ff] = float(dp1[b[idx].ff] + (float(pr[idx].ff * dp1[b[idx].ss+1]) / pr[idx].ss * x1));
        // cout<<dp[b[idx].ss+1] _ (((pr[idx].ff * dp[b[idx].ss+1])%M * inv(pr[idx].ss)) % M * x) % M<<endl;
        
        // cout<<b[idx].ff _ dp[b[idx].ff] _ x _ dpn[b[idx].ff]<<endl;
        // cout<<dp1[b[idx].ss+1] _ b[idx].ss+1<<endl;
        // cout<<b[idx].ff _ dp1[b[idx].ff] _ x1 _ (float(pr[idx].ff * dp1[b[idx].ss+1]) / pr[idx].ss * x1) _ dp1n[b[idx].ff]<<endl;
    }

    // for(i=0;i<=n;i++){
    //     cout<<i _ dp1n[i]<<endl;
    // }
    // for(i=0;i<=n;i++){
    //     cout<<i _ dp1[i]<<endl;
    // }
    cout<<dp[0]<<endl;
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
}