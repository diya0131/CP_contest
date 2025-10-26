#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int a, b;

vector < vector < int > > path;
vector < bool > vis;
vector < int > road;
int res;

bool dfs1(int idx){
    if(idx==b){
        return true;
    }else{
        for(int i=0;i<path[idx].size();i++){
            if(vis[path[idx][i]]==0){
                road.pb(path[idx][i]);
                vis[path[idx][i]]=1;
                if(dfs1(path[idx][i])){
                    return true;
                }
                road.pop_back();
                vis[path[idx][i]]=0;
            }
        }
        return false;
    }
}

void dfs2(int idx, int sum){
    // cout<<idx <<" - "<<sum<<endl;
    bool can = false;
    for(int i=0;i<path[idx].size();i++){
        if(vis[path[idx][i]]==0){
            vis[path[idx][i]]=1;
            can = true;
            dfs2(path[idx][i], sum+1);
        }
    }
    if(!can){
        if(sum>res) res = sum;
    }
}

void solve(){
    int n, i, j, k, x, y;
    cin>>n;
    cin>>a>>b;
    a--;
    b--;
    vector < int > tmp;
    path.clear();
    vis.clear();
    road.clear();
    vis.pb(0);
    for(i=0;i<n;i++){
        vis.pb(0);
        path.pb(tmp);
    }
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        x--;
        y--;
        path[x].pb(y);
        path[y].pb(x);
    }
    road.pb(a);
    vis[a]=1;
    dfs1(a);
    // cout<<"road: "<<endl;
    // for(i=0;i<road.size();i++){
    //     cout<<road[i]<<" ";
    // }
    // cout<<endl;
    k=road.size();
    for(i=0;i<n;i++) vis[i]=0;
    res = 0;
    // cout<<"mid: "<<road[(k-1)/2]<<endl;
    vis[road[(k-1)/2]]=1;
    dfs2(road[(k-1)/2], 0);
    // cout<<"res: "<<res<<endl;
    cout<<2*(n-1) - res + k/2<<endl;

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}