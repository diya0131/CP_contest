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

vector < int > primes;



void solve() {
    int n, i, j, s, t, p;
    cin>>n;
    s = n/3 - 1;
    for(i=0;i<primes.size();i++){
        if(1+2*min(primes[i]-1, n - primes[i])>=s){
            t = primes[i];
            break;
        }
    }
    cout<<t<<" ";
    for(i=1;i<n;i++){
        if(t-i<=0 || t+i>n) break;
        cout<<t-i<<" "<<t+i<<" ";
    }
    if(t-i > 0) {
        for(j=1;j<=t-i;j++){
            cout<<j<<" ";
        }
    } else{
        for(j=t+i;j<=n;j++){
            cout<<j<<" ";
        }
    }
    cout<<endl;
}

int main() {

    vector < bool > isp(100005, 1);
    for(int i=2;i<100005;i++){
        if(isp[i]) {
            primes.pb(i);
            int j=i*2;
            while(j<100005){
                isp[j]=0;
                j+=i;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}