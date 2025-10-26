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

void solve() {
    ll n, i, s, mx=0, to, k;
    cin>>n;
    vector < ll > a(n), b(n, -1), bck(n);
    // -1 - unvisited
    // 0 - loop
    // + - away
    // -2 - current
    for(int i=0; i<n; i++) {
        cin>>a[i];
        a[i]--;
    }
    for(i=0;i<n;i++){
        if(b[i]==-1){
            b[i]=-2;
            to = a[i];
            bck[to]=i;
            while(b[to]==-1){
                b[to]=-2;
                if(b[a[to]]!=-2) bck[a[to]]=to;
                to=a[to];
            }
            if(b[to]==-2){
                k = to;
                b[to]=0;
                to = a[to];
                while(b[to]==-2){
                    b[to]=0;
                    to=a[to];
                }
                to=bck[k];
                
                s=1;
                while(b[to]==-2){
                    b[to]=s;
                    s++;
                    to = bck[to];
                }
            } else{
                s = b[to]+1;
                to = bck[to];
                while(b[to]==-2){
                    b[to]=s;
                    s++;
                    to=bck[to];
                }
            }
            
        }
    }
    for(i=0;i<n;i++){
        mx = max(b[i], mx);
    }
    cout<<mx+2<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}