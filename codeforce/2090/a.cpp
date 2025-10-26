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
    ll n, i, j, s=0, res=0, M = 1e9+7;;
    string a;
    cin>>a;
    n=a.size();
    map < ll, ll > mp;
    mp[0]=1;
    i=0;
    for(char ch:a){
        if(ch=='1') s++;
        else s--;
        if(mp.count(s)>0){
            res=(res+mp[s]*(n-i)%M)%M;
            // cout<<i _ s _ mp[s] _ n-i _ mp[s]*(n-i) _ endl;
        }
        mp[s]=(mp[s]+i+2)%M;
        // cout<<i _ s _ mp[s]<<endl;
        i++;
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