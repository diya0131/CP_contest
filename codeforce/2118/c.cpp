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

ll get(ll k){
    ll q=1;
    while(k%2){
        q*=2;
        k/=2;
    }
    return q;
}

void solve() {
    ll n, k, i, t, s=0;
    cin>>n>>k;
    priority_queue < pair< ll, ll> > pq;
    pair< ll, ll> pr;
    for(int i=0;i<n;i++){
        cin>>t;
        pq.push({-get(t), t});
        while(t>0){
            if(t%2) s++;
            t/=2;
        }
    }
    // cout<<s<<endl;
    while(k>0){

        pr = pq.top();
        pq.pop();
        pr.ff = -pr.ff;
        // cout<<pr.ff _ pr.ss<<endl;

        k-=pr.ff;
        if(k<0) break;
        t = pr.ss+pr.ff;
        pq.push({-get(t), t});
        s++;
    }
    cout<<s<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}