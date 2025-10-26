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

}

int main() {
    ll n, m, i, j, w, s;
    cin>>n>>w;
    vector <ll> weight(n), prof(n), dp(w+1, 0);
    for(int i=0; i<n;i++) cin>>weight[i]>>prof[i];

    for(j=0;j<n;j++){
        for(i=w;i>=1;i--){
            if(i>=weight[j]) dp[i]=max(dp[i], dp[i-weight[j]]+prof[j]);
        }
    }
    cout<<dp[w]<<endl;
}