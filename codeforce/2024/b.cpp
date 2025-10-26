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
    ll n, k, i, j, s=0, p, res=0;
    cin>>n>>k;
    ll a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    i=0;
    p=0;
    while(s<k){
        s+=(a[i]-p)*(n-i);
        res+=(a[i]-p)*(n-i);
        if(s>=k) {
            res-=(s-k);
            cout<<res<<endl;
            return;
        }
        p=a[i];
        i++;
        res++;
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