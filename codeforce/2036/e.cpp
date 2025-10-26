#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    ll n, m, k, s, t, r, i, j, q, mn, mx, te;
    char o;
    cin>>m>>n>>q;
    vector a(n, vector < ll >(m)), b(n, vector < ll >(m));
    for(j=0;j<m; j++){
        for(i=0; i<n; i++){
            cin>>a[i][j];
        }
    }
    for(i=0; i<n; i++){
        t=0;
        for(j=0;j<m; j++){
            t=t | a[i][j];
            b[i][j]=t;
        }
    }
    // for(i=0; i<n; i++){
    //     for(j=0;j<m; j++){
    //         cout<<b[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    while(q--){
        cin>>te;
        mn=0;
        mx=m-1;
        while(te--){
            cin>>r>>o>>k;
            // cout<<r _ o _ k _ t<<endl;
            r--;
            if(o=='>'){
                t=(upper_bound(ALL(b[r]), k)-b[r].begin());
                // cout<<t _ mn _ "min"<<endl;
                mn=max(mn, t);
            } else {
                t=(lower_bound(ALL(b[r]), k)-b[r].begin())-1;
                // cout<<t _ mx _ "max"<<endl;
                mx=min(mx, t);
            }
        }
        // cout<<mn _ mx<<endl;
        if(mn<=mx) cout<<mn+1<<endl;
        else cout<<-1<<endl;
    }
}

int main() {
    // BOOST
    
        solve();
    
}