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
    ll n, i, s, j, k, p, res=0;
    cin>>n;
    vector < ll > a(n);
    for(i=0;i<n;i++) cin>>a[i];
    sort(ALL(a));
    j=n-1;
    while(a[0]+a[1]<=a[j]) j--;
    res=n-j-1;
    for(i=2;i<n;i++){
        while(j+1<n && a[i-1]+a[i]>a[j+1]) j++;
        res=min(res, i-1+n-j-1);
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