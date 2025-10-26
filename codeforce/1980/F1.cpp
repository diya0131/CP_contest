#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, m, k, i, j, s, t, x, y, d, p, pd;
    cin>>n>>m>>k;
    bool res[k];
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++) a[i][j]=0;
    // }
    vector < pair< pair < ll , ll >, ll > > vc;
    for(i=0;i<k;i++){
        res[i]=0;
        cin>>x>>y;
        x--;
        y--;
        vc.push_back({{y, x}, i});
        
    }
    d=0;
    p=0;
    pd=0;
    sort(vc.begin(), vc.end());
    s=0;
    for(i=0;i<k;i++){
        if(vc[i].ff.ss>=d){
            if(i+1<k){
                if(vc[i+1].ff.ff>vc[i].ff.ff){
                    res[vc[i].ss]=1;
                    d=vc[i].ff.ss+1;
                }
            }
            else{
                res[vc[i].ss]=1;
                d=vc[i].ff.ss+1;
            }
            
            
            
        }
        // cout<<vc[i].ff.ff _ vc[i].ff.ss _ d _ p _ (vc[i].ff.ff-p)*(n-pd)<<endl;
        s+=(vc[i].ff.ff-p)*(n-pd);
        p=vc[i].ff.ff;
        pd=d;

    }
    s+=(m-p)*(n-d);
    cout<<s<<endl;
    for(i=0;i<k;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


