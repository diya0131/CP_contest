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
    ll l, r, k=0, t, s, i, q, a;
    cin>>l>>r;
    q = 1;
    while(q*2<=r){
        q*=2;
    }
    while((r & q) == (l & q)){
        if((r & q)!=0) k+=q;
        q/=2;
    }
    t=q;
    q/=2;
    while((r & q)==0 && (l & q)!=0){
        q/=2;
    }
    if((r & q)!=0){
        k+=t;
    } else{
        if((l & q)!=0){
        } else {
            
            k+=t - q;
        }
    }
    q/=2;
    while(q>0){
        if((l & q)==0 || (r & q)==0) k+=q;
        q/=2;
    }
    cout<<l _ k _ r<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}