#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;

void solve() {
    ll n, i, j, k, q, s, x, l, r, m;
    cin>>n>>q;
    vector < vector < ll > >  a(n+1, vector < ll >(20, 0)), b(n+1);
    for(i=0;i<n;i++){
        cin>>k;
        for(j=0;i<20;j++){
            a[k%(n+1)][j]++;    
        }
        
    }
    s=0;
    for(i=0;i<=n;i++){
        s+=a[i];
        b[i]=s;
        cout<<b[i]<<" ";
    }
    cout<<endl;

    while(q--){
        cin>>x;
        l = 1;
        r = n;
        while(l+1<r){
            m=(l+r)/2;
            cout<<m _ a[m] _ (b[m]+b[min(n, x+m)]-b[x-1]) _ b[m] _ b[min(n, x+m)] _ b[x-1]<<endl;
            if(a[m]>0 && (b[m]+b[min(n, x+m)]-b[x-1])>=(n+1)/2){
                l=m;
            } else {
                r=m-1;
            }
        }
        if(a[l]>0 && (b[l]+b[min(n, x+l)]-b[x-1])>=(n+1)/2){
            cout<<l<<" ";
        } else {
            cout<<r<<" ";
        }

    }
    cout<<endl;    
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}