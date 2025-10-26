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

ll take(ll x){
    if(x<0) return 0;
    ll res=0;
    if(x%2==0) {
        res=x;
        x--;
    }
    if(((x+1)/2)%2) res^=1;
    return res;
}

ll get(ll l, ll r){
    
    return take(r) ^ take(l-1);
}

void solve() {
    ll l, r, i, k, res=0, p=1, lp, rp, t;
    cin>>l>>r>>i>>k;
    for(int i1=0;i1<i;i1++) p*=2;
    lp=(l-k+p-1)/p;
    lp=max(0LL, lp);
    rp=(r-k)/p;
    res = get(l, r) ;
    t=0;
    if(lp<=rp && r-k>0){
        // cout<<lp _ rp _ p _ (lp-1)*p+k _ (rp+1)*p+k _ (lp)*p+k _ (rp)*p+k<<endl;
        t=get(lp, rp)*p;
        if((rp-lp)%2==0) t=t ^ k;
    }
    cout<<(res ^ t)<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}