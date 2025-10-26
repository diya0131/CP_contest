#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

vector < ll > a, c;

ll get(ll t){
    ll s=0;
    for(ll i=0;i<a.size();i++){
        s+=((t+c[i]-1)/c[i])*a[i];
    }
    // cout<<t _ " - " _ s<<endl; 
    return s;
}

void solve(){
    ll n, m, h, k ,i, j, s, t,l, r;
    
    cin>>h>>n;
    a.clear();
    c.clear();
    for(i=0;i<n;i++) {
        cin>>k;
        a.pb(k);
    }
    for(i=0;i<n;i++) {
        cin>>k;
        c.pb(k);
    }

    l=1; r=4e10+5;
    while(r-l>1){
        m=(l+r)/2;
        if(get(m)<h) l=m;
        else r=m;
    }
    // cout<<"res: ";
    if(get(l)>=h) cout<<l<<endl;
    else cout<<r<<endl;
}

int main(){
    int t;
    // freopen("input.txt", "r", stdin);
    cin>>t;
    while(t--){
        solve();
    }
}