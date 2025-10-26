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

vector<int>val(5e5+5, 1);

void solve() {
    ll m;
    cin>>m;
    if(m%2==0){
        cout<<-1<<endl;
        return;
    }
    
    
    cout<<val[m]<<endl;
}

int main() {

    int mx = 5e5+5, t, x, tmp;
    val[1]=1;
    vector<bool>isp(mx, 1);
    for(int i=3;i<mx;i+=2){
        val[i]=1+val[i-2];
        tmp = sqrt(i);
        for(int j=3;j<=tmp;j+=2){
            if(i%j==0) val[i] = min(val[i], val[i/j] + val[j] - 1);
        }
        
    }
    // mp[1]=1;
    // for(int i=3;i<mx;i++){
    //     mp[i] = go(i);
    // }
    // for(int i=3;i<20;i+=2){
    //     cout<<val[i]<<endl;
    // }
    // BOOST
    cin >> t;
    while (t--) {
        solve();
    }
}
