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
    vector < int > cnt(26, 0);
    int i, j, k, n;
    char ch;
    cin>>s;
    n=s.size();
    for(i=1;i<n;i++){
        if(s[i-1]==s[i]){
            cout<<s[i]<<s[i]<<endl;
            return;
        }
    }
    if(n>=3){
        for(i=2;i<n;i++){
            if(s[i]!=s[i-2]){
                cout<<s[i-2]<<s[i-1]<<s[i]<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}