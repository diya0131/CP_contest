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
    ll n, t, i, j, k, r, p=0;
    cin>>n;
    bool began=false;
    string s(n, ' ');
    for(i=1;i<n;i++){
        cout<<"?" _ 1 _ i+1<<endl;
        cout.flush();
        cin>>k;
        if(began){
            if(k==p) s[i]='0';
            else s[i]='1';
            
        } else {
            if(k){
                for(j=0;j<i-k;j++){
                    s[j]='1';
                }
                for(j=i-k;j<i;j++){
                    s[j]='0';
                }
                s[i]='1';
                began=1;
                
            }
        }
        p=k;
    }
    if(began){
        cout<<"!" _ s<<endl;
    } else {
        cout<<"! IMPOSSIBLE\n";
    }
    cout.flush();
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}