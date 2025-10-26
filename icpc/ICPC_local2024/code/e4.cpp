#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<
#define ss second
#define ff first
 
using namespace std;

vector < vector < vector < ll >  > > path;
vector < bool >  vis;
vector < ll > road;
vector < vector < ll > > nxt;
ll res;




void dfs(ll idx, ll par){
    // cout<<idx _ path[idx].size()<<" --\n ";
    road.pb(idx);
    vector < ll > vec;
    if(path[idx].size()!=1){
        for(ll i=0;i<path[idx].size();i++){
            if(path[idx][i][0]!=par){
                vec.pb(0);
                vec.pb(path[idx][i][1]);
                vec.pb(path[idx][i][2]);
                nxt.pb(vec);
                dfs(path[idx][i][0], idx);
            }
        }
    }
    else{
        road.pb(path[idx][0][0]);
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
    }
    for(i=0;i<n;i++){
        if(path[i].size()==1){
            res=0;
            cout<<i<<" start\n";
            road.pb(i);
            vec[0]=y;
            vec[1]=c1;
            vec[2]=c2;
            nxt.pb(vec);
            dfs(path[i][0][0], i);
            break;
        }
    }
    ll idx[n], add[n+1];
    for(i=0;i<n;i++){
        cout<<road[i]<<" ";
        idx[road[i]]=i;
        add[i]=0;
    }

    for(i=0;i<n-1;i++){
        add[min(idx[i], idx[i+1])]++;
        add[max(idx[i], idx[i+1])+1]++;
    }
    ll val = 0;
    for(i=0;i<n;i++){
        val+=add[i];
        res+=min( nxt[i][1] * val, nxt[i][2]);

    }
    cout<<res<<endl;
    

}