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

vector < ll > arr;

void go(ll k, ll p){
    if(k+p/2>9) return;
    ll res=0;
    for(int i=0;i<=k/2;i++){
        res=res*10+p;
        p++;
    }
    p--;
    for(int i=0;i<k/2;i++){
        p--;
        res=res*10+p;
    }
    // cout<<k _ p _ res<<endl;
    arr.pb(res);
}

void solve() {
    ll a, b, m;
    cin>>a>>b>>m;
    ll res=0;
    for(ll num:arr){
        if(a<=num && num<=b && num%m==0) {
            res++;
            cout<<num<<endl;
        }
    }
    cout<<res<<endl;
}

int main() {
    for(int i=1;i<=9;i+=2){
        for(int j=1;j<10;j++){
            go(i, j);
        }
    }
    for(int num:arr) cout<<num<<endl;
    freopen("cottontail_climb_part_1_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // BOOST
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
}