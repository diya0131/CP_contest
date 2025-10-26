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
    int n, k, p, t=1;
    cin>>n>>p;
    for(int i=1;i<n;i++){
        cin>>k;
        if(abs(k-p)!=5 && abs(k-p)!=7){
            // cout<<k _ p<<endl;
            t=0;
        }
        p=k;
    }
    if(t) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}