
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ff first
#define ss second
#define PII pair < int, int >
#define PLL pair < ll, ll >

using namespace std;


void solve() {
    ll n, j, i, k, s, t, m, l, r;
    cin>>n;
    string a, b, c, d;
    cin>>a>>b;
    c=a;
    d=b;
    ll pref[n+1][2];
    pref[0][0]=0;
    pref[0][1]=0;
    s=0;
    for(i=1;i<=n;i++){
        if(a[i-1]=='1') s++;
        pref[i][0]=s;
    }
    for(i=1;i+1<n;i++){
        if(a[i-1]=='0' && a[i+1]=='0') b[i]='1';
    }
    for(i=1;i+1<n;i++){
        if(b[i-1]=='1' && b[i+1]=='1') a[i]='1';
    }
    s=0;
    for(i=1;i<=n;i++){
        if(a[i-1]=='1') s++;
        pref[i][1]=s;
    }
    cin>>m;
    while(m--){
        cin>>l>>r;
        s=0;

        switch(r-l){
            case 0:
                if(a[l-1]=='1' && c[l-1]=='0') s=1;
            break;
            case 1:
                if(a[l-1]=='1' && c[l-1]=='0') s++;
                if(a[r-1]=='1' && c[r-1]=='0') s++;
            break;
            case 2:
                if(a[l-1]=='1' && c[l-1]=='0') s++;
                if(a[r-1]=='1' && c[r-1]=='0') s++;
                if(a[l]=='1' && c[l]=='0' && (d[l-1]=='0' || d[r-1]=='0')) s++;
            break;
            default:
                if(a[l-1]=='1' && c[l-1]=='0') s++;
                if(a[r-1]=='1' && c[r-1]=='0') s++;
                if(a[l]=='1' && c[l]=='0' && d[l-1]=='0') s++;
                if(a[r-2]=='1' && c[r-2]=='0' && d[r-1]=='0') s++;
            break;
            // default:
            // break;

        }
        // if(l-1<=r-1 && c[l-1]=='0') s++;
        // if(l-1<=r-1 && c[r-1]=='0') s++;
        // if(l<=r-1 && c[l]=='0' && d[l-1]=='0' && (d[])) s++;
        // if(l-1<=r-2 && c[r-2]=='0') s++;
        // cout<<pref[r][0]-pref[l-1][0] _ pref[r][1]-pref[l-1][1] _ s<<endl;
        cout<<max(pref[r][0]-pref[l-1][0], pref[r][1]-pref[l-1][1]-s)<<endl;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}