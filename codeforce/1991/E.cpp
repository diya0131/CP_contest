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

vector< vector < ll > > path;
vector < bool > vis, par, lvl;
vector < ll > col;
vector < ll > even, odd;
bool can;
void check(ll v, ll p, bool lv) {
    test<<v _ "here\n";
    lv = !lv;
    lvl[v]=lv;
    if(lv) odd.pb(v);
    else even.pb(v);
    vis[v] = true;
    for (ll i = 0;i < path[v].size();i++) {
        if (path[v][i] != p) {
            par[path[v][i]] = v;
            if(vis[path[v][i]]){
                if(lvl[path[v][i]]==lv) can=false;
            } else {
                check(path[v][i], v, lv);
            }
        }
    }
   
}

void dfsbob(ll v) {
    ll a, b, i, j, n, k;
    cin >> a >> b;
    if(v==0){
        cout<<v+1 _ a<<endl;
    } else {
        if (a == col[par[v]]){
            cout<<v+1 _ b<<endl;
        } else {
            cout<<v+1 _ a<<endl;
        }
    }
    cout.flush();
    for(i=0;i<path[v].size();i++){
        if(path[v][i]!=par[v]){
            dfsbob(path[v][i]);
        }
    }
}

void solve() {
    ll n, k, i, j, m, x, y, a, b, e, o;
    cin >> n >> m;
    even.clear();
    odd.clear();
    path.clear();
    path.resize(n);
    col.clear();
    col.resize(n);
    lvl.clear();
    lvl.resize(n);
    par.clear();
    par.resize(n);
    vis.clear();
    vis.resize(n, false);
    for (i = 0;i < m;i++) {
        cin >> x >> y;
        x--;
        y--;
        path[x].pb(y);
        path[y].pb(x);
    }
    par[0] = -1;
    lvl[0]=0;
    bool done=0, wh=0;
    can = true;
    check(0, -1, 0);
    if (can) {
        cout << "Bob\n";
        cout.flush();
        e=0;
        o=0;
        for(i=0;i<n;i++){
            cin>>a>>b;
            if(done){
                if(wh){
                    if(a==2){
                        cout<<even[e]+1 _ b<<endl;
                        cout.flush();
                    } else {
                        cout<<even[e]+1 _ a<<endl;
                        cout.flush();
                    }
                    e++;
                } else {
                    if(a==1){
                        cout<<odd[o]+1 _ b<<endl;
                        cout.flush();
                    } else {
                        cout<<odd[o]+1 _ a<<endl;
                        cout.flush();
                    }
                    o++;
                }
            } else {
                if(a==1 || b==1){
                    if(e<even.size()){
                        cout<<even[e]+1 _ 1<<endl;
                        cout.flush();
                        e++;
                    } else {
                        cout<<odd[o]+1 _ a+b-1<<endl;
                        cout.flush();
                        o++;
                        done = 1;
                        wh = 0;
                    }
                } else {
                    if(o<odd.size()){
                        cout<<odd[o]+1 _ 2<<endl;
                        cout.flush();
                        o++;
                    } else {
                        cout<<even[e]+1 _ 3<<endl;
                        cout.flush();
                        e++;
                        done = 1;
                        wh=1;
                    }
                }
            }
        }

    } else {
        cout << "Alice\n";
        cout.flush();
        for(i=0;i<n;i++){
            cout<<1 _ 2<<endl;
            cout.flush();
            cin>>a>>b;
        }
    }


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}