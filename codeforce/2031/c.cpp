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
    ll n, i, k, s, t, j, p=1;
    cin>>n;
    if(n%2 && n<27){
        cout<<-1<<endl;
    } else {
        if(n%2){
            j=2;
            for(i=0;i<n;i++){
                if(i==0 || i==9 || i==25) cout<<1<<" ";
                else{
                    if(i==10 || i==26) cout<<2<<" ";
                    else {
                        if(p%2) j++;
                        cout<<j<<" ";
                        p=(p+1)%2;
                    }
                }
            }
            cout<<endl;
        } else {
            j=0;
            for(i=0;i<n;i++){
                if(p%2) j++;
                cout<<j<<" ";
                p=(p+1)%2;
            }
            cout<<endl;
        }
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}