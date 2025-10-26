#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define test if(te) cout

using namespace std;

const bool te = 0;


void solve() {
    ll n, i, k, s=0, t;
    cin>>n>>k;
    vector < ll > a(n);
    for(i=0;i<n;i++) cin>>a[i];
    sort(ALL(a));
    for(i=n-2;i>=0;i-=2){
        t=min(a[i+1]-a[i], k);
        a[i]+=t;
        k-=t;
        s+=a[i+1]-a[i];
    }
    if(n%2) s+=a[0];
    cout<<s<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {

        solve();
    }
}