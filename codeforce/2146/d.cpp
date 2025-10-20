#include<bits/stdc++.h>
#include<random>
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

vector<ll>res(2e5+5);
ll s, supl;

void calc(ll l, ll r, ll pref){

    if(l==r){
        s+=(l+pref);
        res[l+pref- supl]=l+pref;
        return;
    }
    ll p = 0;
    while(p<r) p=2*p+1;

    ll m = (p+1)/2;
    // cout<<" - " _ l _ r _ pref _ m<<endl;
    if(l>r) return;


    if(l >=m){
        calc(l-m, r-m, pref+m);
        return;
    }
    if(r - m >= m-1 - l){
        for(ll i=l;i<m;i++){
            res[i+pref - supl] = pref+p - i;
            res[pref+p-i - supl] = i+pref;
        }
        // cout<<pref _ p _ 2*(m - l) _ "left" _ l _ m _ r<<endl;
        calc(m-l, r-m, pref+m);
        s += (pref + p) * 2*(m - l);
    } else {
        for(ll i=m;i<=r;i++){
            res[i+pref - supl] = pref+p - i;
            res[pref+p-i - supl] = i+pref;
        }
        // cout<<pref _ p _ 2*(r - m+1) _ "left" _ l _ m _ r<<endl;
        calc(l, 2*m-2-r, pref);
        s += (pref + p) * 2*(r - m+1) ;
    }
}

void solve() {
    ll l, r;
    cin>>l>>r;
    supl=l;
    if(r - l ==0){
        cout<<l<<endl;
        cout<<l<<endl;
        return;
    }
    // res.clear();
    // res.resize(r+1, 0);
    s=0;
    calc(l, r, 0);
    cout<<s<<endl;
    for(ll i=l;i<=r;i++){
        // cout<<i-supl<<": ";
        cout<<res[i-supl]<<" ";
    }
    cout<<endl;
    
}

int main() {
    int t;

    cin >> t;
    while (t--) {
        solve();
    }
}