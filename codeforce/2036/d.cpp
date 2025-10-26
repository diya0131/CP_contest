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
    ll n, m, i, j, k, s=0, l, sz;
    vector < ll > vc;
    cin>>n>>m;
    char a[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector < char > st;
    k=0;
    while(n-2*k>0 && m-2*k>0){
        i=k;
        st.clear();
        // cout<<k _ m-k<<endl;
        for(j=k;j<m-k;j++){
            st.pb(a[i][j]);
            l++;
        }
        j=m-1-k;
        for(i=k+1;i<n-k;i++){
            st.pb(a[i][j]);
            l++;
        }
        i=n-1-k;
        for(j=m-2-k;j>=k;j--){
            st.pb(a[i][j]);
            l++;
        }
        j=k;
        for(i=n-2-k;i>k;i--){
            st.pb(a[i][j]);
            l++;
        }
        sz=st.size();
        for(i=0;i<sz;i++){
            if(st[(i)%(sz)]=='1' && st[(i+1)%(sz)]=='5' && st[(i+2)%(sz)]=='4' && st[(i+3)%(sz)]=='3') s++;
        }
        k++;
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