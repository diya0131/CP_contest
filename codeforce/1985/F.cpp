#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

ll mod = 1e9+7;

void solve(){
    ll n, m, h, k ,i, j, s, t, l, r, q, p;
    cin>>l>>r>>k;
    t = (9/k)+1;
    s=0;
    m=r;
    q=t;
    p=1;
    while(m>0){
        if(m%2){
            p=(p*q)%mod;
        }
        q=(q*q)%mod;
        m/=2;
    }
    s=p;
    m=l;
    q=t;
    p=1;
    while(m>0){
        if(m%2){
            p=(p*q)%mod;
        }
        q=(q*q)%mod;
        m/=2;
    }
    s=(s-p)%mod;
    if(s<0) s+=mod;
    cout<<s<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}