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
    int n, m, i, j, s=0;
    cin>>n>>m;
    vector < vector <char> > a(n, vector <char> (m));
    vector < vector <bool> > c(n, vector <bool> (m, 0));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
            s+=a[i][j]-'0';
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='1'){
                if(!c[i][j]) {
                    s--;
                    c[i][j]=1;
                }

            } else{
                break;
            }
        }
    }
    for(j=0;j<m;j++){
        for(i=0;i<n;i++){
            if(a[i][j]=='1'){
                if(!c[i][j]) {
                    s--;
                    c[i][j]=1;
                }

            } else{
                break;
            }
        }
    }
    if(s>0) cout<<"NO\n";
    else cout<<"YES\n";
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}