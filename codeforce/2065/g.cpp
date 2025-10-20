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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const bool TEST = 0;

vector < ll > primes;
vector < pair < ll, ll > > divs;

void solve() {
    ll n, i, j, k, s=0;
    cin>>n;
    vector < ll > a(n);
    vector < pair < ll, ll > > b(n);
    for(i=0;i<n;i++) cin>>a[i];
    map < ll,ll > prime_cnt;
    map < pair<ll, ll>,ll > pr_prime_cnt;
    map < ll , ll > one_prime;
    long long res =0;
    for(i=0;i<n;i++){
        // cout<<a[i] _ divs[a[i]].ff _ divs[a[i]].ss _ res<<endl;
        if(divs[a[i]].ff==-1) continue;
        if(divs[a[i]].ss==-1) {
            res = res + s + one_prime[divs[a[i]].ff];
            s++;
            prime_cnt[divs[a[i]].ff]++;
        } else{
            if(divs[a[i]].ff!=divs[a[i]].ss){
                res = res + prime_cnt[divs[a[i]].ff]+prime_cnt[divs[a[i]].ss] + pr_prime_cnt[{divs[a[i]]}];
                one_prime[divs[a[i]].ff]++;
                one_prime[divs[a[i]].ss]++;
                pr_prime_cnt[{divs[a[i]]}]++;
            } else {
                res = res + prime_cnt[divs[a[i]].ff]+ pr_prime_cnt[{divs[a[i]]}];
                one_prime[divs[a[i]].ff]++;
                pr_prime_cnt[{divs[a[i]]}]++;
            }
        }
    }
    cout<<res<<endl;
    
}

int main() {
    divs.assign(200005, {-1, -1});
    vector < bool > is(200005, 1);
    
    for(ll i=2;i<200005;i++){
        if(is[i]){
            primes.pb(i);
            divs[i] = {i, -1};
            ll j=2*i;
            while(j<200005){
                is[j]=0;
                j+=i;
            }
        }
    }
    // cout<<primes.size()<<endl;
    for(ll i=0;i<primes.size();i++){
        
        for(ll j=i;primes[i]*primes[j]<200005;j++){
            divs[primes[i]*primes[j]]={primes[i], primes[j]};
        }
    }
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}