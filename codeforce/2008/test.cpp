#include<bits/stdc++.h>
#define ll long long
#define _ <<" "<<
#define test if (te) cout
using namespace std;

const ll M = 998244353;
const bool te = 0;


int main() {
    ll n, i, j, k, m, t, s, res;
    cin >> n >> k;
    map < ll, ll > mp;

    s = 0;
    vector < ll > dp(n + 1), cl(n + 1), mps(n + 1);
    mps[0] = 1;
    mp[0] = 0;
    cl[0] =0;
    for (i = 1;i <= n;i++) {
        cin >> t;

        s = (s + t);
        test<<i _ s _ "**"<<endl;
        if (s == k) {
            dp[i] = 0;
            cl[i] = 0;
        } else {
            // cl[i - 1] = 1;
            cl[i] = 1;
            dp[i - 1] = 1;
            dp[i] = 2;
            if(i==n){
                cout<<1<<endl;
                return 0;
            }
            if (mp.find(s) != mp.end()) {
                mps[i] = (mps[mp[s]] + cl[mp[s]])%M;
                test<<"mps" _ mps[i] _ mp[s] _ mps[mp[s]] _ cl[mp[s]]<<endl;
            }
            mp[s] = i;
            i++;
            break;
        }
        if (mp.find(s) != mp.end()) {
            mps[i] = (mps[mp[s]] + cl[mp[s]])%M;
            test<<"mps" _ mps[i] _ mp[s] _ mps[mp[s]] _ cl[mp[s]]<<endl;
        }
        mp[s] = i;

    }
    
    
    for (;i < n;i++) {
        cin >> t;
        s = (s + t);
        if (mp.find(s - k) != mp.end()) {
            test << i _ "col" _ mp[s - k] _ cl[mp[s - k]] _ mps[mp[s - k]] << endl;
            dp[i] = (2 * dp[i - 1] - cl[mp[s - k]] - mps[mp[s - k]]) % M;
            cl[i] = (dp[i - 1] - cl[mp[s - k]] - mps[mp[s-k]]) % M;

        } else {
            dp[i] = 2 * dp[i - 1] % M;
            cl[i] = dp[i - 1];
        }
        test << i _ dp[i] _ cl[i]  << endl;
        if (mp.find(s) != mp.end()) {
            mps[i] = (mps[mp[s]] + cl[mp[s]]) % M;
            test<<"mps" _ mps[i] _ mp[s] _ mps[mp[s]] _ cl[mp[s]]<<endl;
        }
        mp[s] = i;
    }
    if (i <= n) {
        cin >> t;
        s = (s + t);
        if (mp.find(s - k) != mp.end()) {
            test << i _ "col" _ mp[s - k] _ cl[mp[s - k]] _ mps[mp[s - k]] << endl;
            dp[i] = (dp[i - 1] - cl[mp[s - k]] - mps[mp[s - k]]) % M;
        } else {
            dp[i] = dp[i - 1] % M;
        }
        test << i _ dp[i] << endl;
        mp[s] = i;
    }
    cout << dp[n] << endl;

}