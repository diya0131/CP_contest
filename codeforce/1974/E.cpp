#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ss second
#define ff first
#define _ <<" "<<

using namespace std;

void solve() {
    ll n, m, k, x, i, j, c, h;
    cin >> m >> x;
    // ll dp[m * 1000 + 1];
    map< ll, ll > mp;
    map< ll, ll >::iterator it;
    vector < pair< ll, ll > > tmp;
    // for (j = 0;j <= m * 1000 ;j++) dp[j] = -1;
    // dp[0] = 0;
    mp[0]=0;
    for (i = 0;i < m;i++) {
        cin >> c >> h;
        for (it = mp.begin(); it!=mp.end(); it++) {
            if (i * x - it->second >= c) {
                // cout<<j<<" "<<dp[j]<<"--"<<h<<endl;
                j =it->first; 
                if( j+h <= m*1000){
                    // if (dp[j + h] == -1) dp[j + h] = dp[j] + c;
                    // else dp[j + h] = min(dp[j + h], dp[j] + c);
                    if (mp.find(j + h) == mp.end()) tmp.pb({j+h, mp[j]+c });
                    else {
                        if(mp[j+h]>mp[j]+c) tmp.pb({ j+h, mp[j]+c });
                    }
                }
            }
        }
        for(j=0;j<tmp.size();j++){
            // cout<<tmp[j].ff <<" - "<<tmp[j].ss<<endl;
            mp[tmp[j].ff]=tmp[j].ss;
        }
        tmp.clear();
    }
    // i = m * 1000;
    // while (dp[i] == -1) {
    //     i--;
    // }
    ll res =0;
    for (it = mp.begin(); it!=mp.end(); it++) {
        res = max(res, it->ff);
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    
        solve();
    }
}