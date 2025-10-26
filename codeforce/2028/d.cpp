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
ll n, i, s, t, j, k;
    map< ll, char > mp;
    mp[0]='q';
    mp[1]='k';
    mp[2]='j';
    cin>>n;
    vector < vector < ll >  > a(3, vector < ll >(n)), b(3, vector < ll >(n, -1));
    for(j=0;j<3;j++){
        for(i=0;i<n;i++){
            cin>>a[j][i];
        }
    }
    ll mx[3], mxp[3];
    vector < ll > to(n, -1), who(n, -1);
    for(j=0;j<3;j++) {
        mx[j]=a[j][n-1];
        mxp[j]=n-1;
    }
    for(i=n-2;i>=0;i--){
        bool can = 0;
        // cout<<"mx" _ i _ mx[0] _ mx[1] _ mx[2]<<endl;
        // cout<<"a" _ i _ a[0][i] _ a[1][i] _ a[2][i]<<endl;
        for(j=0;j<3;j++){
            if(a[j][i]>mx[j]){
                // cout<<"can" _ j _ a[j][i] _ mx[j] _ mxp[j] _ i<<endl;
                to[i]=mxp[j];
                who[i]=j;
                can = true;
            }
        }
        
        if(can){
            for(j=0;j<3;j++){
                if(mx[j]>a[j][i]){
                    mx[j]=a[j][i];
                    mxp[j]=i;
                }
            }
        }
        // cout<<"can" _ can _ mx[0] _ mx[1] _ mx[2]<<endl;
    }
    if(to[0]==-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    s=0;
    k=0;
    while(k!=n-1){
        k=to[k];
        s++;
    }
    cout<<s<<endl;
    k=0;
    while(k!=n-1){
        cout<<mp[who[k]] _ to[k]+1<<endl;
        k=to[k];
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}