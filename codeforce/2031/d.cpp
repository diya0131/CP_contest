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

vector < ll > h, a, mx;
vector < bool > done;
vector < ll > res;


ll dfs(ll k){
    // cout<<k _ endl;
    test<<"dfs" _ k _ a[k] <<endl;
    if(done[k]==true) return res[k];
    if(k==mx[a[k]]){
        return h[mx[k]];
    }
    test<<"go" _ k _ a[k] _ mx[a[k]]<<endl;
    res[k] = dfs(mx[a[k]]);
    done[k]=1;
    return res[k];

}

void solve() {
    ll n, i, s, t, k, mn=LLONG_MAX, l;
    cin>>n;
    pair < ll, ll > pr;
    // vector < ll > h(n), a(n, -1), mx(n);
    h.clear();
    h.resize(n);
    a.clear();
    a.resize(n, -1);
    mx.clear();
    mx.resize(n);
    vector< pair < ll, ll > > b(n);
    // set < pair < ll, ll > > st;
    // set < pair < ll, ll > >::iterator it;
    for(i=0; i<n; i++) {
        cin>>h[i];
        b[i]={h[i], i};
        // st.insert({h[i], i});
    }
    // for(i=n-1;i>=0;i--){
    //     if(mn>h[i]){
    //         mn=h[i];
    //         pr = {h[i], LLONG_MAX};
    //         it= upper_bound(ALL(st), pr );
    //         while(it!=st.end()){
    //             // test<< "clear" _ i _ h[i] _ it->ff _ it->ss<<endl;
    //             a[it->ss]=i;
    //             it++;
    //         }
    //         it= upper_bound(ALL(st), pr );
    //         st.erase(it, st.end());
    //     }
    // }
    sort(ALL(b));
    l=n-1;
    for(i=n-1;i>=0;i--){
        if(mn>h[i]){
            mn=h[i];
            while(l>=0 && b[l].ff>mn){
                a[b[l].ss]=i;
                l--;
            }
        }
    }
    t=LLONG_MIN, k=-1;
    for(i=0;i<n;i++){
        if(h[i]>t){
            t=h[i];
            k=i;
        }
        mx[i]=k;
    }

    done.clear();
    done.assign(n, 0);
    res.clear();
    res.resize(n, 0);
    for(i=0;i<n;i++){
        if(a[i]==-1) a[i]=i;
        else a[i]=max(i, a[i]);
        // test<<"a" _ i _ a[i] _ endl;
    }
    for(i=0;i<n;i++){
        if(!done[i]) {
            res[i] = dfs(i);
            done[i]=1;
        }
        test<<i _ res[i] _ done[i] _ endl;
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int main() {
    BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}