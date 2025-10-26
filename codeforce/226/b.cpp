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
    ll n, i, s=1, k, t, p, mx;
    cin>>n;
    vector < ll > a(n);
    for(i=0;i<n;i++) cin>>a[i];
    if(n%2){
        vector < ll >  pref(n), suff(n);
        mx=1;
        for(i=1;i<n;i+=2){
            pref[i-1]=mx;
            mx=max(mx, a[i]-a[i-1]);
        }
        pref[n-1]=mx;
        mx=1;
        for(i=n-1;i>0;i-=2){
            suff[i]=mx;
            mx=max(mx, a[i]-a[i-1]);
        }
        suff[0]=mx;
        mx=LLONG_MAX;
        for(i=0;i<n;i+=2){
           
            mx=min(mx, max(pref[i], suff[i]));
        }
        cout<<mx<<endl;
    } else {
        mx=1;
        for(i=1;i<n;i+=2){
            mx=max(mx,a[i]-a[i-1]);
        }
        cout<<mx<<endl;
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