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

const ll N=1e5+5, M=1e9+7;

int pow2[N];

void solve() {
    ll n, i;
    cin>>n;
    ll t[n], k[n];
    for(i=0; i<n; i++) cin>>t[i];
    for(i=0; i<n; i++) cin>>k[i];
    for(i=0;i<n;i++){
        if(t[i]==k[i]) cout<<1<<endl;
        else{
            cout<<pow2[k[i]]<<endl;
        }
    }
}

int main() {
    // BOOST
    ll q=1;
    for(ll i=0;i<N;i++){
        pow2[i]=q;
        q=(q*2)%M;
    }
    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    // }
}