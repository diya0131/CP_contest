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
    ll n, m, q, k, i, j, s=0, ch, p, nw;
    cin>>n>>m>>q;
    vector < ll > a(n), b(m);
    for(i=0;i<n;i++) {
        cin>>k;
        k--;
        a[i]=k;
    }
    vector < bool > st(n, 0);
    j=0;
    for(i=0;i<m;i++) cin>>b[i];
    for(i=0;i<m;i++) {
        k=b[i]-1;
        if(st[k]==0){
            // cout<<"new " _ i _ k _ j<<endl;
            if(j<n && a[j]!=k){
                // cout<<j _ i _ k<<endl;
                cout<<"TIDAK\n";
                return;
            } else j++;
            st[k]=1;
        }
    }
    cout<<"YA\n";
    
    
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}