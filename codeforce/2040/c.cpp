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
    ll n, i, k, s, t, p, q;
    cin >> n >> k;
    deque<int > dq;
    dq.push_back(n);
    k--;
    for(i=n-1;i>0;i--){
        if(k%2) dq.push_back(i);
        else dq.push_front(i);
        k/=2;
    }
    if(k>0){
         cout<<"-1\n";
         return;
    }
    while(!dq.empty()) {
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}