#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define ff first
#define ss second
#define PII pair < int, int >
#define PLL pair < ll, ll >

using namespace std;

const ll N = 1e6+1; 

bool cmp(pair < ll, ll > x, ll k){
    return x.ff<k;
}


int main() {
    ll n, i, j, m, s;
    cin>>n>>m;
    ll a[n], b[n], c[m];
    pair < ll, ll > pr[n];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    for(i=0;i<m;i++) cin>>c[i];
    for(i=0;i<n;i++){
        pr[i]={a[i], i};
    }
    sort(pr, pr+n);
    
    vector < pair< ll, ll> > vc;
    vector < pair< ll, ll> >::iterator it;
    pair< ll, ll> p, p1;
    ll idx =0;
    vc.pb(pr[0]);
    for(i=1;i<n;i++){
        if(vc[idx].ff==pr[i].ff){
            if(vc[idx].ff - b[vc[idx].ss] > pr[i].ff - b[pr[i].ss]){
                vc[idx]=pr[i];
            }
        } else{
            if(vc[idx].ff - b[vc[idx].ss] > pr[i].ff - b[pr[i].ss]){
                vc.pb(pr[i]);
                idx++;
            }
        }
    }
    
    vector < ll >  val(N);
    ll t=0, tm=0;
    
    idx=0;
    for(i=0;i<vc[0].ff;i++) val[i]=0;
    tm = vc[0].ff - b[vc[0].ss];
    if(vc.size()>1) idx=1;
    for(i=vc[0].ff;i<N;i++){
        if(i<vc[idx].ff) {
            val[i]=1+val[i-tm];
        }
        else{
            tm=vc[idx].ff - b[vc[idx].ss];
            if(idx+1<vc.size()) idx++;
            val[i]=1+val[i-tm];
        }
    }
    ll res =0;
    p = vc[vc.size()-1];
    t = p.ff - b[p.ss];
    for(i=0;i<m;i++){
        p1.ff= c[i];
        if(c[i]<N) res+=val[c[i]];
        else{
            tm = (c[i]-p.ff)/t+1;
            res+=tm + val[c[i] - t * tm];
        }
    }
    cout<<res*2<<endl;
}