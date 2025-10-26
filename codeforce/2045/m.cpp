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


int c, n, m;
vector <vector< int > > cnt;
vector <vector<char>>a;
void go(int x, int y, int k){
    // cout<<x _ y _ k<<endl;
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(a[x][y]=='.') {
        switch(k){
            case 1:
                go(x-1, y, k);
            break;
            case 2:
                go(x, y+1, k);
            break;
            case 3:
                go(x+1, y, k);
            break;
            case 4:
                go(x, y-1, k);
            break;
        }
    } else{
        if(cnt[x][y]==2) return;
        if(cnt[x][y]==0) c++;
        cnt[x][y]++;
        // cout<<a[x][y]<<endl;
        if(a[x][y]=='/'){
            
            switch(k){
                case 1:
                    go(x, y+1, 2);
                break;
                case 2:
                    go(x-1, y, 1);
                break;
                case 3:
                    go(x, y-1, 4);
                break;
                case 4:
                    go(x+1, y, 3);
                break;
            }
        } else {
            switch(k){
                case 1:
                    go(x, y-1, 4);
                break;
                case 2:
                    go(x+1, y, 3);
                break;
                case 3:
                    go(x, y+1, 2);
                break;
                case 4:
                    go(x-1, y, 1);
                break;
            }
        }
    }
}

void solve() {
    int i, j, k, s=0, t;
    cin>>n>>m;
    a.clear();
    a.assign(n, vector(m, ' '));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j]!='.') s++;
        }
    }
    vector < pair < char, int > > res;
    c=0;
    cnt.assign(n, vector(m, 0));
    // go(0, 2, 3);
    // cout<<c<<endl;
    for(i=0;i<n;i++){
        c=0;
        cnt.assign(n, vector(m, 0));
        go(i, 0, 2);
        if(c==s) res.pb({'W', i+1});
    }
    for(i=0;i<n;i++){
        c=0;
        cnt.assign(n, vector(m, 0));
        go(i, m-1, 4);
        if(c==s) res.pb({'E', i+1});
    }
    for(i=0;i<m;i++){
        c=0;
        cnt.assign(n, vector(m, 0));
        go(0, i, 3);
        if(c==s) res.pb({'N', i+1});
    }
    for(i=0;i<m;i++){
        c=0;
        cnt.assign(n, vector(m, 0));
        go(n-1, i, 1);
        if(c==s) res.pb({'S', i+1});
    }
    cout<<res.size()<<endl;
    for(i=0;i<res.size();i++){
        cout<<res[i].ff<<res[i].ss<<" ";
    }
    cout<<endl;
}

int main() {
    solve();
}