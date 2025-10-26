#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

void solve() {
    ll n, m, k, i, j, q, t, res;
    cin>>n>>m>>q;
    vector < ll > b(m);
    vector < ll >::iterator it;
    for(i=0;i<m;i++) cin>>b[i];
    sort(ALL(b));
    while(q--){
        cin>>k;
        it=lower_bound(ALL(b), k) ;
        if(it==b.begin()){
            res=*b.begin()-1;
            cout<<res<<endl;
            continue;
        } 
        if(it==b.end()){
            res=n-*prev(b.end());
            cout<<res<<endl;
            continue;
        } 
        res=(*it-*prev(it))/2;
        cout<<res<<endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}