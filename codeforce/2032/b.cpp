#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    ll n, k, i;
    cin>>n>>k;
    if(k==1){
        if(n==1){
            cout<<1<<endl;
            cout<<1<<endl;
            return;
        }
        cout<<-1<<endl;
        return;
    }
    if(k==n){
        cout<<-1<<endl;
        return;
    }
    if(k%2){
        cout<<5<<endl;
        cout<<1 _ 2 _ k _ k+1 _ n _ endl;
        return;
    } 
    cout<<3<<endl;
    cout<<1 _ k _ k+1<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}