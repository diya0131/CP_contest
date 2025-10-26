#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<
#define ss second
#define ff first
 
using namespace std;

vector < vector < vector < ll >  > > path;
vector < bool >  vis;




ll dfs(ll idx, ll par, ll dest){
    if(idx==dest){
        return 1;
    }
    else{
        for(ll i=0;i<path[idx].size();i++){
            if(path[idx][i][0]!=par){
                if(dfs(path[idx][i][0], idx, dest)==1){
                    path[idx][i][3]++;
                    return 1;
                }
            }
        }
        return 0;
    }
}

int main(){
    ll n, m, k, i, j, s, t, x, y, c1, c2;
    cin>>n;
    vector < vector < ll > > tmp;
    vector < ll > vec;
    vec.pb(0); vec.pb(0); vec.pb(0); vec.pb(0); 
    for(i=0;i<n;i++){
        path.pb(tmp);
        vis.pb(0);
    }
    ll res=0;
    ll to[n][n][3];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            to[i][j][0]=-1;
        }
    }
    for(i=0;i<n-1;i++){
        cin>>x>>y>>c1>>c2;
        x--;
        y--;
        vec[0]=y;
        vec[1]=c1;
        vec[2]=c2;
        path[x].pb(vec);
        vec[0]=x;
        path[y].pb(vec);
        if(x<y){
            to[x][y][0]=0;
            to[x][y][1]=c1;
            to[x][y][2]=c2;
        }
        else{
            to[y][x][0]=0;
            to[y][x][1]=c1;
            to[y][x][2]=c2;
        }
    }
    for(i=0;i<n-1;i++){
        dfs(i, -1, i+1);
    }
    
    
    for(i=0;i<n;i++){
        for(j=0;j<path[i].size();j++){
            ll d = path[i][j][0];
            if(i<d) to[i][d][0]+=path[i][j][3];
            else to[d][i][0]+=path[i][j][3];
        }
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(to[i][j][0]!=-1){
                // cout<<i _ j _ to[i][j][0] _ to[i][j][1] _ to[i][j][2] _ min(to[i][j][1]*to[i][j][0], to[i][j][2])<<endl;
                res+=min(to[i][j][1]*to[i][j][0], to[i][j][2]);
            }
        }
    }
    cout<<res<<endl;
    

}