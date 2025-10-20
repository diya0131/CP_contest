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

int solve() {
    int n, mn, ix, jx, k=1;
    cin>>n;
    vector<vector<int>>a(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            a[i][j]=0;
        }
    }
    while(1){
        mn = 3*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i][j]==-1) continue;

                if(a[i][j]<mn){
                    mn = a[i][j];
                    ix = i;
                    jx = j;
                }
            }
        }
        a[ix][jx]=-1;
        for(int i=0;i<n;i++){
            if(ix!=i && a[max(ix, i)][min(ix, i)]!=-1) a[max(ix, i)][min(ix, i)]++;
            if(jx!=i && a[max(jx, i)][min(jx, i)]!=-1) a[max(jx, i)][min(jx, i)]++;
        }
        cout<<ix+1 _ jx+1<<endl;
        cout.flush();
        cin>>k;
        if(k==-1) {
            return -1;
        }
        if(k==1) break;
    }
    return 0;
}

int main() {
    int t, k;
    cin >> t;
    while (t--) {
        k = solve();
        if(k==-1) break;
    }
}