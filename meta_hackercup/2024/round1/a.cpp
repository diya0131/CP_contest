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
    double n, i, a, b, j, mn=0, mx=INT_MAX;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a>>b;
        if(a==0) a=0.000001;
        mn=max(mn, i/b);
        mx=min(mx, i/a);
    }
    test<<mn _ mx<<endl;
    if(mn>mx){
        cout<<-1<<endl;
    } else {
        if(mn==0) mn+=0.000001;
        cout<<mn<<endl;
    }
}

int main() {
    // BOOST
    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}