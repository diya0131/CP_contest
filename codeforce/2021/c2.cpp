#include<bits/stdc++.h>
#include<chrono>
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

mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

const bool TEST = 0;
const ll M = 1e9 + 7, p = 100019;
void solve() {
    ll n, m, q, k, i, j, s = 0, ch, p, v, nw, sz, idx, su=0;
    cin >> n >> m >> q;
    vector < ll > a(n), b(m);
    for (i = 0;i < n;i++) {
        cin >> k;
        k--;
        a[k] = i;
    }
    vector < set< ll > > st(n);
    vector < ll > pos(n, INT_MAX);
    
    // cout<<cns _ cns1<<endl;
    for (i = 0;i < m;i++) {
        cin >> k;
        k--;
        b[i] = k;
        st[k].insert(i);
    }
    for (i = 0;i < n;i++) {
        if (!st[i].empty()){
            // cout<<i _ a[i] _ *st[i].begin()<<endl;
            pos[a[i]] = *st[i].begin();
        }
    }

    v = 0;
    for(i=1;i<n;i++){
        // cout<<i _ pos[i] _ (pos[i-1]>pos[i]) _ endl;
        v+=(pos[i-1]>pos[i]);
    }
   
    if (v == 0) cout << "YA\n";
    else cout << "TIDAK\n";
    while (q--) {
        cin >> j >> k;
        // for(auto ite=lst.begin(); ite!=lst.end();ite++) cout<<(*ite).ff _ " - " _  (*ite).ss<<endl;
        k--;
        j--;
        ch = 0;
        nw = 0;
        p = b[j];
        b[j]=k;
        st[p].erase(j);
        st[k].insert(j);
        if(a[p]-1>=0) ch+=(pos[a[p]-1]>pos[a[p]]);
        if(a[p]+1<n) ch+=(pos[a[p]]>pos[a[p]+1]);
        if(st[p].empty()) pos[a[p]]=INT_MAX;
        else pos[a[p]]=*st[p].begin();
        // cout<<p _ a[p] _ *st[p].begin()<<endl;
        if(a[p]-1>=0) nw+=(pos[a[p]-1]>pos[a[p]]);
        if(a[p]+1<n) nw+=(pos[a[p]]>pos[a[p]+1]);
        v+=(nw-ch);
        nw=0;
        ch=0;
        if(a[k]-1>=0) ch+=(pos[a[k]-1]>pos[a[k]]);
        if(a[k]+1<n) ch+=(pos[a[k]]>pos[a[k]+1]);
        pos[a[k]]=*st[k].begin();
        // cout<<k _ a[k] _ *st[k].begin()<<endl;
        if(a[k]-1>=0) nw+=(pos[a[k]-1]>pos[a[k]]);
        if(a[k]+1<n) nw+=(pos[a[k]]>pos[a[k]+1]);
        v+=(nw-ch);
        // for(i=0;i<n;i++) cout<< i _ pos[i]<<endl;
        // cout<<v _ nw _ ch _ a[p] _ a[k]<<endl;
        if (v == 0) cout << "YA\n";
        else cout << "TIDAK\n";
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