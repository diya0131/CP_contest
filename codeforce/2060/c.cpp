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
    ll n, k, i, s=0, t, p=0;
    cin>>n>>k;
    vector < ll > cnt(n+1, 0);
    for(i=0;i<n;i++){
        cin>>t;
        cnt[t]++;
    }
    t=0;
    for(i=1;i<=n;i++){
        
        if(k-i>n || k-i<=0) t+=cnt[i];
        else{
            // cout<<i _ cnt[i] _ cnt[k-i]<<endl;
            if(k-i==i){
                p+=cnt[i]/2;
                t+=cnt[i]%2;
                continue;
            }
            if(cnt[i]>=cnt[k-i]){
                p+=cnt[k-i];
                t+=cnt[i]-cnt[k-i];
            } else{
                p+=cnt[i];
                t+=cnt[k-i]-cnt[i];
            }
            cnt[k-i]=0;
            cnt[i]=0;
        }
    }
    if(t%2) cout<<0<<endl;
    else cout<<p<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}