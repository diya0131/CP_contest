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



pair < ll, ll > gcost(ll m, ll x, ll y, ll z, ll k, ll a){
    // test<<"cost" _ a<<endl;
    ll c, t, d;
    t=(z-k*m*(m+1)/2+(m*k+a-1))/(m*k+a);
    c=a*x+t*y;
    d=k*m*(m+1)/2+(m*k+a)*t;
    return {c, -d};
}

pair < ll, ll > cost(ll m, ll x, ll y, ll z, ll k, ll a){
    // test<<"cost" _ a<<endl;
    ll c, t, d;
    t=(z-k*m*(m+1)/2+(m*k+a-1))/(m*k+a);
    c=m*(k*x+y)+a*x+t*y;
    d=k*m*(m+1)/2+(m*k+a)*t;
    return {c, -d};
}



pair < ll, ll > find(ll m, ll x, ll y, ll z, ll k){
    test<<"find" _ m <<endl;
    ll l=0, r = k, a;
    pair < ll, ll > apr, bpr;
    if(m==0) l=1;
    while(l<r){
        a=(l+r)/2;
        // test<<l _ r _ a<<endl;
        apr = gcost(m, x, y, z ,k, a);
        bpr = gcost(m, x, y, z, k, a+1);
        ll idx=1;
        while(apr==bpr && idx<10){
            apr = gcost(m, x, y, z ,k, a+idx);
            bpr = gcost(m, x, y, z, k, a+idx+1);
            idx++;
        }
        if(apr<bpr){
            r=a;
        } else {
            l=a+1;
        }
        
        
    }
    return cost(m, x, y, z, k, l);
}

void solve() {
    ll n, x, y, m, a, t, k, z, l, r, res=LLONG_MAX;
    cin>>x>>y>>z>>k;
    pair < ll, ll > apr, bpr;
    l=0; r=sqrt(2*z/k)+100;
    for(ll i=l;i<=r;i++){
        apr = find(i, x, y, z ,k);
        res=min(res, apr.ff);
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