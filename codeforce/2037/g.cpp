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
const ll M = 998244353;

vector < ll > p;

ll getp(ll k){
    if(p[k]==k) return k;
    ll par = getp(p[k]);
    p[k]=par;
    return p[k];
}

void merge(ll x, ll y){
    ll px = getp(x), py=getp(y);
    p[px]=py;
}

void solve() {
    ll n, i, j, k, s, q, po;
    cin>>n;
    vector < ll > a(n);
    for(i=0;i<n;i++) cin>>a[i];
    p.resize(n+1000);
    for(i=0;i<n+1000;i++) p[i]=i;
    vector < bool > isp(1000, 1);
    for(i=2;i*i<1000;i++){
        if(isp[i]){
            j=2*i;
            while(j<1000){
                isp[j]=0;
                j+=i;
            }
        }
    }
    s=0;
    for(i=2;i<1000;i++){
        if(isp[i]){
            s++;
            for(j=0;j<n;j++){
                if(a[j]%i){
                    merge(n+i, j);
                    while(a[j]%i==0){
                        a[j]/=i;
                    }
                }
            }
        }
    }
    cout<<s<<endl;
    sort(ALL(a));
    for(i=1;i<n;i++){
        if(a[i]==a[i-1]){
            merge(i, i-1);
        }
    }
    k=getp(0);
    if(getp(n-1)!=k){
        cout<<0<<endl;
        return;
    }
    s=0;
    for(i=1;i<n-1;i++){
        if(getp(i)==k) s++;
    }
    q=1;
    po=2;
    while(s>0){
        if(s%2) q=(q*po)%M;
        po=(po*po)%M;
        s/=2;
    }
    cout<<q<<endl;
}

int main() {
    // BOOST
    
    solve();
    
}