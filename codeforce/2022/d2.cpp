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

map < pair < ll, ll >, bool > mp;

ll ask(ll x, ll y){
    ll k;
    if(mp.find({x, y})!=mp.end()) return mp[{x, y}];
    cout<<"?" _ x _ y <<endl;
    cout.flush();
    cin>>k;
    mp[{x, y}]=k;
    return k;
}

void solve() {
    ll n, i, j, k, s, l, r, m, t, x, y, z, k1, k2, k3;
    cin >> n;
    vector < bool > a(n+1, 0);
    mp.clear();
    for (i = 1;i <= n;i+=3) {
        x = 1;
        k1 = ask(i, i+1);
        if(k1==1) y = x;
        else y = (x+1)%2;
        k2 = ask(i+1, i+2);
        if(k2==1) z = y;
        else z = (y+1)%2;
        k3 = ask(i+2, i);
        if(k3 != (x==z)){
            if(k1!=1) y = x;
            else y = (x+1)%2;
            if(k2==1) z = y;
            else z = (y+1)%2;
            if(k3 == (x==z)){
                cout<<"!" _ i<<endl;
                return;
            }
            if(k1==1) y = x;
            else y = (x+1)%2;
            if(k2!=1) z = y;
            else z = (y+1)%2;
            if(k3 == (x==z)){
                cout<<"!" _ i<<endl;
                return;
            }
            if(k1==1) y = x;
            else y = (x+1)%2;
            if(k2==1) z = y;
            else z = (y+1)%2;
            if(k3 != (x==z)){
                cout<<"!" _ i<<endl;
                return;
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