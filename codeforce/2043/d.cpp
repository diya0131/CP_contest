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
    ll l, r, i, j, g, s, k, res = -1, a=-1, b=-1;
    cin>>l>>r>>g;
    l = ((l-1)/g+1)*g;
    r = r/g * g;
    for(i=0;i<30;i++){
        for(j=0;j<30;j++){
            if(l/g+i > r/g - j) break;
            if(gcd(l/g + i, r/g - j)==1){
                if(r/g - j - l/g - i> res ){
                    res = r/g - j - l/g - i;
                    a = l/g + i;
                    b = r/g - j;
                }
            }
        }
    }
    if(res != -1){
        a*=g;
        b*=g;
    }
    cout<<a _ b<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}