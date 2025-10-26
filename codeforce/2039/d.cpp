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
const ll N = 1e5+16;
vector < ll > cnt(N, 0);

void solve() {
    ll n, m, i, j, k, s, q, t;
    cin>>n>>m;
    vector < ll > st(m);
    for(i=0;i<m;i++) cin>>st[i];
    q = 1;
    for(i=0;i<m;i++) {
        q*=2;
        if(q>n) break;
    }
    if(q<=n){
        cout<<-1<<endl;
        return;
    }
    for(i=1;i<=n;i++){
        cout<<st[m - 1 - cnt[i]]<<" ";
    }
    cout<<endl;

}

int main() {
    ll j, q, t, c;
    vector < bool > isp(N, 1);
    for(ll i=2;i*i<=N;i++){
        if(isp[i]){
            j = 2*i;
            while(j<N){
                isp[j]=0;
                j+=i;
            }
        }
    }
    for(ll i=2;i<N;i++){
        if(isp[i]){
            q=i;
            while(q<N){
                t=q;
                while(t<N){
                    cnt[t]++;
                    t+=q;
                }
                q*=i;
            }
        }
    }
    cin >> t;
    while (t--) {
        solve();
    }
}