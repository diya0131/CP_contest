#include<bits/stdc++.h>

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

const bool TEST = 0;

vector < ll > primes;

void sieve(ll limit){
    vector < bool > isp(limit, true);
    ll n=sqrt(limit), j, c=limit-1;
    for(ll i=2;i<=n;i++){
        if(isp[i]){
            j=2*i;
            while(j<limit){
                c-=isp[j];
                isp[j]=0;
                j+=i;
            }
        }
    }
    primes.resize(c-1);
    j=0;
    for(ll i=2;i<limit;i++){
        if(isp[i]) {
            primes[j]=i;
            j++;
        }
    }
}

vector < vector < int > > adj, cap;

ll bfs(ll start, ll end, vector < int >& parent){
    fill(ALL(parent), -1);
    queue < pair < ll, ll > > q;
    pair < ll, int > pr;
    ll k, i, j, s, res=0;
    q.push({start, LLONG_MAX});
    while(!q.empty()){
        pr=q.front();
        q.pop();
        if(k==end) return pr.ss;
        for(int to: adj[pr.ff]){
            if(parent[to]==-1 && cap[pr.ff][to]>0){
                k=min(pr.ss, cap[pr.ff][to]);
                q.push({to, k});
            }
        }
    }


    return 0;
    
}

ll maxflow(ll start, ll end, ll sz){
    ll res=0, flow;
    vector < int > parent(sz);
    while(flow = bfs(start, end, parent)){
        res+=flow;
    }
    return res;
}

void solve() {
    ll n, m, i, j, s,u, v, c, x, y, res=0, idx=0;
    cin>>n>>m;
    adj.resize(10*n);
    cap.assign(10*n, vector (10*n, 0));
    ll a[n], start, end;
    start=idx++;
    end=idx++;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
   
    map < int, int > mp[n];
    while(m--){
        cin>>u>>v;
        if(u%2) swap(u, v);
        u--; v--;
        i=0;
        while(a[u]>1 && a[v]>1 && i<primes.size()){
            if(a[u]%primes[i]==0 && a[v]%primes[i]==0){
                c=0;
                while(a[u]%primes[i]==0 && a[v]%primes[i]==0){
                    a[u]/=primes[i];
                    a[v]/=primes[i];
                    c++;
                }
                if(mp[u].find(primes[i])==mp[u].end()) mp[u][primes[i]]=idx++;
                x=mp[u][primes[i]];
                if(mp[v].find(primes[i])==mp[v].end()) mp[v][primes[i]]=idx++;
                y=mp[v][primes[i]];

                adj[start].pb(x);
                adj[y].pb(end);
                cap[start][x]=LLONG_MAX;
                cap[y][end]=LLONG_MAX;

                adj[x].pb(y);
                adj[y].pb(x);
                cap[x][y]=c;
            }
            i++;
        }
        if(a[u]>1 && a[u]==a[v]) {
            res++;
            a[u]=a[v]=1;
        }
    }
    ll start = idx++, end=idx++, sz=idx;
    res+=maxflow(start, end, sz);
    
}

int main() {
    // BOOST
    sieve(sqrt(1e9));
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}