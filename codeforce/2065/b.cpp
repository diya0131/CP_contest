#include<bits/stdc++.h>
#include<random>
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
    cin>>s;
    for(int i=s.size()-2;i>=0;i--){
        if(s[i]==s[i+1]){
            cout<<1<<endl;
            return;
        }
    }
    cout<<s.size()<<endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}