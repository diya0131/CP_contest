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
    ll n, r, i, mx=-1, k, s=0, b=0, c;
    cin>>n>>r;
    for(i=0;i<n;i++){
        cin>>k;
        s+=k;
        if(k%2){
            b++;
        }
    }
    
    if(r - (s-b)/2 >= b) c = b;
    else c = (r - (s-b)/2) - ( b - (r - (s-b)/2));
    // cout<<s _ b _ r _ (r - (s-b)/2) _ c<<endl;
    cout<<(s - b) + c<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}