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
    ll n, i, j, t;
    string s[2];
    cin>>n>>s[0]>>s[1];
    bool k=false;
    bool mul=false;
    for(i=0;i<n;i++){
        // cout<<i<<endl;
        // cout<<s[0]<<endl;
        // cout<<s[1]<<endl;
        if(s[0][i]=='.'){
            if(s[1][i]=='.'){
                if(k) {
                    mul=true;
                } else{
                    k=1;
                }
            } else {
                k=0;
                if(i+1<n && s[0][i+1]=='.') s[0][i+1]='#';
                else {
                    cout<<"None\n";
                    return;
                }
            }
        } else {
            if(s[1][i]=='.'){
                if(i+1<n && s[1][i+1]=='.') s[1][i+1]='#';
                else {
                    cout<<"None\n";
                    return;
                }
            } 
            k=0;
        }
    }
    if(mul) cout<<"Multiple\n";
    else cout<<"Unique\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}