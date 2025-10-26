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
    string s;
    ll n, i, j, k = -1, t, l, r;
    cin>>s;
    n=s.size();
    for (i = 0;i < n;i++) {
        if (s[i] == '0') {
            k = i;
            break;
        }
    }
    if (k == -1) {
        cout << 1 _ n _ 1 _ 1 << endl;
        return;
    }
    vector < bool > res(n - k, 0), tmp(n-k);
    l=0;
    for (i = 0;i <= k;i++) {
        if (s[i] == '1') {
            t = 0;
            tmp.clear();
            for (j = k;j < n;j++) {
                tmp[j - k] = (s[j] - '0') ^ (s[i + j - k] - '0');
            }
            bool cmp = false;
            for (j = 0;j < n - k;j++) {
                if (res[j] == tmp[j]) continue;
                if (res[j] < tmp[j]) cmp = 1;
                break;
            }
            if(cmp){
                for(j=0;j<n-k;j++) res[j]=tmp[j];
                l = i;
            }
        }
    }
    cout<<1 _ n _ l+1 _ l+n-k <<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}