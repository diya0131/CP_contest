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

void solve() {
    ll n, i, j, t, k, s=0, f=0, ca=1, cb=1;
    char a = 'L', b = 'R';
    cin>>n;
    cin>>t;
    f=t;
    for(int i=1;i<n;i++){
        cin>>k;
        
        if(k==t){
            if(a!='X'){
                a = 'L'+'R' - a;
            }
            if(b!='X'){
                b = 'L'+'R' - b;
            }
        }
        if(k==t+1){
            if(a!='L') a = 'X';
            else a = 'L';
            if(b!='L') b = 'X';
            else b = 'L';
            
        }
        if(k==t-1){
            if(a!='R') a = 'X';
            else a = 'R';
            if(b!='R') b = 'X';
            else b = 'R';
        }
        if(a!='X'){
            if(a=='R') ca++;
        }
        if(b!='X'){
            if(b=='R') cb++;
        }
        if(abs(t-k)>1){
            a = 'X';
            b = 'X';
        }
        t=k;
        
    }
    if(a!='X' && ca==f) s++;
    if(b!='X' && cb==f) s++;
    cout<<s<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}