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

bool check(ll m, vector<ll>&a){
    ll p, i, n=a.size();
    bool c;
    p = 0;
    c = 1;
    for(i=0;i<n;i++){
        if(a[i]<=m){
            c = 1;
            p=a[i];
            continue;
        }
        if(abs(p-a[i]) > m){
            if(c==0) return false;
            else c = 0;
        }
        p=a[i];
    }
    if(c==0) return false;
    return true;
}

void solve(int idx) {
    long long n, i, t, l, r, m, p;
    bool c;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    l = 0;
    r = 100;
    while(l<r){
        m = (l+r)/2;
        // cout<<m _ check(m, a)<<endl;
        if(check(m, a)) r = m;
        else l = m+1;
    }
    cout<<"Case #"<<idx<<": "<<l<<endl;
}

int main() {
    // BOOST
    freopen("input/snake_scales_chapter_2_input.txt", "r", stdin);
    freopen("output/a_out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        solve(i+1);
    }
}