#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve() {
    ll n, m, x, y, k, i, j, s, t, a, b, sum;
    a = 0;
    b = 0;
    cin >> n >> m >> k;
    char ch;
    ll arr[n][m];
    ll prefix[n+1][m+1];
    bool is[n][m];
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            cin >> ch;
            is[i][j] = ch - '0';

            if (is[i][j]) {
                a += arr[i][j];
            } else {
                b += arr[i][j];
            }
        }
    }
    for(i=0;i<=m;i++){
        prefix[0][i]=0;
    }
    for(i=0;i<=n;i++){
        prefix[i][0]=0;
    }
    for (i = 0;i < n;i++) {
        
        sum = 0;
        for (j = 0;j < m;j++) {
            sum += is[i][j];
            prefix[i+1][j+1] = sum;
        }
    }
    for (i = 1;i < n;i++) {
        for (j = 0;j < m;j++) {
            prefix[i+1][j+1] += prefix[i][j+1];
        }
    }
    // for (i = 0;i <= n;i++) {
    //     for (j = 0;j <= m;j++) {
    //         cout<<prefix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    i = n - 1;
    j = m - 1;
    
    ll val= prefix[i+1][j+1] - prefix[i - k+1][j+1] - prefix[i+1][j - k+1] + prefix[i - k+1][j - k+1];
    ll g = abs(k * k - val - val);
    for (i = k-1;i < n;i++) {
        for (j = k-1;j < m;j++) {
            // cout<<i _ j<<endl;
            val = prefix[i+1][j+1] - prefix[i - k+1][j+1] - prefix[i+1][j - k+1] + prefix[i - k+1][j - k+1];
            // cout<<"val: "<<abs(k * k - val - val)<<endl;
            g = gcd(g, abs(k * k - val - val));
        }
    }
    // cout << "--------" _ g _ abs(a - b) << endl;
    if(g==0) {
        if(a!=b)cout<<"NO\n";
        else cout<<"YES\n";
    }
    else{
        if (abs(a - b) % g == 0) {
            cout << "YES\n";
        } else cout << "NO\n";
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}