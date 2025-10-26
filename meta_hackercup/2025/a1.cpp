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

void solve(int idx) {
    int n, res=0, p, k;
    cin>>n;
    cin>>p;
    for(int i=1;i<n;i++){
        cin>>k;
        res = max(res, abs(k-p));
        p=k;
    }
    cout<<"Case #"<<idx<<": "<<res<<endl;
}

int main() {
    // BOOST
    freopen("input/snake_scales_chapter_1_input.txt", "r", stdin);
    freopen("output/a_out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        solve(i+1);
    }
}