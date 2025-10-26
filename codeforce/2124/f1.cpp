#include<bits/stdc++.h>
#include<chrono>
#include <random>

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
const ll mod = 998244353;

void solve() {
    ll n, m, i, k, s, t, j, ln;
    cin>>n>>m;
    vector<bitset<205>>bt(n);
    for(i=0;i<n;i++) bt[i].reset();
    for(i=0;i<m;i++){
        cin>>k>>t;
        k--;
        t--;
        bt[k].set(t);
    }
    for(i=0;i<n;i++) cout<<i _ bt[i]<<endl;
    vector<ll>dp(n, 0);
    bitset<205>x, t1, t2;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            x.reset();
            ln = i - j +1;
            for(int l=j;l<=i;l++){
                t1 = bt[l]<<(l - j);
                t2 = bt[l]>>(205 - l);
                t2 = t2 <<(205 - ln);
                cout<<i _ j _ l _ t1 _ t2<<endl;
            }
            if(j==0){

            }
        }
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