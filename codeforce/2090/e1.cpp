#include<bits/stdc++.h>
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


const bool TEST = 0;

void solve() {
    ll n, k, i, j, s, t, x, y, sa, sb, res=1;
    cin>>n>>k;
    vector < ll > a(n), b(n), c(n, -1), to(n, -1);
    for(i=0;i<n;i++){
        cin>>a[n-1-i];
    }
    for(i=0;i<n;i++){
        cin>>b[n-1-i];
    }
    for(i=0;i<2*n;i++){
        if(a[i%n]>b[i%n]){
            sa = b[i%n] - a[i%n];
            j = i;
            while(c[(j-1+n)%n]!=-1 && sa<0){
                // cout<<i _ j _ sa _ c[j]<<endl;
                sa += c[(j-1+n)%n];
                j = to[(j-1+n)%n];
            }
            if(sa>=0){
                res = max(res, (i-j+1));
                c[i%n] = sa;
                to[i%n] = j;
                // cout<<i _ " ikh "<<(i-j+1) _ sa _ j<<endl;
            } 
            // cout<<i _ " baga "<<(i-j+1) _ sa _ j<<endl;
        } else {
            c[i%n] = b[i%n] - a[i%n];
            to[i%n] = i;
        }
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}