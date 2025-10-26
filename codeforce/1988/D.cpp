#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

vector < vector < ll > > path;
vector < ll > a;
const ll N=40;

vector < ll > dfs(ll k, ll par){
    vector < ll > res(N, 0);
    vector < ll > tmp(N);
    ll i, j, mi;
    for(i=0;i<N;i++){
        res[i]=a[k]*(i);
    }
    // cout<<k _ path[k].size()<<endl;
    if(path[k].size()==1 && k!=0){
        return res;
    }
    for(i=0;i<path[k].size();i++){
        if(path[k][i]!=par){
            tmp = dfs(path[k][i], k);
            for(j=0;j<N;j++){
                if(j==0) mi=tmp[1];
                else mi=tmp[0];
                for(ll i1=0;i1<N;i1++){
                    if(i1!=j) mi=min(mi, tmp[i1]);
                }
                res[j]+=mi;
            }
            
        }
    }
    // test<<"---" _ k _ endl;
    // for(i=0;i<N;i++){
    //     test<<res[i]<<" ";
    // }
    // test<<endl;
    return res;
}

void solve(){
    ll n, k, s, q, i, j, m, l, x, y, sum=0, mi;
    vector < ll > vc;
    cin>>n;
    path.clear();
    a.clear();
    path.resize(n);
    a.resize(n);
    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        x--; y--;
        path[x].pb(y);
        path[y].pb(x);
    }

    vc = dfs(0,-1);
    mi=vc[0];
    for(i=0;i<N;i++) mi=min(mi, vc[i]);
    cout<<sum+mi<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}