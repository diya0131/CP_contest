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
    int n;
    cin>>n;
    if(n==1 || n==3) {
        cout<<-1<<endl;
        return;
    }
    if(n%2){
        for(int i=0;i<n-5;i++) cout<<3;
        cout<<36366<<endl;
    }else {
        for(int i=0;i<n-2;i++) cout<<3;
        cout<<66<<endl;
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