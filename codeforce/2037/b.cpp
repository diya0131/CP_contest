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

void solve() {
    ll k, i, s, p, a, b;
    cin>>k;
    vector < ll > cnt(k, 0);
    for(i=0;i<k;i++){
        cin>>p;
        if(p<k) cnt[p]++;
    }
    for(i=1;i*i<k-2;i++){
        if(cnt[i] && (k-2)%i==0 && cnt[(k-2)/i]){
            cout<<i _ (k-2)/i<<endl;
            return;
        }
    }
    if(i*i==k-2 && cnt[i]>1){
        cout<<i _ i <<endl;
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