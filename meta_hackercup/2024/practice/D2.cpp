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
ll n;

ll check(ll st, ll k, vector < ll >& a){
    ll i;
    for(i=st+1;i<n;i++){
        if(st+a[i]>=k) k--;
        else k=
    }
}

void solve() {
    ll e, g, i, j, k, s, l, r, m;
    cin>>n>>g;
    vector< ll > a(n), fr(n);
    for(i=0;i<n;i++){
        cin>>e;
        a[i]=e;
    }
    k=INT_MAX;
    for(i=0;i<n;i++){
        k=min(k-1, a[i]);
        fr[i]=k;
    }
    l=0;
    r=n-1;
    while(l<r){
        m=(l+r)/2;
        k = check(m, fr[m], a);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}