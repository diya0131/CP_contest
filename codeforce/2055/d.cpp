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

void solve() {
    ll n, k, l, i, j, res=0, t, v, tmp;
    cin>>n>>k>>l;
    vector < ll > a(n);
    for(i=0;i<n;i++) {
        cin>>a[i];
        a[i]*=2;
    }
    k*=2;
    l*=2;
    sort(ALL(a));
    t = a[0];
    v = k;
    i=1;
    while(v<l && i<n){
        if(a[i] - t<=v){
            v = min(v, a[i]+t) + k;
            
        } else {
            tmp=t;
            t+=(a[i] - t - v)/2;
            v=(a[i] - tmp + v)/2 + k;
        }
        i++;
    }
    if(v<l) t+=l-v;

    cout<<t<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}