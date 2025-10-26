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
    ll n, i, k, s=0, t, l, r, m, mx=-1, res, cnt;
    cin>>n>>k;
    vector < ll>  a(n);
    
    for(i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
        mx=max(mx, a[i]);
    }
    // cout<<s _ mx<<endl;
    res=n;
    while(res>0){
        cnt = (s+k)/res;
        // cout<<res _ cnt<<endl;
        if(cnt>=mx && (s%res==0 || s/res<(s+k)/res)){
            // cout<<cnt _ mx<<endl;
            break;
        }
        res--;
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}