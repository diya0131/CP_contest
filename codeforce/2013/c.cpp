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

bool ask(string& s){
    cout<<"?" _ s<<endl;
    bool bl;
    cin>>bl;
    return bl;
}

void solve() {
    ll n, i, j, k;
    bool bl;
    cin>>n;
    string s="1", t;
    bl = ask(s);
    if(!bl){
        s = string(n, '0');
        cout<<"!" _ s<<endl;
        return;
    }
    while(1){
        if(s.size()==n){
            cout<<"!" _ s<<endl;
            return;
        }
        t=s+"1";
        bl = ask(t);
        if(bl) {
            s = t;
            continue;
        }
        t = s+"0";
        bl = ask(t);
        if(bl) s=t;
        else{
            break;
        }
    }
    ll sz = n - s.size();
    for(i=0;i<sz;i++){
        t = "1"+s;
        bl = ask(t);
        if(bl) s = t;
        else s = "0"+s;
    }
    cout<<"!" _ s<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}