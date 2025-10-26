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

void solve() {
    ll n, m, v, i, j, s, k, t, su, all=0, mx=0;
    cin>>n>>m>>v;
    vector < ll > a(n), l(n, -1), r(n, -1);
    for(i=0;i<n;i++) cin>>a[i];
    s=0;
    j=0;
    su=0;
    for(i=0;i<n;i++){
        all+=a[i];
        su+=a[i];
        s+=a[i];
        if(s>=v){
            l[j]=su;
            j++;
            s=0;
            if(j==n) break;
        }
    }
    s=0;
    su=0;
    j=m-1;
    for(i=n-1;i>=0;i--){
        su+=a[i];
        s+=a[i];
        if(s>=v){
            r[j]=su;
            j--;
            s=0;
            if(j==-1) break;
        }
    }
    if(l[m-1]==-1) {
        cout<<-1<<endl;
        return;
    }
    mx = max(mx, all - r[0]);
    for(i=1;i<m;i++){
        mx=max(mx, all - l[i-1] - r[i]);
    }
    mx = max(mx, all - l[m-1]);
    cout<<mx<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}