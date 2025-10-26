#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

vector < vector < char > > vc;
vector < vector < bool > > vis;
vector < ll > col, row;
set < ll > cols, rows;

ll sz, n, m;

void dfs(ll x, ll y){
    sz++;
    vis[x][y]=1;
    if(x-1>=0) rows.insert(x-1);
    if(y-1>=0) cols.insert(y-1);
    if(x+1<n) rows.insert(x+1);
    if(y+1<m) cols.insert(y+1);
    rows.insert(x);
    cols.insert(y);
    ll i=x-1, j=y;
    if(i>=0 && i<n && j>=0 && j<m){
        if(vis[i][j]==0 && vc[i][j]=='#') dfs(i, j);
    }
    i=x+1, j=y;
    if(i>=0 && i<n && j>=0 && j<m){
        if(vis[i][j]==0 && vc[i][j]=='#') dfs(i, j);
    }
    i=x, j=y-1;
    if(i>=0 && i<n && j>=0 && j<m){
        if(vis[i][j]==0 && vc[i][j]=='#') dfs(i, j);
    }
    i=x, j=y+1;
    if(i>=0 && i<n && j>=0 && j<m){
        if(vis[i][j]==0 && vc[i][j]=='#') dfs(i, j);
    }
}

void solve(){
    ll h, k ,i, j, s, t, l, r, q, p;
    set < ll >::iterator it;
    cin>>n>>m;
    char ch;
    vc.clear();
    vis.clear();
    row.clear();
    col.clear();
    vector < char > tmp;
    vector < bool > tmpbool;
    for(i=0;i<n;i++){
        
        row.pb(0);
    }
    for(i=0;i<m;i++) col.pb(0);
    for(i=0;i<n;i++){
        vc.pb(tmp);
        vis.pb(tmpbool);
        
        for(j=0;j<m;j++){

            cin>>ch;
            if(ch=='#'){
                // row[i]--;
                // col[j]--;
                // if(j==2) cout<<i<<"------------"<<endl;
            }
            else{
                row[i]++;
                col[j]++;
            }
            vc[i].pb(ch);
            vis[i].pb(0);
        }
    }
    // for(i=0;i<n;i++){
    //     cout<<"row1" _ i _ row[i]<<endl;
       
    // }
    // for(i=0;i<m;i++){
    //     cout<<"col1" _ i _ col[i]<<endl;
       
    // }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(vis[i][j]==0 && vc[i][j]=='#'){
                rows.clear();
                cols.clear();
                sz=0;
                dfs(i, j);
                // cout<<i _ j _ sz<<endl;
                // cout<<"rows: ";
                for(it=rows.begin(); it!=rows.end(); it++){
                    // cout<<*it<<" ";
                    row[*it]+=sz;
                }
                // cout<<endl<<"cols: ";
                for(it=cols.begin(); it!=cols.end(); it++){
                    // cout<<*it<<" ";
                    col[*it]+=sz;
                }
                // cout<<endl;
            }
        }
    }
    ll res =0;
    for(i=0;i<n;i++){
        // cout<<"row" _ i _ row[i]<<endl;
        res=max(res, row[i]);
    }
    for(i=0;i<m;i++){
        // cout<<"col" _ i _ col[i]<<endl;
        res=max(res, col[i]);
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