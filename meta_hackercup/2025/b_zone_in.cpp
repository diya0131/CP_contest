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

void solve(int idx) {
    int n, m, s, res=0, x, y, sp;
    cin>>n>>m>>s;
    vector< vector<char>>a(n, vector<char>(m));
    vector< vector<bool>>is(n, vector<bool>(m, 0));
    vector<int>mv={1, 0, -1, 0, 1};
    priority_queue<pair < int, pair < int, int > > > pq;
    pair < int, pair < int, int > > pr;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
            if(a[i][j]=='#'){
                is[i][j]=1;
                pq.push({s, {i, j}});
            }
        }
    }
    while(!pq.empty()){
        pr = pq.top();
        pq.pop();
        // if(is[pr.ss.ff][pr.ss.ss]==1) continue;
        is[pr.ss.ff][pr.ss.ss]=1;
        if(pr.ff!=s) a[pr.ss.ff][pr.ss.ss]='*';
        if(pr.ff>0){
            for(int i=0;i<4;i++){
                x = pr.ss.ff+mv[i];
                y = pr.ss.ss+mv[i+1];
                if(0<=x && x<n && 0<=y && y<m && !is[x][y]){
                    is[x][y]=1;
                    pq.push({pr.ff-1, {x, y}});
                }
            }
        }
    }
    // cout<<s _ n _ m<<endl;
    for(int i=s;i<n-s;i++){
        for(int j=s;j<m-s;j++) {
            // cout<<a[i][j];
            is[i][j]=0;
        }
        // cout<<endl;
    }
    queue<pair<int,int>>q;
    pair<int,int>p;
    for(int i=s;i<n-s;i++){
        for(int j=s;j<m-s;j++) {
            if(!is[i][j]){
                sp=0;
                q.push({i,j});
                while(!q.empty()){
                    p=q.front();
                    q.pop();
                    // cout<<p.ff _ p.ss _ a[p.ff][p.ss]<<endl;
                    if(a[p.ff][p.ss]!='.') continue;
                    
                    sp++;
                    is[p.ff][p.ss]=1;
                    for(int l=0;l<4;l++){
                        x = p.ff+mv[l];
                        y = p.ss+mv[l+1];
                        // cout<<x _ y _ " --\n";
                        if(s<=x && x<n-s && s<=y && y<m-s && !is[x][y]){
                            is[x][y]=1;
                            q.push({x, y});
                        }
                    }
                }
                // cout<<i _ j _ sp<<endl;
                res=max(res, sp);
            }
        }
    }
    cout<<"Case #"<<idx<<": "<<res<<endl;
}

int main() {
    freopen("input/zone_in_input.txt", "r", stdin);
    freopen("output/zone_in_output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        solve(i+1);
    }
}