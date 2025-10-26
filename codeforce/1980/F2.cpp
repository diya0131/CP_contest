#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ <<" "<<

using namespace std;

vector < pair< pair < ll , ll >, ll > > vc;

ll minisolve(ll l, ll r, ll d, ll p, ll pd, ll n, ll m){
    ll k, i, j, s, t, x, y, pr;
    // cout<<n _ m _ d _ p _ pd<<endl;
    
    vector < ll > pts;
    pair< pair < ll , ll >, ll > pi;

    
    // d=0;
    // p=0;
    // pd=0;
    s=0;
    
    for(i=l;i<=r;i++){
        if(vc[i].ff.ss>=d){
            if(i+1<k){
                if(vc[i+1].ff.ff>vc[i].ff.ff){
                    
                    d=vc[i].ff.ss+1;
                }
                
            }
            else{
                d=vc[i].ff.ss+1;
            }
            
            
            
        }
        // cout<<"add: "<<(vc[i].ff.ff-p) _ (n-pd) _ vc[i].ff.ff _ p<<endl;
        s+=(vc[i].ff.ff-p)*(n-pd);
        p=vc[i].ff.ff;
        pd=d;

    }
    // cout<<"add last: "<<(m-p) _ (n-d)<<endl;
    s+=(m-p)*(n-d);
    return s;
}

void solve(){
    vc.clear();
    ll n, m, k, i, j, s, t, x, y, d, p, pd, pr;
    cin>>n>>m>>k;
    ll res[k], down[k];
    
    vector < ll > pts;
    pair< pair < ll , ll >, ll > pi;

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
    pr=-1;
    for(i=0;i<k;i++){
        down[i]=d;
        // cout<<vc[i].ss <<" down "<<d<<endl;
        if(vc[i].ff.ss>=d){
            if(i+1<k){
                if(vc[i+1].ff.ff>vc[i].ff.ff){
                    pr=i;
                    pts.pb(i);
                    // res[vc[i].ss]=1;
                    d=vc[i].ff.ss+1;
                }
                else{
                    d=vc[i].ff.ss+1;
                }
                
            }
            else{
                pr=i;
                pts.pb(i);
                // res[vc[i].ss]=1;
                d=vc[i].ff.ss+1;
            }
            
            
            
        }
        // cout<<"hmm: "<<vc[i].ff.ff _ vc[i].ff.ss _ d _ p _ (vc[i].ff.ff-p)*(n-pd)<<endl;
        s+=(vc[i].ff.ff-p)*(n-pd);
        p=vc[i].ff.ff;
        pd=d;

    }
    s+=(m-p)*(n-d);

    d=0;
    pd=0;
    p=0;
    pr=pts[0];
    ll n1, m1;
    // cout<<"pts: "<<pts.size()<<endl;
    for(i=1;i<pts.size();i++){
        // if(i+1 == pts.size()){
        //     n1=n;
        //     m1=m;
        // }
        // else{
        //     n1=vc[pts[i+1]].ff.ss;
        //     m1=vc[pts[i+1]].ff.ff;
        // }
        res[vc[pr].ss]+=minisolve(pr+1, pts[i]-1, down[pr], vc[pr].ff.ff, down[pr], vc[pr].ff.ss+1, vc[pts[i]].ff.ff);
        // cout<<minisolve(pr+1, pts[i]-1, d, vc[pr].ff.ff, pd, vc[pr].ff.ss+1, vc[pts[i]].ff.ff)<<endl;
        // cout<<pts[i] _ vc[pts[i]].ff.ff _ vc[pts[i]].ff.ss<<endl;
        d=vc[pr].ff.ss+1;
        pr=pts[i];
        
    }
    res[vc[pr].ss]+=minisolve(pr+1, k-1, down[pr], vc[pr].ff.ff, down[pr], vc[pr].ff.ss+1, m);
    // cout<<minisolve(pr+1, k-1, d, vc[pr].ff.ff, pd, vc[pr].ff.ss+1, m)<<endl;
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


