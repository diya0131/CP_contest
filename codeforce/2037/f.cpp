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
const ll M = 998244353;

void solve() {
    ll n, m, k, i, j, t, s, l, r, mid, li, ri;
    bool can, bl;
    cin>>n>>m>>k;
    vector < pair < ll, ll > > a(n);
    map < ll , ll > mp;
    map < ll , ll >::iterator it;
    for(i=0;i<n;i++){
        cin>>a[i].ff;
    }
    for(i=0;i<n;i++){
        cin>>a[i].ss;
    }
    l=1;
    r=1e9;
    while(l<r){
        mid=(l+r)/2;
        can = 1;
        mp.clear();
        for(i=0;i<n;i++){
            t=(a[i].ff-1)/mid+1;
            if(t>m){
                continue;
            } 
            li = max(1LL, a[i].ss + t - m);
            ri = m - t + a[i].ss;
            // cout<<"pre" _ i _  a[i].ff _ a[i].ss _ li _ ri+1<<endl;
            if(li<=ri){
                
                mp[li]++;
                mp[ri+1]--;
            }
        }
        s=0;
        if(can){
            bl=0;
            for(it = mp.begin();it!=mp.end();it++){
                s+=it->ss;
                if(s>=k) {
                    bl=1;
                    break;
                }
            }
            if(!bl) can = 0; 
        }
        // cout<<"can" _ mid _ can<<endl;
        if(can) r=mid;
        else l=mid+1;
    }
    can = 1;
    mid=l;
    mp.clear();
    for(i=0;i<n;i++){
        t=(a[i].ff-1)/mid+1;
        if(t>m){
            continue;
        } 
        li = max(1LL, a[i].ss + t - m);
        ri = m - t + a[i].ss;
        if(li<=ri){
            mp[li]++;
            mp[ri+1]--;
        }
    }
    s=0;
    if(can){
        bl=0;
        for(it = mp.begin();it!=mp.end();it++){
            s+=it->ss;
            if(s>=k) {
                bl=1;
                break;
            }
        }
        if(!bl) can = 0; 
    }
    if(can) cout<<l<<endl;
    else cout<<-1<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}