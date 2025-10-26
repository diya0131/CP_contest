#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<
#define ss second
#define ff first
 
using namespace std;

vector < vector < ll > > path;
vector < bool >  vis;
vector < int > result;
ll col[2], p;

void dfs(ll idx, ll par, ll order, ll re){
    vis[idx]=1;
    if(order>1){
        re++;
        order=0;
    }
    result[idx]=re;
    order++;
    p++;
    for(ll i=0; i<path[idx].size();i++){
        if(path[idx][i]!=par && vis[path[idx][i]]==0){
            dfs(path[idx][i], idx, order, re);
        }
    }
    
    
}

int main(){
    ll n, m, k, i, j, s, t, x, y, res =0;
    cin>>n>>m>>k;
    vector < ll > tmp;
    for(i=0;i<n;i++){
        path.pb(tmp);
        vis.pb(0);
        result.pb(0);
    }

    for(i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        path[x].pb(y);
        path[y].pb(x);
    }
    for(i=0;i<n;i++){
        if(vis[i]==0){
            col[0]=0;
            col[1]=0;
            p=0;
            dfs(i, -1, 0, 0);
            res= max(res, p/2);
        }
    }
    cout<<res<<endl;
    for(i=0;i<n;i++){
        cout<<result[i]+1<<" ";
    }
    cout<<endl;

}