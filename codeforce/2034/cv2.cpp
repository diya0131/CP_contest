#include<bits/stdc++.h>
#include<chrono>
#include <random>

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

ll n, m;

vector < vector < char > > a;
vector < vector < int > > can;
queue< pair < ll ,ll > > q;

void goback(ll p){
    pair < ll, ll >pr;
    while(!q.empty()) {
        pr=q.front();
        q.pop();
        can[pr.ff][pr.ss]=p;
    }
}

void go(ll x, ll y, ll px, ll py){
    // cout<<x _ y <<endl;
    if(x<0 || x>=n || y<0 || y>=m){
        goback(0);
        return;
    }
    if(a[x][y]=='?' || can[x][y]==-2){
        // cout<<"goback\n";
        can[x][y]=1;
        goback(1);
        return;
    }
    // cout<<a[x][y] _ can[x][y]<<endl;
    if(can[x][y]!=-1) {
        goback(can[x][y]);
        return;
    }
    
    switch (a[x][y]) {
    case 'D':
        can[x][y]=-2;
        q.push({x, y});
        go(x + 1, y, x, y);
        return;
    case 'U':
        can[x][y]=-2;
        q.push({x, y});
        go(x - 1, y, x, y);
        return;
    case 'L':
        can[x][y]=-2;
        q.push({x, y});
        go(x, y - 1, x, y);
        return;
    case 'R':
        can[x][y]=-2;
        q.push({x, y});
        go(x, y + 1, x, y);
        return;
    }

}

void solve() {
    ll i, j, k, x, y, res=0;
    while(!q.empty()) {
        q.pop();
    }
    cin>>n>>m;
    a.clear();
    a.assign(n, vector < char> (m));
    can.clear();
    can.assign(n, vector < int> (m, -1));

    for(i=0; i<n; i++){
        for(j=0; j<m; j++) cin>>a[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]!='?' && can[i][j]==-1){
                go(i, j, 0, 0);
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(can[i][j]==-1){
                bool done = false;
                x = i - 1;
                y = j;
                if (!done && x>=0 && x<n && y>=0 && y<m && (a[x][y]=='?' || can[x][y] == 1)) {
                    done = 1;
                } 
                x = i + 1;
                y = j;
                if (!done && x>=0 && x<n && y>=0 && y<m && (a[x][y]=='?' || can[x][y] == 1)) {
                    done = 1;
                }
                x = i;
                y = j - 1;
                if (!done && x>=0 && x<n && y>=0 && y<m && (a[x][y]=='?' || can[x][y] == 1)) {
                    done = 1;
                }
                x = i;
                y = j + 1;
                if (!done && x>=0 && x<n && y>=0 && y<m && (a[x][y]=='?' || can[x][y] == 1)) {
                    done = 1;
                }
                can[i][j]=done;
            } 
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            // cout<<can[i][j]<<" ";
            res+=can[i][j];
        }
        // cout<<endl;
    }
    cout<< res<<endl;;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}