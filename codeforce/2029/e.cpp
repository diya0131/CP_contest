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

vector < ll > p;
vector < bool > isp;

void solve() {
    ll n, i, k, s=0, j, pr=-1, mx;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        k=a[i];
        if(isp[k]){
            pr = k;
        }
    }
    if(pr==-1) cout<<2<<endl;
    else {
        for(i=0;i<n;i++){
            if(isp[a[i]] && a[i]%pr!=0) {
                cout<<-1<<endl;
                return;
            }
            j=0;
            while(a[i]%p[j]!=0) j++;
            if(p[j]==3 && 3*pr<=a[i]) continue;
            if(2*(pr + (p[j] - pr%p[j]))>a[i] && a[i]%pr!=0){
                cout<<-1<<endl;
                return;
            }
        }
        cout<<pr<<endl;
    }
}

int main() {
    // BOOST
    ll N = 4e5+5, j ,i, sz;
    isp.resize(N);
    isp.assign(N, 1);
    isp[0]=0;
    isp[1]=0;
    for(i=2;i*i<=N;i++){
        j=2*i;
        while(j<N){
            isp[j]=0;
            j+=i;
        }
    }
    j=0;
    for(i=0;i<N;i++){
        if(isp[i]) {
            p.pb(i);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}