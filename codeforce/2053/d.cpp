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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

const bool TEST = 0;

const ll M = 998244353;

ll inv(ll k){
    ll p=M-2, q=k, r=1;
    while(p>0){
        if(p%2) r=(r*q)%M;
        q=(q*q)%M;
        p/=2;
    }
    return r;
}

void solve() {
    ll n, i, j, k, s, q, o, x;
    cin>>n>>q;
    vector< ll > a(n), b(n);
    map < ll, ll > mpa, mpb;
    for(i=0;i<n;i++) {
        cin>>a[i];
        mpa[i]=a[i];
    }
    for(i=0;i<n;i++) {
        cin>>b[i];
        mpb[i]=b[i];
    }
    sort(ALL(a));
    sort(ALL(b));
    ll res = 1;
    for(i=0;i<n;i++){
        res = (res * min(a[i], b[i])%M)%M;
    }
    cout<<res<<" ";
    while(q--){
        
        cin>>o>>x;
        
        x--;
        if(o==1){
            k=mpa[x];
            mpa[x]++;
            i = lower_bound(ALL(a), k)- a.begin();
            j = upper_bound(ALL(a), k)- a.begin()-1;
            
            
            if(b[j]>k){
                res=(res*inv(k)%M)%M;
                res=(res*(k+1)%M)%M;
            }
            a[i]++;
            // cout<<endl _ i _ j _ a[j] _ k _ res _ inv(k) _ endl;
            swap(a[i], a[j]);
        } else {
            k=mpb[x];
            mpb[x]++;
            i = lower_bound(ALL(b), k)- b.begin();
            j = upper_bound(ALL(b), k)- b.begin()-1;
            
            if(a[j]>k){
                res=(res*inv(k)%M)%M;
                res=(res*(k+1)%M)%M;
            }
            b[i]++;
            // cout<<endl _ i _ j _ b[j] _ k _ res _ endl;
            swap(b[i], b[j]);
        }
        cout<<res<<" ";
        // cout<<endl;
        // cout << i _ j _ k <<endl;
        // for(i=0;i<n;i++){
        //     cout<<i _ a[i] _ b[i]<<endl;
        // }
    }
    cout<<endl;

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}