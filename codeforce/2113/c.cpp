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
    int n, m, k, s=0, i, j, c=0, mn = INT_MAX, x, y;
    cin>>n>>m>>k;
    vector<string> str(n);
    for(i=0;i<n;i++){
        cin>>str[i];
    }
    vector<vector<int>>a(n, vector<int>(m, 0));
    for(i=0;i<n;i++){
        s=0;
        for(j=0;j<m;j++){
            if(str[i][j]=='g') s++;
            a[i][j] = s;
        }
    }
    for(i=1;i<n;i++){
        for(j=0;j<m;j++){
            a[i][j] += a[i-1][j];
        }
    }
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(str[i][j]=='g')  c++;
            if(str[i][j]=='.'){
               
                

                // cout<<s<<endl;
                x = min(n-1, i + k - 1);
                y = min(m-1, j + k - 1);
                s = a[x][y];
                // cout<<s<<endl;
                if(i - k>=0) s-=a[i-k][y];
                // cout<<s<<endl;
                if(j - k>=0) s-=a[x][j-k];
                if(i-k>=0 && j-k>=0) s+=a[i-k][j-k];

                mn = min(mn, s);




                // cout<<i _ j _ s _ x _ y _ i-k _ j-k<<endl;
            }
        }
    }
    cout<<c - mn<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}