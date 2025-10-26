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
    ll n, q, i, j, s, t, k, d, ds, x;
    cin>>n>>q;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    while(q--){
        cin>>k;
        s=0;
        d=n*n-4*k;
        if(d>=0) {
            ds=sqrt(d);
            if(ds*ds==d){
                if((n+ds)%2==0 && (1<=(n+ds)/2 && (n+ds)/2<=n-1)){
                    test<<"idx1" _ (n+ds)/2 _ a[(n+ds)/2]-a[(n+ds)/2-1]-1<<endl;
                    s+=a[(n+ds)/2]-a[(n+ds)/2-1]-1;
                } 
                if((n-ds)%2==0 && (1<=(n-ds)/2 && (n-ds)/2<=n-1)){
                    if(ds!=0) {
                        test<<"idx1" _ (n-ds)/2 _ a[(n-ds)/2]-a[(n-ds)/2-1]-1<<endl;
                        s+=a[(n-ds)/2]-a[(n-ds)/2-1]-1;
                    }
                } 
            }
        }
        test<<"pre" _ s<<endl;
        d=(n+1)*(n+1)-4*(k+1);
        if(d>=0) {
            ds=sqrt(d);
            if(ds*ds==d){
                if((n+ds+1)%2==0 && (1<=(n+ds+1)/2 && (n+ds+1)/2<=n)){
                    s++;
                } 
                if((n-ds+1)%2==0 && (1<=(n-ds+1)/2 && (n-ds+1)/2<=n)){
                    if(ds!=0) s++;
                } 
            }
        }
        test<<"sum: ";
        cout<<s<<" ";
        test<<endl;
    }
    cout<<endl;
}

int main() {
    // BOOST
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}