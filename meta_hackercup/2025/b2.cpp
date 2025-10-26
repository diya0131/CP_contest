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
const bool TEST = 1;

ll M = 1e9+7;


vector<ll>primes;
ll n, m;
vector<pair<ll, ll>>divs;
vector<ll>d;

ll pw(ll k, ll t){
    if(t==1) return k;
    ll res = 1;
    if(t%2) res = k;
    ll v = pw(k, t/2);
    res = (((res * v)%M * v) % M);
    return res;
}

ll inv(ll k){
    ll p = pw(k, M-2);
    return p;
}

ll calc(ll nm, bool rev){
    test<<nm _ rev _ "calc---------------\n";
    
    ll res=1, t;
    for(int i=0;i<m;i++){
       
        if(rev) t = divs[i].ss - d[i];
        else t = d[i];
        if(t==0) continue;
        for(int j=0;j<t;j++){
            res = (res * nm) % M;
            nm++;
        }
        res = (res * inv(t)) % M;
        test<<i _ t _ res<<endl;
    }
    test<<res<<endl;
    return res;
}

ll go(ll i, ll p, ll a){
    if(p>a) return 0;
    if(i==m) {
        test<<"go" _ p _ a<<endl;
        return (calc(n, 0) * calc(n, 1))%M;
    }
    ll res = 0;
    for(int j=0;j<=divs[i].ss;j++){
        d[i] = j;
        res = (res + go(i+1, p, a));
        p = p * divs[i].ff;
       
    }
    return res;
}

void solve(int idx) {
    ll a, b, t, c, res=0;
    cin>>n>>a>>b;
    divs.clear();
    d.clear();
    t = b;
    for(ll i=0;i<primes.size();i++){
        if(primes[i] > t) break;
        if(t==1) break;
        if(t%primes[i]==0){
            test<<"primes" _ t _ primes[i]<<endl;
            c=0;
            while(t%primes[i]==0){
                c++;
                t/=primes[i];
            }
            divs.pb({primes[i], c});
        }
    }
    if(t>1) divs.pb({t, 1});
    m = divs.size();
    d.resize(m, 0);

    test<<divs.size() _ "divs ----------------\n";
    for(int i=0;i<m;i++){
        test<<i _ divs[i].ff _ divs[i].ss<<endl;
    }
    if(a>=b){
        for(ll i=0;i<m;i++) d[i] = divs[i].ss;
        t = calc(2*n, 0);
        res = (res + t)%M;
    } else {
        t = go(0, 1, a);
        res = (res + t)%M;
    }
    cout<<"Case #"<<idx<<": "<<res<<endl;
}

int main() {
    // BOOST
    ll mx = 1e7+5, t = sqrt(mx), j;
    vector<bool>isp(mx, 1);
    isp[1]=0;
    for(ll i=3;i<=t;i+=2){
        if(isp[i]){
            
            j=2*i;
            while(j<mx){
                isp[j]=0;
                j+=i;
            }
        }
    }
    for(ll i=2;i<mx;i++){
        if(isp[i]) primes.pb(i);
    }


    freopen("input/b_in.txt", "r", stdin);
    freopen("output/b2_out.txt", "w", stdout);
    cin >> t;
    for(int i=0;i<t;i++) {
        solve(i+1);
    }
}