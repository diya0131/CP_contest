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
    int n, a, b, i, x=0, y=0;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    for(int j=0;j<100;j++){
        for(i=0;i<n;i++){
            if(x==a && y==b){
                cout<<"YES\n";
                return;
            }
            switch(s[i]){
                case 'N':
                    y++;
                break;
                case 'E':
                    x++;
                break;
                case 'S':
                    y--;
                break;
                case 'W':
                    x--;
                break;
            }
        }
    }
    cout<<"NO\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}