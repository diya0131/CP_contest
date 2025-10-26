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
    ll n, i, s=0, k=1, t, l=0;
    char p;
    string str;
    cin>>n>>str;
    p='1';
    for(i=0;i<n;i++){
        if(str[i]=='0'){
            if(p=='0'){
                k=1;
            } else{
                s++;
            }
        } else{
            if(p=='1'){
                if(s%2 && k==0){
                    cout<<"NO\n";
                    return;
                }
                s=0;
                k=0;
            } 
        }
        p=str[i];
    }
    if(s>0){
        if(s%2 && k==0 && str[n-1]!='0'){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}