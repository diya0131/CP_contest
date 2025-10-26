#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;


void solve(){
    ll n, i, j, m, x, y, z, k;
    cin>>x>>y>>z>>k;
    vector < ll > a, b;
    n=sqrt(k);
    for(i=1;i<=n;i++){
        if(k%i==0){
            a.pb(i);
            b.pb(k/i);
        }
    }
    i=b.size()-1;
    if(n%k==0) i--;
    while(i>=0) {
        a.pb(b[i]);
        i--;
    }

    n=a.size();
    ll res=0;
    for(i=0;i<n;i++){
        if(a[i]>x) break;
        for(j=0;j<n;j++){
            
            m=a[i]*a[j];
            if(a[j]>y || m>k) break;
            if(k%m==0 && k/m<=z){
                res=max(res, (x-a[i]+1)*(y-a[j]+1)*(z-k/m+1));
            }
            
        }
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}