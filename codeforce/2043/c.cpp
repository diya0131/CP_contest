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

void solve() {
    ll n, i, j, k=-1, s=0, ma=0, mi=0, sma=0, smi=0;
    cin>>n;
    vector< ll > a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1 && a[i]!=-1){
            k = i;
        }
    }
    if(k==-1) k=0;
    s=0;
    for(i=k+1;i<n;i++){
        s+=a[i];
        ma = max(s, ma);
        mi = min(s, mi);
    }
    sma = ma;
    smi = mi;
    ma = 0;
    mi = 0;
    s=0;
    for(i=k-1;i>=0;i--){
        s+=a[i];
        ma = max(s, ma);
        mi = min(s, mi);
    }
    sma += ma;
    smi += mi;
    ma = 0;
    mi = 0;
    s=0;
    for(i=0;i<k;i++){
        s+=a[i];
        if(s<0) s=0;
        ma=max(ma, s);
    }
    s=0;
    for(i=k+1;i<n;i++){
        s+=a[i];
        if(s<0) s=0;
        ma=max(ma, s);
    }
    s=0;
    for(i=0;i<k;i++){
        s+=a[i];
        if(s>0) s=0;
        mi=min(mi, s);
    }
    s=0;
    for(i=k+1;i<n;i++){
        s+=a[i];
        if(s>0) s=0;
        mi=min(mi, s);
    }
    // cout<<sma _ smi _ ma _ mi _ a[k]<<endl;
    ll res = sma - smi + 2 + ma - mi;

    if(min(a[k]+sma, ma) >= max(a[k]+smi, mi)){
        res -= min(a[k]+sma, ma) - max(a[k]+smi, mi)+1;
    }
    cout<<res<<endl;
    if(mi<a[k]+smi){
        for(i=mi;i<=ma;i++){
            cout<<i<<" ";
        }
        for(i=smi; i<=sma;i++){
            if(a[k]+i<mi || ma<a[k]+i) cout<<a[k]+i<<" ";
        }
    } else {
        for(i=smi; i<=sma;i++){
            cout<<a[k]+i<<" ";
        }
        for(i=mi;i<=ma;i++){
            if(i<a[k]+smi || a[k]+sma<i)cout<<i<<" ";
        }
        
    }
    cout<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}