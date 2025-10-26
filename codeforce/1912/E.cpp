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

ll rev(ll k){
    
    ll t=0, p=1;
    if(k<0){
        p=-1;
        k=-k;
    }
    while(k>0){
        t=t*10+k%10;
        k/=10;
    }
    return t*p;
}

void solve() {
    ll p, q, x, t, k, n, rp, rk;
    cin>>p>>q;
    if(p%10==0){
        cout<<"1+";
        p--;
        q--;
    }
    rp = rev(p);
    if((q - rp)%2){
        cout<<"0-5-11-0+4-0+12+";
        q--;
    }
    k = (rp-q)/2;
    if(k%10==0){
        cout<<"0+1-1-0+";
        k--;
    }
    rk = rev(k);
    if(p>=0) cout<<p<<"+0";
    else cout<<0<<p<<"-0";
    if(rk>=0) cout<<"+"<<rk<<"-"<<rk<<"-0";
    else cout<<rk<<"+"<<-rk<<"+0";
}

int main() {
    // BOOST
    solve();
}