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
    ll n, k, i, j, s=0, res=0, t;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>t;
        // cout<<i _ t<<endl;
        if(t){
            s=0;
        } else{
            s++;
            if(s==k){
                res++;
                s=0;
                if(i<n-1){
                    cin>>t;
                    i++;
                    // cout<<i _ t _ "h"<<endl;
                }
            }
        }
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