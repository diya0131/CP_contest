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

int main() {
    ll n, m, i, j, k, s=0, t, x, p, q, nx, ny;
    priority_queue < pair < ll, pair < ll, ll > > > pq;
    pair < ll, pair < ll, ll > >pr;
    cin>>n>>m>>x;
    cin>>p>>q;
    p--;
    q--;
    vector a(n, vector<ll>(m));
    vector vis(n, vector(m, false));
    for(i=0; i<n; i++){
        for(j=0;j<m; j++){
            cin>>a[i][j];
        }
    }
    vector<ll> mx={1, -1, 0, 0}, my = {0, 0, 1, -1};
    vis[p][q] = 1;
    s = a[p][q];
    for(i=0;i<4;i++){
        nx = p+mx[i];
        ny = q+my[i];
        if(0<=nx && nx<n && 0<=ny && ny<m && !vis[nx][ny]){
            vis[nx][ny]=1;
            pr.ff = -a[nx][ny];
            pr.ss ={nx, ny};
            pq.push(pr);
        }
    }
    while(!pq.empty()){
        pr = pq.top();
        pq.pop();
        pr.ff*=-1;
        if(s%x==0) {
            if(pr.ff>=s/x) break;
        }
        else if(pr.ff>s/x) break;
        s+=pr.ff;
        p=pr.ss.ff;
        q=pr.ss.ss;
        for(i=0;i<4;i++){
            nx = p+mx[i];
            ny = q+my[i];
            if(0<=nx && nx<n && 0<=ny && ny<m && !vis[nx][ny]){
                vis[nx][ny]=1;
                pr.ff = -a[nx][ny];
                pr.ss ={nx, ny};
                pq.push(pr);
            }
        }
    }
    cout<<s<<endl;

}