#include<bits/stdc++.h>
#include<random>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const bool TEST = 0;

vector< bool > vis;
vector< int > width;
vector<vector<int>> adj;
vector<vector<int>> tr;

int k;

int buildtree(int nd){
    int s = 1;
    for(int to: adj[nd]){
        if(vis[to]) continue;
        vis[to] = 1;
        tr[nd].pb(to);
        s+=buildtree(to)+1;
    }
    width[nd] = s;
    return s;
}

void draw(int nd, int x, int y, vector<vector<int>>& res){
    int w = width[nd];
    for(int i=x;i<k;i++){
        for(int j=y;j<y+w;j++){
            res[i][j] = nd+1;
        }
    }
    y++;
    for(int to: tr[nd]){
        draw(to, x+1, y, res);
        y+=w+1;
    }
}


vector<vector<int>> create_map(int n, int m, vector<int> a, vector<int> b){
    adj.clear();
    vis.clear();
    width.clear();
    tr.clear();
    tr.resize(n);
    width.resize(n, 0);
    adj.resize(n);
    vis.resize(n, 0);
    for(int i=0;i<a.size();i++){
        adj[a[i]-1].pb(b[i]-1);
        adj[b[i]-1].pb(a[i]-1);
    }
    vis[0] = 1;
    k =buildtree(0);
    vector<vector<int>>res(k, vector<int>(k, 1));

    draw(0, 0, 0, res);

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return res;
}


int main(){
    int n, m;
    cin>>n>>m>>k;
    vector<int> a(k), b(k);
    for(int i=0;i<k;i++){
        cin>>a[i]>>b[i];        
    }
    create_map(n, m, a, b);
}