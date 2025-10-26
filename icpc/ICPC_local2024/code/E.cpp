#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define _ <<" "<<
#define ss second
#define ff first
 
using namespace std;

vector < vector < vector < int >  > > path;
vector < bool >  vis;




pair< ll , ll > dfs(int idx, int par){
    if(path[idx].size()==1){
        if(idx==0) return {1, 0};
        return {2, 0};
    }
    else{
        pair< ll , ll > pr;
        for(int i=0;i<path[idx].size();i++){
            if(path[idx][i]!=par){
                
                pr = 
            }
        }
    }
}

int main(){
    ll n, m, k, i, j, s, t, x, y, c1, c2;
    cin>>n>>m>>k;
    vector < vector < int > > tmp;
    vector < int > vec;
    vec.pb(0); vec.pb(0); vec.pb(0); 
    for(i=0;i<n;i++){
        path.pb(tmp);
        vis.pb(0);
    }
    for(i=0;i<n-1;i++){
        cin>>x>>y>>c1>>c2;
        vec[0]=y;
        vec[1]=c1;
        vec[2]=c2;
        path[x].pb(vec);
    }
    
    dfs(n-1, -1);

    

}