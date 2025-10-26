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
    int n, i, j, k, s=0, u, v, p;
    cin>>n;
    int mw=0, mh=0;
    for(i=0;i<n;i++){
        cin>>u>>v;
        mw=max(mw, u);
        mh=max(mh, v);
    }
   
    cout<<(mw+mh)*2<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}