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

void solve() {
    ll n, i, j, k, s, t, l, r;
    cin>>n;
    vector < ll > a(n), pre(n, n), suf(n, n), sign(n+1, 0), cnt(n, 0);
   
    for(i=0; i<n; i++){
        cin>>a[i];
       
    }
    ll mn=INT_MAX;
    for(i=0;i<n;i++){
        pre[i]=mn;
        mn=min(mn, a[i]);
    }
    mn=INT_MAX;
    for(i=n-1;i>=0;i--){
        suf[i]=mn;
        mn=min(mn, a[i]);
    }
    test<<"here\n";
    for(i=0;i<n;i++){
        l=max(0LL, i-a[i]+1);
        r=min(n-1, i+a[i]-1);
        if(pre[l]<=a[i] || suf[r]<=a[i]){
            cout<<0<<endl;
            return;
        }
        sign[l]++;
        sign[r+1]--;
    }
    s=0;
    for(i=0;i<n;i++){
        // cout<<i _ sign[i]<<endl;
        s+=sign[i];
        cnt[i]=s;
    }
    

    ll res=0;
    for(i=0;i<n;i++){
        // cout<<i _ cnt[i]<<endl; 
        if(cnt[i]==n) res++;
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}