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

map < int, int > mp;

int go(int k){
    if(k==3) return 1;
    if(mp.find(k)!=mp.end()){
        return mp[k];
    }
    int s=0, sq = sqrt(k), t=k, x, y;
    for(int i=3;i<=sq;i+=2){
        if(t%i!=0) continue;
        x = i;
        y = t/i;
        while(t%x==0){
            // cout<<k _ "haha" _ x _ t<<endl;
            s+=go(x);
            t/=x;
            // cout<<t _ x _ s<<endl;
        }
        x = y;
        while(t%x==0){
            // cout<<k _ "haha" _ x _ t<<endl;
            s+=go(x);
            t/=x;
            // cout<<t _ x _ s<<endl;
        }
        if(t==1) break;
    }
    // cout<<t<<endl;
    if(t!=1) s = 1+go(k-2);
    mp[k] = s;
    // cout<<"go" _ k _ mp[k]<<endl;
    return mp[k];
}

void solve() {
    ll m;
    cin>>m;
    if(m%2==0){
        cout<<-1<<endl;
        return;
    }
    ll k=1, res=0, n = sqrt(m);
    
    cout<<1+go(m)<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}