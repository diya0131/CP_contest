#include<bits/stdc++.h>
#include<random>
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

ll gcd(ll x, ll y) {
    while(x!=0 && y!=0){
        if(x>y) x%=y;
        else y%=x;
    }
    return x+y;
}

void solve() {
    ll l, r, g, i, j, res=-1, resl=-1, resr=-1;
    cin>>l >> r>>g;
    l = (l+g-1)/g;
    r = r/g;
    for(i=0;i<40;i++){
        for(j=0;j<40;j++){
            if(l + i <= r - j){
                if(gcd(l+i, r-j)==1){
                    if(r-j - l - i+1 > res){
                        res = (r-j - l - i+1);
                        resl=l+i;
                        resr=r-j;
                    }
                    break;
                }
            }
        }
    }
    if(res==-1) cout<<-1 _ -1<<endl;
    else cout<<resl*g _ resr*g<<endl;
}

int main() {
    BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}